#include "..\script_component.hpp"

(([] call PFUNC(getFrameworkDataCached)) select 0) apply {
  [_x call PFUNC(createInteraction), [], _this select 0]
}
