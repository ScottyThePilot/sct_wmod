params ["_weapon"];

private _compatibleWeaponsMap = [
  missionNamespace,
  "sct_wmod_compatibleWeaponsMap",
  { createHashMap }
] call sct_wmod_fnc_getCached;

_compatibleWeaponsMap getOrDefaultCall [_weapon, {
  ([] call sct_wmod_fnc_getFrameworkDataCached) params ["_actions", "_groups", "_components"];
  private _compatibleWeapons = [];

  {
    private _groupKey = _x;
    private _groupEntries = _y;
    if (_groupEntries findIf { (_x select 0) isEqualTo _weapon } isNotEqualTo -1) then {
      _compatibleWeapons insert [-1, _groupEntries apply { _x select 0 }, true];
    };
  } forEach _groups;

  private _compatibleWeapons = _compatibleWeapons - [_weapon];
  if (_compatibleWeapons isEqualTo []) then {
    localize "STR_sct_wmod_None"
  } else {
    ((_compatibleWeapons - [_weapon]) apply {
      getText (configFile >> "CfgWeapons" >> _x >> "displayName")
    }) joinString endl
  }
}, true]
