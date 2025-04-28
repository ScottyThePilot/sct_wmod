#include "..\script_component.hpp"

// Creates a new ACE Interaction for attaching or detaching a component
params ["_mode", "_id", "_weaponFrom", "_weaponTo", "_componentsAttach", "_componentsDetach"];
private _componentsData = GET_FRAMEWORK_DATA_COMPONENTS;

private _picture = switch (true) do {
  case (count _componentsAttach isEqualTo 1 && _componentsDetach isEqualTo []): {
    (_componentsData get (_componentsAttach select 0)) select 2
  };
  case (_componentsAttach isEqualTo [] && count _componentsDetach isEqualTo 1): {
    (_componentsData get (_componentsDetach select 0)) select 2
  };
  case (count _componentsAttach isEqualTo 1 && count _componentsDetach isEqualTo 1): {
    (_componentsData get (_componentsDetach select 0)) select 2
  };
  default { "" };
};

if (isNil "_picture" || { _picture isEqualTo "" }) then {
  _picture = getTextRaw (configFile >> "CfgWeapons" >> _weaponTo >> "picture");
};

private _componentsFull = _componentsAttach + _componentsDetach;
private _toolsRequired = flatten (_componentsFull apply { (_componentsData get _x) select 3 });
private _toolsRequired = _toolsRequired arrayIntersect _toolsRequired;

[
  _id,
  [
    "interaction",
    [_mode, _weaponFrom, _weaponTo, _componentsAttach, _componentsDetach]
  ] call RFUNC(actionMessageText),
  _picture,
  {
    private _args = [_this select 1] + (_this select 2);
    _args params ["_player", "_mode", "_weaponFrom", "_weaponTo", "_componentsAttach", "_componentsDetach", "_toolsRequired"];

    if (_args call RFUNC(actionConditionUse)) then {
      private _componentsCount = count _componentsAttach + count _componentsDetach;

      private _barText = [
        "progressbar",
        [_mode, _weaponFrom, _weaponTo, _componentsAttach, _componentsDetach]
      ] call RFUNC(actionMessageText);

      [VAR_ACTION_LENGTH * _componentsCount, _args, {
        (_this select 0) call RFUNC(action)
      }, {
        (_this select 0) call RFUNC(actionFail)
      }, _barText, {
        (_this select 0) call RFUNC(actionConditionUse)
      }] call ace_common_fnc_progressBar;
    } else {
      _args call RFUNC(actionFail);
    };
  },
  {
    private _args = [_this select 1] + (_this select 2);
    _args call RFUNC(actionCondition)
  },
  {},
  [_mode, _weaponFrom, _weaponTo, _componentsAttach, _componentsDetach, _toolsRequired]
] call ace_interact_menu_fnc_createAction
