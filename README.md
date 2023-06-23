# Scotty's ACE Weapon Modification

<a href="https://steamcommunity.com/sharedfiles/filedetails/?id=2594641774">
  <img src="https://img.shields.io/endpoint?color=%232a475e%20&url=https%3A%2F%2Fshieldsio-steam-workshop.jross.me%2F2594641774%2Fsubscriptions-text">
</a>

This mod allows more integral weapon components like grenade launchers, optic
rails, etc. to be detached or attached to weapons in the field.

## Support
Current support:
- Vanilla Arma 3
- RHS USAF/AFRF/GREF/SAF
- NIArms

## Adding new components or recipes
If you want to add new components or recipes, you can either contribute to the
project directly, make a mod that defines new components/recipes, or define the
components/recipes in a `description.ext` for a mission.

The following code is an example of how to define a new component and a weapon group.
You can either place this in your `Config.cpp` (if making a patch/compat mod) or
in your `description.ext` (for missions or campaigns).

```cpp
class sct_wmod_defines {
  class WeaponComponents {
    // Defining this does not create an item, it just allows it to be referenced from
    // the `components` entry in a weapon group and allows it to be attached/detached.
    class kac_grip {
      // The display name of this component, shown in the ACE interact menu.
      // If not specified, defaults to the display name of the item specified below.
      displayName = "KAC Grip";
      // The classname of the item for this component.
      // If this class doesn't exist in the game (for example, when the mod isn't loaded)
      // this component won't be usable in any recipes.
      className = "rhsusf_acc_kac_grip";
    };
  };

  class WeaponGroups {
    // This class describes a group of weapon that can be modified (in this case the RHSUSAF M27 IAR).
    // It has two variants, one with the KAC Grip and one without.
    class rhs_m27iar {
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

## Known/Potential Issues
- Weapons with incorrectly defined `baseWeapon` entries may cause incorrect attach/detach actions
