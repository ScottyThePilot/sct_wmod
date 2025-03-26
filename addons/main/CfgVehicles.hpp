class Man;

class CAManBase: Man {
  class ACE_SelfActions {
    class ACE_Equipment {
      class PGVAR(Components) {
        displayName = PCSTRING(Components);
        exceptions[] = { "isNotInside", "isNotSwimming", "isNotSitting" };
        insertChildren = QUOTE(call PFUNC(getComponentActions));
        modifierFunction = "(_this select 3) set [2, getText (configFile >> 'CfgWeapons' >> currentWeapon (_this select 0) >> 'picture')];";
        // Parentheses required because of an ACE (?) bug
        condition = QUOTE((isNil 'VAR_MODIFICATION_ENABLED' || { VAR_MODIFICATION_ENABLED }));
      };
    };
  };
};
