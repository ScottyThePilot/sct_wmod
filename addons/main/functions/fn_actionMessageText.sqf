#include "..\script_component.hpp"

params ["_templates", "_args"];
_templates params ["_templateAttach", "_templateDetach", "_templateSwap", "_templateConvert"];
_args params ["_mode", "_weaponFrom", "_weaponTo", "_componentsAttach", "_componentsDetach"];

private _componentsData = GET_FRAMEWORK_DATA_COMPONENTS;
private _componentsNamesAttach = _componentsAttach apply { (_componentsData get _x) select 1 };
private _componentsNamesDetach = _componentsDetach apply { (_componentsData get _x) select 1 };

switch (_mode) do {
  case "attach": { format [localize _templateAttach, _componentsNamesAttach call PFUNC(textList)] };
  case "detach": { format [localize _templateDetach, _componentsNamesDetach call PFUNC(textList)] };
  case "swap": { format [localize _templateSwap, _componentsNamesDetach select 0, _componentsNamesAttach select 0] };
  case "convert": {
    private _weaponNameFrom = getTextRaw (configFile >> "CfgWeapons" >> _weaponFrom >> "displayName");
    private _weaponNameTo = getTextRaw (configFile >> "CfgWeapons" >> _weaponTo >> "displayName");
    format [localize _templateConvert, _weaponNameFrom, _weaponNameTo]
  };
}
