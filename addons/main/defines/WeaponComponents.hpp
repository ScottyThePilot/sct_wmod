// Note:
// Multiple components can exist pointing to the same item, the item will work correctly for both.
// The main reason you'd want to do this is if a component has a different designation for the
// weapon it's being used with. For example, the PBG-40 grenade launcher is functionally identical
// to the GP-25, so that's the way I've defined it here.

// Universal Components
WEAPON_COMPONENT_NAMED(carryhandle,RGVAR(component_carryhandle),RCSTRING(component_carryhandle));
WEAPON_COMPONENT_NAMED(gp25,RGVAR(component_gp25),RCSTRING(component_gp25));
WEAPON_COMPONENT_NAMED(m203,RGVAR(component_m203),RCSTRING(component_m203));
WEAPON_COMPONENT_NAMED(m320,RGVAR(component_m320),RCSTRING(component_m320));

class dovetail_rail {
  items[] = { QRGVAR(component_dovetail_rail) };
  displayName = RCSTRING(component_dovetail_rail);
  disableDetach = 1;

  class MessageTemplates {
    interaction_attach = RCSTRING(interaction_attach_install);
    interaction_detach = RCSTRING(interaction_detach_uninstall);
    progressbar_attach = RCSTRING(progressbar_attach_install);
    progressbar_detach = RCSTRING(progressbar_detach_uninstall);
    notify_failure_attach = RCSTRING(notify_failure_attach_install);
    notify_failure_detach = RCSTRING(notify_failure_detach_uninstall);
    notify_success_attach = RCSTRING(notify_success_attach_install);
    notify_success_detach = RCSTRING(notify_success_detach_uninstall);
  };
};

class picatinny_rail {
  items[] = { QRGVAR(component_picatinny_rail) };
  displayName = RCSTRING(component_picatinny_rail);
  disableDetach = 1;

  class MessageTemplates {
    interaction_attach = RCSTRING(interaction_attach_install);
    interaction_detach = RCSTRING(interaction_detach_uninstall);
    progressbar_attach = RCSTRING(progressbar_attach_install);
    progressbar_detach = RCSTRING(progressbar_detach_uninstall);
    notify_failure_attach = RCSTRING(notify_failure_attach_install);
    notify_failure_detach = RCSTRING(notify_failure_detach_uninstall);
    notify_success_attach = RCSTRING(notify_success_attach_install);
    notify_success_detach = RCSTRING(notify_success_detach_uninstall);
  };
};

class shotgun_barrel {
  displayName = RCSTRING(component_shotgun_barrel);
  picture = QPATHTO(data\tools\hacksaw.paa);
  toolsRequired[] = { QUOTE(saw) };
  disableAttach = 1;
  isFake = 1;

  class MessageTemplates {
    interaction_detach = RCSTRING(interaction_detach_sawoff);
    progressbar_detach = RCSTRING(progressbar_detach_sawoff);
    notify_failure_detach = RCSTRING(notify_failure_detach_sawoff);
    notify_success_detach = RCSTRING(notify_success_detach_sawoff);
  };
};

class afg {
  items[] = {
    QRGVAR(component_afg),
    "rhsusf_acc_grip2",
    "rhsusf_acc_grip2_tan",
    "rhsusf_acc_grip2_wd"
  };
  displayName = RCSTRING(component_afg);
  picture = QPATHTO(data\components\afg.paa);
  actionLengthMultiplier = 0.5;
};

class vfg {
  items[] = {
    QRGVAR(component_vfg),
    "rhsusf_acc_kac_grip",
    "rhsusf_acc_grip3",
    "rhsusf_acc_grip3_tan",
    "rhsusf_acc_grip1"
  };
  displayName = RCSTRING(component_vfg);
  picture = QPATHTO(data\components\vfg.paa);
  actionLengthMultiplier = 0.5;
};

// A3 Components
WEAPON_COMPONENT_NAMED(3gl,RGVAR(component_3gl),RCSTRING(component_3gl));
WEAPON_COMPONENT_NAMED(six12,RGVAR(component_six12),RCSTRING(component_six12));
WEAPON_COMPONENT_NAMED(msbs_gp,RGVAR(component_msbs_gp),RCSTRING(component_msbs_gp));

// LXWS Components
WEAPON_COMPONENT_NAMED(fal_gl,RGVAR(component_fal_gl),RCSTRING(component_fal_gl));

// RHS Components
WEAPON_COMPONENT_NAMED(b13,RGVAR(component_b13),RCSTRING(component_b13));
WEAPON_COMPONENT_NAMED(b33,RGVAR(component_b33),RCSTRING(component_b33));
WEAPON_COMPONENT_NAMED(m14_rail,RGVAR(component_m14_rail),RCSTRING(component_m14_rail));
WEAPON_COMPONENT_NAMED(m14_ris,RGVAR(component_m14_ris),RCSTRING(component_m14_ris));
WEAPON_COMPONENT_NAMED(m21_rail,RGVAR(component_m21_rail),RCSTRING(component_m21_rail));
WEAPON_COMPONENT_NAMED(pbg40,RGVAR(component_gp25),RCSTRING(component_pbg40));
WEAPON_COMPONENT_NAMED(npz,RGVAR(component_npz),RCSTRING(component_npz));
WEAPON_COMPONENT_NAMED(zenit,RGVAR(component_zenit),RCSTRING(component_zenit));

// a separate m203 component is made that shadows the main m203 component, and is non-attachable
// to account for weapon variants in RHS that have a long and short variant of the m203

class m203_alt_rhs {
  items[] = { QRGVAR(component_m203) };
  displayName = RCSTRING(component_m203);
  disableAttach = 1;
};

// separate grip component entries are defined for RHS to prioritize using/reclaiming RHS' own
// grip attachment items during attach/detach actions rather than the afg and vfg from us

class afg_rhs {
  items[] = {
    "rhsusf_acc_grip2",
    "rhsusf_acc_grip2_tan",
    "rhsusf_acc_grip2_wd",
    QRGVAR(component_afg)
  };
  displayName = RCSTRING(component_afg);
  picture = QPATHTO(data\components\afg.paa);
  actionLengthMultiplier = 0.5;
};

class vfg_rhs {
  items[] = {
    "rhsusf_acc_kac_grip",
    "rhsusf_acc_grip3",
    "rhsusf_acc_grip3_tan",
    "rhsusf_acc_grip1",
    QRGVAR(component_vfg)
  };
  displayName = RCSTRING(component_vfg);
  picture = QPATHTO(data\components\vfg.paa);
  actionLengthMultiplier = 0.5;
};

// NIArms Components
WEAPON_COMPONENT_NAMED(mtk,RGVAR(component_mtk),RCSTRING(component_mtk));
WEAPON_COMPONENT_NAMED(fal_rail,RGVAR(component_fal_rail),RCSTRING(component_fal_rail));
WEAPON_COMPONENT_NAMED(hk_ris1,RGVAR(component_hk_ris1),RCSTRING(component_hk_ris1)); // Small G3 rail
WEAPON_COMPONENT_NAMED(hk_ris2,RGVAR(component_hk_ris2),RCSTRING(component_hk_ris2)); // Large G3 rail
WEAPON_COMPONENT_NAMED(hk_tac,RGVAR(component_hk_tac),RCSTRING(component_hk_tac)); // MP5 grip rail
WEAPON_COMPONENT_NAMED(ag_c,RGVAR(component_ag_c),RCSTRING(component_ag_c));
WEAPON_COMPONENT_NAMED(sig_ris,RGVAR(component_sig_ris),RCSTRING(component_sig_ris));
WEAPON_COMPONENT_NAMED(sig_tac,RGVAR(component_sig_tac),RCSTRING(component_sig_tac));
WEAPON_COMPONENT_NAMED(pws_srx,RGVAR(component_pws_srx),RCSTRING(component_pws_srx));

class rifle_ghillie {
  items[] = { QRGVAR(component_rifle_ghillie) };
  displayName = RCSTRING(component_rifle_ghillie);
  actionLengthMultiplier = 0.25;

  class MessageTemplates {
    interaction_attach = RCSTRING(interaction_attach_apply);
    interaction_detach = RCSTRING(interaction_detach_remove);
    progressbar_attach = RCSTRING(progressbar_attach_apply);
    progressbar_detach = RCSTRING(progressbar_detach_remove);
    notify_failure_attach = RCSTRING(notify_failure_attach_apply);
    notify_failure_detach = RCSTRING(notify_failure_detach_remove);
    notify_success_attach = RCSTRING(notify_success_attach_apply);
    notify_success_detach = RCSTRING(notify_success_detach_remove);
  };
};

// CUP Components
WEAPON_COMPONENT_NAMED(eglm,RGVAR(component_eglm),RCSTRING(component_eglm));
WEAPON_COMPONENT_NAMED(kv04,RGVAR(component_kv04),RCSTRING(component_kv04));
WEAPON_COMPONENT_NAMED(gp34,RGVAR(component_gp25),RCSTRING(component_gp34));
WEAPON_COMPONENT_NAMED(ag36,RGVAR(component_ag_c),RCSTRING(component_ag36));
WEAPON_COMPONENT_NAMED(pk_ris,RGVAR(component_pk_ris),RCSTRING(component_pk_ris));
