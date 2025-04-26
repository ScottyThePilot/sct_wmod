#define WEAPON_COMPONENT_NAMED(ID,ITEM,NAME) \
  class ID { items[] = { #ITEM }; displayName = NAME; }
#define WEAPON_COMPONENT_NAMED_NOATTACH(ID,ITEM,NAME) \
  class ID { items[] = { #ITEM }; displayName = NAME; disableAttach = 1; }
#define WEAPON_COMPONENT_NAMED_NODETACH(ID,ITEM,NAME) \
  class ID { items[] = { #ITEM }; displayName = NAME; disableDetach = 1; }

#define WEAPON_MEMBER_0(ID) \
  class ID { components[] = {}; }
#define WEAPON_MEMBER_1(ID,C1) \
  class ID { components[] = { #C1 }; }
#define WEAPON_MEMBER_2(ID,C1,C2) \
  class ID { components[] = { #C1, #C2 }; }
#define WEAPON_MEMBER_3(ID,C1,C2,C3) \
  class ID { components[] = { #C1, #C2, #C3 }; }
#define WEAPON_MEMBER_4(ID,C1,C2,C3,C4) \
  class ID { components[] = { #C1, #C2, #C3, #C4 }; }

#define WEAPON_TOOL_0(ID,NAME) \
  class ID { items[] = {}; displayName = NAME; }
#define WEAPON_TOOL_1(ID,NAME,I1) \
  class ID { items[] = { #I1 }; displayName = NAME; }
#define WEAPON_TOOL_2(ID,NAME,I1,I2) \
  class ID { items[] = { #I1, #I2 }; displayName = NAME; }
#define WEAPON_TOOL_3(ID,NAME,I1,I2,I3) \
  class ID { items[] = { #I1, #I2, #I3 }; displayName = NAME; }
#define WEAPON_TOOL_4(ID,NAME,I1,I2,I3,I4) \
  class ID { items[] = { #I1, #I2, #I3, #I4 }; displayName = NAME; }

#define CLASS_DEFINES PGVAR(defines)
#define CLASS_COMPONENT_ITEM_FAKE @FAKE_COMPONENT@

#define QCLASS_DEFINES QUOTE(CLASS_DEFINES)
#define QCLASS_COMPONENT_ITEM_FAKE QUOTE(CLASS_COMPONENT_ITEM_FAKE)

#define VAR_MODIFICATION_ENABLED PGVAR(modificationEnabled)
#define VAR_ACTION_LENGTH PGVAR(actionLength)
#define VAR_NEED_FOREGRIP_ITEMS PGVAR(needForegripItems)
#define VAR_MERGE_M320_FAMILY PGVAR(mergeM320Family)
#define VAR_FRAMEWORK_DATA PGVAR(frameworkData)
#define VAR_COMPATIBLE_WEAPONS_MAP PGVAR(compatibleWeaponsMap)
#define VAR_WEAPON_COMPONENTS_MAP PGVAR(weaponComponentsMap)

#define QVAR_MODIFICATION_ENABLED QUOTE(VAR_MODIFICATION_ENABLED)
#define QVAR_ACTION_LENGTH QUOTE(VAR_ACTION_LENGTH)
#define QVAR_NEED_FOREGRIP_ITEMS QUOTE(VAR_NEED_FOREGRIP_ITEMS)
#define QVAR_MERGE_M320_FAMILY QUOTE(VAR_MERGE_M320_FAMILY)
#define QVAR_FRAMEWORK_DATA QUOTE(VAR_FRAMEWORK_DATA)
#define QVAR_COMPATIBLE_WEAPONS_MAP QUOTE(VAR_COMPATIBLE_WEAPONS_MAP)
#define QVAR_WEAPON_COMPONENTS_MAP QUOTE(VAR_WEAPON_COMPONENTS_MAP)

#define ACTION_MESSAGE_TEMPLATES(TEMPLATE) [ \
    PLSTRING(DOUBLES(TEMPLATE,attach)), \
    PLSTRING(DOUBLES(TEMPLATE,detach)), \
    PLSTRING(DOUBLES(TEMPLATE,swap)), \
    PLSTRING(DOUBLES(TEMPLATE,convert)) \
  ]

#define GET_FRAMEWORK_DATA ([] call PFUNC(getFrameworkDataCached))
#define GET_FRAMEWORK_DATA_ACTIONS (GET_FRAMEWORK_DATA select 0)
#define GET_FRAMEWORK_DATA_GROUPS (GET_FRAMEWORK_DATA select 1)
#define GET_FRAMEWORK_DATA_COMPONENTS (GET_FRAMEWORK_DATA select 2)
#define GET_FRAMEWORK_DATA_TOOLS (GET_FRAMEWORK_DATA select 3)
#define RESET_FRAMEWORK_DATA ([] call PFUNC(resetFrameworkDataCache))
