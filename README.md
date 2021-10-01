# Scotty's ACE Weapon Modification

This mod allows more integral weapon components like grenade launchers, optic rails, etc. to be detached or attached to weapons in the field.

## Adding new components or recipes
If you want to add new components or recipes, you can either contribute to the project directly, make a mod that defines new components/recipes, or define the components/recipes in a `description.ext` for a mission.

The following code is an example of how to define a new component and a weapon group.
You can either place this in your `Config.cpp` (if making a patch/compat mod) or in your `description.ext` (for missions).

```cpp
class sct_wmod_defines {
  class WeaponComponents {
    class kac_grip {
      displayName = "KAC Grip";
      // The classname of the item for this component.
      // If this class doesn't exist in the game (for example, when the mod isn't loaded)
      // this component won't be usable in any recipes.
      className = "rhsusf_acc_kac_grip";
      // This lets you define which slots on the weapon should have
      // their attachments removed when attaching or detaching this component.
      // Valid values for this setting are:
      // 0: Muzzle
      // 1: Flashlight/Laser
      // 2: Optic
      // 3: Primary Mag
      // 4: Secondary Mag
      // 5: Bipod/Grip
      attachmentSlots[] = { 5 };
    };
  };

  class WeaponGroups {
    // This class describes a group of weapon that can be modified (in this case the RHSUSAF M27 IAR).
    // It has two variants, one with the KAC Grip and one without.
    class m27iar {
      displayName = "$STR_RHS_CFGWEAPONS_RIFLE_M27IAR";
      // The weapon classes contained within this group and the
      // components that should be considered as attached.
      class rhs_weap_m27iar {
        components[] = {};
      };
      class rhs_weap_m27iar_grip {
        components[] = { "kac_grip" };
      };
    };
  };
};
```
