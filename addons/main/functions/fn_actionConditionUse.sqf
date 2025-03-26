#include "..\script_component.hpp"

params ["_player", "_mode", "", "", "_component"];
if (_mode == "attach" && !(_component in items _player)) exitWith { false };
_this call PFUNC(actionCondition)
