#include "..\script_component.hpp"

[
  QVAR_MODIFICATION_ENABLED,
  "CHECKBOX",
  [
    RLSTRING(setting_modificationEnabled_name),
    RLSTRING(setting_modificationEnabled_description)
  ],
  RLSTRING(settings_category_name),
  true,
  1
] call CBA_fnc_addSetting;

[
  QVAR_ACTION_LENGTH,
  "SLIDER",
  [
    RLSTRING(setting_actionLength_name),
    RLSTRING(setting_actionLength_description)
  ],
  RLSTRING(settings_category_name),
  [0, 60, 10, 2],
  1
] call CBA_fnc_addSetting;

[
  QVAR_NEED_FOREGRIP_ITEMS,
  "CHECKBOX",
  [
    RLSTRING(setting_needForegripItems_name),
    RLSTRING(setting_needForegripItems_description)
  ],
  RLSTRING(settings_category_name),
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
    RLSTRING(setting_mergeM320Family_name),
    RLSTRING(setting_mergeM320Family_description)
  ],
  RLSTRING(settings_category_name),
  false,
  1,
  {
    RESET_FRAMEWORK_DATA;
  }
] call CBA_fnc_addSetting;
