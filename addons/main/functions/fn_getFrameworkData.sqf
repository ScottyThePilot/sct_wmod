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
  private _f = { _map set [toLowerANSI configName _x, _x] };
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
      private _itemConfig = _x call CBA_fnc_getItemConfig;

      if (getNumber (_itemConfig >> "scope") < 2) then {
        WARNING_1("tool item %1 exists, but is not scope 2",configName _itemConfig);
      };

      !isNull _itemConfig
    },
    getText (_y >> "displayName")
  ]]
});

// className: String?
// items: Array<String>
// displayName: String
// picture: String?
// toolsRequired: Array<String>?
// disableAttach: Number
// disableDetach: Number
// isFake: Number

// Components: HashMap<String, Config>
// Component: [ClassNames: Array<String>, DisplayName: String, Picture: String, ToolsRequired: String, AttachEnabled: bool, DetachEnabled: bool, IsFake: bool]
private _components = [QCLASS_DEFINES, "WeaponComponents"] call _collectConfigs;
private _components = createHashMapFromArray (_components apply {
  private _componentKey = _x;
  private _componentItems = getArray (_y >> "items");
  if (isText (_y >> "className")) then {
    _componentItems pushBackUnique getText (_y >> "className");
  };

  private _componentItems = _componentItems select {
    !isNull (_x call CBA_fnc_getItemConfig)
  } apply {
    toLowerANSI _x
  };

  private _componentItemConfigs = _componentItems apply {
    _x call CBA_fnc_getItemConfig
  };

  {
    if (getNumber (_x >> "scope") < 2) then {
      WARNING_1("component item %1 exists, but is not scope 2",configName _x);
    };
  } forEach _componentItemConfigs;

  private _displayName = if (isText (_y >> "displayName")) then {
    getText (_y >> "displayName")
  } else {
    private _displayNameIndex = _componentItemConfigs findIf { isText (_x >> "displayName") };
    if (_displayNameIndex isNotEqualTo -1) then {
      getText ((_componentItemConfigs select _displayNameIndex) >> "displayName")
    } else {
      ""
    }
  };

  private _picture = if (isText (_y >> "picture")) then {
    getTextRaw (_y >> "picture")
  } else {
    private _pictureIndex = _componentItemConfigs findIf { isText (_x >> "picture") };
    if (_pictureIndex isNotEqualTo -1) then {
      getTextRaw ((_componentItemConfigs select _pictureIndex) >> "picture")
    } else {
      ""
    }
  };

  private _toolsRequired = if (isArray (_y >> "toolsRequired")) then {
    getArray (_y >> "toolsRequired") apply {
      toLowerANSI _x
    } select {
      _x in _tools
    }
  } else {
    []
  };

  private _enableAttach = getNumber (_y >> "disableAttach") isNotEqualTo 1;
  private _enableDetach = getNumber (_y >> "disableDetach") isNotEqualTo 1;
  private _isFake = getNumber (_y >> "isFake") isEqualTo 1;

  private _actionLengthMultiplier = if (isNumber (_y >> "actionLengthMultiplier")) then {
    getNumber (_y >> "actionLengthMultiplier")
  } else {
    1.0
  };

  [_componentKey, [
    _componentItems,
    _displayName,
    _picture,
    _toolsRequired,
    _enableAttach,
    _enableDetach,
    _isFake,
    _y >> "MessageTemplates",
    _actionLengthMultiplier
  ]]
} select {
  _x params ["_componentKey", "_componentData"];
  _componentData params [
    "_componentItems",
    "_displayName",
    "_picture",
    "_toolsRequired",
    "_enableAttach",
    "_enableDetach",
    "_isFake",
    "_messageTemplatesConfig",
    "_actionLengthMultiplier"
  ];

  // filter out any entries with an empty item list that are not fake
  _componentItems isNotEqualTo [] || _isFake
});

// Groups: HashMap<String, Group>
// Group: [GroupEntryKey: String, GroupEntryComponents: Array<String>]
private _groups = [QCLASS_DEFINES, "WeaponGroups"] call _collectConfigs;
private _groups = createHashMapFromArray (_groups apply {
  private _groupKey = _x;
  [_groupKey, ("true" configClasses _y) select {
    isClass (configFile >> "CfgWeapons" >> configName _x)
  } apply {
    private _groupEntryKey = toLowerANSI configName _x;
    private _groupEntryConfig = configFile >> "CfgWeapons" >> _groupEntryKey;
    if (getNumber (_groupEntryConfig >> "scope") < 2) then {
      WARNING_1("group entry weapon item %1 exists, but is not scope 2",configName _groupEntryConfig);
    };

    private _groupEntryComponents = getArray (_x >> "components") apply { toLowerANSI _x };
    [_groupEntryKey, _groupEntryComponents]
  } select {
    _x params ["_groupEntryKey", "_groupEntryComponents"];

    private _unknownComponent = _groupEntryComponents findIf { !(_x in _components) };
    if (_unknownComponent isNotEqualTo -1) then {
      private _unknownComponentName = _groupEntryComponents select _unknownComponent;
      WARNING_3("unknown component '%1' found in weapon group entry '%2' on weapon group '%3'",_unknownComponentName,_groupEntryKey,_groupKey);

      false
    } else {
      true
    }
  }]
} select {
  (_x select 1) isNotEqualTo []
});

private _foregripComponents = [];
_foregripComponents insert [-1, getArray (configFile >> QCLASS_DEFINES >> "foregripComponents") apply { toLowerANSI _x }, true];
_foregripComponents insert [-1, getArray (campaignConfigFile >> QCLASS_DEFINES >> "foregripComponents") apply { toLowerANSI _x }, true];
_foregripComponents insert [-1, getArray (missionConfigFile >> QCLASS_DEFINES >> "foregripComponents") apply { toLowerANSI _x }, true];
private _foregripComponents = _foregripComponents select { _x in _components };

INFO_1("foregrip components: %1",str _foregripComponents);

// When 'Foregrip Items Needed' is disabled, all foregrip items according to `foregripComponents[]` will be made fake
{
  private _isFake = !VAR_NEED_FOREGRIP_ITEMS;
  (_components get toLowerANSI _x) set [6, _isFake];
} forEach _foregripComponents;

// Merge component items list for M320 and AG-C when
if (VAR_MERGE_M320_FAMILY && { "m320" in _components && "agc" in _components }) then {
  private _componentItemsM320 = (_components get "m320") select 0;
  private _componentItemsAGC = (_components get "agc") select 0;

  private _componentItemsMerged = _componentItemsM320 + _componentItemsAGC;
  private _componentItemsMerged = _componentItemsMerged arrayIntersect _componentItemsMerged;

  (_components get "m320") set [0, +_componentItemsMerged];
  (_components get "agc") set [0, +_componentItemsMerged];
};

private _actions = [];

{
  private _children = _y;
  {
    _x params ["_weaponFrom", "_componentsWeaponFrom"];
    {
      _x params ["_weaponTo", "_componentsWeaponTo"];

      if (_weaponFrom == _weaponTo) then { continue };

      private _componentsAttach = _componentsWeaponTo - _componentsWeaponFrom;
      private _componentsDetach = _componentsWeaponFrom - _componentsWeaponTo;
      private _componentsCount = count _componentsAttach + count _componentsDetach;
      private _canAttach = _componentsAttach findIf { !((_components get _x) select 4) } isEqualTo -1;
      private _canDetach = _componentsDetach findIf { !((_components get _x) select 5) } isEqualTo -1;
      if (_componentsCount >= 1 && _componentsCount <= 3 && _canAttach && _canDetach) then {
        private _id = QRGVAR(action) + "_" + _weaponFrom + "_to_" + _weaponTo;
        private _mode = switch (true) do {
          case (_componentsDetach isEqualTo []): { "attach" };
          case (_componentsAttach isEqualTo []): { "detach" };
          case (count _componentsAttach isEqualTo 1 && count _componentsDetach isEqualTo 1): { "swap" };
          default { "convert" };
        };

        _actions pushBack [_mode, _id, _weaponFrom, _weaponTo, _componentsAttach, _componentsDetach];
      };
    } forEach _children;
  } forEach _children;
} forEach _groups;

[_actions, _groups, _components, _tools]
