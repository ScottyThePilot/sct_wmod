// Gets a list of items attached to this weapon.
// Returns an array in the format:
// 0: Muzzle (String)
// 1: Flashlight/Laser (String)
// 2: Optic (String)
// 3: Primary Mag (Array)
// 4: Secondary Mag (Array)
// 5: Bipod/Grip (String)

private _a = weaponsItems _this;
private _a = _a select (_a findIf {
  _x select 0 == primaryWeapon _this
});

_a deleteAt 0;
_a
