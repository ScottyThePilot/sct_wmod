#include "..\script_component.hpp"

params ["_weapon"];

private _weaponComponentsMap = [
  missionNamespace,
  QVAR_WEAPON_COMPONENTS_MAP,
  { createHashMap }
] call RFUNC(getCached);

_weaponComponentsMap getOrDefaultCall [_weapon, {
  private _groupsData = GET_FRAMEWORK_DATA_GROUPS;
  private _componentsData = GET_FRAMEWORK_DATA_COMPONENTS;

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
  } forEach _groupsData;

  (_weaponComponents apply {
    (_componentsData get _x) select 1
  }) call RFUNC(textList)
}, true]
