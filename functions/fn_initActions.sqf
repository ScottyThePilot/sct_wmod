// Action: [mode: "attach"|"detach", id, fromWeapon, toWeapon, componentId]

private _actionsCached = missionNamespace getVariable "sct_wmod_actions";
if (!isNil "_actionsCached") exitWith { _actionsCached };

// Assembles a hashmap of configs and their config names by looking at the
// classes under the given path in the game config, campaign config, and mission config.
// Entries take precedence in the following order: `missionConfigFile`, `campaignConfigFile`, configFile`
private _collectConfigs = {
  private _config = configFile;
  { _config = _config >> _x } forEach _this;

  private _campaignConfig = campaignConfigFile;
  { _campaignConfig = _campaignConfig >> _x } forEach _this;

  private _missionConfig = missionConfigFile;
  { _missionConfig = _missionConfig >> _x } forEach _this;

  private _map = createHashMap;
  private _f = { _map set [configName _x, _x] };
  _f forEach ("true" configClasses _config);
  _f forEach ("true" configClasses _campaignConfig);
  _f forEach ("true" configClasses _missionConfig);

  _map
};

private _groups = ["sct_wmod_defines", "WeaponGroups"] call _collectConfigs;
private _components = ["sct_wmod_defines", "WeaponComponents"] call _collectConfigs;

private _getGroupChildren = {
  ("true" configClasses _this) select {
    // Filter out group weapons that do not have a valid class with them
    // (maybe the mod for that item is not loaded?)
    isClass (configFile >> "CfgWeapons" >> configName _x)
  } apply {
    // TODO: don't filter components
    [configName _x, (getArray (_x >> "components")) select {
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

      // Attach/Detach
      if (count _componentsA > count _componentsB) then {
        private _diff = _componentsA - _componentsB;
        if ((count _diff) isEqualTo 1) then {
          private _component = _diff select 0;
          private _componentClass = _components get _component;
          if (getNumber (_componentClass >> "disableAttach") == 0) then {
            private _id = "sct_wmod_action_attach_" + str _idCounter;
            _actions pushBack ["attach", _id, _classB, _classA, _component];
          };
          if (getNumber (_componentClass >> "disableDetach") == 0) then {
            private _id = "sct_wmod_action_detach_" + str _idCounter;
            _actions pushBack ["detach", _id, _classA, _classB, _component];
          };
          _idCounter = _idCounter + 1;
        };
      };
    } forEach _children;
  } forEach _children;
} forEach _groups;

missionNamespace setVariable ["sct_wmod_actions", _actions];
_actions
