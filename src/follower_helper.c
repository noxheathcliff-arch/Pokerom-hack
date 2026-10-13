#include "global.h"
#include "data.h"
#include "event_scripts.h"
#include "follower_helper.h"
#include "overworld.h"
#include "rtc.h"
#include "constants/battle.h"
#include "constants/followers.h"
#include "constants/metatile_behaviors.h"
#include "constants/pokemon.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/weather.h"

#define TYPE_NOT_TYPE1 NUMBER_OF_MON_TYPES

// difficult conditional messages follow
static const u8 sCondMsg00[] = _("{STR_VAR_1} danse avec entrain.");
static const u8 sCondMsg01[] = _("{STR_VAR_1} danse avec grâce!");
static const u8* const sCelebiTexts[] = {sCondMsg00, sCondMsg01, NULL};
static const u8 sCondMsg02[] = _("{STR_VAR_1} produit des flammes et se\nsent d'attaque!");
static const u8 sCondMsg03[] = _("{STR_VAR_1} produit de vives flammes!");
static const u8 sCondMsg04[] = _("{STR_VAR_1} montre qu'il veut en\ndécoudre en crachant des flammes!");
static const u8 sCondMsg05[] = _("{STR_VAR_1} produit de vives flammes!");
static const u8* const sFireTexts[] = {sCondMsg02, sCondMsg03, sCondMsg04, sCondMsg05, NULL};
static const u8 sCondMsg06[] = _("{STR_VAR_1} regarde droit vers\nla Ligue Pokémon.");
static const u8 sCondMsg07[] = _("{STR_VAR_1} fixe la montagne.");
static const u8 sCondMsg08[] = _("Snif! Snif!\nIl a repéré une bonne odeur!");
static const u8 sCondMsg09[] = _("Il farfouille dans les étagères.");
static const u8 sCondMsg10[] = _("{STR_VAR_1} fixe les étagères.");
static const u8* const sShopTexts[] = {sCondMsg09, sCondMsg10, NULL};
static const u8 sCondMsg11[] = _("{STR_VAR_1} regarde fixement son\nvisage.");
static const u8 sCondMsg12[] = _("{STR_VAR_1} est intrigué par la\nBicyclette on dirait!");
static const u8 sCondMsg13[] = _("{STR_VAR_1} veut toucher\nla machine!");
static const u8 sCondMsg14[] = _("{STR_VAR_1} tangue avec le bateau.");
static const u8 sCondMsg15[] = _("{STR_VAR_1} sautille au rythme du\ntangage du bateau.");
static const u8 sCondMsg16[] = _("{STR_VAR_1} n'a pas encore l'air de\nvouloir descendre du bateau.");
static const u8* const sBoatTexts[] = {sCondMsg14, sCondMsg15, sCondMsg16, NULL};
static const u8 sCondMsg17[] = _("{STR_VAR_1} écoute le bruit de la\nmachine.");
static const u8* const sMachineTexts[] = {sCondMsg13, sCondMsg17, NULL};
static const u8 sCondMsg18[] = _("Il s'amuse à éclabousser partout!");
static const u8 sCondMsg19[] = _("Il joue dans le sable!");
static const u8 sCondMsg20[] = _("{STR_VAR_1} s'amuse à arracher\nles herbes.");
static const u8 sCondMsg21[] = _("Il est content de voir les traces de\npas de {PLAYER}!");
static const u8 sCondMsg22[] = _("{STR_VAR_1} est à l'étroit et\ns'énerve!");
static const u8 sCondMsg23[] = _("{STR_VAR_1} est à l'étroit et se met\nen alerte!");
static const u8* const sElevatorTexts[] = {sCondMsg22, sCondMsg23, NULL};
static const u8 sCondMsg24[] = _("Le vent s'est rafraîchi!");
static const u8 sCondMsg25[] = _("{STR_VAR_1} a manqué de trébucher!");
static const u8 sCondMsg26[] = _("Il est surpris en touchant la glace!");
static const u8* const sColdTexts[] = {sCondMsg24, sCondMsg25, sCondMsg26, NULL};
static const u8 sCondMsg27[] = _("Il a des pétales sur la frimousse!");
static const u8 sCondMsg28[] = _("{STR_VAR_1} se met à couiner!");
static const u8 sCondMsg29[] = _("{STR_VAR_1} tremble de peur.");
static const u8 sCondMsg30[] = _("{STR_VAR_1} a l'air triste…");
static const u8* const sFearTexts[] = {sCondMsg29, sCondMsg30, NULL};
static const u8 sCondMsg31[] = _("{STR_VAR_1} se met à l'abri dans les\nhautes herbes.");
static const u8 sCondMsg32[] = _("{STR_VAR_1} a l'air d'avoir très froid.");
static const u8 sCondMsg33[] = _("{STR_VAR_1} fixe la mer.");
static const u8 sCondMsg34[] = _("Il fixe la mer!");
static const u8 sCondMsg35[] = _("{STR_VAR_1} admire le flux et le reflux\nde la mer.");
static const u8* const sSeaTexts[] = {sCondMsg33, sCondMsg34, sCondMsg35, NULL};
static const u8 sCondMsg36[] = _("{STR_VAR_1} écoute le bruit de l'eau\nqui coule avec intérêt.");
static const u8 sCondMsg37[] = _("{STR_VAR_1} a l'air d'aimer la pluie!");
static const u8 sCondMsg38[] = _("{STR_VAR_1} regarde son reflet\ndans l'eau…");
static const u8 sCondMsg39[] = _("{STR_VAR_1} se détend en entendant le\nbruissement des feuilles…");
static const u8 sCondMsg40[] = _("{STR_VAR_1} gratte la glace.");
static const u8 sCondMsg41[] = _("{STR_VAR_1} tripote la glace.");
static const u8* const sIceTexts[] = {sCondMsg26, sCondMsg40, sCondMsg41, NULL};
static const u8 sCondMsg42[] = _("{STR_VAR_1} souffre de sa brûlure.");
static const u8 sCondMsg43[] = _("{STR_VAR_1} regarde dehors et\ns'excite!");
static const u8 sCondMsg44[] = _("{STR_VAR_1} lève les yeux vers le ciel.");
static const u8* const sDayTexts[] = {sCondMsg43, sCondMsg44, NULL};
static const u8 sCondMsg45[] = _("Il aime le ciel étoilé!");
static const u8 sCondMsg46[] = _("Il est fasciné par le ciel étoilé!");
static const u8* const sNightTexts[] = {sCondMsg45, sCondMsg46, NULL};
static const u8 sCondMsg50[] = _("{STR_VAR_1} est inquiet\nà cause de la météo!");

// See the struct definition in follower_helper.h for more info
const struct FollowerMsgInfoExtended gFollowerConditionalMessages[COND_MSG_COUNT] =
{
    [COND_MSG_CELEBI] =
    {
        .text = (u8*)sCelebiTexts,
        .textSpread = 1,
        .script = EventScript_FollowerDance,
        .emotion = FOLLOWER_EMOTION_NEUTRAL,
        .conditions =
        {
            MATCH_SPECIES(SPECIES_CELEBI),
        },
    },
    [COND_MSG_FIRE] =
    {
        .text = (u8*)sFireTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_NEUTRAL,
        .conditions =
        {
            MATCH_TYPES(TYPE_FIRE, TYPE_FIRE),
        },
    },
    [COND_MSG_EVER_GRANDE] =
    {
        .text = sCondMsg06,
        .script = EventScript_FollowerFaceUp,
        .emotion = FOLLOWER_EMOTION_HAPPY,
        .conditions =
        {
            MATCH_MAP(MAP_EVER_GRANDE_CITY),
        },
    },
    [COND_MSG_ROUTE_112] =
    {
        .text = sCondMsg07,
        .emotion = FOLLOWER_EMOTION_HAPPY,
        .conditions =
        {
            MATCH_MAP(MAP_ROUTE112),
        },
    },
    [COND_MSG_DAY_CARE] =
    {
        .text = sCondMsg08,
        .script = EventScript_FollowerNostalgia,
        .emotion = FOLLOWER_EMOTION_NEUTRAL,
        .conditions =
        {
            MATCH_MAP(MAP_ROUTE117_POKEMON_DAY_CARE)
        },
    },
    [COND_MSG_MART] =
    {
        .text = (u8*)sShopTexts,
        .textSpread = 1,
        .script = EventScript_FollowerLookAround,
        .emotion = FOLLOWER_EMOTION_NEUTRAL,
        .conditions =
        {
            MATCH_MUSIC(MUS_POKE_MART)
        },
    },
    [COND_MSG_VICTORY_ROAD] =
    {
        .text = sCondMsg11,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_MUSIC(MUS_VICTORY_ROAD)
        },
    },
    [COND_MSG_BIKE_SHOP] =
    {
        .text = sCondMsg12,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_MAP(MAP_MAUVILLE_CITY_BIKE_SHOP)
        },
    },
    [COND_MSG_MACHINES] =
    {
        .text = (u8*)sMachineTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .orFlag = 1, // match any of these maps
        .conditions =
        {
            MATCH_MAP(MAP_NEW_MAUVILLE_INSIDE),
            MATCH_MAP(MAP_SLATEPORT_CITY_STERNS_SHIPYARD_1F),
            MATCH_MAP(MAP_SLATEPORT_CITY_STERNS_SHIPYARD_2F),
        },
    },
    [COND_MSG_SAILING] =
    {
        .text = (u8*)sBoatTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .script = EventScript_FollowerLookAround,
        .conditions =
        {
            MATCH_MUSIC(MUS_SAILING),
        },
    },
    [COND_MSG_PUDDLE] =
    {
        .text = sCondMsg18,
        .script = EventScript_FollowerHopping,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_ON_MB(MB_SHALLOW_WATER, MB_PUDDLE),
        },
    },
    [COND_MSG_SAND] =
    {
        .text = sCondMsg19,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_ON_MB(MB_SAND, MB_DEEP_SAND),
        },
    },
    [COND_MSG_GRASS] =
    {
        .text = sCondMsg20,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_ON_MB(MB_TALL_GRASS, MB_LONG_GRASS),
        },
    },
    [COND_MSG_FOOTPRINTS] =
    {
        .text = sCondMsg21,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_ON_MB(MB_SAND, MB_FOOTPRINTS),
        },
    },
    [COND_MSG_ELEVATOR] =
    {
        .text = (u8*)sElevatorTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_SURPRISE,
        .conditions =
        {
            MATCH_MAP(MAP_LILYCOVE_CITY_DEPARTMENT_STORE_ELEVATOR),
        },
    },
    [COND_MSG_ICE_ROOM] =
    {
        .text = (u8*)sColdTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_SURPRISE,
        .conditions =
        {
            MATCH_MAP(MAP_SHOAL_CAVE_LOW_TIDE_ICE_ROOM),
        },
    },
    [COND_MSG_ROUTE_117] =
    {
        .text = sCondMsg27,
        .emotion = FOLLOWER_EMOTION_SURPRISE,
        .conditions =
        {
            MATCH_MAP(MAP_ROUTE117),
        },
    },
    [COND_MSG_DRAGON_GROWL] =
    {
        .text = sCondMsg28,
        .emotion = FOLLOWER_EMOTION_UPSET,
        .conditions =
        {
            MATCH_TYPES(TYPE_DRAGON, TYPE_DRAGON),
            MATCH_MAPSEC(MAPSEC_SKY_PILLAR),
        },
    },
    [COND_MSG_FEAR] =
    {
        .text = (u8*)sFearTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_UPSET,
        .conditions =
        {
            MATCH_NOT_TYPES(TYPE_GHOST, TYPE_GHOST),
            MATCH_MAPSEC(MAPSEC_MT_PYRE),
            MATCH_MUSIC(MUS_MT_PYRE),
        },
    },
    [COND_MSG_FIRE_RAIN] =
    {
        .text = sCondMsg31,
        .emotion = FOLLOWER_EMOTION_UPSET,
        .conditions =
        {
            MATCH_TYPES(TYPE_FIRE, TYPE_FIRE),
            MATCH_WEATHER(WEATHER_RAIN, WEATHER_RAIN_THUNDERSTORM),
        },
    },
    [COND_MSG_FROZEN] =
    {
        .text = sCondMsg32,
        .emotion = FOLLOWER_EMOTION_UPSET,
        .conditions =
        {
           MATCH_STATUS(STATUS1_FREEZE),
        },
    },
    [COND_MSG_SEASIDE] =
    {
        .text = (u8*)sSeaTexts,
        .textSpread = 1,
        .script = EventScript_FollowerFaceResult,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_NEAR_MB(MB_OCEAN_WATER, 5),
        },
    },
    [COND_MSG_WATERFALL] =
    {
        .text = sCondMsg36,
        .script = EventScript_FollowerFaceResult,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_NEAR_MB(MB_WATERFALL, 5),
        },
    },
    [COND_MSG_RAIN] =
    {
        .text = sCondMsg37,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
        MATCH_NOT_TYPES(TYPE_FIRE, TYPE_FIRE),
        MATCH_WEATHER(WEATHER_RAIN, WEATHER_RAIN_THUNDERSTORM)
    }
    },
    [COND_MSG_REFLECTION] =
    {
        .text = sCondMsg38,
        .script = EventScript_FollowerFaceResult,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_NEAR_MB(MB_POND_WATER, 1),
        },
    },
    [COND_MSG_LEAVES] =
    {
        .text = sCondMsg39,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_MAPSEC(MAPSEC_PETALBURG_WOODS),
        },
    },
    [COND_MSG_ICE] =
    {
        .text = (u8*)sIceTexts,
        .textSpread = 1,
        .script = EventScript_FollowerFaceResult,
        .emotion = FOLLOWER_EMOTION_PENSIVE,
        .conditions =
        {
            MATCH_NEAR_MB(MB_ICE, 1),
        },
    },
    [COND_MSG_BURN] =
    {
        .text = sCondMsg42,
        .emotion = FOLLOWER_EMOTION_SAD,
        .conditions =
        {
            MATCH_STATUS(STATUS1_BURN),
        },
    },
    [COND_MSG_DAY] =
    {
        .text = (u8*)sDayTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_TIME_OF_DAY(TIME_DAY),
        },
    },
    [COND_MSG_NIGHT] =
    {
        .text = (u8*)sNightTexts,
        .textSpread = 1,
        .emotion = FOLLOWER_EMOTION_MUSIC,
        .conditions =
        {
            MATCH_TIME_OF_DAY(TIME_NIGHT),
        },
    },
    [COND_MSG_ABNORMAL_WEATHER] =
    {
        .text = sCondMsg50,
        .emotion = FOLLOWER_EMOTION_SURPRISE,
        .conditions =
        {
            MATCH_MUSIC(MUS_ABNORMAL_WEATHER),
            MATCH_NOT_SPECIES(SPECIES_KYOGRE),
            MATCH_NOT_SPECIES(SPECIES_GROUDON),
            MATCH_NOT_SPECIES(SPECIES_RAYQUAZA),
        }
    },
};

// Pool of "unconditional" follower messages
const struct FollowerMessagePool gFollowerBasicMessages[FOLLOWER_EMOTION_LENGTH] =
{
    [FOLLOWER_EMOTION_HAPPY]    = {gFollowerHappyMessages,    EventScript_FollowerGeneric, FOLLOWER_HAPPY_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_NEUTRAL]  = {gFollowerNeutralMessages,  EventScript_FollowerGeneric, FOLLOWER_NEUTRAL_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_SAD]      = {gFollowerSadMessages,      EventScript_FollowerGeneric, FOLLOWER_SAD_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_UPSET]    = {gFollowerUpsetMessages,    EventScript_FollowerGeneric, FOLLOWER_UPSET_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_ANGRY]    = {gFollowerAngryMessages,    EventScript_FollowerGeneric, FOLLOWER_ANGRY_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_PENSIVE]  = {gFollowerPensiveMessages,  EventScript_FollowerGeneric, FOLLOWER_PENSIVE_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_LOVE]     = {gFollowerLoveMessages,     EventScript_FollowerGeneric, FOLLOWER_LOVE_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_SURPRISE] = {gFollowerSurpriseMessages, EventScript_FollowerGeneric, FOLLOWER_SURPRISE_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_CURIOUS]  = {gFollowerCuriousMessages,  EventScript_FollowerGeneric, FOLLOWER_CURIOUS_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_MUSIC]    = {gFollowerMusicMessages,    EventScript_FollowerGeneric, FOLLOWER_MUSIC_MESSAGE_COUNT},
    [FOLLOWER_EMOTION_POISONED] = {gFollowerPoisonedMessages, EventScript_FollowerGeneric, FOLLOWER_POISONED_MESSAGE_COUNT},
};
