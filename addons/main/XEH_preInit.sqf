#include ".\script_component.hpp"

[] call COMPILE_SCRIPT(PATHTO(initSettings.sqf));



private _isWeaponComponentItem = toString {
  getNumber (_x >> QRGVAR(isWeaponComponentItem)) isEqualTo 1
};

private _weaponComponentItems = (
  (_isWeaponComponentItem configClasses (configFile >> "CfgWeapons")) +
  (_isWeaponComponentItem configClasses (configFile >> "CfgMagazines"))
) apply { configName _x };

[
  _weaponComponentItems,
  localize RLSTRING(arsenal_components),
  QPATHTO(data\ui\icon_weapon_components_ca.paa)
] call ace_arsenal_fnc_addRightPanelButton;
