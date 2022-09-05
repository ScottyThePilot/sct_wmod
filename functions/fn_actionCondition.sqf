// Determines whether or not the player can detach or attach a component at this moment
params ["_player", "_mode", "_weaponFrom", "", "_component", ""];
// The check against the weapon's `baseWeapon` is to prevent hidden attachment variants
// of a weapon from causing the check to fail
// Unfortunately, this relies on the weapon being defined correctly
private _currentWeapon = currentWeapon _player;
private _currentWeaponBase = getTextRaw (configFile >> "CfgWeapons" >> _currentWeapon >> "baseWeapon");
(_weaponFrom == _currentWeapon || _weaponFrom == _currentWeaponBase) && (switch (_mode) do {
  case "attach": { _component in items _player };
  case "detach": { _player canAdd _component };
  default { throw "expected one of 'attach' or 'detach'" };
})
