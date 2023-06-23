// Performs the action of attaching/detaching a component from a player's weapon
params ["_player", "_mode", "", "_weaponTo", "_component", "_componentName"];
private _loadout = getUnitLoadout _player;
private _weaponSlot = (_loadout select [0, 3]) findIf {
  _x select 0 == currentWeapon _player
};

if (_weaponSlot == -1) then { throw "player is not holding a weapon" };
(_loadout select _weaponSlot) set [0, _weaponTo];

// TODO: figure out if replaced attachments or empty attachment slots get filled with
// weapons' default attachments (attachments shouldn't get created out of thin air)
_player setUnitLoadout _loadout;

private _itemsToInventory = [];
switch (_mode) do {
  case "attach": {
    _player removeItem _component;
  };
  case "detach": {
    _itemsToInventory pushBack _component;
  };
};

// compare the player's previous weapon attachments with their current ones to
// figure out which ones fell off in the process and need to go back into the inventory
private _previousWeaponItems = _loadout select _weaponSlot;
private _currentWeaponItems = (weaponsItems _player) select _weaponSlot;
for "_i" from 1 to 6 do {
  private _previousItem = _previousWeaponItems select _i;
  if ((_currentWeaponItems select _i) isNotEqualTo _previousItem) then {
    //if (_previousItem isEqualTo "") then { throw "error" };
    _itemsToInventory pushBack _previousItem;
  };
};

{
  _x params ["_item", ["_ammo", -1]];
  [_player, _item, "", _ammo] call ace_common_fnc_addToInventory;
} forEach _itemsToInventory;



private _text = switch (_mode) do {
  case "attach": { format [localize "STR_sct_wmod_AttachSuccess", _componentName] };
  case "detach": { format [localize "STR_sct_wmod_DetachSuccess", _componentName] };
};

_text call CBA_fnc_notify;
