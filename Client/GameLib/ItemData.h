#pragma once

// NOTE : Item의 통합 관리 클래스다.
//        Icon, Model (droped on ground), Game Data

#include "../eterLib/GrpSubImage.h"
#include "../eterGrnLib/Thing.h"
#include "GameLibDefines.h"


class CItemData
{
	public:
		enum
		{
			ITEM_NAME_MAX_LEN = 24,
			ITEM_LIMIT_MAX_NUM = 2,
			ITEM_VALUES_MAX_NUM = 6,
			ITEM_SMALL_DESCR_MAX_LEN = 256,
			ITEM_APPLY_MAX_NUM = 3,
			ITEM_SOCKET_MAX_NUM = 3,
#ifdef __UNIMPLEMENTED__
			ITEM_PICK_MAX_LEVEL = 9,
			ITEM_ROD_MAX_LEVEL = 20,
#endif
#ifdef ENABLE_SHINING_SYSTEM
			ITEM_SHINING_MAX_COUNT = 3,
#endif
		};

#ifdef ENABLE_SOULBIND_SYSTEM
		enum ESealBind
		{
			SEAL_BIND_FLAG_DROP,
			SEAL_BIND_FLAG_UPGRADE,
			SEAL_BIND_FLAG_SELL,
			SEAL_BIND_FLAG_ENCHANT,
			SEAL_BIND_FLAG_TRADE,
			SEAL_BIND_FLAG_UNSEAL,
			SEAL_BIND_FLAG_MAX,
		};

		enum ESealDate
		{
			SEAL_DATE_DEFAULT_TIMESTAMP = 0, // 2015/11/12 it's -1
			SEAL_DATE_UNLIMITED_TIMESTAMP = -1, // 2015/11/12 it doesn't exist
		};

		enum ESealItem
		{
			SEAL_ITEM_BINDING_VNUM = 50263,
			SEAL_ITEM_UNBINDING_VNUM = 50264,
		};
#endif

#ifdef __UNIMPLEMENTED__
		enum EPetData
		{
			EGG_USE_SUCCESS = 0,
			EGG_USE_FAILED_TIMEOVER = 2,
			EGG_USE_FAILED_BECAUSE_NAME = 1,
			GROWTH_PET_ITEM_USE_COOL_TIME = 1,
			PET_EGG_USE_TRUE = 0,
			PET_EGG_USE_FAILED_BECAUSE_TRADING = 1,
			PET_EGG_USE_FAILED_BECAUSE_SHOP_OPEN = 2,
			PET_EGG_USE_FAILED_BECAUSE_MALL_OPEN = 3,
			PET_EGG_USE_FAILED_BECAUSE_SAFEBOX_OPEN = 4,
			PET_HATCHING_MONEY = 100000,
			PET_NAME_MAX_SIZE = 20,
			PET_NAME_MIN_SIZE = 4,
		};
#endif

		enum EItemType
		{
			ITEM_TYPE_NONE,					//0
			ITEM_TYPE_WEAPON,				//1//무기
			ITEM_TYPE_ARMOR,				//2//갑옷
			ITEM_TYPE_USE,					//3//아이템 사용
			ITEM_TYPE_AUTOUSE,				//4
			ITEM_TYPE_MATERIAL,				//5
			ITEM_TYPE_SPECIAL,				//6 //스페셜 아이템
			ITEM_TYPE_TOOL,					//7
			ITEM_TYPE_LOTTERY,				//8//복권
			ITEM_TYPE_ELK,					//9//돈
			ITEM_TYPE_METIN,				//10
			ITEM_TYPE_CONTAINER,			//11
			ITEM_TYPE_FISH,					//12//낚시
			ITEM_TYPE_ROD,					//13
			ITEM_TYPE_RESOURCE,				//14
			ITEM_TYPE_CAMPFIRE,				//15
			ITEM_TYPE_UNIQUE,				//16
			ITEM_TYPE_SKILLBOOK,			//17
			ITEM_TYPE_QUEST,				//18
			ITEM_TYPE_POLYMORPH,			//19
			ITEM_TYPE_TREASURE_BOX,			//20//보물상자
			ITEM_TYPE_TREASURE_KEY,			//21//보물상자 열쇠
			ITEM_TYPE_SKILLFORGET,			//22
			ITEM_TYPE_GIFTBOX,				//23
			ITEM_TYPE_PICK,					//24
			ITEM_TYPE_HAIR,					//25//머리
			ITEM_TYPE_TOTEM,				//26//토템
			ITEM_TYPE_BLEND,				//27//생성될때 랜덤하게 속성이 붙는 약물
			ITEM_TYPE_COSTUME,				//28//코스츔 아이템 (2011년 8월 추가된 코스츔 시스템용 아이템)
			ITEM_TYPE_UNUSED1,					//29
			ITEM_TYPE_UNUSED2,					//30
			ITEM_TYPE_EXTRACT,					//31 추출도구.
			ITEM_TYPE_SECONDARY_COIN,			//32 명도전.
			ITEM_TYPE_UNUSED3,					//33

			ITEM_TYPE_MAX_NUM,
		};

#ifdef __UNIMPLEMENTED__
		enum EResourceSubTypes
		{
			RESOURCE_FISHBONE = 0,
			RESOURCE_WATERSTONEPIECE = 1,
			RESOURCE_WATERSTONE = 2,
			RESOURCE_BLOOD_PEARL = 3,
			RESOURCE_BLUE_PEARL = 4,
			RESOURCE_WHITE_PEARL = 5,
			RESOURCE_BUCKET = 6,
			RESOURCE_CRYSTAL = 7,
			RESOURCE_GEM = 8,
			RESOURCE_STONE = 9,
			RESOURCE_METIN = 10,
			RESOURCE_ORE = 11,
		};

		enum EPetSubTypes
		{
			PET_EGG = 0,
			PET_UPBRINGING = 1,
			PET_BAG = 2,
			PET_FEEDSTUFF = 3,
			PET_SKILL = 4,
			PET_SKILL_DEL_BOOK = 5,
		};

		enum EMediumSubTypes
		{
			MEDIUM_MOVE_COSTUME_ATTR = 0,
		};
#endif

		enum EWeaponSubTypes
		{
			WEAPON_SWORD, //0
			WEAPON_DAGGER, //1	//이도류
			WEAPON_BOW, //2
			WEAPON_TWO_HANDED, //3
			WEAPON_BELL, //4
			WEAPON_FAN, //5
			WEAPON_ARROW, //6
			WEAPON_MOUNT_SPEAR, //7
#ifdef ENABLE_WOLFMAN_CHARACTER
			WEAPON_CLAW = 8, //8
#endif
#ifdef ENABLE_QUIVER_SYSTEM
			WEAPON_QUIVER = 9, //9
#endif
#ifdef __UNIMPLEMENTED__
			WEAPON_BOUQUET = 10, //10
#endif
			WEAPON_NUM_TYPES, //11 2015/11/12

			WEAPON_NONE = WEAPON_NUM_TYPES+1,
		};

		enum EMaterialSubTypes
		{
			MATERIAL_LEATHER,
			MATERIAL_BLOOD,
			MATERIAL_ROOT,
			MATERIAL_NEEDLE,
			MATERIAL_JEWEL,
		};

		enum EArmorSubTypes
		{
			ARMOR_BODY,
			ARMOR_HEAD,
			ARMOR_SHIELD,
			ARMOR_WRIST,
			ARMOR_FOOTS,
		    ARMOR_NECK,
			ARMOR_EAR,
			ARMOR_NUM_TYPES
		};

		enum ECostumeSubTypes
		{
			COSTUME_BODY,				//0	갑옷(main look)
			COSTUME_HAIR,				//1	헤어(탈착가능)
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
			COSTUME_MOUNT	= 2,		//2
#endif
#ifdef ENABLE_ACCE_COSTUME_SYSTEM
			COSTUME_ACCE	= 3,		//3
#endif
#ifdef ENABLE_WEAPON_COSTUME_SYSTEM
			COSTUME_WEAPON	= 4,		//4
#endif
			COSTUME_NUM_TYPES,
		};

		enum EUseSubTypes
		{
			USE_POTION,					// 0
			USE_TALISMAN,
			USE_TUNING,
			USE_MOVE,
			USE_TREASURE_BOX,
			USE_MONEYBAG,
			USE_BAIT,
			USE_ABILITY_UP,
			USE_AFFECT,
			USE_CREATE_STONE,
			USE_SPECIAL,				// 10
			USE_POTION_NODELAY,
			USE_CLEAR,
			USE_INVISIBILITY,
			USE_DETACHMENT,
			USE_BUCKET,
			USE_POTION_CONTINUE,
			USE_CLEAN_SOCKET,
			USE_CHANGE_ATTRIBUTE,
			USE_ADD_ATTRIBUTE,
			USE_ADD_ACCESSORY_SOCKET,	// 20
			USE_PUT_INTO_ACCESSORY_SOCKET,
			USE_ADD_ATTRIBUTE2,
			USE_RECIPE,
			USE_CHANGE_ATTRIBUTE2,
			USE_BIND,
			USE_UNBIND,
			USE_TIME_CHARGE_PER,
			USE_TIME_CHARGE_FIX,				// 28
			USE_UNUSED1,
			USE_PUT_INTO_RING_SOCKET,			// 30 반지 소켓에 사용할 수 있는 아이템 (유니크 반지 말고, 새로 추가된 반지 슬롯)
#ifdef ENABLE_USE_COSTUME_ATTR
			USE_CHANGE_COSTUME_ATTR,			// 31
			USE_RESET_COSTUME_ATTR,				// 32
#endif
		};

		enum EMetinSubTypes
		{
			METIN_NORMAL,
			METIN_GOLD,
		};

		enum ELimitTypes
		{
			LIMIT_NONE,

			LIMIT_LEVEL,
			LIMIT_STR,
			LIMIT_DEX,
			LIMIT_INT,
			LIMIT_CON,
			LIMIT_PCBANG,

			/// 착용 여부와 상관 없이 실시간으로 시간 차감 (socket0에 소멸 시간이 박힘: unix_timestamp 타입)
			LIMIT_REAL_TIME,

			/// 아이템을 맨 처음 사용(혹은 착용) 한 순간부터 리얼타임 타이머 시작
			/// 최초 사용 전에는 socket0에 사용가능시간(초단위, 0이면 프로토의 limit value값 사용) 값이 쓰여있다가
			/// 아이템 사용시 socket1에 사용 횟수가 박히고 socket0에 unix_timestamp 타입의 소멸시간이 박힘.
			LIMIT_REAL_TIME_START_FIRST_USE,

			/// 아이템을 착용 중일 때만 사용 시간이 차감되는 아이템
			/// socket0에 남은 시간이 초단위로 박힘. (아이템 최초 사용시 해당 값이 0이면 프로토의 limit value값을 socket0에 복사)
			LIMIT_TIMER_BASED_ON_WEAR,

			LIMIT_MAX_NUM
		};

		enum EItemAntiFlag
		{
			ITEM_ANTIFLAG_FEMALE        = (1 << 0),		// 여성 사용 불가
			ITEM_ANTIFLAG_MALE          = (1 << 1),		// 남성 사용 불가
			ITEM_ANTIFLAG_WARRIOR       = (1 << 2),		// 무사 사용 불가
			ITEM_ANTIFLAG_ASSASSIN      = (1 << 3),		// 자객 사용 불가
			ITEM_ANTIFLAG_SURA          = (1 << 4),		// 수라 사용 불가
			ITEM_ANTIFLAG_SHAMAN        = (1 << 5),		// 무당 사용 불가
			ITEM_ANTIFLAG_GET           = (1 << 6),		// 집을 수 없음
			ITEM_ANTIFLAG_DROP          = (1 << 7),		// 버릴 수 없음
			ITEM_ANTIFLAG_SELL          = (1 << 8),		// 팔 수 없음
			ITEM_ANTIFLAG_EMPIRE_A      = (1 << 9),		// A 제국 사용 불가
			ITEM_ANTIFLAG_EMPIRE_B      = (1 << 10),	// B 제국 사용 불가
			ITEM_ANTIFLAG_EMPIRE_R      = (1 << 11),	// C 제국 사용 불가
			ITEM_ANTIFLAG_SAVE          = (1 << 12),	// 저장되지 않음
			ITEM_ANTIFLAG_GIVE          = (1 << 13),	// 거래 불가
			ITEM_ANTIFLAG_PKDROP        = (1 << 14),	// PK시 떨어지지 않음
			ITEM_ANTIFLAG_STACK         = (1 << 15),	// 합칠 수 없음
			ITEM_ANTIFLAG_MYSHOP        = (1 << 16),	// 개인 상점에 올릴 수 없음
			ITEM_ANTIFLAG_SAFEBOX		= (1 << 17),
#ifdef ENABLE_WOLFMAN_CHARACTER
			ITEM_ANTIFLAG_WOLFMAN		= (1 << 18),
#endif
		};

		enum EItemFlag
		{
			ITEM_FLAG_REFINEABLE        = (1 << 0),		// 개량 가능
			ITEM_FLAG_SAVE              = (1 << 1),
			ITEM_FLAG_STACKABLE         = (1 << 2),     // 여러개 합칠 수 있음
			ITEM_FLAG_COUNT_PER_1GOLD   = (1 << 3),		// 가격이 개수 / 가격으로 변함
			ITEM_FLAG_SLOW_QUERY        = (1 << 4),		// 게임 종료시에만 SQL에 쿼리함
			ITEM_FLAG_RARE              = (1 << 5),
			ITEM_FLAG_UNIQUE            = (1 << 6),
			ITEM_FLAG_MAKECOUNT			= (1 << 7),
			ITEM_FLAG_IRREMOVABLE		= (1 << 8),
			ITEM_FLAG_CONFIRM_WHEN_USE	= (1 << 9),
			ITEM_FLAG_QUEST_USE         = (1 << 10),    // 퀘스트 스크립트 돌리는지?
			ITEM_FLAG_QUEST_USE_MULTIPLE= (1 << 11),    // 퀘스트 스크립트 돌리는지?
			ITEM_FLAG_UNUSED03          = (1 << 12),    // UNUSED03
			ITEM_FLAG_LOG               = (1 << 13),    // 사용시 로그를 남기는 아이템인가?
			ITEM_FLAG_APPLICABLE		= (1 << 14),
		};

		enum EWearPositions
		{
			WEAR_BODY,          // 0
			WEAR_HEAD,          // 1
			WEAR_FOOTS,         // 2
			WEAR_WRIST,         // 3
			WEAR_WEAPON,        // 4
			WEAR_NECK,          // 5
			WEAR_EAR,           // 6
			WEAR_UNIQUE1,       // 7
			WEAR_UNIQUE2,       // 8
			WEAR_ARROW,         // 9
			WEAR_SHIELD,        // 10

			WEAR_ABILITY1,  // 11
			WEAR_ABILITY2,  // 12
			WEAR_ABILITY3,  // 13
			WEAR_ABILITY4,  // 14
			WEAR_ABILITY5,  // 15
			WEAR_ABILITY6,  // 16
			WEAR_ABILITY7,  // 17
			WEAR_ABILITY8,  // 18
			WEAR_COSTUME_BODY,	// 19
			WEAR_COSTUME_HAIR,	// 20

#ifdef ENABLE_WEAPON_COSTUME_SYSTEM
			WEAR_COSTUME_WEAPON,// 21
#endif

			WEAR_SPECIAL, // 22

			WEAR_MAX_NUM = 32,
		};

		enum EItemWearableFlag
		{
			WEARABLE_BODY       = (1 << 0),
			WEARABLE_HEAD       = (1 << 1),
			WEARABLE_FOOTS      = (1 << 2),
			WEARABLE_WRIST      = (1 << 3),
			WEARABLE_WEAPON     = (1 << 4),
			WEARABLE_NECK       = (1 << 5),
			WEARABLE_EAR        = (1 << 6),
			WEARABLE_UNIQUE     = (1 << 7),
			WEARABLE_SHIELD     = (1 << 8),
			WEARABLE_ARROW      = (1 << 9),
		};

		enum EApplyTypes
		{
			APPLY_NONE,                 // 0
			APPLY_MAX_HP,               // 1
			APPLY_MAX_SP,               // 2
			APPLY_CON,                  // 3
			APPLY_INT,                  // 4
			APPLY_STR,                  // 5
			APPLY_DEX,                  // 6
			APPLY_ATT_SPEED,            // 7
			APPLY_MOV_SPEED,            // 8
			APPLY_CAST_SPEED,           // 9
			APPLY_HP_REGEN,             // 10
			APPLY_SP_REGEN,             // 11
			APPLY_POISON_PCT,           // 12
			APPLY_STUN_PCT,             // 13
			APPLY_SLOW_PCT,             // 14
			APPLY_CRITICAL_PCT,         // 15
			APPLY_PENETRATE_PCT,        // 16
			APPLY_ATTBONUS_HUMAN,       // 17
			APPLY_ATTBONUS_ANIMAL,      // 18
			APPLY_ATTBONUS_ORC,         // 19
			APPLY_ATTBONUS_MILGYO,      // 20
			APPLY_ATTBONUS_UNDEAD,      // 21
			APPLY_ATTBONUS_DEVIL,       // 22
			APPLY_STEAL_HP,             // 23
			APPLY_STEAL_SP,             // 24
			APPLY_MANA_BURN_PCT,        // 25
			APPLY_DAMAGE_SP_RECOVER,    // 26
			APPLY_BLOCK,                // 27
			APPLY_DODGE,                // 28
			APPLY_RESIST_SWORD,         // 29
			APPLY_RESIST_TWOHAND,       // 30
			APPLY_RESIST_DAGGER,        // 31
			APPLY_RESIST_BELL,          // 32
			APPLY_RESIST_FAN,           // 33
			APPLY_RESIST_BOW,           // 34
			APPLY_RESIST_FIRE,          // 35
			APPLY_RESIST_ELEC,          // 36
			APPLY_RESIST_MAGIC,         // 37
			APPLY_RESIST_WIND,          // 38
			APPLY_REFLECT_MELEE,        // 39
			APPLY_REFLECT_CURSE,        // 40
			APPLY_POISON_REDUCE,        // 41
			APPLY_KILL_SP_RECOVER,      // 42
			APPLY_EXP_DOUBLE_BONUS,     // 43
			APPLY_GOLD_DOUBLE_BONUS,    // 44
			APPLY_ITEM_DROP_BONUS,      // 45
			APPLY_POTION_BONUS,         // 46
			APPLY_KILL_HP_RECOVER,      // 47
			APPLY_IMMUNE_STUN,          // 48
			APPLY_IMMUNE_SLOW,          // 49
			APPLY_IMMUNE_FALL,          // 50
			APPLY_SKILL,                // 51
			APPLY_BOW_DISTANCE,         // 52
			APPLY_ATT_GRADE_BONUS,            // 53
			APPLY_DEF_GRADE_BONUS,            // 54
			APPLY_MAGIC_ATT_GRADE,      // 55
			APPLY_MAGIC_DEF_GRADE,      // 56
			APPLY_CURSE_PCT,            // 57
			APPLY_MAX_STAMINA,			// 58
			APPLY_ATT_BONUS_TO_WARRIOR, // 59
			APPLY_ATT_BONUS_TO_ASSASSIN,// 60
			APPLY_ATT_BONUS_TO_SURA,    // 61
			APPLY_ATT_BONUS_TO_SHAMAN,  // 62
			APPLY_ATT_BONUS_TO_MONSTER, // 63
			APPLY_MALL_ATTBONUS,        // 64 공격력 +x%
			APPLY_MALL_DEFBONUS,        // 65 방어력 +x%
			APPLY_MALL_EXPBONUS,        // 66 경험치 +x%
			APPLY_MALL_ITEMBONUS,       // 67 아이템 드롭율 x/10배
			APPLY_MALL_GOLDBONUS,       // 68 돈 드롭율 x/10배
			APPLY_MAX_HP_PCT,           // 69 최대 생명력 +x%
			APPLY_MAX_SP_PCT,           // 70 최대 정신력 +x%
			APPLY_SKILL_DAMAGE_BONUS,   // 71 스킬 데미지 * (100+x)%
			APPLY_NORMAL_HIT_DAMAGE_BONUS,      // 72 평타 데미지 * (100+x)%
			APPLY_SKILL_DEFEND_BONUS,   // 73 스킬 데미지 방어 * (100-x)%
			APPLY_NORMAL_HIT_DEFEND_BONUS,      // 74 평타 데미지 방어 * (100-x)%
			APPLY_EXTRACT_HP_PCT,		//75
			APPLY_PC_BANG_EXP_BONUS,		//76
			APPLY_PC_BANG_DROP_BONUS,		//77
			APPLY_RESIST_WARRIOR,			//78
			APPLY_RESIST_ASSASSIN ,			//79
			APPLY_RESIST_SURA,				//80
			APPLY_RESIST_SHAMAN,			//81
			APPLY_UNUSED1,
			APPLY_DEF_GRADE,				// 83 방어력. DEF_GRADE_BONUS는 클라에서 두배로 보여지는 의도된 버그(...)가 있다.
			APPLY_COSTUME_ATTR_BONUS,		// 84 코스튬 아이템에 붙은 속성치 보너스
			APPLY_MAGIC_ATTBONUS_PER,		// 85 마법 공격력 +x%
			APPLY_MELEE_MAGIC_ATTBONUS_PER,			// 86 마법 + 밀리 공격력 +x%

			APPLY_RESIST_ICE,		// 87 냉기 저항
			APPLY_RESIST_EARTH,		// 88 대지 저항
			APPLY_RESIST_DARK,		// 89 어둠 저항

			APPLY_ANTI_CRITICAL_PCT,	//90 크리티컬 저항
			APPLY_ANTI_PENETRATE_PCT,	//91 관통타격 저항

#ifdef ENABLE_WOLFMAN_CHARACTER
			APPLY_BLEEDING_REDUCE			= 92,	//92
			APPLY_BLEEDING_PCT				= 93,	//93
			APPLY_ATT_BONUS_TO_WOLFMAN		= 94,	//94
			APPLY_RESIST_WOLFMAN			= 95,	//95
			APPLY_RESIST_CLAW				= 96,	//96
#endif

#ifdef ENABLE_ACCE_COSTUME_SYSTEM
			APPLY_ACCEDRAIN_RATE			= 97,	//97
#endif

#ifdef ENABLE_MAGIC_REDUCTION_SYSTEM
			APPLY_RESIST_MAGIC_REDUCTION	= 98,	//98
#endif

			MAX_APPLY_NUM					= 99,
		};

		enum EImmuneFlags
		{
			IMMUNE_PARA         = (1 << 0),
			IMMUNE_CURSE        = (1 << 1),
			IMMUNE_STUN         = (1 << 2),
			IMMUNE_SLEEP        = (1 << 3),
			IMMUNE_SLOW         = (1 << 4),
			IMMUNE_POISON       = (1 << 5),
			IMMUNE_TERROR       = (1 << 6),
		};

#pragma pack(push)
#pragma pack(1)
		typedef struct SItemLimit
		{
			BYTE        bType;
			long        lValue;
		} TItemLimit;

		typedef struct SItemApply
		{
			BYTE        bType;
			long        lValue;
		} TItemApply;

		typedef struct SItemTable_r152
		{
			DWORD       dwVnum;
			char        szName[ITEM_NAME_MAX_LEN + 1];
			char        szLocaleName[ITEM_NAME_MAX_LEN + 1];
			BYTE        bType;
			BYTE        bSubType;

			BYTE        bWeight;
			BYTE        bSize;

			DWORD       dwAntiFlags;
			DWORD       dwFlags;
			DWORD       dwWearFlags;
			DWORD       dwImmuneFlag;

			GoldType       dwIBuyItemPrice;
			GoldType		dwISellItemPrice;

			TItemLimit  aLimits[ITEM_LIMIT_MAX_NUM];
			TItemApply  aApplies[ITEM_APPLY_MAX_NUM];
			long        alValues[ITEM_VALUES_MAX_NUM];
			long        alSockets[ITEM_SOCKET_MAX_NUM];
			DWORD       dwRefinedVnum;
			WORD		wRefineSet;
			BYTE        bAlterToMagicItemPct;
			BYTE		bSpecular;
			BYTE        bGainSocketPct;
		} TItemTable_r152;

		typedef struct SItemTable_r156
		{
			DWORD       dwVnum;
			DWORD       dwVnumRange;
			char        szName[ITEM_NAME_MAX_LEN + 1];
			char        szLocaleName[ITEM_NAME_MAX_LEN + 1];
			BYTE        bType;
			BYTE        bSubType;

			BYTE        bWeight;
			BYTE        bSize;

			DWORD       dwAntiFlags;
			DWORD       dwFlags;
			DWORD       dwWearFlags;
			DWORD       dwImmuneFlag;

			GoldType       dwIBuyItemPrice;
			GoldType		dwISellItemPrice;

			TItemLimit  aLimits[ITEM_LIMIT_MAX_NUM];
			TItemApply  aApplies[ITEM_APPLY_MAX_NUM];
			long        alValues[ITEM_VALUES_MAX_NUM];
			long        alSockets[ITEM_SOCKET_MAX_NUM];
			DWORD       dwRefinedVnum;
			WORD		wRefineSet;
			BYTE        bAlterToMagicItemPct;
			BYTE		bSpecular;
			BYTE        bGainSocketPct;
		} TItemTable_r156;

		typedef struct SItemTable_r158
		{
			DWORD       dwVnum;
			DWORD       dwVnumRange;
			char        szName[ITEM_NAME_MAX_LEN + 1];
			char        szLocaleName[ITEM_NAME_MAX_LEN + 1];
			BYTE        bType;
			BYTE        bSubType;

			BYTE        bWeight;
			BYTE        bSize;

			DWORD       dwAntiFlags;
			DWORD       dwFlags;
			DWORD       dwWearFlags;
			DWORD       dwImmuneFlag;

			GoldType       dwIBuyItemPrice;
			GoldType		dwISellItemPrice;

			TItemLimit  aLimits[ITEM_LIMIT_MAX_NUM];
			TItemApply  aApplies[ITEM_APPLY_MAX_NUM];
			long        alValues[ITEM_VALUES_MAX_NUM];
			long        alSockets[ITEM_SOCKET_MAX_NUM];
			DWORD       dwRefinedVnum;
			WORD		wRefineSet;
			BYTE        bAlterToMagicItemPct;
			BYTE		bSpecular;
			BYTE        bGainSocketPct;
			WORD		wWearableFlag;
		} TItemTable_r158;

		typedef SItemTable_r156 SItemTable, TItemTable;

#ifdef ENABLE_PROTOSTRUCT_AUTODETECT
		typedef struct SItemTableAll
		{
			static bool IsValidStruct(DWORD structSize)
			{
				switch (structSize)
				{
					case sizeof(TItemTable_r152):
					case sizeof(TItemTable_r156):
					case sizeof(TItemTable_r158):
						return true;
						break;
				}
				return false;
			}

			static void Process(void* obj, DWORD structSize, DWORD i, CItemData::TItemTable& t)
			{
				#define ITABLE_COPY_STR(x) strncpy_s(t.##x##, sizeof(t.##x##), r.##x##, _TRUNCATE)
				#define ITABLE_COPY_INT(x) t.##x## = r.##x
				#define ITABLE_ZERO_STR(x) memset(t.##x##, 0, sizeof(t.##x##));
				#define ITABLE_ZERO_INT(x) t.##x## = 0
				#define ITABLE_COUNT(x) _countof(t.##x##)
				#define ITABLE_PROCESS(len)\
					CItemData::TItemTable_r##len## & r = *((CItemData::TItemTable_r##len## *) obj + i);\
					ITABLE_COPY_INT(dwVnum);\
					ITABLE_COPY_STR(szName);\
					ITABLE_COPY_STR(szLocaleName);\
					ITABLE_COPY_INT(bType);\
					ITABLE_COPY_INT(bSubType);\
					ITABLE_COPY_INT(bWeight);\
					ITABLE_COPY_INT(bSize);\
					ITABLE_COPY_INT(dwAntiFlags);\
					ITABLE_COPY_INT(dwFlags);\
					ITABLE_COPY_INT(dwWearFlags);\
					ITABLE_COPY_INT(dwImmuneFlag);\
					ITABLE_COPY_INT(dwIBuyItemPrice);\
					ITABLE_COPY_INT(dwISellItemPrice);\
					for (size_t i=0; i<ITABLE_COUNT(aLimits); ++i)\
					{\
						ITABLE_COPY_INT(aLimits[i].bType);\
						ITABLE_COPY_INT(aLimits[i].lValue);\
					}\
					for (size_t i=0; i<CItemData::ITEM_APPLY_MAX_NUM; ++i)\
					{\
						ITABLE_COPY_INT(aApplies[i].bType);\
						ITABLE_COPY_INT(aApplies[i].lValue);\
					}\
					for (size_t i=0; i<CItemData::ITEM_VALUES_MAX_NUM; ++i)\
					{\
						ITABLE_COPY_INT(alValues[i]);\
					}\
					for (size_t i=0; i<CItemData::ITEM_SOCKET_MAX_NUM; ++i)\
					{\
						ITABLE_COPY_INT(alSockets[i]);\
					}\
					ITABLE_COPY_INT(dwRefinedVnum);\
					ITABLE_COPY_INT(wRefineSet);\
					ITABLE_COPY_INT(bAlterToMagicItemPct);\
					ITABLE_COPY_INT(bSpecular);\
					ITABLE_COPY_INT(bGainSocketPct);

				switch (structSize)
				{
					case sizeof(TItemTable_r152):
						{
							ITABLE_PROCESS(152);
							ITABLE_ZERO_INT(dwVnumRange);
						}
						break;
					case sizeof(TItemTable_r156):
						{
							ITABLE_PROCESS(156);
							ITABLE_COPY_INT(dwVnumRange);
						}
						break;
					case sizeof(TItemTable_r158):
						{
							ITABLE_PROCESS(158);
							ITABLE_COPY_INT(dwVnumRange);
						}
						break;
				}
			}
		} TItemTableAll;
#endif //ENABLE_PROTOSTRUCT_AUTODETECT

#pragma pack(pop)

	public:
		CItemData();
		virtual ~CItemData();

		void Clear();
		void SetSummary(const std::string& c_rstSumm);
		void SetDescription(const std::string& c_rstDesc);
#ifdef ENABLE_LANG_SYSTEM
		void SetName(const std::string& c_Name);
#endif

		CGraphicThing * GetModelThing();
		CGraphicThing * GetSubModelThing();
		CGraphicThing * GetDropModelThing();
		CGraphicSubImage * GetIconImage();

		DWORD GetLODModelThingCount();
		BOOL GetLODModelThingPointer(DWORD dwIndex, CGraphicThing ** ppModelThing);

		DWORD GetAttachingDataCount();
		BOOL GetCollisionDataPointer(DWORD dwIndex, const NRaceData::TAttachingData ** c_ppAttachingData);
		BOOL GetAttachingDataPointer(DWORD dwIndex, const NRaceData::TAttachingData ** c_ppAttachingData);

		/////
		const TItemTable*	GetTable() const;
		DWORD GetIndex() const;
		const char * GetName() const;
		const char * GetDescription() const;
		const char * GetSummary() const;
		BYTE GetType() const;
		BYTE GetSubType() const;
		UINT GetRefine() const;
		const char* GetUseTypeString() const;
		DWORD GetWeaponType() const;
		BYTE GetSize() const;
		BOOL IsAntiFlag(DWORD dwFlag) const;
		BOOL IsFlag(DWORD dwFlag) const;
		BOOL IsWearableFlag(DWORD dwFlag) const;
		BOOL HasNextGrade() const;
		DWORD GetWearFlags() const;
		GoldType GetIBuyItemPrice() const;
		GoldType GetISellItemPrice() const;
		BOOL GetLimit(BYTE byIndex, TItemLimit * pItemLimit) const;
		BOOL GetApply(BYTE byIndex, TItemApply * pItemApply) const;
		long GetValue(BYTE byIndex) const;
		long GetSocket(BYTE byIndex) const;
		long SetSocket(BYTE byIndex,DWORD value);
		int GetSocketCount() const;
		DWORD GetIconNumber() const;

		UINT	GetSpecularPoweru() const;
		float	GetSpecularPowerf() const;

		/////

		BOOL IsEquipment() const;

		/////

		//BOOL LoadItemData(const char * c_szFileName);
		void SetDefaultItemData(const char * c_szIconFileName, const char * c_szModelFileName  = NULL);
		void SetItemTableData(TItemTable * pItemTable);

#ifdef ENABLE_SHINING_SYSTEM
    struct TItemShiningTable 
	{
        char szShinings[ITEM_SHINING_MAX_COUNT][256];
    public:
        bool Any() const
        {
            for (int i = 0; i < CItemData::ITEM_SHINING_MAX_COUNT; i++)
            {
                if (strcmp(szShinings[i], ""))
                {
                    return true;
                }
            }
            return false;
        }
    };
	
    void SetItemShiningTableData(BYTE bIndex, const char* szEffectname);
    CItemData::TItemShiningTable GetItemShiningTable() { return m_ItemShiningTable; }
#endif

	protected:
		void __LoadFiles();
		void __SetIconImage(const char * c_szFileName);

	protected:
		std::string m_strModelFileName;
		std::string m_strSubModelFileName;
		std::string m_strDropModelFileName;
		std::string m_strIconFileName;
		std::string m_strDescription;
		std::string m_strSummary;
		std::vector<std::string> m_strLODModelFileNameVector;

		CGraphicThing * m_pModelThing;
		CGraphicThing * m_pSubModelThing;
		CGraphicThing * m_pDropModelThing;
		CGraphicSubImage * m_pIconImage;
		std::vector<CGraphicThing *> m_pLODModelThingVector;

		NRaceData::TAttachingDataVector m_AttachingDataVector;
		DWORD		m_dwVnum;
		TItemTable m_ItemTable;
#ifdef ENABLE_SHINING_SYSTEM
		TItemShiningTable m_ItemShiningTable;
#endif

	public:
		static void DestroySystem();

		static CItemData* New();
		static void Delete(CItemData* pkItemData);

		static CDynamicPool<CItemData>		ms_kPool;
};
