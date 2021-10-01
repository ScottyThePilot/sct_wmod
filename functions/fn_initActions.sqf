// Action: [mode: "attach"|"detach", id, fromWeapon, toWeapon, componentId]

private _groupsConfig = (configFile >> "sct_wmod_defines" >> "WeaponGroups") call BIS_fnc_getCfgSubClasses;
private _groupsMissionConfig = (missionConfigFile >> "sct_wmod_defines" >> "WeaponGroups") call BIS_fnc_getCfgSubClasses;
_groupsConfig = (_groupsConfig - _groupsMissionConfig) apply {
  [_x, configFile >> "sct_wmod_defines" >> "WeaponGroups" >> _x]
};
_groupsMissionConfig = _groupsMissionConfig apply {
  [_x, missionConfigFile >> "sct_wmod_defines" >> "WeaponGroups" >> _x]
};

private _groups = createHashMapFromArray (_groupsConfig + _groupsMissionConfig);



private _componentsConfig = (configFile >> "sct_wmod_defines" >> "WeaponComponents") call BIS_fnc_getCfgSubClasses;
private _componentsMissionConfig = (missionConfigFile >> "sct_wmod_defines" >> "WeaponComponents") call BIS_fnc_getCfgSubClasses;
_componentsConfig = (_componentsConfig - _componentsMissionConfig) apply {
  [_x, configFile >> "sct_wmod_defines" >> "WeaponComponents" >> _x]
};
_componentsMissionConfig = _componentsMissionConfig apply {
  [_x, missionConfigFile >> "sct_wmod_defines" >> "WeaponComponents" >> _x]
};

private _components = createHashMapFromArray (_componentsConfig + _componentsMissionConfig);



private _getGroupChildren = {
  (_this call BIS_fnc_getCfgSubClasses) select {
    // Filter out group weapons that do not have a valid class with them
    // (maybe the mod for that item is not loaded?)
    isClass (configFile >> "CfgWeapons" >> _x)
  } apply {
    [_x, (getArray (_this >> _x >> "components")) select {
      // Filter out components that do not have a valid class with them
      // (maybe the mod for that item is not loaded?)
      private _c = getTextRaw ((_components get _x) >> "className");
      isClass (configFile >> "CfgWeapons" >> _c) ||
      isClass (configFile >> "CfgMagazines" >> _c)
    }]
  }
};

private _actions = [];
private _idCounter = 0;

{
  private _children = _y call _getGroupChildren;
  {
    _x params ["_classA", "_componentsA"];
    {
      _x params ["_classB", "_componentsB"];
      if (count _componentsA > count _componentsB) then {
        private _diff = _componentsA - _componentsB;
        if ((count _diff) isEqualTo 1) then {
          private _component = _diff select 0;
          private _idAttach = format ["sct_wmod_action_attach_%1", _idCounter];
          private _idDetach = format ["sct_wmod_action_detach_%1", _idCounter];
          _actions pushBack ["detach", _idDetach, _classA, _classB, _component];
          _actions pushBack ["attach", _idAttach, _classB, _classA, _component];
          _idCounter = _idCounter + 1;
        };
      };
    } forEach _children;
  } forEach _children;
} forEach _groups;

_actions
