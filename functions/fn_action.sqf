params ["_player", "_mode", "_weaponFrom", "_weaponTo", "_component", "_attachmentsRemove"];

private _a = weaponsItems _player;
private _attachmentsFrom = _a select (_a findIf {
  _x select 0 == primaryWeapon _player
});

_attachmentsFrom deleteAt 0;
private _itemsToInventory = _attachmentsRemove apply {
  private _attachment = _attachmentsFrom select _x;
  _attachmentsFrom set [_x, ""];
  _attachment
};

switch (_mode) do {
  case "attach": { _player removeItem _component };
  case "detach": { _player addItem _component };
};

_player removeWeaponGlobal _weaponFrom;
_player addWeaponGlobal _weaponTo;

private _a = weaponsItems _player;
private _attachmentsNew = _a select (_a findIf {
  _x select 0 == primaryWeapon _player
});

_itemsToInventory pushBack (_attachmentsNew select 4);
_itemsToInventory pushBack (_attachmentsNew select 5);

removeAllPrimaryWeaponItems _player;

_player selectWeapon _weaponTo;

{_player addWeaponItem [_weaponTo, _x, true]} forEach _attachmentsFrom;

{
  switch (typeName _x) do {
    case "ARRAY": { _player addMagazine _x };
    case "STRING": { _player addItem _x };
  };
} forEach _itemsToInventory;
