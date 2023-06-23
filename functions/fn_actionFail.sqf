params ["_player", "_mode", "", "", "_component", "_componentName"];
private _text = if (_mode == "attach" && !(_component in items _player)) then {
  // Failed because the component item was not in the player's inventory
  format [localize "STR_sct_wmod_NotInInventory", _componentName]
} else {
  // Failed for some other reason (player's weapon was somehow changed?)
  switch (_mode) do {
    case "attach": { format [localize "STR_sct_wmod_AttachFailure", _componentName] };
    case "detach": { format [localize "STR_sct_wmod_DetachFailure", _componentName] };
  }
};

_text call CBA_fnc_notify;
