/* Copyright (c) 2002-2003 krzYszcz and others.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.  */

/* The three uses of the 'hammerfile' proxy class are:
   1. providing `embedding' facility -- storing master object's state
   in a .pd file,
   2. encapsulating openpanel/savepanel management,
   3. extending the gui of Pd with a simple text editor window.

   A master class which needs embedding feature (like coll), passes
   a nonzero flag to the hammerfile setup routine, and a nonzero embedfn
   function pointer to the hammerfile constructor.  If a master needs
   access to the panels (like collcommon), then it passes nonzero readfn
   and/or writefn callback pointers to the constructor.  A master which has
   an associated text editor, AND wants to update object's state after
   edits, passes a nonzero updatefn callback in a call to the constructor. */

#include <stdio.h>
#include <string.h>
#include "m_pd.h"
#include "g_canvas.h"
/* need this for t_class::c_wb field access, LATER find a better way... */
#include "unstable/pd_imp.h"
#include "hammer/file.h"

static t_class *hammerfile_class = 0;
static t_hammerfile *hammerfile_proxies;
static t_symbol *ps__C;

static t_hammerfile *hammerfile_getproxy(t_pd *master)
{
    t_hammerfile *f;
    for (f = hammerfile_proxies; f; f = f->f_next)
	if (f->f_master == master)
	    return (f);
    return (0);
}

/* FIXME somehow plug the "save changes" dialog into close-by-wm */
/* FIXME dirty condition */
static void hammereditor_guidefs(void)
{
    sys_gui("proc hammereditor_open {name geometry title} {\n");
    sys_gui(" if {[winfo exists $name]} {\n");
    sys_gui("  $name.text delete 1.0 end\n");
    sys_gui(" } else {\n");
    sys_gui("  toplevel $name\n");
    sys_gui("  wm title $name $title\n");
    sys_gui("  wm geometry $name $geometry\n");
    sys_gui("  text $name.text -relief raised -bd 2 \\\n");
    sys_gui("   -font -*-courier-medium--normal--12-* \\\n");
    sys_gui("   -yscrollcommand \"$name.scroll set\" -background lightgrey\n");
    sys_gui("  scrollbar $name.scroll -command \"$name.text yview\"\n");
    sys_gui("  pack $name.scroll -side right -fill y\n");
    sys_gui("  pack $name.text -side left -fill both -expand 1\n");
    sys_gui(" }\n");
    sys_gui("}\n");

    sys_gui("proc hammereditor_doclose {name} {\n");
    sys_gui(" destroy $name\n");
    sys_gui("}\n");

    sys_gui("proc hammereditor_append {name contents} {\n");
    sys_gui(" if {[winfo exists $name]} {\n");
    sys_gui("  $name.text insert end $contents\n");
    sys_gui(" }\n");
    sys_gui("}\n");

    /* FIXME make it more reliable */
    sys_gui("proc hammereditor_send {name} {\n");
    sys_gui(" if {[winfo exists $name]} {\n");
    sys_gui("  set ii [$name.text index [concat end - 1 lines]]\n");
    sys_gui("  pd [concat miXed$name clear \\;]\n");
    sys_gui("  for {set i 1} \\\n");
    sys_gui("   {[$name.text compare $i.end < $ii]} \\\n");
    sys_gui("  	{incr i 1} {\n");
    sys_gui("   set lin [$name.text get $i.0 $i.end]\n");
    sys_gui("   if {$lin != \"\"} {\n");
    /* LATER rethink semi/comma mapping */
    sys_gui("    regsub -all \\; $lin \"  _semi_ \" tmplin\n");
    sys_gui("    regsub -all \\, $tmplin \"  _comma_ \" lin\n");
    sys_gui("    pd [concat miXed$name addline $lin \\;]\n");
    sys_gui("   }\n");
    sys_gui("  }\n");
    sys_gui("  pd [concat miXed$name end \\;]\n");
    sys_gui(" }\n");
    sys_gui("}\n");

    sys_gui("proc hammereditor_close {name ask} {\n");
    sys_gui(" if {[winfo exists $name]} {\n");
    sys_gui("  set dirty $ask\n");  /* FIXME */
    sys_gui("  if {$dirty == 0} {hammereditor_doclose $name} else {\n");
    sys_gui("   set title [wm title $name]\n");
    sys_gui("   set answer [tk_messageBox \\-type yesnocancel \\\n");
    sys_gui("    \\-icon question \\\n");
    sys_gui("    \\-message [concat Save changes to $title?]]\n");
    sys_gui("   if {$answer == \"yes\"} {hammereditor_send $name}\n");
    sys_gui("   if {$answer != \"cancel\"} {hammereditor_doclose $name}\n");
    sys_gui("  }\n");
    sys_gui(" }\n");
    sys_gui("}\n");
}

void hammereditor_open(t_hammerfile *f, char *title)
{
    if (!title) title = class_getname(*f->f_master);
    sys_vgui("hammereditor_open .%x %dx%d {%s}\n", (int)f, 600, 340, title);
}

static void hammereditor_tick(t_hammerfile *f)
{
    sys_vgui("hammereditor_close .%x %d\n", (int)f, 1);
}

void hammereditor_close(t_hammerfile *f, int ask)
{
    if (ask)
	/* hack: deferring modal dialog creation in order to allow for
	   a message box redraw to happen -- LATER investigate */
 	clock_delay(f->f_editorclock, 0);
    else
	sys_vgui("hammereditor_close .%x %d\n", (int)f, 0);
}

void hammereditor_append(t_hammerfile *f, char *contents)
{
    if (!contents) contents = "";
    sys_vgui("hammereditor_append .%x {%s}\n", (int)f, contents);
}

static void hammereditor_clear(t_hammerfile *f)
{
    if (f->f_editorfn)
    {
	if (f->f_binbuf)
	    binbuf_clear(f->f_binbuf);
	else
	    f->f_binbuf = binbuf_new();
    }
}

static void hammereditor_addline(t_hammerfile *f,
				 t_symbol *s, int ac, t_atom *av)
{
    if (f->f_editorfn)
    {
	int i;
	t_atom *ap;
	for (i = 0, ap = av; i < ac; i++, ap++)
	{
	    if (ap->a_type == A_SYMBOL)
	    {
		/* LATER rethink semi/comma mapping */
		if (!strcmp(ap->a_w.w_symbol->s_name, "_semi_"))
		    SETSEMI(ap);
		else if (!strcmp(ap->a_w.w_symbol->s_name, "_comma_"))
		    SETCOMMA(ap);
	    }
	}
	binbuf_add(f->f_binbuf, ac, av);
    }
}

static void hammereditor_end(t_hammerfile *f)
{
    if (f->f_editorfn)
    {
	(*f->f_editorfn)(f->f_master, 0, binbuf_getnatom(f->f_binbuf),
			 binbuf_getvec(f->f_binbuf));
	binbuf_clear(f->f_binbuf);
    }
}

static void hammerpanel_guidefs(void)
{
    sys_gui("proc hammerpanel_save {target inidir inifile} {\n");
    sys_gui(" if {$inifile != \"\"} {\n");
    sys_gui("  set filename [tk_getSaveFile \\\n");
    sys_gui("   -initialdir $inidir -initialfile $inifile]\n");
    sys_gui(" } else {\n");
    sys_gui("  set filename [tk_getSaveFile]\n");
    sys_gui(" }\n");
    sys_gui(" if {$filename != \"\"} {\n");
    sys_gui("  pd [concat $target symbol [pdtk_enquote $filename] \\;]\n");
    sys_gui(" }\n");
    sys_gui("}\n");
}

static void hammerpanel_symbol(t_hammerfile *f, t_symbol *s)
{
    if (s && s != &s_ && f->f_panelfn)
	(*f->f_panelfn)(f->f_master, s, 0, 0);
}

static void hammerpanel_tick(t_hammerfile *f)
{
    if (f->f_savepanel)
	sys_vgui("pdtk_openpanel %s\n", f->f_bindname->s_name);
    else
	sys_vgui("hammerpanel_save %s {%s} {%s}\n", f->f_bindname->s_name,
		 f->f_inidir->s_name, f->f_inifile->s_name);
}

/* these are hacks: deferring modal dialog creation in order to allow for
   a message box redraw to happen -- LATER investigate */
void hammerpanel_open(t_hammerfile *f)
{
    clock_delay(f->f_panelclock, 0);
}

void hammerpanel_save(t_hammerfile *f, t_symbol *inidir, t_symbol *inifile)
{
    /* LATER ask if we can rely on s_ pointing to "" */
    f->f_savepanel->f_inidir = (inidir ? inidir : &s_);
    f->f_savepanel->f_inifile = (inifile ? inifile : &s_);
    clock_delay(f->f_savepanel->f_panelclock, 0);
}

/* Currently embeddable hammer classes do not use the 'saveto' method.
   In order to use it, any embeddable class would have to add a creation
   method to pd_canvasmaker -- then saving could be done with a 'proper'
   sequence:  #N <master> <args>; #X <whatever>; ...; #X restore <x> <y>;
   However, this works only for -lib externals.  So, we choose a sequence:
   #X obj <x> <y> <master> <args>; #C <whatever>; ...; #C restore;
   Since the first message in this sequence is a valid creation message
   on its own, we have to distinguish loading from a .pd file, and other
   cases (editing). */

static void hammerembed_gc(t_pd *x, t_symbol *s, int expected)
{
    t_pd *garbage;
    int count = 0;
    while (garbage = pd_findbyclass(s, *x)) pd_unbind(garbage, s), count++;
    if (count != expected)
	bug("hammerembed_gc (%d garbage bindings)", count);
}

static void hammerembed_restore(t_pd *master)
{
    hammerembed_gc(master, ps__C, 1);
}

void hammerembed_save(t_gobj *master, t_binbuf *bb)
{
    t_hammerfile *f = hammerfile_getproxy((t_pd *)master);
    t_text *t = (t_text *)master;
    binbuf_addv(bb, "ssii", &s__X, gensym("obj"),
    	    	(int)t->te_xpix, (int)t->te_ypix);
    binbuf_addbinbuf(bb, t->te_binbuf);
    binbuf_addsemi(bb);
    if (f && f->f_embedfn)
	(*f->f_embedfn)(f->f_master, bb, ps__C);
    binbuf_addv(bb, "ss;", ps__C, gensym("restore"));
}

int hammerfile_ismapped(t_hammerfile *f)
{
    return (f->f_canvas->gl_mapped);
}

int hammerfile_isloading(t_hammerfile *f)
{
    return (f->f_canvas->gl_loading);
}

/* LATER find a better way */
int hammerfile_ispasting(t_hammerfile *f)
{
    int result = 0;
    t_canvas *cv = f->f_canvas;
    if (!cv->gl_loading)
    {
	t_pd *z = s__X.s_thing;
	if (z == (t_pd *)cv)
	{
	    pd_popsym(z);
	    if (s__X.s_thing == (t_pd *)cv) result = 1;
	    pd_pushsym(z);
	}
	else if (z) result = 1;
    }
#if 0
    if (result) post("pasting");
#endif
    return (result);
}

void hammerfile_free(t_hammerfile *f)
{
    t_hammerfile *prev, *next;
    hammereditor_close(f, 0);
    if (f->f_embedfn)
	/* just in case of missing 'restore' */
	hammerembed_gc(f->f_master, ps__C, 0);
    if (f->f_savepanel)
    {
	pd_unbind((t_pd *)f->f_savepanel, f->f_savepanel->f_bindname);
	pd_free((t_pd *)f->f_savepanel);
    }
    if (f->f_bindname) pd_unbind((t_pd *)f, f->f_bindname);
    if (f->f_panelclock) clock_free(f->f_panelclock);
    if (f->f_editorclock) clock_free(f->f_editorclock);
    for (prev = 0, next = hammerfile_proxies;
	 next; prev = next, next = next->f_next)
	if (next == f)
	    break;
    if (prev)
	prev->f_next = f->f_next;
    else if (f == hammerfile_proxies)
	hammerfile_proxies = f->f_next;
    pd_free((t_pd *)f);
}

t_hammerfile *hammerfile_new(t_pd *master, t_hammerembedfn embedfn,
			     t_hammerfilefn readfn, t_hammerfilefn writefn,
			     t_hammerfilefn updatefn)
{
    t_hammerfile *result = (t_hammerfile *)pd_new(hammerfile_class);
    result->f_master = master;
    result->f_next = hammerfile_proxies;
    hammerfile_proxies = result;
    if (!(result->f_canvas = canvas_getcurrent()))
    {
	bug("hammerfile_new: out of context");
	return (result);
    }

    /* 1. embedding */
    if (result->f_embedfn = embedfn)
    {
	/* just in case of missing 'restore' */
	hammerembed_gc(master, ps__C, 0);
	if (hammerfile_isloading(result) || hammerfile_ispasting(result))
	    pd_bind(master, ps__C);
    }

    /* 2. the panels */
    if (readfn || writefn)
    {
	t_hammerfile *f;
	char buf[64];
	sprintf(buf, "miXed.%x", (int)result);
	result->f_bindname = gensym(buf);
	pd_bind((t_pd *)result, result->f_bindname);
	result->f_panelfn = readfn;
	result->f_panelclock = clock_new(result, (t_method)hammerpanel_tick);
	f = (t_hammerfile *)pd_new(hammerfile_class);
	f->f_master = master;
	sprintf(buf, "miXed.%x", (int)f);
	f->f_bindname = gensym(buf);
	pd_bind((t_pd *)f, f->f_bindname);
	f->f_panelfn = writefn;	
	f->f_panelclock = clock_new(f, (t_method)hammerpanel_tick);
	result->f_savepanel = f;
    }
    else result->f_savepanel = 0;

    /* 3. editor */
    if (result->f_editorfn = updatefn)
    {
	result->f_editorclock = clock_new(result, (t_method)hammereditor_tick);
	if (!result->f_bindname)
	{
	    char buf[64];
	    sprintf(buf, "miXed.%x", (int)result);
	    result->f_bindname = gensym(buf);
	    pd_bind((t_pd *)result, result->f_bindname);
	}
    }
    return (result);
}

void hammerfile_setup(t_class *c, int embeddable)
{
    if (embeddable)
    {
	t_widgetbehavior *newwb = getbytes(sizeof(*newwb));  /* never freed */
	*newwb = *c->c_wb;
	newwb->w_savefn = hammerembed_save;
	class_setwidget(c, newwb);
	class_addmethod(c, (t_method)hammerembed_restore,
			gensym("restore"), 0);
    }
    if (!hammerfile_class)
    {
	ps__C = gensym("#C");
	hammerfile_class = class_new(gensym("_hammerfile"), 0, 0,
				     sizeof(t_hammerfile),
				     CLASS_PD | CLASS_NOINLET, 0);
	class_addsymbol(hammerfile_class, hammerpanel_symbol);
	class_addmethod(hammerfile_class, (t_method)hammereditor_clear,
			gensym("clear"), 0);
	class_addmethod(hammerfile_class, (t_method)hammereditor_addline,
			gensym("addline"), A_GIMME, 0);
	class_addmethod(hammerfile_class, (t_method)hammereditor_end,
			gensym("end"), 0);
	/* LATER find a way of ensuring that these are not defined yet... */
	hammereditor_guidefs();
	hammerpanel_guidefs();
    }
}
