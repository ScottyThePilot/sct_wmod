#include "..\script_component.hpp"

params ["_unit", "_toolsRequired"];

if (_toolsRequired isEqualTo []) exitWith { [] };

private _frameworkData = [] call PFUNC(getFrameworkDataCached);

_toolsRequired apply {
  (_frameworkData select 3) get _x
} select {
  _x params ["_toolItems", "_displayName"];
  _toolItems findIf { _x in items _unit } isEqualTo -1
}
