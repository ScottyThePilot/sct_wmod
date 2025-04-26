class Man;

class CAManBase: Man {
  class ACE_SelfActions {
    class ACE_Equipment {
      class RGVAR(Components) {
        displayName = RCSTRING(interaction_components);
        exceptions[] = { "isNotInside", "isNotSwimming", "isNotSitting" };
        insertChildren = QUOTE(CALL2(RFUNC(createInteractions),_target,_player));
        modifierFunction = "(_this select 3) set [2, getText (configFile >> 'CfgWeapons' >> currentWeapon (_this select 0) >> 'picture')];";
        condition = QUOTE((!isNil 'VAR_MODIFICATION_ENABLED' && { VAR_MODIFICATION_ENABLED }));
      };
    };
  };
};
