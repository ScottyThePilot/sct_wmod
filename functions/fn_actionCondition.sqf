// Determines whether or not the player should see the attach/detach action
params ["_player", "", "_weaponFrom"];
// The check against the weapon's `baseWeapon` is to prevent hidden attachment variants
// of a weapon from causing the check to fail
// Unfortunately, this relies on the weapon being defined correctly
private _currentWeapon = currentWeapon _player;
private _currentWeaponBase = getTextRaw (configFile >> "CfgWeapons" >> _currentWeapon >> "baseWeapon");
_weaponFrom == _currentWeapon || _weaponFrom == _currentWeaponBase
