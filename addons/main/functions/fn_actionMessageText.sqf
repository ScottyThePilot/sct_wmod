#include "..\script_component.hpp"

params ["_templateBase", "_args"];
_args params ["_mode", "_weaponFrom", "_weaponTo", "_componentsAttach", "_componentsDetach"];

private _componentsData = GET_FRAMEWORK_DATA_COMPONENTS;
private _componentsAll = _componentsAttach + _componentsDetach;
private _componentsNamesAttach = _componentsAttach apply { (_componentsData get _x) select 1 };
private _componentsNamesDetach = _componentsDetach apply { (_componentsData get _x) select 1 };

private _templateKey = _templateBase + "_" + _mode;
private _template = getText (configFile >> QCLASS_DEFINES >> "DefaultMessageTemplates" >> _templateKey);
if ((count _componentsAttach + count _componentsDetach) isEqualTo 1) then {
  private _componentData = _componentsData get ((_componentsAttach + _componentsDetach) select 0);
  if (isText ((_componentData select 7) >> _templateKey)) then {
    _template = getText ((_componentData select 7) >> _templateKey);
  };
};

switch (_mode) do {
  case "attach": { format [_template, _componentsNamesAttach call RFUNC(textList)] };
  case "detach": { format [_template, _componentsNamesDetach call RFUNC(textList)] };
  case "swap": { format [_template, _componentsNamesDetach select 0, _componentsNamesAttach select 0] };
  case "convert": {
    private _weaponNameFrom = getTextRaw (configFile >> "CfgWeapons" >> _weaponFrom >> "displayName");
    private _weaponNameTo = getTextRaw (configFile >> "CfgWeapons" >> _weaponTo >> "displayName");
    format [_template, _weaponNameFrom, _weaponNameTo]
  };
}
