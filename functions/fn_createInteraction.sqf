// Creates a new ACE Interaction for attaching or detaching a component
params ["_mode", "_id", "_weaponFrom", "_weaponTo", "_c"];
private _componentClass = configFile >> "sct_wmod_defines" >> "WeaponComponents" >> _c;
private _findConfig = { _this select (_this findIf { !isNull _x }) };

private _component = getTextRaw (_componentClass >> "className");

private _componentName = getText ([
  _componentClass >> "displayName",
  configFile >> "CfgWeapons" >> _component >> "displayName",
  configFile >> "CfgMagazines" >> _component >> "displayName"
] call _findConfig);

private _componentPicture = getTextRaw ([
  _componentClass >> "picture",
  configFile >> "CfgWeapons" >> _component >> "picture",
  configFile >> "CfgMagazines" >> _component >> "picture"
] call _findConfig);

[
  _id,
  format [localize (switch (_mode) do {
    case "attach": { "STR_sct_wmod_Attach" };
    case "detach": { "STR_sct_wmod_Detach" };
  }), _componentName],
  _componentPicture,
  {
    private _args = [_this select 1] + (_this select 2);
    private _barText = localize (switch (_args select 1) do {
      case "attach": { "STR_sct_wmod_Attaching" };
      case "detach": { "STR_sct_wmod_Detaching" };
    });

    [SCT_wmod_actionLength, _args, {
      (_this select 0) call sct_wmod_fnc_action
    }, {
      (_this select 0) call sct_wmod_fnc_actionFail
    }, _barText, {
      (_this select 0) call sct_wmod_fnc_actionConditionUse
    }] call ace_common_fnc_progressBar;
  },
  { ([_this select 1] + (_this select 2)) call sct_wmod_fnc_actionCondition },
  {},
  [_mode, _weaponFrom, _weaponTo, _component, _componentName]
] call ace_interact_menu_fnc_createAction
