/* Copyright (c) 2003 krzYszcz and others.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.  */

#include "m_pd.h"
#include "g_canvas.h"
#include "shared.h"
#include "unstable/forky.h"

//#define FORKY_DEBUG

/* To be called in a 'dsp' method -- e.g. if there are no feeders, the caller
   might use an optimized version of a 'perform' routine.
   LATER think about replacing 'linetraverser' calls with something faster. */
int forky_hasfeeders(t_object *x, t_glist *glist, int inno, t_symbol *outsym)
{
    t_linetraverser t;
    linetraverser_start(&t, glist);
    while (linetraverser_next(&t))
	if (t.tr_ob2 == x && t.tr_inno == inno
#ifdef PD_VERSION  /* FIXME ask Miller */
	    && (!outsym || outsym == outlet_getsymbol(t.tr_outlet))
#endif
	    )
	    return (1);
    return (0);
}

/* Not really a forky, just found no better place to put it in.
   Used in bitwise signal binops (sickle).  Checked against msp2. */
t_int forky_getbitmask(int ac, t_atom *av)
{
    t_int result = 0;
    if (sizeof(shared_t_bitmask) >= sizeof(t_int))
    {
	int nbits = sizeof(t_int) * 8;
	shared_t_bitmask bitmask = 1 << (nbits - 1);
	if (ac > nbits)
	    ac = nbits;
	while (ac--)
	{
	    if (av->a_type == A_FLOAT &&
		(int)av->a_w.w_float)  /* CHECKED */
		result |= bitmask;
	    /* CHECKED symbols are zero */
	    bitmask >>= 1;
	    av++;
	}
	/* CHECKED missing are zero */
#ifdef FORKY_DEBUG
	post("mask set to %.8x", result);
#endif
    }
    else bug("sizeof(shared_t_bitmask)");
    return (result);
}
