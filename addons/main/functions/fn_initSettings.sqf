#include "..\script_component.hpp"

[
  QVAR_MODIFICATION_ENABLED,
  "CHECKBOX",
  [
    PLSTRING(setting_modificationEnabled_name),
    PLSTRING(setting_modificationEnabled_description)
  ],
  PLSTRING(settings_category_name),
  true,
  1
] call CBA_fnc_addSetting;

[
  QVAR_ACTION_LENGTH,
  "SLIDER",
  [
    PLSTRING(setting_actionLength_name),
    PLSTRING(setting_actionLength_description)
  ],
  PLSTRING(settings_category_name),
  [0, 60, 10, 2],
  1
] call CBA_fnc_addSetting;

[
  QVAR_NEED_FOREGRIP_ITEMS,
  "CHECKBOX",
  [
    PLSTRING(setting_needForegripItems_name),
    PLSTRING(setting_needForegripItems_description)
  ],
  PLSTRING(settings_category_name),
  true,
  1,
  {
    RESET_FRAMEWORK_DATA;
  }
] call CBA_fnc_addSetting;

[
  QVAR_MERGE_M320_FAMILY,
  "CHECKBOX",
  [
    PLSTRING(setting_mergeM320Family_name),
    PLSTRING(setting_mergeM320Family_description)
  ],
  PLSTRING(settings_category_name),
  false,
  1,
  {
    RESET_FRAMEWORK_DATA;
  }
] call CBA_fnc_addSetting;
