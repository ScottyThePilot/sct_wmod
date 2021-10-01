// Determines whether or not the player can detach or attach a component at this moment
params ["_player", "_mode", "_weaponFrom", "", "_component", ""];
(_weaponFrom == currentWeapon _player) && (switch (_mode) do {
  case "attach": { _component in items _player };
  case "detach": { _player canAdd _component };
})
