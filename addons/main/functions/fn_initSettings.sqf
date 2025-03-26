#include "..\script_component.hpp"

[
  QVAR_MODIFICATION_ENABLED,
  "CHECKBOX",
  PCSTRING(EnableModificationSetting),
  PCSTRING(SettingsCategoryName),
  true,
  1
] call CBA_fnc_addSetting;

[
  QVAR_ACTION_LENGTH,
  "SLIDER",
  PCSTRING(ActionLengthSetting),
  PCSTRING(SettingsCategoryName),
  [0, 60, 10, 1],
  1
] call CBA_fnc_addSetting;
