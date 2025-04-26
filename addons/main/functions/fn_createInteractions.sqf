#include "..\script_component.hpp"

params ["_target", "_player"];

GET_FRAMEWORK_DATA_ACTIONS apply {
  [_x call PFUNC(createInteraction), [], _target]
}
