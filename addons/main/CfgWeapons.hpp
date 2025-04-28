class CBA_MiscItem;
class CBA_MiscItem_ItemInfo;

class RGVAR(tool_hacksaw): CBA_MiscItem {
  author = "ScottyThePilot";
  displayName = RCSTRING(tool_hacksaw);
  picture = QPATHTO(data\tools\hacksaw.paa);
  descriptionShort = RCSTRING(tool_description_hacksaw);

  ACE_isTool = 1;

  class ItemInfo: CBA_MiscItem_ItemInfo {
    mass = 2;
  };

  scope = 2;
};

class RGVAR(ccore): CBA_MiscItem {
  RGVAR(isWeaponComponentItem) = 1;
  class ItemInfo: CBA_MiscItem_ItemInfo {
    mass = 2;
  };
};

class RGVAR(component_3gl): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_3gl);
  picture = QPATHTO(data\components\3gl.paa);
  descriptionShort = RCSTRING(component_description_3gl);
  scope = 2;
};

class RGVAR(component_b13): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_b13);
  picture = QPATHTO(data\components\b13.paa);
  descriptionShort = RCSTRING(component_description_rail_side_ak);
  scope = 2;
};

class RGVAR(component_b33): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_b33);
  picture = QPATHTO(data\components\b33.paa);
  descriptionShort = RCSTRING(component_description_rail_top_ak);
  scope = 2;
};

class RGVAR(component_carryhandle): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_carryhandle);
  picture = QPATHTO(data\components\carryhandle.paa);
  descriptionShort = RCSTRING(component_description_carryhandle);
  scope = 2;
};

class RGVAR(component_gp25): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_gp25);
  picture = QPATHTO(data\components\gp25.paa);
  descriptionShort = RCSTRING(component_description_gp25);
  scope = 2;
};

class RGVAR(component_m14_rail): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_m14_rail);
  picture = QPATHTO(data\components\m14_rail.paa);
  descriptionShort = RCSTRING(component_description_m14_rail);
  scope = 2;
};

class RGVAR(component_m14_ris): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_m14_ris);
  picture = QPATHTO(data\components\m14_ris.paa);
  descriptionShort = RCSTRING(component_description_m14_ris);
  scope = 2;
};

class RGVAR(component_m21_rail): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_m21_rail);
  picture = QPATHTO(data\components\m21_rail.paa);
  descriptionShort = RCSTRING(component_description_m21_rail);
  scope = 2;
};

class RGVAR(component_m203): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_m203);
  picture = QPATHTO(data\components\m203.paa);
  descriptionShort = RCSTRING(component_description_m4_gl);
  scope = 2;
};

class RGVAR(component_m320): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_m320);
  picture = QPATHTO(data\components\m320.paa);
  descriptionShort = RCSTRING(component_description_m4_gl);
  scope = 2;
};

class RGVAR(component_npz): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_npz);
  picture = QPATHTO(data\components\npz.paa);
  descriptionShort = RCSTRING(component_description_rail_side_ak);
  scope = 2;
};

class RGVAR(component_zenit): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_zenit);
  picture = QPATHTO(data\components\zenit.paa);
  descriptionShort = RCSTRING(component_description_rail_handguard_ak);
  scope = 2;
};

class RGVAR(component_mtk): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_mtk);
  picture = QPATHTO(data\components\mtk.paa);
  descriptionShort = RCSTRING(component_description_rail_side_ak);
  scope = 2;
};

class RGVAR(component_fal_rail): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_fal_rail);
  picture = QPATHTO(data\components\fal_rail.paa);
  descriptionShort = RCSTRING(component_description_fal_rail);
  scope = 2;
};

class RGVAR(component_hk_ris1): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_hk_ris1);
  picture = QPATHTO(data\components\hk_ris1.paa);
  descriptionShort = RCSTRING(component_description_hk_ris);
  scope = 2;
};

class RGVAR(component_hk_ris2): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_hk_ris2);
  picture = QPATHTO(data\components\hk_ris2.paa);
  descriptionShort = RCSTRING(component_description_hk_ris);
  scope = 2;
};

class RGVAR(component_hk_tac): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_hk_tac);
  picture = QPATHTO(data\components\hk_tac.paa);
  descriptionShort = RCSTRING(component_description_hk_tac);
  scope = 2;
};

class RGVAR(component_ag_c): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_agc_full);
  picture = QPATHTO(data\components\ag_c.paa);
  descriptionShort = RCSTRING(component_description_ag_c);
  scope = 2;
};

class RGVAR(component_sig_ris): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_sig_ris);
  picture = QPATHTO(data\components\sig_ris.paa);
  descriptionShort = RCSTRING(component_description_sig_ris);
  scope = 2;
};

class RGVAR(component_sig_tac): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_sig_tac);
  picture = QPATHTO(data\components\sig_tac.paa);
  descriptionShort = RCSTRING(component_description_sig_tac);
  scope = 2;
};

class RGVAR(component_dovetail_rail): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_dovetail_rail_full);
  picture = QPATHTO(data\components\dovetail_rail.paa);
  descriptionShort = RCSTRING(component_description_dovetail_rail);
  scope = 2;
};

class RGVAR(component_picatinny_rail): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_picatinny_rail_full);
  picture = QPATHTO(data\components\picatinny_rail.paa);
  descriptionShort = RCSTRING(component_description_picatinny_rail);
  scope = 2;
};

class RGVAR(component_eglm): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_eglm_full);
  picture = QPATHTO(data\components\eglm.paa);
  descriptionShort = RCSTRING(component_description_eglm);
  scope = 2;
};

class RGVAR(component_kv04): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_kv04);
  picture = QPATHTO(data\components\kv04.paa);
  descriptionShort = RCSTRING(component_description_rail_side_ak);
  scope = 2;
};

class RGVAR(component_pk_ris): RGVAR(ccore) {
  author = "ScottyThePilot";
  displayName = RCSTRING(component_pk_ris_full);
  picture = QPATHTO(data\components\pk_ris.paa);
  descriptionShort = RCSTRING(component_description_pk_ris);
  scope = 2;
};

class RGVAR(component_fal_gl): RGVAR(ccore) {
  uthor = "ScottyThePilot";
  displayName = RCSTRING(component_fal_gl);
  picture = QPATHTO(data\components\fal_gl.paa);
  descriptionShort = RCSTRING(component_description_fal_gl);
  scope = 2;
};

class RGVAR(component_six12): RGVAR(ccore) {
  uthor = "ScottyThePilot";
  displayName = RCSTRING(component_six12);
  picture = QPATHTO(data\components\six12.paa);
  descriptionShort = RCSTRING(component_description_six12);
  scope = 2;
};

class RGVAR(component_msbs_gp): RGVAR(ccore) {
  uthor = "ScottyThePilot";
  displayName = RCSTRING(component_msbs_gp);
  picture = QPATHTO(data\components\msbs_gp.paa);
  descriptionShort = RCSTRING(component_description_msbs_gp);
  scope = 2;
};

class RGVAR(component_masterkey): RGVAR(ccore) {
  uthor = "ScottyThePilot";
  displayName = RCSTRING(component_masterkey);
  picture = QPATHTO(data\components\masterkey.paa);
  descriptionShort = RCSTRING(component_description_masterkey);
  scope = 2;
};

class RGVAR(component_afg): RGVAR(ccore) {
  uthor = "ScottyThePilot";
  displayName = RCSTRING(component_afg_full);
  picture = QPATHTO(data\components\afg.paa);
  scope = 2;
};

class RGVAR(component_vfg): RGVAR(ccore) {
  uthor = "ScottyThePilot";
  displayName = RCSTRING(component_vfg_full);
  picture = QPATHTO(data\components\vfg.paa);
  scope = 2;
};
