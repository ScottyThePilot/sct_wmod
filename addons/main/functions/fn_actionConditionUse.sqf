#include "..\script_component.hpp"

params ["_player", "_mode", "_weaponFrom", "_weaponTo", "_componentsAttach", "_componentsDetach", "_toolsRequired"];

private _missingComponentsRequired = [_player, _componentsAttach] call RFUNC(getMissingComponentsRequired);
if (_missingComponentsRequired isNotEqualTo []) exitWith { false };

private _missingToolsRequired = [_player, _toolsRequired] call RFUNC(getMissingToolsRequired);
if (_missingToolsRequired isNotEqualTo []) exitWith { false };

_this call RFUNC(actionCondition)
