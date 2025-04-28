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
      QRGVAR(component_3gl),
      QRGVAR(component_b13),
      QRGVAR(component_b33),
      QRGVAR(component_carryhandle),
      QRGVAR(component_gp25),
      QRGVAR(component_m14_rail),
      QRGVAR(component_m14_ris),
      QRGVAR(component_m21_rail),
      QRGVAR(component_m203),
      QRGVAR(component_m320),
      QRGVAR(component_npz),
      QRGVAR(component_zenit),
      QRGVAR(component_mtk),
      QRGVAR(component_fal_rail),
      QRGVAR(component_hk_ris1),
      QRGVAR(component_hk_ris2),
      QRGVAR(component_hk_tac),
      QRGVAR(component_ag_c),
      QRGVAR(component_sig_ris),
      QRGVAR(component_sig_tac),
      QRGVAR(component_dovetail_rail),
      QRGVAR(component_picatinny_rail),
      QRGVAR(component_eglm),
      QRGVAR(component_kv04),
      QRGVAR(component_pk_ris),
      QRGVAR(component_fal_gl),
      QRGVAR(component_six12),
      QRGVAR(component_msbs_gp),
      QRGVAR(component_masterkey),
      QRGVAR(component_afg),
      QRGVAR(component_vfg)
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

        class dependencies {
          CBA[] = { "cba_main", { 3, 18, 0 }, "(true)" };
          ACE[] = { "ace_main", { 3, 18, 0 }, "(true)" };
        };
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
      class actionMessageText {};
      class createInteraction {};
      class createInteractions {};
      class getCached {};
      class getCompatibleWeaponsNames {};
      class getComponentsItems {};
      class getFrameworkData {};
      class getFrameworkDataCached {};
      class getMissingComponentsRequired {};
      class getMissingToolsRequired {};
      class getWeaponComponentsNames {};
      class resetFrameworkDataCache {};
      class textList {};
    };
  };
};

class Extended_PreInit_EventHandlers {
  class ADDON {
    init = QUOTE(call COMPILE_SCRIPT(PATHTO(XEH_preInit.sqf)));
  };
};

class ace_arsenal_stats {
  class statBase;

  class RGVAR(weapon_components): statBase {
    scope = 2;
    displayName = RCSTRING(arsenal_components);
    priority = 1.15;
    showText = 1;
    textStatement = QUOTE((configName (_this select 1) call RFUNC(getWeaponComponentsNames)));
    tabs[] = { { 0, 1, 2 }, {} };
  };

  class RGVAR(compatible_weapons): statBase {
    scope = 2;
    displayName = RCSTRING(arsenal_compatible_weapons);
    priority = 1.16;
    showText = 1;
    textStatement = QUOTE((configName (_this select 1) call RFUNC(getCompatibleWeaponsNames)));
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
  // Determines which weapon components are considered 'foregrips' for the purposes of the 'Foregrip Items Needed' setting
  // (for internal use, this API may change or disappear without warning)
  foregripComponents[] = { "afg", "vfg", "afg_rhs", "vfg_rhs" };

  class WeaponComponents {
    #include "./defines/WeaponComponents.hpp"
  };

  class WeaponGroups {
    #include "./defines/WeaponGroupsA3.hpp"
    #include "./defines/WeaponGroupsAegis.hpp"
    #include "./defines/WeaponGroupsAtlas.hpp"
    #include "./defines/WeaponGroupsCUP.hpp"
    #include "./defines/WeaponGroupsJCA.hpp"
    #include "./defines/WeaponGroupsLXWS.hpp"
    #include "./defines/WeaponGroupsNIArms.hpp"
    #include "./defines/WeaponGroupsRHS.hpp"
  };

  class WeaponTools {
    #include "./defines/WeaponTools.hpp"
  };
};
