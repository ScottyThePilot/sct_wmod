[
  "SCT_wmod_modificationEnabled",
  "CHECKBOX",
  "$STR_sct_wmod_EnableModificationSetting",
  "Scotty's ACE Weapon Modification",
  true,
  1
] call CBA_fnc_addSetting;

[
  "SCT_wmod_actionLength",
  "SLIDER",
  "$STR_sct_wmod_ActionLengthSetting",
  "Scotty's ACE Weapon Modification",
  [0, 60, 10, 1],
  1
] call CBA_fnc_addSetting;
