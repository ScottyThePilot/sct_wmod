#include "..\script_component.hpp"

params ["_player", "_mode", "", "", "_component", "_componentName", "_toolsRequired"];

if (_mode == "attach" && {
  _component isNotEqualTo QCLASS_COMPONENT_ITEM_FAKE
} && {
  !(_component in items _player)
}) exitWith {
  // Failed because the component item was not in the player's inventory
  (format [
    localize PLSTRING(ComponentNotInInventory),
    _componentName
  ]) call CBA_fnc_notify;
};

private _missingToolsRequired = [_player, _toolsRequired] call PFUNC(getMissingToolsRequired);
if (_missingToolsRequired isNotEqualTo []) exitWith {
  // Failed because a required tool was not in the player's inventory
  (format [
    localize PLSTRING(ToolsNotInInventory),
    _missingToolsRequired apply { _x select 1 } joinString ", "
  ]) call CBA_fnc_notify;
};

(format [
  switch (_mode) do {
    case "attach": { localize PLSTRING(AttachFailure) };
    case "detach": { localize PLSTRING(DetachFailure) };
  },
  _componentName
]) call CBA_fnc_notify;
