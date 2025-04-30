#include "..\script_component.hpp"

params ["_unit", "_componentsRequired", "_mode"];

if (_componentsRequired isEqualTo []) exitWith { [] };

private _componentsData = GET_FRAMEWORK_DATA_COMPONENTS;

_componentsRequired apply {
  _componentsData get _x
} select {
  !(_x select 6)
} apply {
  _x params [
    "_componentItems",
    "_displayName",
    "_picture",
    "_toolsRequired",
    "_enableAttach",
    "_enableDetach",
    "_isFake"
  ];

  private _componentItemIndex = switch (_mode) do {
    case "attach": { _componentItems findIf { [_x, _unit] call RFUNC(hasItem) } };
    case "detach": { 0 };
    default { -1 };
  };

  if (
    _componentItems isNotEqualTo [] &&
    _componentItemIndex >= 0 &&
    _componentItemIndex < count _componentItems
  ) then {
    _componentItems select _componentItemIndex
  } else {
    nil
  }
} select {
  !isNil "_x"
}
