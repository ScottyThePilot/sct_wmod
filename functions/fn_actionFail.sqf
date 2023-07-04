params ["_player", "_mode", "", "", "_component", "_componentName"];
private _text = if (_mode == "attach" && !(_component in items _player)) then {
  // Failed because the component item was not in the player's inventory
  (format [localize "STR_sct_wmod_NotInInventory", _componentName]) call CBA_fnc_notify;
};
