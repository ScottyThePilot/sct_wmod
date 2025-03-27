#include "..\script_component.hpp"

params ["_player", "_mode", "", "", "_component", "", "_toolsRequired"];

if (_mode == "attach" && {
  _component isNotEqualTo QCLASS_COMPONENT_ITEM_FAKE
} && {
  !(_component in items _player)
}) exitWith { false };

private _missingToolsRequired = [_player, _toolsRequired] call PFUNC(getMissingToolsRequired);
if (_missingToolsRequired isNotEqualTo []) exitWith { false };

_this call PFUNC(actionCondition)
