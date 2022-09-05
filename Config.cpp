class CfgPatches {
  class sct_wmod {
    name = "Scotty's ACE Weapon Modification";
    author = "ScottyThePilot";
    authorUrl = "https://steamcommunity.com/id/scottythepilot/";
    url = "";
    requiredAddons[] = {
      "cba_main",
      "ace_common",
      "ace_interact_menu",
      "ace_interaction"
    };
    version = 1.1;
    versionStr = "1.1.0";
    versionAr[] = { 1, 1, 0 };
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
      class createInteraction {};
      class getComponentActions {};
      class initActions {};
      class initSettings {};
      class weaponsItems {};
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
          modifierFunction = "_this select 3 set [2, getText (configFile >> 'CfgWeapons' >> currentWeapon (_this select 0) >> 'picture')];";
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

  class sct_wmod_component_b13: sct_wmod_ccore {
    scope = 2;
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_b13";
    picture = "\sct_wmod\data\components\b13.paa";
    descriptionShort = "A side-mounted picatinny rail adaptor for the AK family of rifles";
  };

  class sct_wmod_component_b33: sct_wmod_ccore {
    scope = 2;
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_b33";
    picture = "\sct_wmod\data\components\b33.paa";
    descriptionShort = "A reciever cover with integrated picatinny rail for the AK family of rifles";
  };

  class sct_wmod_component_carryhandle: sct_wmod_ccore {
    scope = 2;
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_carryhandle";
    picture = "\sct_wmod\data\components\carryhandle.paa";
    descriptionShort = "A carryhandle unit with integrated sight designed for the M4 and M16 series of rifles";
  };

  class sct_wmod_component_gp25: sct_wmod_ccore {
    scope = 2;
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_gp25";
    picture = "\sct_wmod\data\components\gp25.paa";
    descriptionShort = "A 40mm under-barrel grenade launcher for the AK family of rifles";
  };

  class sct_wmod_component_m14_rail: sct_wmod_ccore {
    scope = 2;
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_m14_rail";
    picture = "\sct_wmod\data\components\m14_rail.paa";
    descriptionShort = "A side-mounted picatinny rail adaptor for the M14";
  };

  class sct_wmod_component_m14_ris: sct_wmod_ccore {
    scope = 2;
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_m14_ris";
    picture = "\sct_wmod\data\components\m14_ris.paa";
    descriptionShort = "A top-mounted picatinny rail system for the M14";
  };

  class sct_wmod_component_m203: sct_wmod_ccore {
    scope = 2;
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_m203";
    picture = "\sct_wmod\data\components\m203.paa";
    descriptionShort = "A 40mm underbarrel grenade launcher for the AR-15 family of rifles";
  };

  class sct_wmod_component_m320: sct_wmod_ccore {
    scope = 2;
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_m320";
    picture = "\sct_wmod\data\components\m320.paa";
    descriptionShort = "A 40mm underbarrel grenade launcher for the AR-15 family of rifles";
  };

  class sct_wmod_component_npz: sct_wmod_ccore {
    scope = 2;
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_npz";
    picture = "\sct_wmod\data\components\npz.paa";
    descriptionShort = "A side-mounted picatinny rail adaptor for the AK family of rifles";
  };

  class sct_wmod_component_zenit: sct_wmod_ccore {
    scope = 2;
    author = "ScottyThePilot";
    displayName = "$STR_sct_wmod_c_zenit";
    picture = "\sct_wmod\data\components\zenit.paa";
    descriptionShort = "A picatinny rail adaptor handguard for the AK family of rifles";
  };
};

class sct_wmod_defines {
  #include "WeaponComponents.hpp"

  class WeaponGroups {
    #include "WeaponGroupsRHS.hpp"
  };
};
