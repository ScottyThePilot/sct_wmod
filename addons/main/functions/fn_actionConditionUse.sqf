#include "..\script_component.hpp"

params ["_player", "_mode", "_weaponFrom", "_weaponTo", "_componentsAttach", "_componentsDetach", "_toolsRequired"];

private _missingComponentsRequired = [_player, _componentsAttach] call PFUNC(getMissingComponentsRequired);
if (_missingComponentsRequired isNotEqualTo []) exitWith { false };

private _missingToolsRequired = [_player, _toolsRequired] call PFUNC(getMissingToolsRequired);
if (_missingToolsRequired isNotEqualTo []) exitWith { false };

_this call PFUNC(actionCondition)
