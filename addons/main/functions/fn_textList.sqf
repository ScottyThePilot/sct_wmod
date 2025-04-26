#include "..\script_component.hpp"

private _template = RLSTRING(list) + str count _this;
format ([localize _template] + _this)
