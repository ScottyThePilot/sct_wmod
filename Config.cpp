class CfgPatches {
  class sct_wmod {
    name = "Scotty's ACE Weapon Modification";
    author = "ScottyThePilot";
    authorUrl = "https://steamcommunity.com/id/scottythepilot/";
    url = "https://github.com/ScottyThePilot/sct_wmod";
    requiredAddons[] = {
      "cba_main",
      "ace_common",
      "ace_interact_menu",
      "ace_interaction"
    };
    version = 1.5;
    versionStr = "1.5.0";
    versionAr[] = { 1, 5, 0 };
    units[] = {};
    weapons[] = {};
  };
};

class CfgFunctions {
  class sct_wmod {
    class functions {
      file = "\sct_wmod\functions";
      class action {};
      class actionCondition {};
      class actionConditionUse {};
      class actionFail {};
      class createInteraction {};
      class getComponentActions {};
      class initActions {};
      class initSettings {};
    };
  };
};

class Extended_PreInit_EventHandlers {
  class sct_wmod_init_settings {
    init = "call sct_wmod_fnc_initSettings";
  };
};

class CfgVehicles {
  class Man;

  class CAManBase: Man {
    class ACE_SelfActions {
      class ACE_Equipment {
        class sct_wmod_Components {
          displayName = "$STR_sct_wmod_Components";
          exceptions[] = { "isNotInside", "isNotSwimming", "isNotSitting" };
          insertChildren = "call sct_wmod_fnc_getComponentActions";
          modifierFunction = "(_this select 3) set [2, getText (configFile >> 'CfgWeapons' >> currentWeapon (_this select 0) >> 'picture')];";
          // Parentheses required because of an ACE (?) bug
          condition = "(isNil 'SCT_wmod_modificationEnabled' || { SCT_wmod_modificationEnabled })";
        };
      };
    };
  };
};

class CfgWeapons {
  class ItemCore;
  class InventoryItem_Base_F;

  class sct_wmod_ccore: ItemCore {
    type = 4096;
    simulation = "ItemMineDetector";
    class ItemInfo: InventoryItem_Base_F {
      mass = 2;
    };
  };

  class sct_wmod_component_3gl: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_3gl";
    picture = "\sct_wmod\data\components\3gl.paa";
    descriptionShort = "A 40mm underbarrel grenade launcher for the MX";
    scope = 2;
  };

  class sct_wmod_component_b13: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_b13";
    picture = "\sct_wmod\data\components\b13.paa";
    descriptionShort = "A side-mounted picatinny rail adapter for the AK family of rifles";
    scope = 2;
  };

  class sct_wmod_component_b33: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_b33";
    picture = "\sct_wmod\data\components\b33.paa";
    descriptionShort = "A reciever cover with integrated picatinny rail for the AK family of rifles";
    scope = 2;
  };

  class sct_wmod_component_carryhandle: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_carryhandle";
    picture = "\sct_wmod\data\components\carryhandle.paa";
    descriptionShort = "A carryhandle unit with integrated sight designed for the M4 and M16 series of rifles";
    scope = 2;
  };

  class sct_wmod_component_gp25: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_gp25";
    picture = "\sct_wmod\data\components\gp25.paa";
    descriptionShort = "A 40mm under-barrel grenade launcher for the AK family of rifles";
    scope = 2;
  };

  class sct_wmod_component_m14_rail: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_m14_rail";
    picture = "\sct_wmod\data\components\m14_rail.paa";
    descriptionShort = "A side-mounted picatinny rail adapter for the M14";
    scope = 2;
  };

  class sct_wmod_component_m14_ris: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_m14_ris";
    picture = "\sct_wmod\data\components\m14_ris.paa";
    descriptionShort = "A top-mounted picatinny rail system for the M14";
    scope = 2;
  };

  class sct_wmod_component_m21_rail: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_m21_rail";
    picture = "\sct_wmod\data\components\m21_rail.paa";
    descriptionShort = "A side-mounted picatinny rail adapter for the M21 Zastava";
    scope = 2;
  };

  class sct_wmod_component_m203: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_m203";
    picture = "\sct_wmod\data\components\m203.paa";
    descriptionShort = "A 40mm underbarrel grenade launcher for the AR-15 family of rifles";
    scope = 2;
  };

  class sct_wmod_component_m320: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_m320";
    picture = "\sct_wmod\data\components\m320.paa";
    descriptionShort = "A 40mm underbarrel grenade launcher for the AR-15 family of rifles";
    scope = 2;
  };

  class sct_wmod_component_npz: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_npz";
    picture = "\sct_wmod\data\components\npz.paa";
    descriptionShort = "A side-mounted picatinny rail adapter for the AK family of rifles";
    scope = 2;
  };

  class sct_wmod_component_zenit: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_zenit";
    picture = "\sct_wmod\data\components\zenit.paa";
    descriptionShort = "A picatinny rail adapter handguard for the AK family of rifles";
    scope = 2;
  };

  class sct_wmod_component_mtk: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_mtk";
    picture = "\sct_wmod\data\components\mtk.paa";
    descriptionShort = "A side-mounted picatinny rail adapter for the AK family of rifles";
    scope = 2;
  };

  class sct_wmod_component_fal_rail: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_fal_rail";
    picture = "\sct_wmod\data\components\fal_rail.paa";
    descriptionShort = "A picatinny optic rail mount for the FN FAL";
    scope = 2;
  };

  class sct_wmod_component_hk_ris1: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_hk_ris1";
    picture = "\sct_wmod\data\components\hk_ris1.paa";
    descriptionShort = "A picatinny optic rail mount for the HK G3 family of rifles";
    scope = 2;
  };

  class sct_wmod_component_hk_ris2: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_hk_ris2";
    picture = "\sct_wmod\data\components\hk_ris2.paa";
    descriptionShort = "A picatinny optic rail mount for the HK G3 family of rifles";
    scope = 2;
  };

  class sct_wmod_component_hk_tac: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_hk_tac";
    picture = "\sct_wmod\data\components\hk_tac.paa";
    descriptionShort = "A picatinny rail adapter handguard for the HK MP5 rifles";
    scope = 2;
  };

  class sct_wmod_component_ag_c: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_agc_full";
    picture = "\sct_wmod\data\components\ag_c.paa";
    descriptionShort = "A 40mm underbarrel grenade launcher, from which the M320 is derived";
    scope = 2;
  };

  class sct_wmod_component_sig_ris: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_sig_ris";
    picture = "\sct_wmod\data\components\sig_ris.paa";
    descriptionShort = "A picatinny optic rail mount for the SIG SG 550 family of rifles";
    scope = 2;
  };

  class sct_wmod_component_sig_tac: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_sig_tac";
    picture = "\sct_wmod\data\components\sig_tac.paa";
    descriptionShort = "A picatinny rail adapter handguard for the SIG SG 550 family of rifles";
    scope = 2;
  };

  class sct_wmod_component_dovetail_rail: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_dovetail_rail_full";
    picture = "\sct_wmod\data\components\dovetail_rail.paa";
    descriptionShort = "An optic mounting rail kit for the AK family of rifles (non-removable)";
    scope = 2;
  };

  //class sct_wmod_component_picatinny_rail: sct_wmod_ccore {
  //  author = "ScottyThePilot";
  //  displayName = "$STR_sct_wmod_c_picatinny_rail_full";
  //  picture = "\sct_wmod\data\components\picatinny_rail.paa";
  //  descriptionShort = "A picatinny rail kit for many kinds of weapons (non-removable)";
  //  scope = 2;
  //};

  class sct_wmod_component_eglm: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_eglm_full";
    picture = "\sct_wmod\data\components\eglm.paa";
    descriptionShort = "A 40mm underbarrel grenade launcher for the FN SCAR, Remington ACR, and similar rifles";
    scope = 2;
  };

  class sct_wmod_component_kv04: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_kv04";
    picture = "\sct_wmod\data\components\kv04.paa";
    descriptionShort = "A side-mounted picatinny rail adapter for the AK family of rifles";
    scope = 2;
  };

  class sct_wmod_component_pk_ris: sct_wmod_ccore {
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_pk_ris_full";
    picture = "\sct_wmod\data\components\pk_ris.paa";
    descriptionShort = "A picatinny optic rail mount for the PKM, PKP, and other Klashnikov machine guns";
    scope = 2;
  };
};

class sct_wmod_defines {
  #define COMPONENT(ID,CLASSNAME) \
    class ID { className = #CLASSNAME; }
  #define COMPONENT_NAMED(ID,CLASSNAME,NAME) \
    class ID { className = #CLASSNAME; displayName = NAME; }
  #define COMPONENT_NAMED_NOATTACH(ID,CLASSNAME,NAME) \
    class ID { className = #CLASSNAME; displayName = NAME; disableAttach = 1; }
  #define COMPONENT_NAMED_NODETACH(ID,CLASSNAME,NAME) \
    class ID { className = #CLASSNAME; displayName = NAME; disableDetach = 1; }

  class WeaponComponents {
    #include "WeaponComponents.hpp"
  };

  #define MEMBER0(ID) class ID { components[] = {}; }
  #define MEMBER1(ID,M1) class ID { components[] = { #M1 }; }
  #define MEMBER2(ID,M1,M2) class ID { components[] = { #M1, #M2 }; }
  #define MEMBER3(ID,M1,M2,M3) class ID { components[] = { #M1, #M2, #M3 }; }
  #define MEMBER4(ID,M1,M2,M3,M4) class ID { components[] = { #M1, #M2, #M3, #M4 }; }

  class WeaponGroups {
    #include "WeaponGroupsA3.hpp"
    #include "WeaponGroupsAegis.hpp"
    #include "WeaponGroupsCUP.hpp"
    #include "WeaponGroupsLXWS.hpp"
    #include "WeaponGroupsNIArms.hpp"
    #include "WeaponGroupsRHS.hpp"
  };
};
