// scope~'s properties dialog

sys_gui("package provide dialog_scope 0.1\n");
sys_gui("namespace eval ::dialog_scope:: {   \n");
sys_gui("namespace export pdtk_scope_dialog\n");
sys_gui("}\n");

// scope_clip_ents
sys_gui("proc ::dialog_scope::scope_clip_ents {mytoplevel} {\n");
sys_gui("set vid [string trimleft $mytoplevel .]\n");
// dimensions
sys_gui("set var_scope_width [concat scope_width_$vid]\n");
sys_gui("global $var_scope_width\n");
sys_gui("set var_scope_height [concat scope_height_$vid]\n");
sys_gui("global $var_scope_height\n");
// dimensions bounds
sys_gui("set var_scope_width_min [concat scope_width_min_$vid]\n");
sys_gui("global $var_scope_width_min\n");
sys_gui("set var_scope_height_min [concat scope_height_min_$vid]\n");
sys_gui("global $var_scope_height_min\n");
// buffer
sys_gui("set var_scope_cal [concat scope_cal_$vid]\n");
sys_gui("global $var_scope_cal\n");
sys_gui("set var_scope_bufsize [concat scope_bufsize_$vid]\n");
sys_gui("global $var_scope_bufsize\n");
// buffer bounds
sys_gui("set var_scope_cal_min [concat scope_cal_min_$vid]\n");
sys_gui("global $var_scope_cal_min\n");
sys_gui("set var_scope_cal_max [concat scope_cal_max_$vid]\n");
sys_gui("global $var_scope_cal_max\n");
sys_gui("set var_scope_bufsize_min [concat scope_bufsize_min_$vid]\n");
sys_gui("global $var_scope_bufsize_min\n");
sys_gui("set var_scope_bufsize_max [concat scope_bufsize_max_$vid]\n");
sys_gui("global $var_scope_bufsize_max\n");
// delay
sys_gui("set var_scope_del [concat scope_del_$vid]\n");
sys_gui("global $var_scope_del\n");
// delay bounds
sys_gui("set var_scope_del_min [concat scope_del_min_$vid]\n");
sys_gui("global $var_scope_del_min\n");

// bound checks //////////////
//dimensions
sys_gui("if { [eval concat $$var_scope_width] < [eval concat $$var_scope_width_min] } {\n");
sys_gui("set $var_scope_width [eval concat $$var_scope_width_min] \n");
sys_gui("$mytoplevel.dim.fr.w_ent configure -textvariable $var_scope_width\n");
sys_gui("}\n");
sys_gui("if { [eval concat $$var_scope_height] < [eval concat $$var_scope_height_min] } {\n");
sys_gui("set $var_scope_height [eval concat $$var_scope_height_min] \n");
sys_gui("$mytoplevel.dim.fr.h_ent configure -textvariable $var_scope_height\n");
sys_gui("}\n");
//buffer
sys_gui("if { [eval concat $$var_scope_cal] < [eval concat $$var_scope_cal_min] } {\n");
sys_gui("set $var_scope_cal [eval concat $$var_scope_cal_min] \n");
sys_gui("$mytoplevel.buf.fr.cal_ent configure -textvariable $var_scope_cal\n");
sys_gui("}\n");
sys_gui("if { [eval concat $$var_scope_cal] > [eval concat $$var_scope_cal_max] } {\n");
sys_gui("set $var_scope_cal [eval concat $$var_scope_cal_max] \n");
sys_gui("$mytoplevel.buf.fr.cal_ent configure -textvariable $var_scope_cal\n");
sys_gui("}\n");
sys_gui("if { [eval concat $$var_scope_bufsize] < [eval concat $$var_scope_bufsize_min] } {\n");
sys_gui("set $var_scope_bufsize [eval concat $$var_scope_bufsize_min] \n");
sys_gui("$mytoplevel.buf.fr.bufsize_ent configure -textvariable $var_scope_bufsize\n");
sys_gui("}\n");
sys_gui("if { [eval concat $$var_scope_bufsize] > [eval concat $$var_scope_bufsize_max] } {\n");
sys_gui("set $var_scope_bufsize [eval concat $$var_scope_bufsize_max] \n");
sys_gui("$mytoplevel.buf.fr.bufsize_ent configure -textvariable $var_scope_bufsize\n");
sys_gui("}\n");
//delay
sys_gui("if { [eval concat $$var_scope_del] < [eval concat $$var_scope_del_min] } {\n");
sys_gui("set $var_scope_del [eval concat $$var_scope_del_min] \n");
sys_gui("$mytoplevel.misc.fr.del_ent configure -textvariable $var_scope_del\n");
sys_gui("}\n");
sys_gui("}    \n");

// scope_check_range
sys_gui("proc ::dialog_scope::scope_check_range {mytoplevel} {\n");
sys_gui("set vid [string trimleft $mytoplevel .]\n");
sys_gui("set var_scope_min_range [concat scope_min_range_$vid]\n");
sys_gui("global $var_scope_min_range\n");
sys_gui("set var_scope_max_range [concat scope_max_range_$vid]\n");
sys_gui("global $var_scope_max_range\n");
sys_gui("if { [eval concat $$var_scope_min_range] > [eval concat $$var_scope_max_range] } {\n");
sys_gui("set temp [eval concat $$var_scope_min_range]\n");
sys_gui("set $var_scope_min_range [eval concat $$var_scope_max_range]\n");
sys_gui("set $var_scope_max_range [eval concat $temp]\n");
sys_gui("$mytoplevel.range.fr.min_ent configure -textvariable $var_scope_min_range\n");
sys_gui("$mytoplevel.range.fr.max_ent configure -textvariable $var_scope_max_range\n");
sys_gui("}\n");
sys_gui("}\n");

// ::dialog_scope::scope_empty_ents
sys_gui("proc ::dialog_scope::scope_empty_ents {mytoplevel} {\n");
sys_gui("set vid [string trimleft $mytoplevel .]\n");
sys_gui("set var_scope_width [concat scope_width_$vid]\n");
sys_gui("global $var_scope_width\n");
sys_gui("set var_scope_height [concat scope_height_$vid]\n");
sys_gui("global $var_scope_height\n");
sys_gui("set var_scope_cal [concat scope_cal_$vid]\n");
sys_gui("global $var_scope_cal\n");
sys_gui("set var_scope_bufsize [concat scope_bufsize_$vid]\n");
sys_gui("global $var_scope_bufsize\n");
sys_gui("set var_scope_min_range [concat scope_min_range_$vid]\n");
sys_gui("global $var_scope_min_range\n");
sys_gui("set var_scope_max_range [concat scope_max_range_$vid]\n");
sys_gui("global $var_scope_max_range\n");
sys_gui("set var_scope_del [concat scope_del_$vid]\n");
sys_gui("global $var_scope_del\n");
sys_gui("set var_scope_tr_level [concat scope_tr_level_$vid]\n");
sys_gui("global $var_scope_tr_level\n");
sys_gui("set var_scope_draw_style [concat scope_draw_style_$vid]\n");
sys_gui("global $var_scope_draw_style\n");
sys_gui("set var_scope_width_init [concat scope_width_init_$vid]\n");
sys_gui("global $var_scope_width_init\n");
sys_gui("set var_scope_height_init [concat scope_height_init_$vid]\n");
sys_gui("global $var_scope_height_init\n");
sys_gui("set var_scope_cal_init [concat scope_cal_init_$vid]\n");
sys_gui("global $var_scope_cal_init\n");
sys_gui("set var_scope_bufsize_init [concat scope_bufsize_init_$vid]\n");
sys_gui("global $var_scope_bufsize_init\n");
sys_gui("set var_scope_min_range_init [concat scope_min_range_init_$vid]\n");
sys_gui("global $var_scope_min_range_init\n");
sys_gui("set var_scope_max_range_init [concat scope_max_range_init_$vid]\n");
sys_gui("global $var_scope_max_range_init\n");
sys_gui("set var_scope_del_init [concat scope_del_init_$vid]\n");
sys_gui("global $var_scope_del_init\n");
sys_gui("set var_scope_tr_level_init [concat scope_tr_level_init_$vid]\n");
sys_gui("global $var_scope_tr_level_init\n");
sys_gui("if {[eval concat $$var_scope_width] eq \"\"} {set $var_scope_width [eval concat $$var_scope_width_init]}\n");
sys_gui("if {[eval concat $$var_scope_height] eq \"\"} {set $var_scope_height [eval concat $$var_scope_height_init]}\n");
sys_gui("if {[eval concat $$var_scope_cal] eq \"\"} {set $var_scope_cal [eval concat $$var_scope_cal_init]}\n");
sys_gui("if {[eval concat $$var_scope_bufsize] eq \"\"} {set $var_scope_bufsize [eval concat $$var_scope_bufsize_init]}\n");
sys_gui("if {[eval concat $$var_scope_min_range] eq \"\"} {set $var_scope_min_range [eval concat $$var_scope_min_range_init]}\n");
sys_gui("if {[eval concat $$var_scope_max_range] eq \"\"} {set $var_scope_max_range [eval concat $$var_scope_max_range_init]}\n");
sys_gui("if {[eval concat $$var_scope_del] eq \"\"} {set $var_scope_del [eval concat $$var_scope_del_init]}\n");
sys_gui("if {[eval concat $$var_scope_tr_level] eq \"\"} {set $var_scope_tr_level [eval concat $$var_scope_tr_level_init]}\n");
sys_gui("}\n");

// sel_col_example
sys_gui("proc ::dialog_scope::scope_set_col_example {mytoplevel} {\n");
sys_gui("set vid [string trimleft $mytoplevel .]\n");
sys_gui("set var_scope_bcol [concat scope_bcol_$vid]\n");
sys_gui("global $var_scope_bcol\n");
sys_gui("set var_scope_gcol [concat scope_gcol_$vid]\n");
sys_gui("global $var_scope_gcol\n");
sys_gui("set var_scope_fcol [concat scope_fcol_$vid]\n");
sys_gui("global $var_scope_fcol\n");
sys_gui("$mytoplevel.colors.scopevis.cv itemconfigure \"bg\" -fill [eval concat $$var_scope_bcol]\n");
sys_gui("$mytoplevel.colors.scopevis.cv itemconfigure \"gr\" -fill [eval concat $$var_scope_gcol]\n");
sys_gui("$mytoplevel.colors.scopevis.cv itemconfigure \"fg\" -fill [eval concat $$var_scope_fcol]\n");
// for OSX live updates
sys_gui("if {$::windowingsystem eq \"aqua\"} {\n");
sys_gui("::dialog_scope::apply_and_rebind_return $mytoplevel\n");
sys_gui("}\n");
sys_gui("}\n");
// scope_preset_col
sys_gui("proc ::dialog_scope::scope_preset_col {mytoplevel presetcol} {\n");
sys_gui("set vid [string trimleft $mytoplevel .]\n");
sys_gui("set var_scope_f2_g1_b0 [concat scope_f2_g1_b0_$vid]\n");
sys_gui("global $var_scope_f2_g1_b0\n");
sys_gui("set var_scope_bcol [concat scope_bcol_$vid]\n");
sys_gui("global $var_scope_bcol\n");
sys_gui("set var_scope_gcol [concat scope_gcol_$vid]\n");
sys_gui("global $var_scope_gcol\n");
sys_gui("set var_scope_fcol [concat scope_fcol_$vid]\n");
sys_gui("global $var_scope_fcol\n");
sys_gui("if { [eval concat $$var_scope_f2_g1_b0] == 0 } { set $var_scope_bcol $presetcol }\n");
sys_gui("if { [eval concat $$var_scope_f2_g1_b0] == 1 } { set $var_scope_gcol $presetcol }\n");
sys_gui("if { [eval concat $$var_scope_f2_g1_b0] == 2 } { set $var_scope_fcol $presetcol }\n");
sys_gui("::dialog_scope::scope_set_col_example $mytoplevel\n");
sys_gui("}\n");
// scope_choose_col_bkgrfg
sys_gui("proc ::dialog_scope::scope_choose_col_bkgrfg {mytoplevel} {\n");
sys_gui("set vid [string trimleft $mytoplevel .]\n");
sys_gui("set var_scope_f2_g1_b0 [concat scope_f2_g1_b0_$vid]\n");
sys_gui("global $var_scope_f2_g1_b0\n");
sys_gui("set var_scope_bcol [concat scope_bcol_$vid]\n");
sys_gui("global $var_scope_bcol\n");
sys_gui("set var_scope_gcol [concat scope_gcol_$vid]\n");
sys_gui("global $var_scope_gcol\n");
sys_gui("set var_scope_fcol [concat scope_fcol_$vid]\n");
sys_gui("global $var_scope_fcol\n");
sys_gui("if {[eval concat $$var_scope_f2_g1_b0] == 0} {\n");
sys_gui("set $var_scope_bcol [eval concat $$var_scope_bcol]\n");
sys_gui("set helpstring [tk_chooseColor -title [_ \"Background color\"] -initialcolor [eval concat $$var_scope_bcol]]\n");
sys_gui("if { $helpstring ne \"\" } {\n");
sys_gui("set $var_scope_bcol $helpstring }\n");
sys_gui("}\n");
sys_gui("if {[eval concat $$var_scope_f2_g1_b0] == 1} {\n");
sys_gui("set $var_scope_gcol [eval concat $$var_scope_gcol]\n");
sys_gui("set helpstring [tk_chooseColor -title [_ \"Grid color\"] -initialcolor [eval concat $$var_scope_gcol]]\n");
sys_gui("if { $helpstring ne \"\" } {\n");
sys_gui("set $var_scope_gcol $helpstring }\n");
sys_gui("}\n");
sys_gui("if {[eval concat $$var_scope_f2_g1_b0] == 2} {\n");
sys_gui("set $var_scope_fcol [eval concat $$var_scope_fcol]\n");
sys_gui("set helpstring [tk_chooseColor -title [_ \"Phosphor color\"] -initialcolor [eval concat $$var_scope_fcol]]\n");
sys_gui("if { $helpstring ne \"\" } {\n");
sys_gui("set $var_scope_fcol $helpstring }\n");
sys_gui("}\n");
sys_gui("::dialog_scope::scope_set_col_example $mytoplevel\n");
sys_gui("}\n");

// scope_trigger_mode
sys_gui("proc ::dialog_scope::scope_trigger_mode {mytoplevel tr_mode} {\n");
sys_gui("set vid [string trimleft $mytoplevel .]\n");
sys_gui("set var_scope_tr_mode [concat scope_tr_mode_$vid]\n");
sys_gui("global $var_scope_tr_mode\n");
sys_gui("set var_scope_tr_mode0 [concat scope_tr_mode0_$vid]\n");
sys_gui("global $var_scope_tr_mode0\n");
sys_gui("set var_scope_tr_mode1 [concat scope_tr_mode1_$vid]\n");
sys_gui("global $var_scope_tr_mode1\n");
sys_gui("set var_scope_tr_mode2 [concat scope_tr_mode2_$vid]\n");
sys_gui("global $var_scope_tr_mode2\n");
sys_gui("if {$tr_mode == 0} {\n");
sys_gui("set $var_scope_tr_mode 0\n");
sys_gui("$mytoplevel.trg.tr_mode.trb configure -text [eval concat $$var_scope_tr_mode0]\n");
sys_gui("} elseif {$tr_mode == 1} {\n");
sys_gui("set $var_scope_tr_mode 1\n");
sys_gui("$mytoplevel.trg.tr_mode.trb configure -text [eval concat $$var_scope_tr_mode1]\n");
sys_gui("} else {\n");
sys_gui("set $var_scope_tr_mode 2\n");
sys_gui("$mytoplevel.trg.tr_mode.trb configure -text [eval concat $$var_scope_tr_mode2]\n");
sys_gui("}\n");
// for OSX live updates
sys_gui("if {$::windowingsystem eq \"aqua\"} {\n");
sys_gui("::dialog_scope::apply_and_rebind_return $mytoplevel\n");
sys_gui("}\n");
sys_gui("}\n");

// APPLY !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
sys_gui("proc ::dialog_scope::apply {mytoplevel} {\n");
sys_gui("set vid [string trimleft $mytoplevel .]\n");
sys_gui("set var_scope_width [concat scope_width_$vid]\n");
sys_gui("global $var_scope_width\n");
sys_gui("set var_scope_height [concat scope_height_$vid]\n");
sys_gui("global $var_scope_height\n");
sys_gui("set var_scope_cal [concat scope_cal_$vid]\n");
sys_gui("global $var_scope_cal\n");
sys_gui("set var_scope_bufsize [concat scope_bufsize_$vid]\n");
sys_gui("global $var_scope_bufsize\n");
sys_gui("set var_scope_min_range [concat scope_min_range_$vid]\n");
sys_gui("global $var_scope_min_range\n");
sys_gui("set var_scope_max_range [concat scope_max_range_$vid]\n");
sys_gui("global $var_scope_max_range\n");
sys_gui("set var_scope_del [concat scope_del_$vid]\n");
sys_gui("global $var_scope_del\n");
sys_gui("set var_scope_tr_mode [concat scope_tr_mode_$vid]\n");
sys_gui("global $var_scope_tr_mode\n");
sys_gui("set var_scope_tr_level [concat scope_tr_level_$vid]\n");
sys_gui("global $var_scope_tr_level\n");
sys_gui("set var_scope_draw_style [concat scope_draw_style_$vid]\n");
sys_gui("global $var_scope_draw_style\n");

// Receive
sys_vgui("set var_scope_rcv [concat scope_rcv_$vid]\n");
sys_vgui("global $var_scope_rcv\n");
sys_vgui("set hhhrcv [eval concat $$var_scope_rcv]\n");

sys_gui("set var_scope_bcol [concat scope_bcol_$vid]\n");
sys_gui("global $var_scope_bcol\n");
sys_gui("set var_scope_gcol [concat scope_gcol_$vid]\n");
sys_gui("global $var_scope_gcol\n");
sys_gui("set var_scope_fcol [concat scope_fcol_$vid]\n");
sys_gui("global $var_scope_fcol\n");
sys_gui("::dialog_scope::scope_empty_ents $mytoplevel\n");
sys_gui("::dialog_scope::scope_clip_ents $mytoplevel\n");
sys_gui("::dialog_scope::scope_check_range $mytoplevel\n");
sys_gui("pdsend [concat $mytoplevel dialog \\\n");
sys_gui("[eval concat $$var_scope_width] \\\n");
sys_gui("[eval concat $$var_scope_height] \\\n");
sys_gui("[eval concat $$var_scope_cal] \\\n");
sys_gui("[eval concat $$var_scope_bufsize] \\\n");
sys_gui("[eval concat $$var_scope_min_range] \\\n");
sys_gui("[eval concat $$var_scope_max_range] \\\n");
sys_gui("[eval concat $$var_scope_del] \\\n");
sys_gui("[eval concat $$var_scope_draw_style] \\\n");
sys_gui("[eval concat $$var_scope_tr_mode] \\\n");
sys_gui("[eval concat $$var_scope_tr_level] \\\n");
sys_gui("[eval concat $$var_scope_bcol] \\\n");
sys_gui("[eval concat $$var_scope_gcol] \\\n");
sys_gui("[eval concat $$var_scope_fcol] \\\n");
sys_gui("$hhhrcv]\n");
sys_gui("}	\n");

// CANCEL !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
sys_gui("proc ::dialog_scope::cancel {mytoplevel} {\n");
sys_gui("pdsend \"$mytoplevel cancel\"\n");
sys_gui("}\n");

// OK / APPLY / CANCEL
sys_gui("proc ::dialog_scope::ok {mytoplevel} {\n");
sys_gui("::dialog_scope::apply $mytoplevel\n");
sys_gui("::dialog_scope::cancel $mytoplevel\n");
sys_gui("}\n");

// pdtk_scope_dialog
sys_gui("proc ::dialog_scope::pdtk_scope_dialog {mytoplevel \\\n");
sys_gui("dim_header width width_label height height_label \\\n");
sys_gui("buf_header cal cal_label bufsize bufsize_label \\\n");
sys_gui("range_header min_range min_range_label max_range max_range_label \\\n");
sys_gui("del_header del del_label draw_style_header draw_style draw_style_label\\\n");
sys_gui("rcv rcv_label\\\n");
sys_gui("trg_header tr_mode tr_mode_label tr_level tr_level_label \\\n");
sys_gui("dim_mins width_min height_min \\\n");
sys_gui("cal_min_max cal_min cal_max bufsize_min_max bufsize_min bufsize_max \\\n");
sys_gui("del_mins del_min \\\n");
sys_gui("bcol gcol fcol} {\n");
sys_gui("set vid [string trimleft $mytoplevel .]\n");
sys_gui("set var_scope_width [concat scope_width_$vid]\n");
sys_gui("global $var_scope_width\n");
sys_gui("set var_scope_height [concat scope_height_$vid]\n");
sys_gui("global $var_scope_height\n");
sys_gui("set var_scope_cal [concat scope_cal_$vid]\n");
sys_gui("global $var_scope_cal\n");
sys_gui("set var_scope_bufsize [concat scope_bufsize_$vid]\n");
sys_gui("global $var_scope_bufsize\n");
sys_gui("set var_scope_min_range [concat scope_min_range_$vid]\n");
sys_gui("global $var_scope_min_range\n");
sys_gui("set var_scope_max_range [concat scope_max_range_$vid]\n");
sys_gui("global $var_scope_max_range\n");
sys_gui("set var_scope_del [concat scope_del_$vid]\n");
sys_gui("global $var_scope_del\n");
sys_gui("set var_scope_tr_mode [concat scope_tr_mode_$vid]\n");
sys_gui("global $var_scope_tr_mode\n");
sys_gui("set var_scope_tr_mode0 [concat scope_tr_mode0_$vid]\n");
sys_gui("global $var_scope_tr_mode0\n");
sys_gui("set var_scope_tr_mode1 [concat scope_tr_mode1_$vid]\n");
sys_gui("global $var_scope_tr_mode1\n");
sys_gui("set var_scope_tr_mode2 [concat scope_tr_mode2_$vid]\n");
sys_gui("global $var_scope_tr_mode2\n");
sys_gui("set var_scope_tr_level [concat scope_tr_level_$vid]\n");
sys_gui("global $var_scope_tr_level\n");
sys_gui("set var_scope_draw_style [concat scope_draw_style_$vid]\n");
sys_gui("global $var_scope_draw_style\n");
// Receive
sys_gui("set var_scope_rcv [concat scope_rcv_$vid]\n");
sys_gui("global $var_scope_rcv\n");
sys_gui("set var_scope_f2_g1_b0 [concat scope_f2_g1_b0_$vid]\n");
sys_gui("global $var_scope_f2_g1_b0\n");
sys_gui("set var_scope_bcol [concat scope_bcol_$vid]\n");
sys_gui("global $var_scope_bcol\n");
sys_gui("set var_scope_gcol [concat scope_gcol_$vid]\n");
sys_gui("global $var_scope_gcol\n");
sys_gui("set var_scope_fcol [concat scope_fcol_$vid]\n");
sys_gui("global $var_scope_fcol\n");
sys_gui("set var_scope_width_min [concat scope_width_min_$vid]\n");
sys_gui("global $var_scope_width_min\n");
sys_gui("set var_scope_height_min [concat scope_height_min_$vid]\n");
sys_gui("global $var_scope_height_min\n");
sys_gui("set var_scope_cal_min [concat scope_cal_min_$vid]\n");
sys_gui("global $var_scope_cal_min\n");
sys_gui("set var_scope_cal_max [concat scope_cal_max_$vid]\n");
sys_gui("global $var_scope_cal_max\n");
sys_gui("set var_scope_bufsize_min [concat scope_bufsize_min_$vid]\n");
sys_gui("global $var_scope_bufsize_min\n");
sys_gui("set var_scope_bufsize_max [concat scope_bufsize_max_$vid]\n");
sys_gui("global $var_scope_bufsize_max\n");
sys_gui("set var_scope_del_min [concat scope_del_min_$vid]\n");
sys_gui("global $var_scope_del_min\n");
sys_gui("set var_scope_width_init [concat scope_width_init_$vid]\n");
sys_gui("global $var_scope_width_init\n");
sys_gui("set var_scope_height_init [concat scope_height_init_$vid]\n");
sys_gui("global $var_scope_height_init\n");
sys_gui("set var_scope_cal_init [concat scope_cal_init_$vid]\n");
sys_gui("global $var_scope_cal_init\n");
sys_gui("set var_scope_bufsize_init [concat scope_bufsize_init_$vid]\n");
sys_gui("global $var_scope_bufsize_init\n");
sys_gui("set var_scope_min_range_init [concat scope_min_range_init_$vid]\n");
sys_gui("global $var_scope_min_range_init\n");
sys_gui("set var_scope_max_range_init [concat scope_max_range_init_$vid]\n");
sys_gui("global $var_scope_max_range_init\n");
sys_gui("set var_scope_del_init [concat scope_del_init_$vid]\n");
sys_gui("global $var_scope_del_init\n");
sys_gui("set var_scope_tr_level_init [concat scope_tr_level_init_$vid]\n");
sys_gui("global $var_scope_tr_level_init\n");
sys_gui("set $var_scope_width $width\n");
sys_gui("set $var_scope_height $height\n");
sys_gui("set $var_scope_cal $cal\n");
sys_gui("set $var_scope_bufsize $bufsize\n");
sys_gui("set $var_scope_min_range $min_range\n");
sys_gui("set $var_scope_max_range $max_range\n");
sys_gui("set $var_scope_del $del\n");
sys_gui("set $var_scope_draw_style $draw_style\n");
// Receive
sys_gui("set $var_scope_rcv $rcv\n");
sys_gui("set $var_scope_tr_mode $tr_mode\n");
sys_gui("set $var_scope_tr_level $tr_level  \n");
sys_gui("set $var_scope_bcol $bcol\n");
sys_gui("set $var_scope_gcol $gcol\n");
sys_gui("set $var_scope_fcol $fcol\n");
sys_gui("set $var_scope_f2_g1_b0 0\n");
sys_gui("set $var_scope_width_init $width\n");
sys_gui("set $var_scope_height_init $height\n");
sys_gui("set $var_scope_cal_init $cal\n");
sys_gui("set $var_scope_bufsize_init $bufsize\n");
sys_gui("set $var_scope_min_range_init $min_range\n");
sys_gui("set $var_scope_max_range_init $max_range\n");
sys_gui("set $var_scope_del_init $del\n");
sys_gui("set $var_scope_tr_level_init $tr_level \n");
sys_gui("set $var_scope_width_min $width_min\n");
sys_gui("set $var_scope_height_min $height_min\n");
sys_gui("set $var_scope_cal_min $cal_min\n");
sys_gui("set $var_scope_cal_max $cal_max\n");
sys_gui("set $var_scope_bufsize_min $bufsize_min\n");
sys_gui("set $var_scope_bufsize_max $bufsize_max\n");
sys_gui("set $var_scope_del_min $del_min\n");
sys_gui("set width_label [_ \"Width:\"]\n");
sys_gui("set height_label [_ \"Height:\"]\n");
sys_gui("set buf_header [_ \"Buffer Settings:\"]\n");
sys_gui("set cal_label [_ \"Samples Per Point:\"]\n");
sys_gui("set bufsize_label [_ \"Buffer Size:\"]\n");
sys_gui("set range_header [_ \"Signal Range:\"]\n");
sys_gui("set min_range_label [_ \"Lower:\"]\n");
sys_gui("set max_range_label [_ \"Upper:\"]\n");
sys_gui("set del_header [_ \"Delay:\"]\n");
sys_gui("set del_label [_ \"Delay:\"]\n");
sys_gui("set draw_style_label [_ \"Alternate Drawstyle:\"]\n");
sys_gui("set rcv_label [_ \"Receive Symbol:\"]\n");
sys_gui("set tr_mode_label [_ \"Trigger Mode:\"]\n");
sys_gui("set tr_mode0_label [_ \"None\"]\n");
sys_gui("set tr_mode1_label [_ \"Up\"]\n");
sys_gui("set tr_mode2_label [_ \"Down\"]\n");
sys_gui("set tr_level_label [_ \"Trigger Level:\"]\n");
sys_gui("set $var_scope_tr_mode0 $tr_mode0_label\n");
sys_gui("set $var_scope_tr_mode1 $tr_mode1_label\n");
sys_gui("set $var_scope_tr_mode2 $tr_mode2_label\n");
sys_gui("toplevel $mytoplevel -class DialogWindow\n");
sys_gui("wm title $mytoplevel [format [_ \"scope~ Properties\"] ]\n");
sys_gui("wm group $mytoplevel .\n");
sys_gui("wm resizable $mytoplevel 0 0\n");
sys_gui("wm transient $mytoplevel $::focused_window\n");
sys_gui("$mytoplevel configure -menu $::dialog_menubar\n");
sys_gui("$mytoplevel configure -padx 0 -pady 0\n");
sys_gui("::pd_bindings::dialog_bindings $mytoplevel \"scope\"\n");
// dimensions
sys_gui("labelframe $mytoplevel.dim -borderwidth 1 -pady 8 -text [_ \"Dimensions:\"]\n");
sys_gui("pack $mytoplevel.dim -side top -fill x -pady 5\n");
sys_gui("frame $mytoplevel.dim.fr\n");
sys_gui("label $mytoplevel.dim.fr.w_lab -text [_ $width_label]\n");
sys_gui("entry $mytoplevel.dim.fr.w_ent -textvariable $var_scope_width -width 4\n");
sys_gui("label $mytoplevel.dim.fr.dummy1 -text \"\" -width 1\n");
sys_gui("label $mytoplevel.dim.fr.h_lab -text [_ $height_label]\n");
sys_gui("entry $mytoplevel.dim.fr.h_ent -textvariable $var_scope_height -width 4\n");
sys_gui("pack $mytoplevel.dim.fr -side left -expand 1\n");
sys_gui("pack $mytoplevel.dim.fr.w_lab $mytoplevel.dim.fr.w_ent \\\n");
sys_gui("$mytoplevel.dim.fr.dummy1 $mytoplevel.dim.fr.h_lab $mytoplevel.dim.fr.h_ent -side left\n");
// calccount & bufsize
sys_gui("labelframe $mytoplevel.buf -borderwidth 1 -pady 8 -text [_ $buf_header]\n");
sys_gui("pack $mytoplevel.buf -side top -fill x -pady 5\n");
sys_gui("frame $mytoplevel.buf.fr\n");
sys_gui("label $mytoplevel.buf.fr.cal_lab -text [_ $cal_label]\n");
sys_gui("entry $mytoplevel.buf.fr.cal_ent -textvariable $var_scope_cal -width 4\n");
sys_gui("label $mytoplevel.buf.fr.dummy1 -text \"\" -width 1\n");
sys_gui("label $mytoplevel.buf.fr.bufsize_lab -text [_ $bufsize_label]\n");
sys_gui("entry $mytoplevel.buf.fr.bufsize_ent -textvariable $var_scope_bufsize -width 4\n");
sys_gui("pack $mytoplevel.buf.fr -side left -expand 1\n");
sys_gui("pack $mytoplevel.buf.fr.cal_lab $mytoplevel.buf.fr.cal_ent -side left\n");
sys_gui("pack $mytoplevel.buf.fr.dummy1 $mytoplevel.buf.fr.bufsize_lab $mytoplevel.buf.fr.bufsize_ent -side left\n");
// range
sys_gui("labelframe $mytoplevel.range -borderwidth 1 -pady 8 -text [_ $range_header]\n");
sys_gui("pack $mytoplevel.range -side top -fill x -pady 5\n");
sys_gui("frame $mytoplevel.range.fr\n");
sys_gui("label $mytoplevel.range.fr.min_lab -text [_ $min_range_label]\n");
sys_gui("entry $mytoplevel.range.fr.min_ent -textvariable $var_scope_min_range -width 8\n");
sys_gui("label $mytoplevel.range.fr.dummy1 -text \"\" -width 1\n");
sys_gui("label $mytoplevel.range.fr.max_lab -text [_ $max_range_label]\n");
sys_gui("entry $mytoplevel.range.fr.max_ent -textvariable $var_scope_max_range -width 8\n");
sys_gui("pack $mytoplevel.range.fr -side left -expand 1\n");
sys_gui("pack $mytoplevel.range.fr.min_lab $mytoplevel.range.fr.min_ent -side left\n");
sys_gui("pack $mytoplevel.range.fr.dummy1 $mytoplevel.range.fr.max_lab $mytoplevel.range.fr.max_ent -side left\n");
//trigger
sys_gui("set current_tr_mode \"None\"\n");
sys_gui("if {[eval concat $$var_scope_tr_mode] == 1} \\\n");
sys_gui("{ set current_tr_mode \"Up\" }\n");
sys_gui("if {[eval concat $$var_scope_tr_mode] == 2} \\\n");
sys_gui("{ set current_tr_mode \"Down\" }\n");
sys_gui("labelframe $mytoplevel.trg \n");
sys_gui("pack $mytoplevel.trg -side top -fill x -pady 5\n");
sys_gui("frame $mytoplevel.trg.tr_mode\n");
sys_gui("label $mytoplevel.trg.tr_mode.lab -text [_ $tr_mode_label]\n");
sys_gui("button $mytoplevel.trg.tr_mode.trb -text $current_tr_mode -width 4\n");
sys_gui("label $mytoplevel.trg.dummy1 -text \"\" -width 1\n");
sys_gui("label $mytoplevel.trg.tr_level_lab -text [_ $tr_level_label]\n");
sys_gui("entry $mytoplevel.trg.tr_level_ent -textvariable $var_scope_tr_level -width 8\n");
sys_gui("$mytoplevel.trg config -borderwidth 1 -padx 5 -pady 5 -text [_ \"Trigger Settings:\"]\n");
sys_gui("pack $mytoplevel.trg.tr_mode\n");
sys_gui("pack $mytoplevel.trg.tr_mode.lab -side left\n");
sys_gui("pack $mytoplevel.trg.tr_mode.trb -side left\n");
sys_gui("$mytoplevel.trg config -padx 10\n");
sys_gui("pack configure $mytoplevel.trg.tr_mode -side left\n");
sys_gui("pack $mytoplevel.trg.dummy1 $mytoplevel.trg.tr_level_lab $mytoplevel.trg.tr_level_ent -side left\n");
sys_gui("menu $mytoplevel.tr_mode_popup\n");
sys_gui("$mytoplevel.tr_mode_popup add command \\\n");
sys_gui("-label \"None\" -command \"::dialog_scope::scope_trigger_mode $mytoplevel 0\"\n");
sys_gui("$mytoplevel.tr_mode_popup add command \\\n");
sys_gui("-label \"Up\" -command \"::dialog_scope::scope_trigger_mode $mytoplevel 1\"\n");
sys_gui("$mytoplevel.tr_mode_popup add command \\\n");
sys_gui("-label \"Down\" -command \"::dialog_scope::scope_trigger_mode $mytoplevel 2\"\n");
sys_gui("bind $mytoplevel.trg.tr_mode.trb <Button> [list tk_popup $mytoplevel.tr_mode_popup %X %Y]\n");
//delay & drawstyle
sys_gui("labelframe $mytoplevel.misc -borderwidth 1 -pady 8 -text [_ \"Other Settings:\"]\n");
sys_gui("pack $mytoplevel.misc -side top -pady 5 -fill x\n");
sys_gui("frame $mytoplevel.misc.fr\n");
sys_gui("label $mytoplevel.misc.fr.del_lab -text [_ $del_label]\n");
sys_gui("entry $mytoplevel.misc.fr.del_ent -textvariable $var_scope_del -width 7\n");
sys_gui("label $mytoplevel.misc.fr.dummy1 -text \"\" -width 4\n");
sys_gui("label $mytoplevel.misc.fr.draw_style_lab -text [_ $draw_style_label]\n");
sys_gui("checkbutton $mytoplevel.misc.fr.draw_style_chk -variable $var_scope_draw_style \\\n");
sys_gui("-command \"::dialog_scope::apply_and_rebind_return $mytoplevel\" \n");
sys_gui("pack $mytoplevel.misc.fr -side left -expand 1\n");
sys_gui("pack $mytoplevel.misc.fr.del_lab $mytoplevel.misc.fr.del_ent \\\n");
sys_gui("$mytoplevel.misc.fr.dummy1 $mytoplevel.misc.fr.draw_style_lab $mytoplevel.misc.fr.draw_style_chk -side left\n");

// Receive
sys_gui("labelframe $mytoplevel.rcv -borderwidth 1 -pady 8 -text [_ \"Receive:\"]\n");
sys_gui("pack $mytoplevel.rcv -side top -pady 5 -fill x\n");
sys_gui("frame $mytoplevel.rcv.fr\n");
sys_gui("label $mytoplevel.rcv.fr.rcv_lab -text [_ $rcv_label]\n");
sys_gui("entry $mytoplevel.rcv.fr.rcv_ent -textvariable $var_scope_rcv -width 21\n");
sys_gui("pack $mytoplevel.rcv.fr \n");
sys_gui("pack $mytoplevel.rcv.fr.rcv_lab $mytoplevel.rcv.fr.rcv_ent -side left \n");

// colors
sys_gui("labelframe $mytoplevel.colors -borderwidth 1 -text [_ \"Colors:\"] -padx 5 -pady 5\n");
sys_gui("pack $mytoplevel.colors -fill x\n");
sys_gui("frame $mytoplevel.colors.scopevis \n");
sys_gui("pack $mytoplevel.colors.scopevis -side top -pady 10\n");
sys_gui("canvas $mytoplevel.colors.scopevis.cv -width 81 -height 65 \\\n");
sys_gui("-relief flat -highlightthickness 0\n");
sys_gui("pack $mytoplevel.colors.scopevis.cv -in $mytoplevel.colors.scopevis\n");
sys_gui("$mytoplevel.colors.scopevis.cv create rectangle 0 0 80 64 \\\n");
sys_gui("-fill [eval concat $$var_scope_bcol] -tags {\"bg\"}\n");
sys_gui("foreach i {0 10 20 30 40 50 60 70 80} {\n");
sys_gui("$mytoplevel.colors.scopevis.cv create line $i 0 $i 64 -fill [eval concat $$var_scope_gcol] \\\n");
sys_gui("-width 0.5 -tags {\"gr\"}\n");
sys_gui("}\n");
sys_gui("foreach i {0 16 32 48 64} {\n");
sys_gui("$mytoplevel.colors.scopevis.cv create line 0 $i 80 $i -fill [eval concat $$var_scope_gcol] \\\n");
sys_gui("-width 0.5 -tags {\"gr\"}\n");
sys_gui("}\n");
sys_gui("$mytoplevel.colors.scopevis.cv create line \\\n");
sys_gui("0 32 5 19.754 10 9.367 15 2.436 \\\n");
sys_gui("20 0 25 2.436 30 9.367 35 19.754 \\\n");
sys_gui("40 32 45 44.246 50 54.624 55 61.564 \\\n");
sys_gui("60 64 65 61.564 70 54.624 75 44.246 \\\n");
sys_gui("80 32 \\\n");
sys_gui("-smooth bezier -fill [eval concat $$var_scope_fcol] \\\n");
sys_gui("-width 0.9 -tags {\"fg\"}\n");
sys_gui("frame $mytoplevel.colors.dummy\n");
sys_gui("pack $mytoplevel.colors.dummy -side top -pady 10\n");
sys_gui("frame $mytoplevel.colors.select\n");
sys_gui("pack $mytoplevel.colors.select -side top\n");
sys_gui("radiobutton $mytoplevel.colors.select.radio0 -value 0 -variable \\\n");
sys_gui("$var_scope_f2_g1_b0 -text [_ \"Background\"] -justify left\n");
sys_gui("radiobutton $mytoplevel.colors.select.radio1 -value 1 -variable \\\n");
sys_gui("$var_scope_f2_g1_b0 -text [_ \"Grid\"] -justify left\n");
sys_gui("radiobutton $mytoplevel.colors.select.radio2 -value 2 -variable \\\n");
sys_gui("$var_scope_f2_g1_b0 -text [_ \"Phosphor\"] -justify left\n");
sys_gui("pack $mytoplevel.colors.select.radio0 $mytoplevel.colors.select.radio1 \\\n");
sys_gui("$mytoplevel.colors.select.radio2 -side left\n");
sys_gui("frame $mytoplevel.colors.sections \n");
sys_gui("pack $mytoplevel.colors.sections -side top -pady 5\n");
sys_gui("button $mytoplevel.colors.sections.but -text [_ \"Compose color\"] \\\n");
sys_gui("-command \"::dialog_scope::scope_choose_col_bkgrfg $mytoplevel\"\n");
sys_gui("pack $mytoplevel.colors.sections.but -side left -anchor w -pady 5 \\\n");
sys_gui("-expand yes -fill x\n");
// color scheme by Mary Ann Benedetto http://piR2.org
sys_gui("foreach r {r1 r2 r3} hexcols {\n");
sys_gui("{ \"#FFFFFF\" \"#DFDFDF\" \"#BBBBBB\" \"#FFC7C6\" \"#FFE3C6\" \"#FEFFC6\" \"#C6FFC7\" \"#C6FEFF\" \"#C7C6FF\" \"#E3C6FF\" }\n");
sys_gui("{ \"#9F9F9F\" \"#7C7C7C\" \"#606060\" \"#FF0400\" \"#FF8300\" \"#FAFF00\" \"#00FF04\" \"#00FAFF\" \"#0400FF\" \"#9C00FF\" }\n");
sys_gui("{ \"#404040\" \"#202020\" \"#000000\" \"#551312\" \"#553512\" \"#535512\" \"#0F4710\" \"#0E4345\" \"#131255\" \"#2F004D\" } } \\\n");
sys_gui("{\n");
sys_gui("frame $mytoplevel.colors.$r\n");
sys_gui("pack $mytoplevel.colors.$r -side top\n");
sys_gui("foreach i { 0 1 2 3 4 5 6 7 8 9} hexcol $hexcols \\\n");
sys_gui("{\n");
sys_gui("label $mytoplevel.colors.$r.c$i -background $hexcol -activebackground $hexcol -relief ridge -padx 7 -pady 0\n");
sys_gui("bind $mytoplevel.colors.$r.c$i <Button> \"::dialog_scope::scope_preset_col $mytoplevel $hexcol\"\n");
sys_gui("}\n");
sys_gui("pack $mytoplevel.colors.$r.c0 $mytoplevel.colors.$r.c1 $mytoplevel.colors.$r.c2 $mytoplevel.colors.$r.c3 \\\n");
sys_gui("$mytoplevel.colors.$r.c4 $mytoplevel.colors.$r.c5 $mytoplevel.colors.$r.c6 $mytoplevel.colors.$r.c7 \\\n");
sys_gui("$mytoplevel.colors.$r.c8 $mytoplevel.colors.$r.c9 -side left\n");
sys_gui("}\n");
//buttons
sys_gui("frame $mytoplevel.cao -pady 10\n");
sys_gui("pack $mytoplevel.cao -side top -expand 1 -fill x\n");
sys_gui("button $mytoplevel.cao.cancel -text [_ \"Cancel\"] \\\n");
sys_gui("-command \"::dialog_scope::cancel $mytoplevel\"\n");
sys_gui("pack $mytoplevel.cao.cancel -side left -padx 10 -expand 1 -fill x\n");
sys_gui("if {$::windowingsystem ne \"aqua\"} {\n");
sys_gui("button $mytoplevel.cao.apply -text [_ \"Apply\"] \\\n");
sys_gui("-command \"::dialog_scope::apply $mytoplevel\"\n");
sys_gui("pack $mytoplevel.cao.apply -side left -padx 10 -expand 1 -fill x\n");
sys_gui("}\n");
sys_gui("button $mytoplevel.cao.ok -text [_ \"OK\"] \\\n");
sys_gui("-command \"::dialog_scope::ok $mytoplevel\" -default active\n");
sys_gui("pack $mytoplevel.cao.ok -side left -padx 10 -expand 1 -fill x\n");
sys_gui("$mytoplevel.dim.fr.w_ent select from 0\n");
sys_gui("$mytoplevel.dim.fr.w_ent select adjust end\n");
sys_gui("focus $mytoplevel.dim.fr.w_ent\n");
// live widget updates on OSX in lieu of Apply button
sys_gui("if {$::windowingsystem eq \"aqua\"} {\n");
// call apply on Return in entry boxes that are in focus & rebind Return to ok button
sys_gui("bind $mytoplevel.dim.fr.w_ent <KeyPress-Return> \"::dialog_scope::apply_and_rebind_return $mytoplevel\"\n");
sys_gui("bind $mytoplevel.dim.fr.h_ent <KeyPress-Return> \"::dialog_scope::apply_and_rebind_return $mytoplevel\"\n");
sys_gui("bind $mytoplevel.buf.fr.cal_ent <KeyPress-Return> \"::dialog_scope::apply_and_rebind_return $mytoplevel\"\n");
sys_gui("bind $mytoplevel.buf.fr.bufsize_ent <KeyPress-Return> \"::dialog_scope::apply_and_rebind_return $mytoplevel\"\n");
sys_gui("bind $mytoplevel.range.fr.min_ent <KeyPress-Return> \"::dialog_scope::apply_and_rebind_return $mytoplevel\"\n");
sys_gui("bind $mytoplevel.range.fr.max_ent <KeyPress-Return> \"::dialog_scope::apply_and_rebind_return $mytoplevel\"\n");
sys_gui("bind $mytoplevel.trg.tr_level_ent <KeyPress-Return> \"::dialog_scope::apply_and_rebind_return $mytoplevel\"\n");
sys_gui("bind $mytoplevel.misc.fr.del_ent <KeyPress-Return> \"::dialog_scope::apply_and_rebind_return $mytoplevel\"\n");
// unbind Return from ok button when an entry takes focus
sys_gui("$mytoplevel.dim.fr.w_ent config -validate focusin -vcmd \"::dialog_scope::unbind_return $mytoplevel\"\n");
sys_gui("$mytoplevel.dim.fr.h_ent config -validate focusin -vcmd \"::dialog_scope::unbind_return $mytoplevel\"\n");
sys_gui("$mytoplevel.buf.fr.cal_ent config -validate focusin -vcmd \"::dialog_scope::unbind_return $mytoplevel\"\n");
sys_gui("$mytoplevel.buf.fr.bufsize_ent config -validate focusin -vcmd \"::dialog_scope::unbind_return $mytoplevel\"\n");
sys_gui("$mytoplevel.range.fr.min_ent config -validate focusin -vcmd \"::dialog_scope::unbind_return $mytoplevel\"\n");
sys_gui("$mytoplevel.range.fr.max_ent config -validate focusin -vcmd \"::dialog_scope::unbind_return $mytoplevel\"\n");
sys_gui("$mytoplevel.trg.tr_level_ent config -validate focusin -vcmd \"::dialog_scope::unbind_return $mytoplevel\"\n");
sys_gui("$mytoplevel.misc.fr.del_ent config -validate focusin -vcmd \"::dialog_scope::unbind_return $mytoplevel\"\n");
// remove cancel button from focus list since it's not activated on Return
sys_gui("$mytoplevel.cao.cancel config -takefocus 0\n");
// can't see focus for buttons, so disable it
sys_gui("$mytoplevel.trg.tr_mode.trb config -takefocus 0\n");
sys_gui("$mytoplevel.colors.select.radio0 config -takefocus 0\n");
sys_gui("$mytoplevel.colors.select.radio1 config -takefocus 0\n");
sys_gui("$mytoplevel.colors.select.radio2 config -takefocus 0\n");
sys_gui("$mytoplevel.colors.sections.but config -takefocus 0\n");
// show active focus on the ok button as it *is* activated on Return
sys_gui("$mytoplevel.cao.ok config -default normal\n");
sys_gui("bind $mytoplevel.cao.ok <FocusIn> \"$mytoplevel.cao.ok config -default active\"\n");
sys_gui("bind $mytoplevel.cao.ok <FocusOut> \"$mytoplevel.cao.ok config -default normal\"\n");
sys_gui("}\n");
sys_gui("}\n");

// for live widget updates on OSX
sys_gui("proc ::dialog_scope::apply_and_rebind_return {mytoplevel} {\n");
sys_gui("::dialog_scope::apply $mytoplevel\n");
sys_gui("bind $mytoplevel <KeyPress-Return> \"::dialog_scope::ok $mytoplevel\"\n");
sys_gui("focus $mytoplevel.cao.ok\n");
sys_gui("return 0\n");
sys_gui("}\n");
// for live widget updates on OSX
sys_gui("proc ::dialog_scope::unbind_return {mytoplevel} {\n");
sys_gui("bind $mytoplevel <KeyPress-Return> break\n");
sys_gui("return 1\n");
sys_gui("}\n");
