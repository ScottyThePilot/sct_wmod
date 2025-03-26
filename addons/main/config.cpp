#include "script_component.hpp"

class CfgPatches {
  class ADDON {
    name = ADDON_NAME;
    author = "ScottyThePilot";
    authors[] = { "ScottyThePilot" };
    url = "https://github.com/ScottyThePilot/sct_wmod";
    VERSION_CONFIG;
    requiredVersion = REQUIRED_VERSION;
    requiredAddons[] = {
      "cba_main",
      "ace_common",
      "ace_arsenal",
      "ace_interact_menu",
      "ace_interaction"
    };
    units[] = {};
    weapons[] = {
      QPGVAR(component_3gl),
      QPGVAR(component_b13),
      QPGVAR(component_b33),
      QPGVAR(component_carryhandle),
      QPGVAR(component_gp25),
      QPGVAR(component_m14_rail),
      QPGVAR(component_m14_ris),
      QPGVAR(component_m21_rail),
      QPGVAR(component_m203),
      QPGVAR(component_m320),
      QPGVAR(component_npz),
      QPGVAR(component_zenit),
      QPGVAR(component_mtk),
      QPGVAR(component_fal_rail),
      QPGVAR(component_hk_ris1),
      QPGVAR(component_hk_ris2),
      QPGVAR(component_hk_tac),
      QPGVAR(component_ag_c),
      QPGVAR(component_sig_ris),
      QPGVAR(component_sig_tac),
      QPGVAR(component_dovetail_rail),
      QPGVAR(component_picatinny_rail),
      QPGVAR(component_eglm),
      QPGVAR(component_kv04),
      QPGVAR(component_pk_ris),
      QPGVAR(component_fal_gl)
    };
  };

  // just in case anything expects the `sct_wmod` addon to still exist
  class PREFIX: ADDON {
    units[] = {};
    weapons[] = {};
  };
};

class CfgSettings {
  class CBA {
    class Versioning {
      class ADDON {
        main_addon = QUOTE(ADDON_MAIN);
      };
    };
  };
};

class CfgFunctions {
  class PREFIX {
    class functions {
      file = QPATHTO_FUNCS;
      class action {};
      class actionCondition {};
      class actionConditionUse {};
      class actionFail {};
      class createInteraction {};
      class getCached {};
      class getCompatibleWeaponsNames {};
      class getComponentActions {};
      class getFrameworkData {};
      class getFrameworkDataCached {};
      class getWeaponComponentsNames {};
      class initSettings {};
    };
  };
};

class Extended_PreInit_EventHandlers {
  class PGVAR(init_settings) {
    init = QUOTE(call PFUNC(initSettings));
  };
};

class ace_arsenal_stats {
  class statBase;

  class PGVAR(weapon_components): statBase {
    scope = 2;
    displayName = PCSTRING(Components);
    priority = 1.15;
    showText = 1;
    textStatement = QUOTE((configName (_this select 1) call PFUNC(getWeaponComponentsNames)));
    tabs[] = { { 0, 1, 2 }, {} };
  };

  class PGVAR(compatible_weapons): statBase {
    scope = 2;
    displayName = PCSTRING(CompatibleWeapons);
    priority = 1.16;
    showText = 1;
    textStatement = QUOTE((configName (_this select 1) call PFUNC(getCompatibleWeaponsNames)));
    tabs[] = { { 0, 1, 2 }, {} };
  };
};

class CfgVehicles {
  #include "CfgVehicles.hpp"
};

class CfgWeapons {
  #include "CfgWeapons.hpp"
};

class CLASS_DEFINES {
  class WeaponComponents {
    #include "./defines/WeaponComponents.hpp"
  };

  class WeaponGroups {
    #include "./defines/WeaponGroupsA3.hpp"
    #include "./defines/WeaponGroupsAegis.hpp"
    #include "./defines/WeaponGroupsCUP.hpp"
    #include "./defines/WeaponGroupsLXWS.hpp"
    #include "./defines/WeaponGroupsNIArms.hpp"
    #include "./defines/WeaponGroupsRHS.hpp"
  };
};
