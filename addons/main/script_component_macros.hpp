#define WEAPON_COMPONENT_NAMED(ID,CLASSNAME,NAME) \
  class ID { className = #CLASSNAME; displayName = NAME; }
#define WEAPON_COMPONENT_NAMED_NOATTACH(ID,CLASSNAME,NAME) \
  class ID { className = #CLASSNAME; displayName = NAME; disableAttach = 1; }
#define WEAPON_COMPONENT_NAMED_NODETACH(ID,CLASSNAME,NAME) \
  class ID { className = #CLASSNAME; displayName = NAME; disableDetach = 1; }

#define WEAPON_COMPONENT_NAMED_TOOL(ID,CLASSNAME,NAME,TOOL) \
  class ID { className = #CLASSNAME; displayName = NAME; toolsRequired[] = { #TOOL }; }
#define WEAPON_COMPONENT_NAMED_TOOL_NOATTACH(ID,CLASSNAME,NAME,TOOL) \
  class ID { className = #CLASSNAME; displayName = NAME; disableAttach = 1; toolsRequired[] = { #TOOL }; }
#define WEAPON_COMPONENT_NAMED_TOOL_NODETACH(ID,CLASSNAME,NAME,TOOL) \
  class ID { className = #CLASSNAME; displayName = NAME; disableDetach = 1; toolsRequired[] = { #TOOL }; }

#define WEAPON_COMPONENT_NAMED_TOOL_FAKE(ID,NAME,PICTURE,TOOL) \
  class ID { className = QCLASS_COMPONENT_ITEM_FAKE; displayName = NAME; picture = PICTURE; toolsRequired[] = { #TOOL }; }
#define WEAPON_COMPONENT_NAMED_TOOL_FAKE_NOATTACH(ID,NAME,PICTURE,TOOL) \
  class ID { className = QCLASS_COMPONENT_ITEM_FAKE; displayName = NAME; picture = PICTURE; disableAttach = 1; toolsRequired[] = { #TOOL }; }
#define WEAPON_COMPONENT_NAMED_TOOL_FAKE_NODETACH(ID,NAME,PICTURE,TOOL) \
  class ID { className = QCLASS_COMPONENT_ITEM_FAKE; displayName = NAME; picture = PICTURE; disableDetach = 1; toolsRequired[] = { #TOOL }; }

#define WEAPON_MEMBER_0(ID) \
  class ID { components[] = {}; }
#define WEAPON_MEMBER_1(ID,M1) \
  class ID { components[] = { #M1 }; }
#define WEAPON_MEMBER_2(ID,M1,M2) \
  class ID { components[] = { #M1, #M2 }; }
#define WEAPON_MEMBER_3(ID,M1,M2,M3) \
  class ID { components[] = { #M1, #M2, #M3 }; }
#define WEAPON_MEMBER_4(ID,M1,M2,M3,M4) \
  class ID { components[] = { #M1, #M2, #M3, #M4 }; }

#define WEAPON_TOOL_0(ID,NAME) \
  class ID { items[] = {}; displayName = NAME; }
#define WEAPON_TOOL_1(ID,NAME,M1) \
  class ID { items[] = { #M1 }; displayName = NAME; }
#define WEAPON_TOOL_2(ID,NAME,M1,M2) \
  class ID { items[] = { #M1, #M2 }; displayName = NAME; }
#define WEAPON_TOOL_3(ID,NAME,M1,M2,M3) \
  class ID { items[] = { #M1, #M2, #M3 }; displayName = NAME; }
#define WEAPON_TOOL_4(ID,NAME,M1,M2,M3,M4) \
  class ID { items[] = { #M1, #M2, #M3, #M4 }; displayName = NAME; }

#define CLASS_DEFINES PGVAR(defines)
#define CLASS_COMPONENT_ITEM_FAKE @FAKE_COMPONENT@

#define QCLASS_DEFINES QUOTE(CLASS_DEFINES)
#define QCLASS_COMPONENT_ITEM_FAKE QUOTE(CLASS_COMPONENT_ITEM_FAKE)

#define VAR_MODIFICATION_ENABLED PGVAR(modificationEnabled)
#define VAR_ACTION_LENGTH PGVAR(actionLength)
#define VAR_FRAMEWORK_DATA PGVAR(frameworkData)
#define VAR_COMPATIBLE_WEAPONS_MAP PGVAR(compatibleWeaponsMap)
#define VAR_WEAPON_COMPONENTS_MAP PGVAR(weaponComponentsMap)

#define QVAR_MODIFICATION_ENABLED QUOTE(VAR_MODIFICATION_ENABLED)
#define QVAR_ACTION_LENGTH QUOTE(VAR_ACTION_LENGTH)
#define QVAR_FRAMEWORK_DATA QUOTE(VAR_FRAMEWORK_DATA)
#define QVAR_COMPATIBLE_WEAPONS_MAP QUOTE(VAR_COMPATIBLE_WEAPONS_MAP)
#define QVAR_WEAPON_COMPONENTS_MAP QUOTE(VAR_WEAPON_COMPONENTS_MAP)
