#include "..\script_component.hpp"

params ["_unit", "_toolsRequired"];

if (_toolsRequired isEqualTo []) exitWith { [] };

private _toolsData = GET_FRAMEWORK_DATA_TOOLS;

_toolsRequired apply {
  _toolsData get _x
} select {
  _x params ["_toolItems", "_displayName"];

  _toolItems findIf { _x in items _unit } isEqualTo -1
}
