#include "..\script_component.hpp"

params ["_item", "_unit"];

([_unit, 1] call ace_common_fnc_uniqueItems) findIf { _x == _item } isNotEqualTo -1
