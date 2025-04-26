#include "..\script_component.hpp"

params ["_player", "_mode", "_weaponFrom", "_weaponTo", "_componentsAttach", "_componentsDetach", "_toolsRequired"];

private _missingComponentsRequired = [_player, _componentsAttach] call RFUNC(getMissingComponentsRequired);
if (_missingComponentsRequired isNotEqualTo []) exitWith {
  // Failed because the component item was not in the player's inventory
  (format [
    localize RLSTRING(notify_missing_components),
    (_missingComponentsRequired apply { _x select 1 }) call RFUNC(textList)
  ]) call CBA_fnc_notify;
};

private _missingToolsRequired = [_player, _toolsRequired] call RFUNC(getMissingToolsRequired);
if (_missingToolsRequired isNotEqualTo []) exitWith {
  // Failed because a required tool was not in the player's inventory
  (format [
    localize RLSTRING(notify_missing_tools),
    (_missingToolsRequired apply { _x select 1 }) call RFUNC(textList)
  ]) call CBA_fnc_notify;
};

([
  ACTION_MESSAGE_TEMPLATES(notify_failure),
  [_mode, _weaponFrom, _weaponTo, _componentsAttach, _componentsDetach]
] call RFUNC(actionMessageText)) call CBA_fnc_notify;
