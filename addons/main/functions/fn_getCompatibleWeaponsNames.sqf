#include "..\script_component.hpp"

params ["_weapon"];

private _compatibleWeaponsMap = [
  missionNamespace,
  QVAR_COMPATIBLE_WEAPONS_MAP,
  { createHashMap }
] call PFUNC(getCached);

_compatibleWeaponsMap getOrDefaultCall [_weapon, {
  ([] call PFUNC(getFrameworkDataCached)) params ["_actions", "_groups", "_components"];
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
    localize PLSTRING(None)
  } else {
    ((_compatibleWeapons - [_weapon]) apply {
      getText (configFile >> "CfgWeapons" >> _x >> "displayName")
    }) joinString endl
  }
}, true]
