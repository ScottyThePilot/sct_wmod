params ["_player", "_mode", "_weaponFrom", "_weaponTo", "_component", "_attachmentsRemove"];

// TODO: deprecate the current attachments removal method,
// and determine which attachments to put in the player's inventory by which ones fail
// when attempting to add them to the weapon.

// get a list of attachments on the weapon
private _attachmentsFrom = _player call sct_wmod_fnc_weaponsItems;
private _itemsToInventory = _attachmentsRemove apply {
  private _attachment = _attachmentsFrom select _x;
  _attachmentsFrom set [_x, ""];
  _attachment
};

// add or remove the component from the player's inventory
switch (_mode) do {
  case "attach": { _player removeItem _component };
  case "detach": { _player addItem _component };
};

// swap the player's weapon
_player removeWeaponGlobal (primaryWeapon _player);
_player addWeaponGlobal _weaponTo;

// remove any attachments that may come by default with this weapon class
removeAllPrimaryWeaponItems _player;

// `addWeapon` loads magazines into the weapon from the player's inventory.
// manually remove those magazines from the weapon and put them in the player's inventory
{
  _x params ["_item", "_count"];
  _player removePrimaryWeaponItem _item;
  [_player, _item, "", _count] call ace_common_fnc_addToInventory;
} forEach (_player call sct_wmod_fnc_weaponsItems) select [3, 2];

// select the new weapon
_player selectWeapon _weaponTo;

// add all the weapon attachments back
{
  _player addWeaponItem [_weaponTo, _x, true];
} forEach _attachmentsFrom;

// add the rest of the items to the player's inventory
{
  _x params ["_item", ["_count", -1]];
  [_player, _item, "", _count] call ace_common_fnc_addToInventory;
} forEach _itemsToInventory;
