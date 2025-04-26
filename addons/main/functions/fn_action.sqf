#include "..\script_component.hpp"

// Performs the action of attaching/detaching a component from a player's weapon
params ["_player", "_mode", "_weaponFrom", "_weaponTo", "_componentsAttach", "_componentsDetach", "_toolsRequired"];
private _extendedLoadout = [_player] call CBA_fnc_getLoadout;
private _loadout = _extendedLoadout select 0;
private _weaponSlot = (_loadout select [0, 3]) findIf {
  (_x select 0) isEqualTo currentWeapon _player
};

if (_weaponSlot isEqualTo -1) then { throw "player is not holding a weapon" };
(_loadout select _weaponSlot) set [0, _weaponTo];

[_player, _extendedLoadout] call CBA_fnc_setLoadout;

{
  _player removeItem _x;
} forEach ([_player, _componentsAttach, "attach"] call PFUNC(getComponentsItems));
private _itemsToInventory = [_player, _componentsDetach, "detach"] call PFUNC(getComponentsItems);

// compare the player's previous weapon attachments with their current ones to
// figure out which ones fell off in the process and need to go back into the inventory
private _previousWeaponItems = _loadout select _weaponSlot;
private _currentWeaponItems = (weaponsItems _player) select _weaponSlot;
for "_i" from 1 to 6 do {
  private _previousItem = _previousWeaponItems select _i;
  if ((_currentWeaponItems select _i) isNotEqualTo _previousItem) then {
    assert (_previousItem isNotEqualTo "");
    _itemsToInventory pushBack _previousItem;
  };
};

{
  _x params ["_item", ["_ammo", -1]];
  [_player, _item, "", _ammo] call ace_common_fnc_addToInventory;
} forEach _itemsToInventory;



([
  ACTION_MESSAGE_TEMPLATES(notify_success),
  [_mode, _weaponFrom, _weaponTo, _componentsAttach, _componentsDetach]
] call PFUNC(actionMessageText)) call CBA_fnc_notify;
