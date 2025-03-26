#include "..\script_component.hpp"

params ["_weapon"];

private _weaponComponentsMap = [
  missionNamespace,
  QVAR_WEAPON_COMPONENTS_MAP,
  { createHashMap }
] call PFUNC(getCached);

_weaponComponentsMap getOrDefaultCall [_weapon, {
  ([] call PFUNC(getFrameworkDataCached)) params ["_actions", "_groups", "_components"];
  private _weaponComponents = [];

  {
    private _groupKey = _x;
    private _groupEntries = _y;
    private _groupEntryWeaponIndex = _groupEntries findIf { (_x select 0) isEqualTo _weapon };
    if (_groupEntryWeaponIndex isNotEqualTo -1) then {
      private _groupEntryWeapon = _groupEntries select _groupEntryWeaponIndex;
      _groupEntryWeapon params ["_groupEntryWeaponKey", "_groupEntryWeaponComponents"];
      _weaponComponents insert [-1, _groupEntryWeaponComponents, true];
    };
  } forEach _groups;

  if (_weaponComponents isEqualTo []) then {
    localize PLSTRING(None)
  } else {
    (_weaponComponents apply {
      private _componentConfig = _components get _x;
      getText (_componentConfig >> "displayName")
    }) joinString ", "
  }
}, true]
