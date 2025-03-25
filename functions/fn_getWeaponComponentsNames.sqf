params ["_weapon"];

private _weaponComponentsMap = [
  missionNamespace,
  "sct_wmod_weaponComponentsMap",
  { createHashMap }
] call sct_wmod_fnc_getCached;

_weaponComponentsMap getOrDefaultCall [_weapon, {
  ([] call sct_wmod_fnc_getFrameworkDataCached) params ["_actions", "_groups", "_components"];
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
    localize "STR_sct_wmod_None"
  } else {
    (_weaponComponents apply {
      private _componentConfig = _components get _x;
      getText (_componentConfig >> "displayName")
    }) joinString ", "
  }
}, true]
