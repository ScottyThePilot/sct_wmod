// Note:
// Multiple components can exist pointing to the same item, the item will work correctly for both.
// The only reason you'd want to do this is if a component has a different designation for the
// weapon it's being used with. For example, the PBG-40 grenade launcher is functionally identical
// to the GP-25, so that's the way I've defined it here.

// Universal Components
COMPONENT_NAMED(carryhandle,sct_wmod_component_carryhandle,"$STR_sct_wmod_c_carryhandle");
COMPONENT_NAMED(gp25,sct_wmod_component_gp25,"$STR_sct_wmod_c_gp25");
COMPONENT_NAMED(m203,sct_wmod_component_m203,"$STR_sct_wmod_c_m203");
COMPONENT_NAMED(m320,sct_wmod_component_m320,"$STR_sct_wmod_c_m320");
COMPONENT_NAMED_NODETACH(dovetail_rail,sct_wmod_component_dovetail_rail,"$STR_sct_wmod_c_dovetail_rail");
//COMPONENT_NAMED_NODETACH(picatinny_rail,sct_wmod_component_picatinny_rail,"$STR_sct_wmod_c_picatinny_rail");

// A3 Components
COMPONENT_NAMED(3gl,sct_wmod_component_3gl,"$STR_sct_wmod_c_3gl");

// RHS Components
COMPONENT_NAMED(b13,sct_wmod_component_b13,"$STR_sct_wmod_c_b13");
COMPONENT_NAMED(b33,sct_wmod_component_b33,"$STR_sct_wmod_c_b33");
COMPONENT_NAMED(m14_rail,sct_wmod_component_m14_rail,"$STR_sct_wmod_c_m14_rail");
COMPONENT_NAMED(m14_ris,sct_wmod_component_m14_ris,"$STR_sct_wmod_c_m14_ris");
COMPONENT_NAMED(m21_rail,sct_wmod_component_m21_rail,"$STR_sct_wmod_c_m21_rail");
COMPONENT_NAMED(pbg40,sct_wmod_component_gp25,"$STR_sct_wmod_c_pbg40");
COMPONENT_NAMED(npz,sct_wmod_component_npz,"$STR_sct_wmod_c_npz");
COMPONENT_NAMED(zenit,sct_wmod_component_zenit,"$STR_sct_wmod_c_zenit");

// NIArms Components
COMPONENT_NAMED(mtk,sct_wmod_component_mtk,"$STR_sct_wmod_c_mtk");
COMPONENT_NAMED(fal_rail,sct_wmod_component_fal_rail,"$STR_sct_wmod_c_fal_rail");
COMPONENT_NAMED(hk_ris1,sct_wmod_component_hk_ris1,"$STR_sct_wmod_c_hk_ris1"); // Small G3 rail
COMPONENT_NAMED(hk_ris2,sct_wmod_component_hk_ris2,"$STR_sct_wmod_c_hk_ris2"); // Large G3 rail
COMPONENT_NAMED(hk_tac,sct_wmod_component_hk_tac,"$STR_sct_wmod_c_hk_tac"); // MP5 grip rail
COMPONENT_NAMED(ag_c,sct_wmod_component_ag_c,"$STR_sct_wmod_c_ag_c");
COMPONENT_NAMED(sig_ris,sct_wmod_component_sig_ris,"$STR_sct_wmod_c_sig_ris");
COMPONENT_NAMED(sig_tac,sct_wmod_component_sig_tac,"$STR_sct_wmod_c_sig_tac");

// CUP Components
COMPONENT_NAMED(eglm,sct_wmod_component_eglm,"$STR_sct_wmod_c_eglm");
COMPONENT_NAMED(kv04,sct_wmod_component_kv04,"$STR_sct_wmod_c_kv04");
COMPONENT_NAMED(gp34,sct_wmod_component_gp25,"$STR_sct_wmod_c_gp34");
COMPONENT_NAMED(ag36,sct_wmod_component_ag_c,"$STR_sct_wmod_c_ag36");
COMPONENT_NAMED(pk_ris,sct_wmod_component_pk_ris,"$STR_sct_wmod_c_pk_ris");
