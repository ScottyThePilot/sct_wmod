#include "..\script_component.hpp"

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

// Tools: HashMap<String, [ToolItems: Array<String>, DisplayName: String]>
private _tools = [QCLASS_DEFINES, "WeaponTools"] call _collectConfigs;
private _tools = createHashMapFromArray (_tools apply {
  [_x, [
    getArray (_y >> "items") select {
      isClass (configFile >> "CfgWeapons" >> _x) ||
      isClass (configFile >> "CfgMagazines" >> _x)
    },
    getText (_y >> "displayName")
  ]]
});

// Components: HashMap<String, Config>
private _components = [QCLASS_DEFINES, "WeaponComponents"] call _collectConfigs;
private _components = createHashMapFromArray (_components apply { [_x, _y] } select {
  _x params ["_componentKey", "_componentConfig"];
  isText (_componentConfig >> "className") && {
    private _componentClassName = getTextRaw (_componentConfig >> "className");
    _componentClassName isEqualTo QCLASS_COMPONENT_ITEM_FAKE ||
    isClass (configFile >> "CfgWeapons" >> _componentClassName) ||
    isClass (configFile >> "CfgMagazines" >> _componentClassName)
  }
});

// Groups: HashMap<String, Group>
// Group: [GroupEntryKey: String, GroupEntryComponents: Array<String>]
private _groups = [QCLASS_DEFINES, "WeaponGroups"] call _collectConfigs;
private _groups = createHashMapFromArray (_groups apply {
  private _groupKey = _x;
  [_groupKey, ("true" configClasses _y) select {
    isClass (configFile >> "CfgWeapons" >> configName _x)
  } apply {
    private _groupEntryKey = configName _x;
    private _groupEntryComponents = getArray (_x >> "components");
    private _unknownComponent = _groupEntryComponents findIf { !(_x in _components) };
    if (_unknownComponent isNotEqualTo -1) then {
      diag_log format [
        "sct_wmod: unknown component '%1' found in weapon group entry '%2' on weapon group '%3'",
        _groupEntryComponents select _unknownComponent, _groupEntryKey, _groupKey
      ];
      _groupEntryComponents = nil;
    };

    [_groupEntryKey, _groupEntryComponents]
  } select {
    !isNil { _x select 1 }
  }]
});

private _actions = [];
private _idCounter = 0;

{
  private _children = _y;
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
            private _id = QPGVAR(action_attach_) + str _idCounter;
            _actions pushBack ["attach", _id, _classB, _classA, _component];
          };
          if (getNumber (_componentClass >> "disableDetach") == 0) then {
            private _id = QPGVAR(action_detach_) + str _idCounter;
            _actions pushBack ["detach", _id, _classA, _classB, _component];
          };
          _idCounter = _idCounter + 1;
        };
      };
    } forEach _children;
  } forEach _children;
} forEach _groups;

[_actions, _groups, _components, _tools]
