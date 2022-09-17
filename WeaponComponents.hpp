// 0: Muzzle
// 1: Flashlight/Laser
// 2: Optic
// 3: Primary Mag
// 4: Secondary Mag
// 5: Bipod/Grip



// Universal Components

class carryhandle {
  displayName = "$STR_sct_wmod_c_carryhandle";
  className = "sct_wmod_component_carryhandle";
  attachmentSlots[] = {};
};

class gp25 {
  displayName = "$STR_sct_wmod_c_gp25";
  className = "sct_wmod_component_gp25";
  attachmentSlots[] = { 1, 4, 5 };
};

class gp25_fl {
  displayName = "$STR_sct_wmod_c_gp25";
  className = "sct_wmod_component_gp25";
  // Like the `gp25` component but doesn't remove the flashlight
  attachmentSlots[] = { 4, 5 };
};

class m203 {
  displayName = "$STR_sct_wmod_c_m203";
  className = "sct_wmod_component_m203";
  attachmentSlots[] = { 4, 5 };
};

class m320 {
  displayName = "$STR_sct_wmod_c_m320";
  className = "sct_wmod_component_m320";
  attachmentSlots[] = { 4, 5 };
};

// A3 Components

class 3gl {
  displayName = "$STR_sct_wmod_c_3gl";
  className = "sct_wmod_component_3gl";
  attachmentSlots[] = { 5 };
};

// RHS Components

class b13 {
  displayName = "$STR_sct_wmod_c_b13";
  className = "sct_wmod_component_b13";
  attachmentSlots[] = { 2 };
};

class b33 {
  displayName = "$STR_sct_wmod_c_b33";
  className = "sct_wmod_component_b33";
  attachmentSlots[] = { 2 };
};

class m14_rail {
  displayName = "$STR_sct_wmod_c_m14_rail";
  className = "sct_wmod_component_m14_rail";
  attachmentSlots[] = { 2 };
};

class m14_ris {
  displayName = "$STR_sct_wmod_c_m14_ris";
  className = "sct_wmod_component_m14_ris";
  attachmentSlots[] = { 1, 2 };
};

class m21_rail {
  displayName = "$STR_sct_wmod_c_m21_rail";
  className = "sct_wmod_component_m21_rail";
  attachmentSlots[] = { 2 };
};

class pbg40 {
  displayName = "$STR_sct_wmod_c_pbg40";
  className = "sct_wmod_component_gp25";
  attachmentSlots[] = { 1, 4, 5 };
};

class npz {
  displayName = "$STR_sct_wmod_c_npz";
  className = "sct_wmod_component_npz";
  attachmentSlots[] = { 2 };
};

class zenit {
  displayName = "$STR_sct_wmod_c_zenit";
  className = "sct_wmod_component_zenit";
  attachmentSlots[] = { 1 };
};

// NIArms Components

class mtk {
  displayName = "$STR_sct_wmod_c_mtk";
  className = "sct_wmod_component_mtk";
  attachmentSlots[] = { 2 };
};

class fal_rail {
  displayName = "$STR_sct_wmod_c_fal_rail";
  className = "sct_wmod_component_fal_rail";
  attachmentSlots[] = { 2 };
};

class hk_ris1 {
  displayName = "$STR_sct_wmod_c_hk_ris1";
  className = "sct_wmod_component_hk_ris1";
  attachmentSlots[] = { 2 };
};

class hk_ris2 {
  displayName = "$STR_sct_wmod_c_hk_ris2";
  className = "sct_wmod_component_hk_ris2";
  attachmentSlots[] = { 2 };
};

class hk_tac {
  displayName = "$STR_sct_wmod_c_hk_tac";
  className = "sct_wmod_component_hk_tac";
  attachmentSlots[] = { 1, 5 };
};

class ag_c {
  displayName = "$STR_sct_wmod_c_ag_c";
  className = "sct_wmod_component_ag_c";
  attachmentSlots[] = { 4, 5 };
};

class sig_ris {
  displayName = "$STR_sct_wmod_c_sig_ris";
  className = "sct_wmod_component_sig_ris";
  attachmentSlots[] = { 2 };
};

class sig_tac {
  displayName = "$STR_sct_wmod_c_sig_tac";
  className = "sct_wmod_component_sig_tac";
  attachmentSlots[] = { 1, 5 };
};
