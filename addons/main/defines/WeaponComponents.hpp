// Note:
// Multiple components can exist pointing to the same item, the item will work correctly for both.
// The only reason you'd want to do this is if a component has a different designation for the
// weapon it's being used with. For example, the PBG-40 grenade launcher is functionally identical
// to the GP-25, so that's the way I've defined it here.

// Universal Components
WEAPON_COMPONENT_NAMED(carryhandle,PGVAR(component_carryhandle),PCSTRING(component_carryhandle));
WEAPON_COMPONENT_NAMED(gp25,PGVAR(component_gp25),PCSTRING(component_gp25));
WEAPON_COMPONENT_NAMED(m203,PGVAR(component_m203),PCSTRING(component_m203));
WEAPON_COMPONENT_NAMED(m320,PGVAR(component_m320),PCSTRING(component_m320));

class dovetail_rail {
  items[] = { QPGVAR(component_dovetail_rail) };
  displayName = PCSTRING(component_dovetail_rail);
  disableDetach = 1;
};

class picatinny_rail {
  items[] = { QPGVAR(component_picatinny_rail) };
  displayName = PCSTRING(component_picatinny_rail);
  disableDetach = 1;
};

class shotgun_barrel {
  displayName = PCSTRING(component_shotgun_barrel);
  picture = QPATHTO(data\tools\hacksaw.paa);
  toolsRequired[] = { QUOTE(saw) };
  disableAttach = 1;
  isFake = 1;
};

class afg {
  items[] = {
    QPGVAR(component_afg)
  };
  displayName = PCSTRING(component_afg);
  picture = QPATHTO(data\components\afg.paa);
};

class vfg {
  items[] = {
    QPGVAR(component_vfg)
  };
  displayName = PCSTRING(component_vfg);
  picture = QPATHTO(data\components\vfg.paa);
};

// A3 Components
WEAPON_COMPONENT_NAMED(3gl,PGVAR(component_3gl),PCSTRING(component_3gl));
WEAPON_COMPONENT_NAMED(six12,PGVAR(component_six12),PCSTRING(component_six12));
WEAPON_COMPONENT_NAMED(msbs_gp,PGVAR(component_msbs_gp),PCSTRING(component_msbs_gp));

// LXWS Components
WEAPON_COMPONENT_NAMED(fal_gl,PGVAR(component_fal_gl),PCSTRING(component_fal_gl));

// RHS Components
WEAPON_COMPONENT_NAMED(b13,PGVAR(component_b13),PCSTRING(component_b13));
WEAPON_COMPONENT_NAMED(b33,PGVAR(component_b33),PCSTRING(component_b33));
WEAPON_COMPONENT_NAMED(m14_rail,PGVAR(component_m14_rail),PCSTRING(component_m14_rail));
WEAPON_COMPONENT_NAMED(m14_ris,PGVAR(component_m14_ris),PCSTRING(component_m14_ris));
WEAPON_COMPONENT_NAMED(m21_rail,PGVAR(component_m21_rail),PCSTRING(component_m21_rail));
WEAPON_COMPONENT_NAMED(pbg40,PGVAR(component_gp25),PCSTRING(component_pbg40));
WEAPON_COMPONENT_NAMED(npz,PGVAR(component_npz),PCSTRING(component_npz));
WEAPON_COMPONENT_NAMED(zenit,PGVAR(component_zenit),PCSTRING(component_zenit));

// separate grip component entries are defined for RHS to prioritize using/reclaiming RHS' own
// grip attachment items during attach/detach actions rather than the afg and vfg from us

class afg_rhs {
  items[] = {
    QPGVAR(component_afg)
  };
  displayName = PCSTRING(component_afg);
  picture = QPATHTO(data\components\afg.paa);
};

class vfg_rhs {
  items[] = {
    QPGVAR(component_vfg)
  };
  displayName = PCSTRING(component_vfg);
  picture = QPATHTO(data\components\vfg.paa);
};

// NIArms Components
WEAPON_COMPONENT_NAMED(mtk,PGVAR(component_mtk),PCSTRING(component_mtk));
WEAPON_COMPONENT_NAMED(fal_rail,PGVAR(component_fal_rail),PCSTRING(component_fal_rail));
WEAPON_COMPONENT_NAMED(hk_ris1,PGVAR(component_hk_ris1),PCSTRING(component_hk_ris1)); // Small G3 rail
WEAPON_COMPONENT_NAMED(hk_ris2,PGVAR(component_hk_ris2),PCSTRING(component_hk_ris2)); // Large G3 rail
WEAPON_COMPONENT_NAMED(hk_tac,PGVAR(component_hk_tac),PCSTRING(component_hk_tac)); // MP5 grip rail
WEAPON_COMPONENT_NAMED(ag_c,PGVAR(component_ag_c),PCSTRING(component_ag_c));
WEAPON_COMPONENT_NAMED(sig_ris,PGVAR(component_sig_ris),PCSTRING(component_sig_ris));
WEAPON_COMPONENT_NAMED(sig_tac,PGVAR(component_sig_tac),PCSTRING(component_sig_tac));

// CUP Components
WEAPON_COMPONENT_NAMED(eglm,PGVAR(component_eglm),PCSTRING(component_eglm));
WEAPON_COMPONENT_NAMED(kv04,PGVAR(component_kv04),PCSTRING(component_kv04));
WEAPON_COMPONENT_NAMED(gp34,PGVAR(component_gp25),PCSTRING(component_gp34));
WEAPON_COMPONENT_NAMED(ag36,PGVAR(component_ag_c),PCSTRING(component_ag36));
WEAPON_COMPONENT_NAMED(pk_ris,PGVAR(component_pk_ris),PCSTRING(component_pk_ris));
