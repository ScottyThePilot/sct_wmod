// Creates a new ACE Interaction for attaching or detaching a component
params ["_mode", "_id", "_weaponFrom", "_weaponTo", "_c"];
private _c = configFile >> "sct_wmod_defines" >> "WeaponComponents" >> _c;
private _component = getTextRaw (_c >> "className");
private _componentName = getText (_c >> "displayName");
private _attachmentsRemove = getArray (_c >> "attachmentSlots");

[
  _id,
  switch (_mode) do {
    case "attach": { format [localize "STR_sct_wmod_Attach", _componentName] };
    case "detach": { format [localize "STR_sct_wmod_Detach", _componentName] };
  },
  getTextRaw (configFile >> "CfgWeapons" >> _component >> "picture"),
  {
    private _args = [_this select 1] + (_this select 2);
    private _barText = switch (_args select 1) do {
      case "attach": { localize "STR_sct_wmod_Attaching" };
      case "detach": { localize "STR_sct_wmod_Detaching" };
    };

    // TODO: add CBA setting for changing the progress bar time
    [SCT_wmod_actionLength, _args, {
      (_this select 0) call sct_wmod_fnc_action
    }, {}, _barText, {
      (_this select 0) call sct_wmod_fnc_actionCondition
    }] call ace_common_fnc_progressBar;
  },
  { ([_this select 1] + (_this select 2)) call sct_wmod_fnc_actionCondition },
  {},
  [_mode, _weaponFrom, _weaponTo, _component, _attachmentsRemove]
] call ace_interact_menu_fnc_createAction
