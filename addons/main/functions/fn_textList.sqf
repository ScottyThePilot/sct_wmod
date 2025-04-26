#include "..\script_component.hpp"

private _template = PLSTRING(list) + str count _this;
format ([localize _template] + _this)
