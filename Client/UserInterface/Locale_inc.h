#pragma once

//////////////////////////////////////////////////////////////////////////
// ### Default Ymir Macros ###
#define LOCALE_SERVICE_EUROPE
#define ENABLE_COSTUME_SYSTEM
// ### Default Ymir Macros ###
#define CEF_BROWSER // CEF Browser
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////

// --- Offline Shop by Great
#define ENABLE_OFFLINE_SHOP
#define ENABLE_FULL_YANG

// --- TP Anzeige
//#define ENABLE_VIEW_TARGET_PLAYER_HP
#define ENABLE_VIEW_TARGET_DECIMAL_HP

// --- Channel Switcher
#define ENABLE_MOVE_CHANNEL

// --- Verbesserungsfenster geöffnet lassen
#define ENABLE_REFINE_RENEWAL

// --- Restart Tod NEU
#define RENEWAL_DEAD_PACKET

// --- Aktive Affects bei Mobs und Spieler anzeigen
#define ENABLE_TARGET_AFFECT

// --- Schreibt info in PN
#define ENABLE_WHISPER_TIPPING

// --- VWK per Button rückverwandeln
#define ENABLE_AFFECT_POLYMORPH_REMOVE

// --- ALT-KEY EQ-Vergleichen
#define __COMPARE_TOOLTIP__

// --- Stack enpacken Add-on
#define ENABLE_UNSTACK_ADDON

// --- Item Namen auf Boden Erweiterung
#define ENABLE_EXTENDED_ITEMNAME_ON_GROUND

// --- Monster Target Info
#define ENABLE_SEND_TARGET_INFO

// -- New Login Interface
#define CRYPT_LOGINSETTINGS

// -- Ladescreen Infos
#define __LOADING_TIP__

//////////////////////////////////////////////////////////////////////////

#define ENABLE_SHINING_SYSTEM
#define WJ_ENABLE_TRADABLE_ICON
#define GMS_CAN_WALK_REALLY_FAST
#define ENABLE_LANG_SYSTEM

typedef long long GoldType;

//////////////////////////////////////////////////////////////////////////
// ### New From LocaleInc ###
#define ENABLE_PACK_GET_CHECK
#define ENABLE_CANSEEHIDDENTHING_FOR_GM
#define ENABLE_PROTOSTRUCT_AUTODETECT

// #define ENABLE_PLAYER_PER_ACCOUNT5
#define ENABLE_LEVEL_IN_TRADE
// #define ENABLE_DICE_SYSTEM
#define ENABLE_EXTEND_INVEN_SYSTEM
#define ENABLE_LVL115_ARMOR_EFFECT
#define ENABLE_SLOT_WINDOW_EX
#define ENABLE_TEXT_LEVEL_REFRESH
#define ENABLE_USE_COSTUME_ATTR

#define WJ_SHOW_MOB_INFO
#ifdef WJ_SHOW_MOB_INFO
#define ENABLE_SHOW_MOBAIFLAG
#define ENABLE_SHOW_MOBLEVEL
#endif
// ### New From LocaleInc ###
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// ### From GameLib ###
// #define ENABLE_WOLFMAN_CHARACTER

// #define ENABLE_MAGIC_REDUCTION_SYSTEM
// #define ENABLE_MOUNT_COSTUME_SYSTEM
#define ENABLE_WEAPON_COSTUME_SYSTEM
// ### From GameLib ###
//////////////////////////////////////////////////////////////////////////
