#include "..\script_component.hpp"

params ["_player", "_mode", "", "", "_component", "_componentName"];
private _template = if (_mode == "attach" && !(_component in items _player)) then {
  // Failed because the component item was not in the player's inventory
  localize PLSTRING(NotInInventory)
} else {
  switch (_mode) do {
    case "attach": { localize PLSTRING(AttachFailure) };
    case "detach": { localize PLSTRING(DetachFailure) };
  };
};

(format [_template, _componentName]) call CBA_fnc_notify;
