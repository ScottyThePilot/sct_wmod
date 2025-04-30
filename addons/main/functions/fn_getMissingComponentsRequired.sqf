#include "..\script_component.hpp"

params ["_unit", "_componentsRequired"];

if (_componentsRequired isEqualTo []) exitWith { [] };

private _componentsData = GET_FRAMEWORK_DATA_COMPONENTS;

_componentsRequired apply {
  _componentsData get _x
} select {
  _x params [
    "_componentItems",
    "_displayName",
    "_picture",
    "_toolsRequired",
    "_enableAttach",
    "_enableDetach",
    "_isFake"
  ];

  if (_isFake) then {
    false
  } else {
    _componentItems findIf {
      [_x, _unit] call RFUNC(hasItem)
    } isEqualTo -1
  }
}
