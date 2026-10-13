#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen9[] =
{
#endif

#if P_FAMILY_SPRIGATITO
    [SPECIES_SPRIGATITO] =
    {
        .baseHP        = 40,
        .baseAttack    = 61,
        .baseDefense   = 54,
        .baseSpeed     = 65,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
        .expYield = 62,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_PROTEAN },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Poussacha"),
        .cryId = CRY_SPRIGATITO,
        .natDexNum = NATIONAL_DEX_SPRIGATITO,
        .categoryName = _("Chat Plante"),
        .height = 4,
        .weight = 41,
        .description = COMPOUND_STRING(
            "La boule de feu en forme d'œuf qui surmonte sa\n"
            "tête résulte de la fusion entre son énergie de\n"
            "type Feu et son trop-plein de vitalité."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sprigatito,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Sprigatito,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Sprigatito,
        .shinyPalette = gMonShinyPalette_Sprigatito,
        .iconSprite = gMonIcon_Sprigatito,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-2, 5, SHADOW_SIZE_S)
        FOOTPRINT(Sprigatito)
        OVERWORLD(
            sPicTable_Sprigatito,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sprigatito,
            gShinyOverworldPalette_Sprigatito
        )
        .levelUpLearnset = sSprigatitoLevelUpLearnset,
        .teachableLearnset = sSprigatitoTeachableLearnset,
        .eggMoveLearnset = sSprigatitoEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_FLORAGATO}),
    },

    [SPECIES_FLORAGATO] =
    {
        .baseHP        = 61,
        .baseAttack    = 80,
        .baseDefense   = 63,
        .baseSpeed     = 83,
        .baseSpAttack  = 60,
        .baseSpDefense = 63,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
        .expYield = 144,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_PROTEAN },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Matourgeon"),
        .cryId = CRY_FLORAGATO,
        .natDexNum = NATIONAL_DEX_FLORAGATO,
        .categoryName = _("Chat Plante"),
        .height = 9,
        .weight = 122,
        .description = COMPOUND_STRING(
            "Quand il chante, son oiseau de feu change de\n"
            "forme. Cet oiseau serait né lorsqu'une âme a pris\n"
            "possession de sa boule de feu."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Floragato,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Floragato,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Floragato,
        .shinyPalette = gMonShinyPalette_Floragato,
        .iconSprite = gMonIcon_Floragato,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 11, SHADOW_SIZE_M)
        FOOTPRINT(Floragato)
        OVERWORLD(
            sPicTable_Floragato,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Floragato,
            gShinyOverworldPalette_Floragato
        )
        .levelUpLearnset = sFloragatoLevelUpLearnset,
        .teachableLearnset = sFloragatoTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_MEOWSCARADA}),
    },

    [SPECIES_MEOWSCARADA] =
    {
        .baseHP        = 76,
        .baseAttack    = 110,
        .baseDefense   = 70,
        .baseSpeed     = 123,
        .baseSpAttack  = 81,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GRASS, TYPE_DARK),
        .catchRate = 45,
        .expYield = 265,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_PROTEAN },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Miascarade"),
        .cryId = CRY_MEOWSCARADA,
        .natDexNum = NATIONAL_DEX_MEOWSCARADA,
        .categoryName = _("Magicien"),
        .height = 15,
        .weight = 312,
        .description = COMPOUND_STRING(
            "Originaire d'une contrée lointaine, il est venu\n"
            "s'installer dans la région il y a longtemps. Ses\n"
            "ailes sécrètent un gel qui repousse l'eau et les\n"
            "saletés."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Meowscarada,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Meowscarada,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Meowscarada,
        .shinyPalette = gMonShinyPalette_Meowscarada,
        .iconSprite = gMonIcon_Meowscarada,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 14, SHADOW_SIZE_S)
        FOOTPRINT(Meowscarada)
        OVERWORLD(
            sPicTable_Meowscarada,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Meowscarada,
            gShinyOverworldPalette_Meowscarada
        )
        .levelUpLearnset = sMeowscaradaLevelUpLearnset,
        .teachableLearnset = sMeowscaradaTeachableLearnset,
    },
#endif //P_FAMILY_SPRIGATITO

#if P_FAMILY_FUECOCO
    [SPECIES_FUECOCO] =
    {
        .baseHP        = 67,
        .baseAttack    = 45,
        .baseDefense   = 59,
        .baseSpeed     = 36,
        .baseSpAttack  = 63,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
        .expYield = 62,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_UNAWARE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Chochodile"),
        .cryId = CRY_FUECOCO,
        .natDexNum = NATIONAL_DEX_FUECOCO,
        .categoryName = _("Croco Feu"),
        .height = 4,
        .weight = 98,
        .description = COMPOUND_STRING(
            "Ils courent dans les hauts-fonds pour renforcer\n"
            "les muscles de leurs pattes et rivalisent entre\n"
            "eux pour voir qui a le coup de pied le plus\n"
            "élégant."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Fuecoco,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Fuecoco,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Fuecoco,
        .shinyPalette = gMonShinyPalette_Fuecoco,
        .iconSprite = gMonIcon_Fuecoco,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-3, 5, SHADOW_SIZE_S)
        FOOTPRINT(Fuecoco)
        OVERWORLD(
            sPicTable_Fuecoco,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Fuecoco,
            gShinyOverworldPalette_Fuecoco
        )
        .levelUpLearnset = sFuecocoLevelUpLearnset,
        .teachableLearnset = sFuecocoTeachableLearnset,
        .eggMoveLearnset = sFuecocoEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_CROCALOR}),
    },

    [SPECIES_CROCALOR] =
    {
        .baseHP        = 81,
        .baseAttack    = 55,
        .baseDefense   = 78,
        .baseSpeed     = 49,
        .baseSpAttack  = 90,
        .baseSpDefense = 58,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
        .expYield = 144,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_UNAWARE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Crocogril"),
        .cryId = CRY_CROCALOR,
        .natDexNum = NATIONAL_DEX_CROCALOR,
        .categoryName = _("Croco Feu"),
        .height = 10,
        .weight = 307,
        .description = COMPOUND_STRING(
            "Il peut propulser un camion dans les airs d'un\n"
            "simple coup de pied. Ses puissantes pattes lui\n"
            "permettent aussi d'exécuter des danses insolites."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Crocalor,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Crocalor,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Crocalor,
        .shinyPalette = gMonShinyPalette_Crocalor,
        .iconSprite = gMonIcon_Crocalor,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 8, SHADOW_SIZE_M)
        FOOTPRINT(Crocalor)
        OVERWORLD(
            sPicTable_Crocalor,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Crocalor,
            gShinyOverworldPalette_Crocalor
        )
        .levelUpLearnset = sCrocalorLevelUpLearnset,
        .teachableLearnset = sCrocalorTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_SKELEDIRGE}),
    },

    [SPECIES_SKELEDIRGE] =
    {
        .baseHP        = 104,
        .baseAttack    = 75,
        .baseDefense   = 100,
        .baseSpeed     = 66,
        .baseSpAttack  = 110,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_FIRE, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 265,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_UNAWARE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Flâmigator"),
        .cryId = CRY_SKELEDIRGE,
        .natDexNum = NATIONAL_DEX_SKELEDIRGE,
        .categoryName = _("Chanteur"),
        .height = 16,
        .weight = 3265,
        .description = COMPOUND_STRING(
            "Il possède un sens de l'odorat développé qu'il\n"
            "utilise uniquement pour chercher de la nourriture,\n"
            "ce qu'il fait à longueur de journée."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Skeledirge,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Skeledirge,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Skeledirge,
        .shinyPalette = gMonShinyPalette_Skeledirge,
        .iconSprite = gMonIcon_Skeledirge,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 7, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Skeledirge)
        OVERWORLD(
            sPicTable_Skeledirge,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Skeledirge,
            gShinyOverworldPalette_Skeledirge
        )
        .levelUpLearnset = sSkeledirgeLevelUpLearnset,
        .teachableLearnset = sSkeledirgeTeachableLearnset,
    },
#endif //P_FAMILY_FUECOCO

#if P_FAMILY_QUAXLY
    [SPECIES_QUAXLY] =
    {
        .baseHP        = 55,
        .baseAttack    = 65,
        .baseDefense   = 45,
        .baseSpeed     = 50,
        .baseSpAttack  = 50,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield =  62,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_MOXIE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Coiffeton"),
        .cryId = CRY_QUAXLY,
        .natDexNum = NATIONAL_DEX_QUAXLY,
        .categoryName = _("Caneton"),
        .height = 5,
        .weight = 61,
        .description = COMPOUND_STRING(
            "Sa peau lisse à l'aspect satiné fait sa fierté. Le\n"
            "bout de sa queue dégage un parfum puissant."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Quaxly,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Quaxly,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Quaxly,
        .shinyPalette = gMonShinyPalette_Quaxly,
        .iconSprite = gMonIcon_Quaxly,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 5, SHADOW_SIZE_S)
        FOOTPRINT(Quaxly)
        OVERWORLD(
            sPicTable_Quaxly,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Quaxly,
            gShinyOverworldPalette_Quaxly
        )
        .levelUpLearnset = sQuaxlyLevelUpLearnset,
        .teachableLearnset = sQuaxlyTeachableLearnset,
        .eggMoveLearnset = sQuaxlyEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_QUAXWELL}),
    },

    [SPECIES_QUAXWELL] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 65,
        .baseSpeed     = 65,
        .baseSpAttack  = 65,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = 144,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_MOXIE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Canarbello"),
        .cryId = CRY_QUAXWELL,
        .natDexNum = NATIONAL_DEX_QUAXWELL,
        .categoryName = _("Leçon"),
        .height = 12,
        .weight = 215,
        .description = COMPOUND_STRING(
            "Il se sert de sa queue pour creuser son terrier\n"
            "dans les profondeurs rocheuses de la terre.\n"
            "Celui-ci peut faire jusqu'à 10 km de long."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Quaxwell,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Quaxwell,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Quaxwell,
        .shinyPalette = gMonShinyPalette_Quaxwell,
        .iconSprite = gMonIcon_Quaxwell,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 10, SHADOW_SIZE_S)
        FOOTPRINT(Quaxwell)
        OVERWORLD(
            sPicTable_Quaxwell,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Quaxwell,
            gShinyOverworldPalette_Quaxwell
        )
        .levelUpLearnset = sQuaxwellLevelUpLearnset,
        .teachableLearnset = sQuaxwellTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_QUAQUAVAL}),
    },

    [SPECIES_QUAQUAVAL] =
    {
        .baseHP        = 85,
        .baseAttack    = 120,
        .baseDefense   = 80,
        .baseSpeed     = 85,
        .baseSpAttack  = 85,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_WATER, TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = 265,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_MOXIE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Palmaval"),
        .cryId = CRY_QUAQUAVAL,
        .natDexNum = NATIONAL_DEX_QUAQUAVAL,
        .categoryName = _("Danseur"),
        .height = 18,
        .weight = 619,
        .description = COMPOUND_STRING(
            "La boule de fil qui entoure son corps est assez\n"
            "élastique pour repousser les faux d'Insécateur,\n"
            "son ennemi juré."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Quaquaval,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Quaquaval,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Quaquaval,
        .shinyPalette = gMonShinyPalette_Quaquaval,
        .iconSprite = gMonIcon_Quaquaval,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-7, 13, SHADOW_SIZE_M)
        FOOTPRINT(Quaquaval)
        OVERWORLD(
            sPicTable_Quaquaval,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Quaquaval,
            gShinyOverworldPalette_Quaquaval
        )
        .levelUpLearnset = sQuaquavalLevelUpLearnset,
        .teachableLearnset = sQuaquavalTeachableLearnset,
    },
#endif //P_FAMILY_QUAXLY

#if P_FAMILY_LECHONK
    [SPECIES_LECHONK] =
    {
        .baseHP        = 54,
        .baseAttack    = 45,
        .baseDefense   = 40,
        .baseSpeed     = 35,
        .baseSpAttack  = 35,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 255,
        .expYield = 51,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_AROMA_VEIL, ABILITY_GLUTTONY, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Gourmelet"),
        .cryId = CRY_LECHONK,
        .natDexNum = NATIONAL_DEX_LECHONK,
        .categoryName = _("Pourceau"),
        .height = 5,
        .weight = 102,
        .description = COMPOUND_STRING(
            "Ce Pokémon s'accroche aux branches ou aux\n"
            "plafonds grâce à son fil et se déplace en silence.\n"
            "Il élimine ses proies sans qu'elles le remarquent."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Lechonk,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Lechonk,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Lechonk,
        .shinyPalette = gMonShinyPalette_Lechonk,
        .iconSprite = gMonIcon_Lechonk,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, 1, SHADOW_SIZE_S)
        FOOTPRINT(Lechonk)
        OVERWORLD(
            sPicTable_Lechonk,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Lechonk,
            gShinyOverworldPalette_Lechonk
        )
        .levelUpLearnset = sLechonkLevelUpLearnset,
        .teachableLearnset = sLechonkTeachableLearnset,
        .eggMoveLearnset = sLechonkEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_OINKOLOGNE_M, CONDITIONS({IF_GENDER, MON_MALE})},
                                {EVO_LEVEL, 18, SPECIES_OINKOLOGNE_F, CONDITIONS({IF_GENDER, MON_FEMALE})}),
    },

    [SPECIES_OINKOLOGNE_M] =
    {
        .baseHP        = 110,
        .baseAttack    = 100,
        .baseDefense   = 75,
        .baseSpeed     = 65,
        .baseSpAttack  = 59,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 100,
        .expYield = 171,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(0),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_LINGERING_AROMA, ABILITY_GLUTTONY, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Fragroin"),
        .cryId = CRY_OINKOLOGNE_M,
        .natDexNum = NATIONAL_DEX_OINKOLOGNE,
        .categoryName = _("Pourceau"),
        .height = 10,
        .weight = 1200,
        .description = COMPOUND_STRING(
            "Sa troisième paire de pattes est repliée. Il\n"
            "possède assez de force pour sauter à plus de dix\n"
            "mètres lorsqu'il est en difficulté."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_OinkologneM,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_OinkologneM,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_OinkologneM,
        .shinyPalette = gMonShinyPalette_OinkologneM,
        .iconSprite = gMonIcon_OinkologneM,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 6, SHADOW_SIZE_M)
        FOOTPRINT(Oinkologne)
        OVERWORLD(
            sPicTable_OinkologneM,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_OinkologneM,
            gShinyOverworldPalette_OinkologneM
        )
        .levelUpLearnset = sOinkologneMLevelUpLearnset,
        .teachableLearnset = sOinkologneTeachableLearnset,
        .formSpeciesIdTable = sOinkologneFormSpeciesIdTable,
    },

    [SPECIES_OINKOLOGNE_F] =
    {
        .baseHP        = 115,
        .baseAttack    = 90,
        .baseDefense   = 70,
        .baseSpeed     = 65,
        .baseSpAttack  = 59,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 100,
        .expYield = 171,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(100),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_AROMA_VEIL, ABILITY_GLUTTONY, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Fragroin"),
        .cryId = CRY_OINKOLOGNE_F,
        .natDexNum = NATIONAL_DEX_OINKOLOGNE,
        .categoryName = _("Pourceau"),
        .height = 10,
        .weight = 1200,
        .description = COMPOUND_STRING(
            "Sa troisième paire de pattes est repliée. Il\n"
            "possède assez de force pour sauter à plus de dix\n"
            "mètres lorsqu'il est en difficulté."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_OinkologneF,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_OinkologneF,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_OinkologneF,
        .shinyPalette = gMonShinyPalette_OinkologneF,
        .iconSprite = gMonIcon_OinkologneF,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 6, SHADOW_SIZE_M)
        FOOTPRINT(Oinkologne)
        OVERWORLD(
            sPicTable_OinkologneF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_OinkologneF,
            gShinyOverworldPalette_OinkologneF
        )
        .levelUpLearnset = sOinkologneFLevelUpLearnset,
        .teachableLearnset = sOinkologneTeachableLearnset,
        .formSpeciesIdTable = sOinkologneFormSpeciesIdTable,
    },
#endif //P_FAMILY_LECHONK

#if P_FAMILY_TAROUNTULA
    [SPECIES_TAROUNTULA] =
    {
        .baseHP        = 35,
        .baseAttack    = 41,
        .baseDefense   = 45,
        .baseSpeed     = 20,
        .baseSpAttack  = 29,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_BUG),
        .catchRate = 255,
        .expYield = 42,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_INSOMNIA, ABILITY_NONE, ABILITY_STAKEOUT },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Tissenboule"),
        .cryId = CRY_TAROUNTULA,
        .natDexNum = NATIONAL_DEX_TAROUNTULA,
        .categoryName = _("Boule de Fil"),
        .height = 3,
        .weight = 40,
        .description = COMPOUND_STRING(
            "Il confectionne une boule de boue en mélangeant\n"
            "de la terre, du sable et de l'énergie de type Psy.\n"
            "À ses yeux, elle importe plus que sa propre vie."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tarountula,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Tarountula,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Tarountula,
        .shinyPalette = gMonShinyPalette_Tarountula,
        .iconSprite = gMonIcon_Tarountula,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 2, SHADOW_SIZE_M)
        FOOTPRINT(Tarountula)
        OVERWORLD(
            sPicTable_Tarountula,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Tarountula,
            gShinyOverworldPalette_Tarountula
        )
        .levelUpLearnset = sTarountulaLevelUpLearnset,
        .teachableLearnset = sTarountulaTeachableLearnset,
        .eggMoveLearnset = sTarountulaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 15, SPECIES_SPIDOPS}),
    },

    [SPECIES_SPIDOPS] =
    {
        .baseHP        = 60,
        .baseAttack    = 79,
        .baseDefense   = 92,
        .baseSpeed     = 35,
        .baseSpAttack  = 52,
        .baseSpDefense = 86,
        .types = MON_TYPES(TYPE_BUG),
        .catchRate = 120,
        .expYield = 141,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_INSOMNIA, ABILITY_NONE, ABILITY_STAKEOUT },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Filentrappe"),
        .cryId = CRY_SPIDOPS,
        .natDexNum = NATIONAL_DEX_SPIDOPS,
        .categoryName = _("Piège"),
        .height = 10,
        .weight = 165,
        .description = COMPOUND_STRING(
            "Le corps qui porte la sphère bouge à peine. On se\n"
            "demande donc si c'est bien lui qui contrôle les\n"
            "actions de ce Pokémon."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Spidops,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Spidops,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Spidops,
        .shinyPalette = gMonShinyPalette_Spidops,
        .iconSprite = gMonIcon_Spidops,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 8, SHADOW_SIZE_L)
        FOOTPRINT(Spidops)
        OVERWORLD(
            sPicTable_Spidops,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Spidops,
            gShinyOverworldPalette_Spidops
        )
        .levelUpLearnset = sSpidopsLevelUpLearnset,
        .teachableLearnset = sSpidopsTeachableLearnset,
    },
#endif //P_FAMILY_TAROUNTULA

#if P_FAMILY_NYMBLE
    [SPECIES_NYMBLE] =
    {
        .baseHP        = 33,
        .baseAttack    = 46,
        .baseDefense   = 40,
        .baseSpeed     = 45,
        .baseSpAttack  = 21,
        .baseSpDefense = 25,
        .types = MON_TYPES(TYPE_BUG),
        .catchRate = 190,
        .expYield = 42,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 20,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_NONE, ABILITY_TINTED_LENS },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Lilliterelle"),
        .cryId = CRY_NYMBLE,
        .natDexNum = NATIONAL_DEX_NYMBLE,
        .categoryName = _("Sauterelle"),
        .height = 2,
        .weight = 10,
        .description = COMPOUND_STRING(
            "Les Tomberro sont devenus des Pokémon Spectre\n"
            "après avoir passé de nombreuses années à\n"
            "protéger la tombe de leurs défunts maîtres."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Nymble,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Nymble,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Nymble,
        .shinyPalette = gMonShinyPalette_Nymble,
        .iconSprite = gMonIcon_Nymble,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(1, 3, SHADOW_SIZE_M)
        FOOTPRINT(Nymble)
        OVERWORLD(
            sPicTable_Nymble,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Nymble,
            gShinyOverworldPalette_Nymble
        )
        .levelUpLearnset = sNymbleLevelUpLearnset,
        .teachableLearnset = sNymbleTeachableLearnset,
        .eggMoveLearnset = sNymbleEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 24, SPECIES_LOKIX}),
    },

    [SPECIES_LOKIX] =
    {
        .baseHP        = 71,
        .baseAttack    = 102,
        .baseDefense   = 78,
        .baseSpeed     = 92,
        .baseSpAttack  = 52,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_BUG, TYPE_DARK),
        .catchRate = 30,
        .expYield = 158,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 0,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_NONE, ABILITY_TINTED_LENS },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Gambex"),
        .cryId = CRY_LOKIX,
        .natDexNum = NATIONAL_DEX_LOKIX,
        .categoryName = _("Sauterelle"),
        .height = 10,
        .weight = 175,
        .description = COMPOUND_STRING(
            "Il passe la majeure partie de son temps à dormir\n"
            "dans des cimetières. C'est le Pokémon chien le plus\n"
            "loyal au monde."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Lokix,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Lokix,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Lokix,
        .shinyPalette = gMonShinyPalette_Lokix,
        .iconSprite = gMonIcon_Lokix,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 11, SHADOW_SIZE_M)
        FOOTPRINT(Lokix)
        OVERWORLD(
            sPicTable_Lokix,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Lokix,
            gShinyOverworldPalette_Lokix
        )
        .levelUpLearnset = sLokixLevelUpLearnset,
        .teachableLearnset = sLokixTeachableLearnset,
    },
#endif //P_FAMILY_NYMBLE

#if P_FAMILY_PAWMI
    [SPECIES_PAWMI] =
    {
        .baseHP        = 45,
        .baseAttack    = 50,
        .baseDefense   = 20,
        .baseSpeed     = 60,
        .baseSpAttack  = 40,
        .baseSpDefense = 25,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = 48,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_STATIC, ABILITY_NATURAL_CURE, ABILITY_IRON_FIST },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pohm"),
        .cryId = CRY_PAWMI,
        .natDexNum = NATIONAL_DEX_PAWMI,
        .categoryName = _("Souris"),
        .height = 3,
        .weight = 25,
        .description = COMPOUND_STRING(
            "Lorsqu'il gonfle son sac gulaire, l'intensité du\n"
            "courant électrique qu'il produit augmente. Il peut\n"
            "parcourir 700 km par jour en planant."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pawmi,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Pawmi,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Pawmi,
        .shinyPalette = gMonShinyPalette_Pawmi,
        .iconSprite = gMonIcon_Pawmi,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(1, 4, SHADOW_SIZE_M)
        FOOTPRINT(Pawmi)
            OVERWORLD(
            sPicTable_Pawmi,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Pawmi,
            gShinyOverworldPalette_Pawmi
        )
        .levelUpLearnset = sPawmiLevelUpLearnset,
        .teachableLearnset = sPawmiTeachableLearnset,
        .eggMoveLearnset = sPawmiEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_PAWMO}),
    },

    [SPECIES_PAWMO] =
    {
        .baseHP        = 60,
        .baseAttack    = 75,
        .baseDefense   = 40,
        .baseSpeed     = 85,
        .baseSpAttack  = 50,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_FIGHTING),
        .catchRate = 80,
        .expYield = 123,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_VOLT_ABSORB, ABILITY_NATURAL_CURE, ABILITY_IRON_FIST },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pohmotte"),
        .cryId = CRY_PAWMO,
        .natDexNum = NATIONAL_DEX_PAWMO,
        .categoryName = _("Souris"),
        .height = 4,
        .weight = 65,
        .description = COMPOUND_STRING(
            "Ces Pokémon se regroupent selon leur couleur. Le\n"
            "plumage vert est le plus fréquent, car il est\n"
            "déterminé par un gène dominant."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pawmo,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Pawmo,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Pawmo,
        .shinyPalette = gMonShinyPalette_Pawmo,
        .iconSprite = gMonIcon_Pawmo,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-3, 10, SHADOW_SIZE_S)
        FOOTPRINT(Pawmo)
        OVERWORLD(
            sPicTable_Pawmo,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Pawmo,
            gShinyOverworldPalette_Pawmo
        )
        .levelUpLearnset = sPawmoLevelUpLearnset,
        .teachableLearnset = sPawmoTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_PAWMOT, CONDITIONS({IF_MIN_OVERWORLD_STEPS, 1000})}),
    },

    [SPECIES_PAWMOT] =
    {
        .baseHP        = 70,
        .baseAttack    = 115,
        .baseDefense   = 70,
        .baseSpeed     = 105,
        .baseSpAttack  = 70,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = 245,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_VOLT_ABSORB, ABILITY_NATURAL_CURE, ABILITY_IRON_FIST },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pohmarmotte"),
        .cryId = CRY_PAWMOT,
        .natDexNum = NATIONAL_DEX_PAWMOT,
        .categoryName = _("Pose Paume"),
        .height = 9,
        .weight = 410,
        .description = COMPOUND_STRING(
            "Une volée de Flamenroule peut dépasser les dix\n"
            "mille individus. Leurs mouvements synchronisés\n"
            "offrent un spectacle majestueux."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pawmot,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Pawmot,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Pawmot,
        .shinyPalette = gMonShinyPalette_Pawmot,
        .iconSprite = gMonIcon_Pawmot,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 11, SHADOW_SIZE_M)
        FOOTPRINT(Pawmot)
        OVERWORLD(
            sPicTable_Pawmot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Pawmot,
            gShinyOverworldPalette_Pawmot
        )
        .levelUpLearnset = sPawmotLevelUpLearnset,
        .teachableLearnset = sPawmotTeachableLearnset,
    },
#endif //P_FAMILY_PAWMI

#if P_FAMILY_TANDEMAUS
    [SPECIES_TANDEMAUS] =
    {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 45,
        .baseSpeed     = 75,
        .baseSpAttack  = 40,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 150,
        .expYield = 61,
        .evYield_Speed = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_RUN_AWAY, ABILITY_PICKUP, ABILITY_OWN_TEMPO },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Compagnol"),
        .cryId = CRY_TANDEMAUS,
        .natDexNum = NATIONAL_DEX_TANDEMAUS,
        .categoryName = _("Couple"),
        .height = 3,
        .weight = 18,
        .description = COMPOUND_STRING(
            "Ce Pokémon s'arme d'un masque de glace et de\n"
            "lames sur sa crête, puis s'élance sur ses\n"
            "adversaires avec agilité pour les lacérer."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tandemaus,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Tandemaus,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Tandemaus,
        .shinyPalette = gMonShinyPalette_Tandemaus,
        .iconSprite = gMonIcon_Tandemaus,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, -1, SHADOW_SIZE_M)
        FOOTPRINT(Tandemaus)
        OVERWORLD(
            sPicTable_Tandemaus,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Tandemaus,
            gShinyOverworldPalette_Tandemaus
        )
        .levelUpLearnset = sTandemausLevelUpLearnset,
        .teachableLearnset = sTandemausTeachableLearnset,
        .eggMoveLearnset = sTandemausEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL_BATTLE_ONLY, 25, SPECIES_MAUSHOLD_FOUR, CONDITIONS({IF_PID_MODULO_100_GT, 0})},
                                {EVO_LEVEL_BATTLE_ONLY, 25, SPECIES_MAUSHOLD_THREE, CONDITIONS({IF_PID_MODULO_100_EQ, 0})}),
    },

    [SPECIES_MAUSHOLD_THREE] =
    {
        .baseHP        = 74,
        .baseAttack    = 75,
        .baseDefense   = 70,
        .baseSpeed     = 111,
        .baseSpAttack  = 65,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 75,
        .expYield = 165,
        .evYield_Speed = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_FRIEND_GUARD, ABILITY_CHEEK_POUCH, ABILITY_TECHNICIAN },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Famignol"),
        .cryId = CRY_MAUSHOLD_THREE,
        .natDexNum = NATIONAL_DEX_MAUSHOLD,
        .categoryName = _("Famille"),
        .height = 3,
        .weight = 23,
        .description = COMPOUND_STRING(
            "Il gèle l'air alentour pour protéger son visage\n"
            "avec un masque de glace et doter sa crête\n"
            "dorsale de lames gelées."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MausholdThree,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        /*.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,*/
        .backPic = gMonBackPic_MausholdThree,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 15,
        /*.backAnimId = BACK_ANIM_NONE,*/
        .palette = gMonPalette_Maushold,
        .shinyPalette = gMonShinyPalette_Maushold,
        .iconSprite = gMonIcon_MausholdThree,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(4, -1, SHADOW_SIZE_L)
        FOOTPRINT(MausholdThree)
        OVERWORLD(
            sPicTable_MausholdThree,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_MausholdThree,
            gShinyOverworldPalette_MausholdThree
        )
        .levelUpLearnset = sMausholdLevelUpLearnset,
        .teachableLearnset = sMausholdTeachableLearnset,
        .formSpeciesIdTable = sMausholdFormSpeciesIdTable,
    },

    [SPECIES_MAUSHOLD_FOUR] =
    {
        .baseHP        = 74,
        .baseAttack    = 75,
        .baseDefense   = 70,
        .baseSpeed     = 111,
        .baseSpAttack  = 65,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 75,
        .expYield = 165,
        .evYield_Speed = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_FRIEND_GUARD, ABILITY_CHEEK_POUCH, ABILITY_TECHNICIAN },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Famignol"),
        .cryId = CRY_MAUSHOLD_FOUR,
        .natDexNum = NATIONAL_DEX_MAUSHOLD,
        .categoryName = _("Famille"),
        .height = 3,
        .weight = 28,
        .description = COMPOUND_STRING(
            "Il gèle l'air alentour pour protéger son visage\n"
            "avec un masque de glace et doter sa crête\n"
            "dorsale de lames gelées."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MausholdFour,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        /*.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,*/
        .backPic = gMonBackPic_MausholdFour,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 15,
        /*.backAnimId = BACK_ANIM_NONE,*/
        .palette = gMonPalette_Maushold,
        .shinyPalette = gMonShinyPalette_Maushold,
        .iconSprite = gMonIcon_MausholdFour,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, -1, SHADOW_SIZE_L)
        FOOTPRINT(MausholdFour)
        OVERWORLD(
            sPicTable_MausholdFour,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_MausholdFour,
            gShinyOverworldPalette_MausholdFour
        )
        .levelUpLearnset = sMausholdLevelUpLearnset,
        .teachableLearnset = sMausholdTeachableLearnset,
        .formSpeciesIdTable = sMausholdFormSpeciesIdTable,
    },
#endif //P_FAMILY_TANDEMAUS

#if P_FAMILY_FIDOUGH
    [SPECIES_FIDOUGH] =
    {
        .baseHP        = 37,
        .baseAttack    = 55,
        .baseDefense   = 70,
        .baseSpeed     = 65,
        .baseSpAttack  = 30,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_FAIRY),
        .catchRate = 190,
        .expYield = 62,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_MINERAL),
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_NONE, ABILITY_KLUTZ },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pâtachiot"),
        .cryId = CRY_FIDOUGH,
        .natDexNum = NATIONAL_DEX_FIDOUGH,
        .categoryName = _("Chiot"),
        .height = 3,
        .weight = 109,
        .description = COMPOUND_STRING(
            "Ce Pokémon est né lorsque, portée par le vent,\n"
            "une âme incapable de trouver le repos s'est\n"
            "retrouvée empêtrée dans des herbes sèches."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Fidough,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Fidough,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Fidough,
        .shinyPalette = gMonShinyPalette_Fidough,
        .iconSprite = gMonIcon_Fidough,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(4, 0, SHADOW_SIZE_S)
        FOOTPRINT(Fidough)
        OVERWORLD(
            sPicTable_Fidough,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Fidough,
            gShinyOverworldPalette_Fidough
        )
        .levelUpLearnset = sFidoughLevelUpLearnset,
        .teachableLearnset = sFidoughTeachableLearnset,
        .eggMoveLearnset = sFidoughEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 26, SPECIES_DACHSBUN}),
    },

    [SPECIES_DACHSBUN] =
    {
        .baseHP        = 57,
        .baseAttack    = 80,
        .baseDefense   = 115,
        .baseSpeed     = 95,
        .baseSpAttack  = 50,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_FAIRY),
        .catchRate = 90,
        .expYield = 167,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_MINERAL),
        .abilities = { ABILITY_WELL_BAKED_BODY, ABILITY_NONE, ABILITY_AROMA_VEIL },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Briochien"),
        .cryId = CRY_DACHSBUN,
        .natDexNum = NATIONAL_DEX_DACHSBUN,
        .categoryName = _("Chien"),
        .height = 5,
        .weight = 149,
        .description = COMPOUND_STRING(
            "Ce Pokémon vit caché dans un coffre robuste qui\n"
            "lui octroie une solide défense, mais dont le poids\n"
            "gêne ses déplacements."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Dachsbun,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Dachsbun,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Dachsbun,
        .shinyPalette = gMonShinyPalette_Dachsbun,
        .iconSprite = gMonIcon_Dachsbun,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-1, 7, SHADOW_SIZE_L)
        FOOTPRINT(Dachsbun)
        OVERWORLD(
            sPicTable_Dachsbun,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Dachsbun,
            gShinyOverworldPalette_Dachsbun
        )
        .levelUpLearnset = sDachsbunLevelUpLearnset,
        .teachableLearnset = sDachsbunTeachableLearnset,
    },
#endif //P_FAMILY_FIDOUGH

#if P_FAMILY_SMOLIV
    [SPECIES_SMOLIV] =
    {
        .baseHP        = 41,
        .baseAttack    = 35,
        .baseDefense   = 45,
        .baseSpeed     = 30,
        .baseSpAttack  = 58,
        .baseSpDefense = 51,
        .types = MON_TYPES(TYPE_GRASS, TYPE_NORMAL),
        .catchRate = 255,
        .expYield = 52,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_EARLY_BIRD, ABILITY_NONE, ABILITY_HARVEST },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Olivini"),
        .cryId = CRY_SMOLIV,
        .natDexNum = NATIONAL_DEX_SMOLIV,
        .categoryName = _("Olive"),
        .height = 3,
        .weight = 65,
        .description = COMPOUND_STRING(
            "Sa tête rouge convertit la substance piquante\n"
            "produite par son corps en énergie de type Feu et\n"
            "crache des flammes brûlantes."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Smoliv,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Smoliv,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Smoliv,
        .shinyPalette = gMonShinyPalette_Smoliv,
        .iconSprite = gMonIcon_Smoliv,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Smoliv)
        OVERWORLD(
            sPicTable_Smoliv,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Smoliv,
            gShinyOverworldPalette_Smoliv
        )
        .levelUpLearnset = sSmolivLevelUpLearnset,
        .teachableLearnset = sSmolivTeachableLearnset,
        .eggMoveLearnset = sSmolivEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_DOLLIV}),
    },

    [SPECIES_DOLLIV] =
    {
        .baseHP        = 52,
        .baseAttack    = 53,
        .baseDefense   = 60,
        .baseSpeed     = 33,
        .baseSpAttack  = 78,
        .baseSpDefense = 78,
        .types = MON_TYPES(TYPE_GRASS, TYPE_NORMAL),
        .catchRate = 120,
        .expYield = 124,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_EARLY_BIRD, ABILITY_NONE, ABILITY_HARVEST },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Olivado"),
        .cryId = CRY_DOLLIV,
        .natDexNum = NATIONAL_DEX_DOLLIV,
        .categoryName = _("Olive"),
        .height = 6,
        .weight = 119,
        .description = COMPOUND_STRING(
            "Ce Pokémon produit de l'électricité en agitant sa\n"
            "queue. Lorsqu'il perçoit un danger, sa tête\n"
            "clignote pour avertir ses congénères."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Dolliv,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Dolliv,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Dolliv,
        .shinyPalette = gMonShinyPalette_Dolliv,
        .iconSprite = gMonIcon_Dolliv,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, 9, SHADOW_SIZE_M)
        FOOTPRINT(Dolliv)
        OVERWORLD(
            sPicTable_Dolliv,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Dolliv,
            gShinyOverworldPalette_Dolliv
        )
        .levelUpLearnset = sDollivLevelUpLearnset,
        .teachableLearnset = sDollivTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_ARBOLIVA}),
    },

    [SPECIES_ARBOLIVA] =
    {
        .baseHP        = 78,
        .baseAttack    = 69,
        .baseDefense   = 90,
        .baseSpeed     = 39,
        .baseSpAttack  = 125,
        .baseSpDefense = 109,
        .types = MON_TYPES(TYPE_GRASS, TYPE_NORMAL),
        .catchRate = 45,
        .expYield = 255,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_SEED_SOWER, ABILITY_NONE, ABILITY_HARVEST },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Arboliva"),
        .cryId = CRY_ARBOLIVA,
        .natDexNum = NATIONAL_DEX_ARBOLIVA,
        .categoryName = _("Olive"),
        .height = 14,
        .weight = 482,
        .description = COMPOUND_STRING(
            "Lorsque ce Pokémon allonge et contracte son\n"
            "corps élastique, son nombril-dynamo produit une\n"
            "quantité d'électricité colossale."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Arboliva,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Arboliva,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Arboliva,
        .shinyPalette = gMonShinyPalette_Arboliva,
        .iconSprite = gMonIcon_Arboliva,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 13, SHADOW_SIZE_L)
        FOOTPRINT(Arboliva)
        OVERWORLD(
            sPicTable_Arboliva,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Arboliva,
            gShinyOverworldPalette_Arboliva
        )
        .levelUpLearnset = sArbolivaLevelUpLearnset,
        .teachableLearnset = sArbolivaTeachableLearnset,
    },
#endif //P_FAMILY_SMOLIV

#if P_FAMILY_SQUAWKABILLY
    [SPECIES_SQUAWKABILLY_GREEN] =
    {
        .baseHP        = 82,
        .baseAttack    = 96,
        .baseDefense   = 51,
        .baseSpeed     = 92,
        .baseSpAttack  = 45,
        .baseSpDefense = 51,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 190,
        .expYield = 146,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_HUSTLE, ABILITY_GUTS },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Tapatoès"),
        .cryId = CRY_SQUAWKABILLY,
        .natDexNum = NATIONAL_DEX_SQUAWKABILLY,
        .categoryName = _("Perroquet"),
        .height = 6,
        .weight = 24,
        .description = COMPOUND_STRING(
            "Il projette du sel pour en recouvrir ses proies.\n"
            "Celles-ci subissent alors un processus de salaison\n"
            "et se déshydratent."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Squawkabilly,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        /*.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,*/
        .backPic = gMonBackPic_Squawkabilly,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        /*.backAnimId = BACK_ANIM_NONE,*/
        .palette = gMonPalette_SquawkabillyGreen,
        .shinyPalette = gMonShinyPalette_SquawkabillyGreen,
        .iconSprite = gMonIcon_SquawkabillyGreen,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-6, 9, SHADOW_SIZE_M)
        FOOTPRINT(Squawkabilly)
        OVERWORLD(
            sPicTable_SquawkabillyGreen,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_SquawkabillyGreen,
            gShinyOverworldPalette_SquawkabillyGreen
        )
        .levelUpLearnset = sSquawkabillyLevelUpLearnset,
        .teachableLearnset = sSquawkabillyTeachableLearnset,
        .eggMoveLearnset = sSquawkabillyEggMoveLearnset,
        .formSpeciesIdTable = sSquawkabillyFormSpeciesIdTable,
    },

    [SPECIES_SQUAWKABILLY_BLUE] =
    {
        .baseHP        = 82,
        .baseAttack    = 96,
        .baseDefense   = 51,
        .baseSpeed     = 92,
        .baseSpAttack  = 45,
        .baseSpDefense = 51,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 190,
        .expYield = 146,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_HUSTLE, ABILITY_GUTS },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Tapatoès"),
        .cryId = CRY_SQUAWKABILLY,
        .natDexNum = NATIONAL_DEX_SQUAWKABILLY,
        .categoryName = _("Perroquet"),
        .height = 6,
        .weight = 24,
        .description = COMPOUND_STRING(
            "Il projette du sel pour en recouvrir ses proies.\n"
            "Celles-ci subissent alors un processus de salaison\n"
            "et se déshydratent."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Squawkabilly,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        /*.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,*/
        .backPic = gMonBackPic_Squawkabilly,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        /*.backAnimId = BACK_ANIM_NONE,*/
        .palette = gMonPalette_SquawkabillyBlue,
        .shinyPalette = gMonShinyPalette_SquawkabillyBlue,
        .iconSprite = gMonIcon_SquawkabillyBlue,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-6, 9, SHADOW_SIZE_M)
        FOOTPRINT(Squawkabilly)
        OVERWORLD(
            sPicTable_SquawkabillyBlue,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_SquawkabillyBlue,
            gShinyOverworldPalette_SquawkabillyBlue
        )
        .levelUpLearnset = sSquawkabillyLevelUpLearnset,
        .teachableLearnset = sSquawkabillyTeachableLearnset,
        .eggMoveLearnset = sSquawkabillyEggMoveLearnset,
        .formSpeciesIdTable = sSquawkabillyFormSpeciesIdTable,
    },

    [SPECIES_SQUAWKABILLY_YELLOW] =
    {
        .baseHP        = 82,
        .baseAttack    = 96,
        .baseDefense   = 51,
        .baseSpeed     = 92,
        .baseSpAttack  = 45,
        .baseSpDefense = 51,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 190,
        .expYield = 146,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_HUSTLE, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Tapatoès"),
        .cryId = CRY_SQUAWKABILLY,
        .natDexNum = NATIONAL_DEX_SQUAWKABILLY,
        .categoryName = _("Perroquet"),
        .height = 6,
        .weight = 24,
        .description = COMPOUND_STRING(
            "Il projette du sel pour en recouvrir ses proies.\n"
            "Celles-ci subissent alors un processus de salaison\n"
            "et se déshydratent."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Squawkabilly,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        /*.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,*/
        .backPic = gMonBackPic_Squawkabilly,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        /*.backAnimId = BACK_ANIM_NONE,*/
        .palette = gMonPalette_SquawkabillyYellow,
        .shinyPalette = gMonShinyPalette_SquawkabillyYellow,
        .iconSprite = gMonIcon_SquawkabillyYellow,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-6, 9, SHADOW_SIZE_M)
        FOOTPRINT(Squawkabilly)
        OVERWORLD(
            sPicTable_SquawkabillyYellow,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_SquawkabillyYellow,
            gShinyOverworldPalette_SquawkabillyYellow
        )
        .levelUpLearnset = sSquawkabillyLevelUpLearnset,
        .teachableLearnset = sSquawkabillyTeachableLearnset,
        .eggMoveLearnset = sSquawkabillyEggMoveLearnset,
        .formSpeciesIdTable = sSquawkabillyFormSpeciesIdTable,
    },

    [SPECIES_SQUAWKABILLY_WHITE] =
    {
        .baseHP        = 82,
        .baseAttack    = 96,
        .baseDefense   = 51,
        .baseSpeed     = 92,
        .baseSpAttack  = 45,
        .baseSpDefense = 51,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 190,
        .expYield = 146,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_HUSTLE, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Tapatoès"),
        .cryId = CRY_SQUAWKABILLY,
        .natDexNum = NATIONAL_DEX_SQUAWKABILLY,
        .categoryName = _("Perroquet"),
        .height = 6,
        .weight = 24,
        .description = COMPOUND_STRING(
            "Il projette du sel pour en recouvrir ses proies.\n"
            "Celles-ci subissent alors un processus de salaison\n"
            "et se déshydratent."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Squawkabilly,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        /*.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,*/
        .backPic = gMonBackPic_Squawkabilly,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        /*.backAnimId = BACK_ANIM_NONE,*/
        .palette = gMonPalette_SquawkabillyWhite,
        .shinyPalette = gMonShinyPalette_SquawkabillyWhite,
        .iconSprite = gMonIcon_SquawkabillyWhite,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-6, 9, SHADOW_SIZE_M)
        FOOTPRINT(Squawkabilly)
        OVERWORLD(
            sPicTable_SquawkabillyWhite,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_SquawkabillyWhite,
            gShinyOverworldPalette_SquawkabillyWhite
        )
        .levelUpLearnset = sSquawkabillyLevelUpLearnset,
        .teachableLearnset = sSquawkabillyTeachableLearnset,
        .eggMoveLearnset = sSquawkabillyEggMoveLearnset,
        .formSpeciesIdTable = sSquawkabillyFormSpeciesIdTable,
    },
#endif //P_FAMILY_SQUAWKABILLY

#if P_FAMILY_NACLI
    [SPECIES_NACLI] =
    {
        .baseHP        = 55,
        .baseAttack    = 55,
        .baseDefense   = 75,
        .baseSpeed     = 25,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_ROCK),
        .catchRate = 255,
        .expYield = 56,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_PURIFYING_SALT, ABILITY_STURDY, ABILITY_CLEAR_BODY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Selutin"),
        .cryId = CRY_NACLI,
        .natDexNum = NATIONAL_DEX_NACLI,
        .categoryName = _("Halite"),
        .height = 4,
        .weight = 160,
        .description = COMPOUND_STRING(
            "Lorsqu'il détecte un danger, il ouvre ses pétales\n"
            "cristallins et son corps conique tire un rayon\n"
            "laser."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Nacli,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Nacli,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Nacli,
        .shinyPalette = gMonShinyPalette_Nacli,
        .iconSprite = gMonIcon_Nacli,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, 5, SHADOW_SIZE_S)
        FOOTPRINT(Nacli)
        OVERWORLD(
            sPicTable_Nacli,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Nacli,
            gShinyOverworldPalette_Nacli
        )
        .levelUpLearnset = sNacliLevelUpLearnset,
        .teachableLearnset = sNacliTeachableLearnset,
        .eggMoveLearnset = sNacliEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 24, SPECIES_NACLSTACK}),
    },

    [SPECIES_NACLSTACK] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 100,
        .baseSpeed     = 35,
        .baseSpAttack  = 35,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_ROCK),
        .catchRate = 120,
        .expYield = 124,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_PURIFYING_SALT, ABILITY_STURDY, ABILITY_CLEAR_BODY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Amassel"),
        .cryId = CRY_NACLSTACK,
        .natDexNum = NATIONAL_DEX_NACLSTACK,
        .categoryName = _("Halite"),
        .height = 6,
        .weight = 1050,
        .description = COMPOUND_STRING(
            "Ce Pokémon est d'un naturel doux, mais lorsqu'il se\n"
            "met en colère, il mord à l'aide de ses incisives\n"
            "acérées et imprégnées de venin paralysant."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Naclstack,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Naclstack,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 17,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Naclstack,
        .shinyPalette = gMonShinyPalette_Naclstack,
        .iconSprite = gMonIcon_Naclstack,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, 0, SHADOW_SIZE_L)
        FOOTPRINT(Naclstack)
        OVERWORLD(
            sPicTable_Naclstack,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Naclstack,
            gShinyOverworldPalette_Naclstack
        )
        .levelUpLearnset = sNaclstackLevelUpLearnset,
        .teachableLearnset = sNaclstackTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_GARGANACL}),
    },

    [SPECIES_GARGANACL] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 130,
        .baseSpeed     = 35,
        .baseSpAttack  = 45,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_ROCK),
        .catchRate = 45,
        .expYield = 250,
        .evYield_Defense = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_PURIFYING_SALT, ABILITY_STURDY, ABILITY_CLEAR_BODY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Gigansel"),
        .cryId = CRY_GARGANACL,
        .natDexNum = NATIONAL_DEX_GARGANACL,
        .categoryName = _("Halite"),
        .height = 23,
        .weight = 2400,
        .description = COMPOUND_STRING(
            "Ce Pokémon cultive de la levure dans son corps.\n"
            "Depuis très longtemps, il cohabite avec les êtres\n"
            "humains et les aide à cuisiner."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Garganacl,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Garganacl,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Garganacl,
        .shinyPalette = gMonShinyPalette_Garganacl,
        .iconSprite = gMonIcon_Garganacl,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 13, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Garganacl)
        OVERWORLD(
            sPicTable_Garganacl,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Garganacl,
            gShinyOverworldPalette_Garganacl
        )
        .levelUpLearnset = sGarganaclLevelUpLearnset,
        .teachableLearnset = sGarganaclTeachableLearnset,
    },
#endif //P_FAMILY_NACLI

#if P_FAMILY_CHARCADET
    [SPECIES_CHARCADET] =
    {
        .baseHP        = 40,
        .baseAttack    = 50,
        .baseDefense   = 40,
        .baseSpeed     = 35,
        .baseSpAttack  = 50,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 90,
        .expYield = 51,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_NONE, ABILITY_FLAME_BODY },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Charbambin"),
        .cryId = CRY_CHARCADET,
        .natDexNum = NATIONAL_DEX_CHARCADET,
        .categoryName = _("Enfant Feu"),
        .height = 6,
        .weight = 105,
        .description = COMPOUND_STRING(
            "Ces Pokémon vivent en colonies au fin fond des\n"
            "bois. Ils détestent au plus haut point que des\n"
            "personnes inconnues s'approchent d'eux."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Charcadet,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Charcadet,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Charcadet,
        .shinyPalette = gMonShinyPalette_Charcadet,
        .iconSprite = gMonIcon_Charcadet,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-1, 5, SHADOW_SIZE_S)
        FOOTPRINT(Charcadet)
        OVERWORLD(
            sPicTable_Charcadet,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Charcadet,
            gShinyOverworldPalette_Charcadet
        )
        .levelUpLearnset = sCharcadetLevelUpLearnset,
        .teachableLearnset = sCharcadetTeachableLearnset,
        .eggMoveLearnset = sCharcadetEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_AUSPICIOUS_ARMOR, SPECIES_ARMAROUGE},
                                {EVO_ITEM, ITEM_MALICIOUS_ARMOR, SPECIES_CERULEDGE}),
    },

    [SPECIES_ARMAROUGE] =
    {
        .baseHP        = 85,
        .baseAttack    = 60,
        .baseDefense   = 100,
        .baseSpeed     = 75,
        .baseSpAttack  = 125,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_FIRE, TYPE_PSYCHIC),
        .catchRate = 25,
        .expYield = 263,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 35,
        .friendship = 20,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_NONE, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Carmadura"),
        .cryId = CRY_ARMAROUGE,
        .natDexNum = NATIONAL_DEX_ARMAROUGE,
        .categoryName = _("Feu Guerrier"),
        .height = 15,
        .weight = 850,
        .description = COMPOUND_STRING(
            "Seul un Scalproie qui s'est hissé au plus haut\n"
            "rang d'une grande armée peut évoluer en\n"
            "Scalpereur."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Armarouge,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Armarouge,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Armarouge,
        .shinyPalette = gMonShinyPalette_Armarouge,
        .iconSprite = gMonIcon_Armarouge,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 14, SHADOW_SIZE_L)
        FOOTPRINT(Armarouge)
        OVERWORLD(
            sPicTable_Armarouge,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Armarouge,
            gShinyOverworldPalette_Armarouge
        )
        .levelUpLearnset = sArmarougeLevelUpLearnset,
        .teachableLearnset = sArmarougeTeachableLearnset,
    },

    [SPECIES_CERULEDGE] =
    {
        .baseHP        = 75,
        .baseAttack    = 125,
        .baseDefense   = 80,
        .baseSpeed     = 85,
        .baseSpAttack  = 60,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_FIRE, TYPE_GHOST),
        .catchRate = 25,
        .expYield = 263,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 35,
        .friendship = 20,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_NONE, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Malvalame"),
        .cryId = CRY_CERULEDGE,
        .natDexNum = NATIONAL_DEX_CERULEDGE,
        .categoryName = _("Feu Bretteur"),
        .height = 16,
        .weight = 620,
        .description = COMPOUND_STRING(
            "Il a évolué en Courrousinge grâce à une\n"
            "utilisation acharnée de la même capacité, à tel\n"
            "point que les veines sur son front ont failli\n"
            "exploser."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ceruledge,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Ceruledge,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Ceruledge,
        .shinyPalette = gMonShinyPalette_Ceruledge,
        .iconSprite = gMonIcon_Ceruledge,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(9, 14, SHADOW_SIZE_L)
        FOOTPRINT(Ceruledge)
        OVERWORLD(
            sPicTable_Ceruledge,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Ceruledge,
            gShinyOverworldPalette_Ceruledge
        )
        .levelUpLearnset = sCeruledgeLevelUpLearnset,
        .teachableLearnset = sCeruledgeTeachableLearnset,
    },
#endif //P_FAMILY_CHARCADET

#if P_FAMILY_TADBULB
    [SPECIES_TADBULB] =
    {
        .baseHP        = 61,
        .baseAttack    = 31,
        .baseDefense   = 41,
        .baseSpeed     = 45,
        .baseSpAttack  = 59,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = 54,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_STATIC, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Têtampoule"),
        .cryId = CRY_TADBULB,
        .natDexNum = NATIONAL_DEX_TADBULB,
        .categoryName = _("Électêtard"),
        .height = 3,
        .weight = 4,
        .description = COMPOUND_STRING(
            "Lorsqu'on l'attaque, ce Pokémon se sert de ses\n"
            "poils comme de poings pour rouer de coups ses\n"
            "adversaires."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tadbulb,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 12,
        .backPic = gMonBackPic_Tadbulb,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Tadbulb,
        .shinyPalette = gMonShinyPalette_Tadbulb,
        .iconSprite = gMonIcon_Tadbulb,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 19, SHADOW_SIZE_S)
        FOOTPRINT(Tadbulb)
        OVERWORLD(
            sPicTable_Tadbulb,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Tadbulb,
            gShinyOverworldPalette_Tadbulb
        )
        .levelUpLearnset = sTadbulbLevelUpLearnset,
        .teachableLearnset = sTadbulbTeachableLearnset,
        .eggMoveLearnset = sTadbulbEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_BELLIBOLT}),
    },

    [SPECIES_BELLIBOLT] =
    {
        .baseHP        = 109,
        .baseAttack    = 64,
        .baseDefense   = 91,
        .baseSpeed     = 45,
        .baseSpAttack  = 103,
        .baseSpDefense = 83,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 50,
        .expYield = 173,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = { ABILITY_ELECTROMORPHOSIS, ABILITY_STATIC, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Ampibidou"),
        .cryId = CRY_BELLIBOLT,
        .natDexNum = NATIONAL_DEX_BELLIBOLT,
        .categoryName = _("Élecrapaud"),
        .height = 12,
        .weight = 1130,
        .description = COMPOUND_STRING(
            "Ces Pokémon travaillent en équipe. À l'aide de leur\n"
            "incisive, ils extraient les matériaux nécessaires\n"
            "pour construire leur nid, puis ils les emportent."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Bellibolt,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Bellibolt,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Bellibolt,
        .shinyPalette = gMonShinyPalette_Bellibolt,
        .iconSprite = gMonIcon_Bellibolt,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 7, SHADOW_SIZE_M)
        FOOTPRINT(Bellibolt)
        OVERWORLD(
            sPicTable_Bellibolt,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Bellibolt,
            gShinyOverworldPalette_Bellibolt
        )
        .levelUpLearnset = sBelliboltLevelUpLearnset,
        .teachableLearnset = sBelliboltTeachableLearnset,
    },
#endif //P_FAMILY_TADBULB

#if P_FAMILY_WATTREL
    [SPECIES_WATTREL] =
    {
        .baseHP        = 40,
        .baseAttack    = 40,
        .baseDefense   = 35,
        .baseSpeed     = 70,
        .baseSpAttack  = 55,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_FLYING),
        .catchRate = 180,
        .expYield = 56,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FLYING),
        .abilities = { ABILITY_WIND_POWER, ABILITY_VOLT_ABSORB, ABILITY_COMPETITIVE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Zapétrel"),
        .cryId = CRY_WATTREL,
        .natDexNum = NATIONAL_DEX_WATTREL,
        .categoryName = _("Océanite"),
        .height = 4,
        .weight = 36,
        .description = COMPOUND_STRING(
            "On pense qu'il fait un nœud à la base de son cou\n"
            "afin d'empêcher l'énergie qu'il accumule dans son\n"
            "ventre de s'échapper par son bec."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Wattrel,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Wattrel,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Wattrel,
        .shinyPalette = gMonShinyPalette_Wattrel,
        .iconSprite = gMonIcon_Wattrel,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 0, SHADOW_SIZE_S)
        FOOTPRINT(Wattrel)
        OVERWORLD(
            sPicTable_Wattrel,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Wattrel,
            gShinyOverworldPalette_Wattrel
        )
        .levelUpLearnset = sWattrelLevelUpLearnset,
        .teachableLearnset = sWattrelTeachableLearnset,
        .eggMoveLearnset = sWattrelEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_KILOWATTREL}),
    },

    [SPECIES_KILOWATTREL] =
    {
        .baseHP        = 70,
        .baseAttack    = 70,
        .baseDefense   = 60,
        .baseSpeed     = 125,
        .baseSpAttack  = 105,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_FLYING),
        .catchRate = 90,
        .expYield = 172,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FLYING),
        .abilities = { ABILITY_WIND_POWER, ABILITY_VOLT_ABSORB, ABILITY_COMPETITIVE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Fulgulairo"),
        .cryId = CRY_KILOWATTREL,
        .natDexNum = NATIONAL_DEX_KILOWATTREL,
        .categoryName = _("Frégate"),
        .height = 14,
        .weight = 386,
        .description = COMPOUND_STRING(
            "Ce Pokémon laisse des grains de sel dans son\n"
            "sillage. Cette trace est depuis longtemps\n"
            "surnommée “ route du sel ”."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Kilowattrel,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Kilowattrel,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Kilowattrel,
        .shinyPalette = gMonShinyPalette_Kilowattrel,
        .iconSprite = gMonIcon_Kilowattrel,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-6, 6, SHADOW_SIZE_M)
        FOOTPRINT(Kilowattrel)
        OVERWORLD(
            sPicTable_Kilowattrel,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Kilowattrel,
            gShinyOverworldPalette_Kilowattrel
        )
        .levelUpLearnset = sKilowattrelLevelUpLearnset,
        .teachableLearnset = sKilowattrelTeachableLearnset,
    },
#endif //P_FAMILY_WATTREL

#if P_FAMILY_MASCHIFF
    [SPECIES_MASCHIFF] =
    {
        .baseHP        = 60,
        .baseAttack    = 78,
        .baseDefense   = 60,
        .baseSpeed     = 51,
        .baseSpAttack  = 40,
        .baseSpDefense = 51,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 150,
        .expYield = 68,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_RUN_AWAY, ABILITY_STAKEOUT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Grondogue"),
        .cryId = CRY_MASCHIFF,
        .natDexNum = NATIONAL_DEX_MASCHIFF,
        .categoryName = _("Jeunot"),
        .height = 5,
        .weight = 160,
        .description = COMPOUND_STRING(
            "Ce Pokémon aime les lieux animés. Il arrive de\n"
            "croiser des Gromago sauvages vivant au beau\n"
            "milieu de la ville."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Maschiff,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Maschiff,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Maschiff,
        .shinyPalette = gMonShinyPalette_Maschiff,
        .iconSprite = gMonIcon_Maschiff,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(2, 5, SHADOW_SIZE_L)
        FOOTPRINT(Maschiff)
        OVERWORLD(
            sPicTable_Maschiff,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Maschiff,
            gShinyOverworldPalette_Maschiff
        )
        .levelUpLearnset = sMaschiffLevelUpLearnset,
        .teachableLearnset = sMaschiffTeachableLearnset,
        .eggMoveLearnset = sMaschiffEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_MABOSSTIFF}),
    },

    [SPECIES_MABOSSTIFF] =
    {
        .baseHP        = 80,
        .baseAttack    = 120,
        .baseDefense   = 90,
        .baseSpeed     = 85,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 75,
        .expYield = 177,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_GUARD_DOG, ABILITY_STAKEOUT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Dogrino"),
        .cryId = CRY_MABOSSTIFF,
        .natDexNum = NATIONAL_DEX_MABOSSTIFF,
        .categoryName = _("Parrain"),
        .height = 11,
        .weight = 610,
        .description = COMPOUND_STRING(
            "Son corps serait composé de 1 000 pièces.\n"
            "Sociable, il peut se lier d'amitié très rapidement\n"
            "avec n'importe qui."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mabosstiff,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Mabosstiff,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Mabosstiff,
        .shinyPalette = gMonShinyPalette_Mabosstiff,
        .iconSprite = gMonIcon_Mabosstiff,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 5, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Mabosstiff)
        OVERWORLD(
            sPicTable_Mabosstiff,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Mabosstiff,
            gShinyOverworldPalette_Mabosstiff
        )
        .levelUpLearnset = sMabosstiffLevelUpLearnset,
        .teachableLearnset = sMabosstiffTeachableLearnset,
    },
#endif //P_FAMILY_MASCHIFF

#if P_FAMILY_SHROODLE
    [SPECIES_SHROODLE] =
    {
        .baseHP        = 40,
        .baseAttack    = 65,
        .baseDefense   = 35,
        .baseSpeed     = 75,
        .baseSpAttack  = 40,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_POISON, TYPE_NORMAL),
        .catchRate = 190,
        .expYield = 58,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_UNBURDEN, ABILITY_PICKPOCKET, ABILITY_PRANKSTER },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Gribouraigne"),
        .cryId = CRY_SHROODLE,
        .natDexNum = NATIONAL_DEX_SHROODLE,
        .categoryName = _("Souris Venin"),
        .height = 2,
        .weight = 7,
        .description = COMPOUND_STRING(
            "Il affiche toujours un air renfrogné pour qu'on\n"
            "le prenne au sérieux, mais même les enfants en\n"
            "pleurs éclatent de rire lorsqu'ils voient sa tête."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Shroodle,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Shroodle,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 16,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Shroodle,
        .shinyPalette = gMonShinyPalette_Shroodle,
        .iconSprite = gMonIcon_Shroodle,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, -6, SHADOW_SIZE_S)
        FOOTPRINT(Shroodle)
        OVERWORLD(
            sPicTable_Shroodle,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Shroodle,
            gShinyOverworldPalette_Shroodle
        )
        .levelUpLearnset = sShroodleLevelUpLearnset,
        .teachableLearnset = sShroodleTeachableLearnset,
        .eggMoveLearnset = sShroodleEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_GRAFAIAI}),
    },

    [SPECIES_GRAFAIAI] =
    {
        .baseHP        = 63,
        .baseAttack    = 95,
        .baseDefense   = 65,
        .baseSpeed     = 110,
        .baseSpAttack  = 80,
        .baseSpDefense = 72,
        .types = MON_TYPES(TYPE_POISON, TYPE_NORMAL),
        .catchRate = 90,
        .expYield = 170,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_UNBURDEN, ABILITY_POISON_TOUCH, ABILITY_PRANKSTER },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Tag-Tag"),
        .cryId = CRY_GRAFAIAI,
        .natDexNum = NATIONAL_DEX_GRAFAIAI,
        .categoryName = _("Singe Venin"),
        .height = 7,
        .weight = 272,
        .description = COMPOUND_STRING(
            "Ce Pokémon emmagasine de l'énergie dans ses\n"
            "grandes bajoues. Il la libère ensuite d'un coup\n"
            "pour balayer ses adversaires au loin."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Grafaiai,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Grafaiai,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Grafaiai,
        .shinyPalette = gMonShinyPalette_Grafaiai,
        .iconSprite = gMonIcon_Grafaiai,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-2, 5, SHADOW_SIZE_S)
        FOOTPRINT(Grafaiai)
        OVERWORLD(
            sPicTable_Grafaiai,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Grafaiai,
            gShinyOverworldPalette_Grafaiai
        )
        .levelUpLearnset = sGrafaiaiLevelUpLearnset,
        .teachableLearnset = sGrafaiaiTeachableLearnset,
    },
#endif //P_FAMILY_SHROODLE

#if P_FAMILY_BRAMBLIN
    [SPECIES_BRAMBLIN] =
    {
        .baseHP        = 40,
        .baseAttack    = 65,
        .baseDefense   = 30,
        .baseSpeed     = 60,
        .baseSpAttack  = 45,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_GRASS, TYPE_GHOST),
        .catchRate = 190,
        .expYield = 55,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_WIND_RIDER, ABILITY_NONE, ABILITY_INFILTRATOR },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Virovent"),
        .cryId = CRY_BRAMBLIN,
        .natDexNum = NATIONAL_DEX_BRAMBLIN,
        .categoryName = _("Virevoltant"),
        .height = 6,
        .weight = 6,
        .description = COMPOUND_STRING(
            "Ce Pokémon a été aperçu à plusieurs reprises ces\n"
            "dernières années. Son nom s'inspire d'une\n"
            "créature évoquée dans un certain livre."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Bramblin,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Bramblin,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Bramblin,
        .shinyPalette = gMonShinyPalette_Bramblin,
        .iconSprite = gMonIcon_Bramblin,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(2, 0, SHADOW_SIZE_S)
        FOOTPRINT(Bramblin)
        OVERWORLD(
            sPicTable_Bramblin,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Bramblin,
            gShinyOverworldPalette_Bramblin
        )
        .levelUpLearnset = sBramblinLevelUpLearnset,
        .teachableLearnset = sBramblinTeachableLearnset,
        .eggMoveLearnset = sBramblinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_BRAMBLEGHAST, CONDITIONS({IF_MIN_OVERWORLD_STEPS, 1000})}),
    },

    [SPECIES_BRAMBLEGHAST] =
    {
        .baseHP        = 55,
        .baseAttack    = 115,
        .baseDefense   = 70,
        .baseSpeed     = 90,
        .baseSpAttack  = 80,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GRASS, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 168,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_WIND_RIDER, ABILITY_NONE, ABILITY_INFILTRATOR },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Virevorreur"),
        .cryId = CRY_BRAMBLEGHAST,
        .natDexNum = NATIONAL_DEX_BRAMBLEGHAST,
        .categoryName = _("Virevoltant"),
        .height = 12,
        .weight = 60,
        .description = COMPOUND_STRING(
            "Il est possible que ce Pokémon soit la créature\n"
            "évoquée sous le nom de “ Fongus-Furie ” dans un\n"
            "certain livre."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Brambleghast,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Brambleghast,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Brambleghast,
        .shinyPalette = gMonShinyPalette_Brambleghast,
        .iconSprite = gMonIcon_Brambleghast,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 6, SHADOW_SIZE_M)
        FOOTPRINT(Brambleghast)
        OVERWORLD(
            sPicTable_Brambleghast,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Brambleghast,
            gShinyOverworldPalette_Brambleghast
        )
        .levelUpLearnset = sBrambleghastLevelUpLearnset,
        .teachableLearnset = sBrambleghastTeachableLearnset,
    },
#endif //P_FAMILY_BRAMBLIN

#if P_FAMILY_TOEDSCOOL
    [SPECIES_TOEDSCOOL] =
    {
        .baseHP        = 40,
        .baseAttack    = 40,
        .baseDefense   = 35,
        .baseSpeed     = 70,
        .baseSpAttack  = 50,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_GROUND, TYPE_GRASS),
        .catchRate = 190,
        .expYield = 67,
        .evYield_SpDefense = 1,
        .itemCommon = ITEM_TINY_MUSHROOM,
        .itemRare = ITEM_BIG_MUSHROOM,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_MYCELIUM_MIGHT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Terracool"),
        .cryId = CRY_TOEDSCOOL,
        .natDexNum = NATIONAL_DEX_TOEDSCOOL,
        .categoryName = _("Champiméduse"),
        .height = 9,
        .weight = 330,
        .description = COMPOUND_STRING(
            "Quand sa colère a franchi un seuil critique, il a\n"
            "acquis une puissance qui l'a émancipé des limites\n"
            "de son corps."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Toedscool,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Toedscool,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Toedscool,
        .shinyPalette = gMonShinyPalette_Toedscool,
        .iconSprite = gMonIcon_Toedscool,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 10, SHADOW_SIZE_M)
        FOOTPRINT(Toedscool)
        OVERWORLD(
            sPicTable_Toedscool,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Toedscool,
            gShinyOverworldPalette_Toedscool
        )
        .levelUpLearnset = sToedscoolLevelUpLearnset,
        .teachableLearnset = sToedscoolTeachableLearnset,
        .eggMoveLearnset = sToedscoolEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_TOEDSCRUEL}),
    },

    [SPECIES_TOEDSCRUEL] =
    {
        .baseHP        = 80,
        .baseAttack    = 70,
        .baseDefense   = 65,
        .baseSpeed     = 100,
        .baseSpAttack  = 80,
        .baseSpDefense = 120,
        .types = MON_TYPES(TYPE_GROUND, TYPE_GRASS),
        .catchRate = 90,
        .expYield = 180,
        .evYield_SpDefense = 2,
        .itemCommon = ITEM_TINY_MUSHROOM,
        .itemRare = ITEM_BIG_MUSHROOM,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_MYCELIUM_MIGHT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Terracruel"),
        .cryId = CRY_TOEDSCRUEL,
        .natDexNum = NATIONAL_DEX_TOEDSCRUEL,
        .categoryName = _("Champiméduse"),
        .height = 19,
        .weight = 580,
        .description = COMPOUND_STRING(
            "Son type change selon le masque qu'il porte. Son\n"
            "agilité et ses coups de pied habiles lui permettent\n"
            "de malmener ses adversaires."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Toedscruel,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Toedscruel,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Toedscruel,
        .shinyPalette = gMonShinyPalette_Toedscruel,
        .iconSprite = gMonIcon_Toedscruel,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 8, SHADOW_SIZE_L)
        FOOTPRINT(Toedscruel)
        OVERWORLD(
            sPicTable_Toedscruel,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Toedscruel,
            gShinyOverworldPalette_Toedscruel
        )
        .levelUpLearnset = sToedscruelLevelUpLearnset,
        .teachableLearnset = sToedscruelTeachableLearnset,
    },
#endif //P_FAMILY_TOEDSCOOL

#if P_FAMILY_KLAWF
    [SPECIES_KLAWF] =
    {
        .baseHP        = 70,
        .baseAttack    = 100,
        .baseDefense   = 115,
        .baseSpeed     = 75,
        .baseSpAttack  = 35,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_ROCK),
        .catchRate = 120,
        .expYield = 158,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = { ABILITY_ANGER_SHELL, ABILITY_SHELL_ARMOR, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Craparoi"),
        .cryId = CRY_KLAWF,
        .natDexNum = NATIONAL_DEX_KLAWF,
        .categoryName = _("Embuscade"),
        .height = 13,
        .weight = 790,
        .description = COMPOUND_STRING(
            "Il fait éclore une grande fleur composée d'une\n"
            "substance toxique, et repousse ses adversaires\n"
            "en s'alliant avec les Germéclat."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Klawf,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Klawf,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 20,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Klawf,
        .shinyPalette = gMonShinyPalette_Klawf,
        .iconSprite = gMonIcon_Klawf,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 0, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Klawf)
        OVERWORLD(
            sPicTable_Klawf,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Klawf,
            gShinyOverworldPalette_Klawf
        )
        .levelUpLearnset = sKlawfLevelUpLearnset,
        .teachableLearnset = sKlawfTeachableLearnset,
        .eggMoveLearnset = sKlawfEggMoveLearnset,
    },
#endif //P_FAMILY_KLAWF

#if P_FAMILY_CAPSAKID
    [SPECIES_CAPSAKID] =
    {
        .baseHP        = 50,
        .baseAttack    = 62,
        .baseDefense   = 40,
        .baseSpeed     = 50,
        .baseSpAttack  = 62,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 190,
        .expYield = 61,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_INSOMNIA, ABILITY_KLUTZ },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Pimito"),
        .cryId = CRY_CAPSAKID,
        .natDexNum = NATIONAL_DEX_CAPSAKID,
        .categoryName = _("Habanero"),
        .height = 3,
        .weight = 30,
        .description = COMPOUND_STRING(
            "On raconte qu'il est né lorsqu'un mystérieux\n"
            "Pokémon Poison a pris possession d'un moteur\n"
            "laissé à l'abandon dans une casse."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Capsakid,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Capsakid,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Capsakid,
        .shinyPalette = gMonShinyPalette_Capsakid,
        .iconSprite = gMonIcon_Capsakid,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(2, 0, SHADOW_SIZE_S)
        FOOTPRINT(Capsakid)
        OVERWORLD(
            sPicTable_Capsakid,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Capsakid,
            gShinyOverworldPalette_Capsakid
        )
        .levelUpLearnset = sCapsakidLevelUpLearnset,
        .teachableLearnset = sCapsakidTeachableLearnset,
        .eggMoveLearnset = sCapsakidEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_FIRE_STONE, SPECIES_SCOVILLAIN}),
    },

    [SPECIES_SCOVILLAIN] =
    {
        .baseHP        = 65,
        .baseAttack    = 108,
        .baseDefense   = 65,
        .baseSpeed     = 75,
        .baseSpAttack  = 108,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_GRASS, TYPE_FIRE),
        .catchRate = 75,
        .expYield = 170,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_INSOMNIA, ABILITY_MOODY },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Scovilain"),
        .cryId = CRY_SCOVILLAIN,
        .natDexNum = NATIONAL_DEX_SCOVILLAIN,
        .categoryName = _("Habanero"),
        .height = 9,
        .weight = 150,
        .description = COMPOUND_STRING(
            "Il produit de l'énergie en faisant exploser dans\n"
            "ses huit cylindres un mélange gazeux qui contient\n"
            "une substance toxique et des minéraux."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Scovillain,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Scovillain,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Scovillain,
        .shinyPalette = gMonShinyPalette_Scovillain,
        .iconSprite = gMonIcon_Scovillain,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 11, SHADOW_SIZE_M)
        FOOTPRINT(Scovillain)
        OVERWORLD(
            sPicTable_Scovillain,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Scovillain,
            gShinyOverworldPalette_Scovillain
        )
        .levelUpLearnset = sScovillainLevelUpLearnset,
        .teachableLearnset = sScovillainTeachableLearnset,
        .formSpeciesIdTable = sScovillainFormSpeciesIdTable,
        .formChangeTable = sScovillainFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_SCOVILLAIN_MEGA] =
    {
        .baseHP        = 65,
        .baseAttack    = 138,
        .baseDefense   = 85,
        .baseSpeed     = 75,
        .baseSpAttack  = 138,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_GRASS, TYPE_FIRE),
        .catchRate = 75,
        .expYield = 170,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_SPICY_SPRAY, ABILITY_SPICY_SPRAY, ABILITY_SPICY_SPRAY },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Scovilain"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_SCOVILLAIN_MEGA,
    #else
        .cryId = CRY_SCOVILLAIN,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_SCOVILLAIN,
        .categoryName = _("Habanero"),
        .height = 12,
        .weight = 220,
        .description = COMPOUND_STRING(
            "Il produit de l'énergie en faisant exploser dans\n"
            "ses huit cylindres un mélange gazeux qui contient\n"
            "une substance toxique et des minéraux."
        ),
        .frontPic = gMonFrontPic_ScovillainMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ScovillainMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ScovillainMega,
        .shinyPalette = gMonShinyPalette_ScovillainMega,
        .iconSprite = gMonIcon_ScovillainMega,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Scovillain)
        SHADOW(1, 12, SHADOW_SIZE_M)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sScovillainLevelUpLearnset,
        .teachableLearnset = sScovillainTeachableLearnset,
        .formSpeciesIdTable = sScovillainFormSpeciesIdTable,
        .formChangeTable = sScovillainFormChangeTable,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_CAPSAKID

#if P_FAMILY_RELLOR
    [SPECIES_RELLOR] =
    {
        .baseHP        = 41,
        .baseAttack    = 50,
        .baseDefense   = 60,
        .baseSpeed     = 30,
        .baseSpAttack  = 31,
        .baseSpDefense = 58,
        .types = MON_TYPES(TYPE_BUG),
        .catchRate = 190,
        .expYield = 54,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_COMPOUND_EYES, ABILITY_NONE, ABILITY_SHED_SKIN },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Léboulérou"),
        .cryId = CRY_RELLOR,
        .natDexNum = NATIONAL_DEX_RELLOR,
        .categoryName = _("Rouleur"),
        .height = 2,
        .weight = 10,
        .description = COMPOUND_STRING(
            "Il lévite à un centimètre du sol grâce à l'énergie\n"
            "psychique qui émane des volants de son abdomen."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Rellor,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Rellor,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Rellor,
        .shinyPalette = gMonShinyPalette_Rellor,
        .iconSprite = gMonIcon_Rellor,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(4, -3, SHADOW_SIZE_L)
        FOOTPRINT(Rellor)
        OVERWORLD(
            sPicTable_Rellor,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Rellor,
            gShinyOverworldPalette_Rellor
        )
        .levelUpLearnset = sRellorLevelUpLearnset,
        .teachableLearnset = sRellorTeachableLearnset,
        .eggMoveLearnset = sRellorEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_RABSCA, CONDITIONS({IF_MIN_OVERWORLD_STEPS, 1000})}),
    },

    [SPECIES_RABSCA] =
    {
        .baseHP        = 75,
        .baseAttack    = 50,
        .baseDefense   = 85,
        .baseSpeed     = 45,
        .baseSpAttack  = 115,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_BUG, TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = 165,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SYNCHRONIZE, ABILITY_NONE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Bérasca"),
        .cryId = CRY_RABSCA,
        .natDexNum = NATIONAL_DEX_RABSCA,
        .categoryName = _("Rouleur"),
        .height = 3,
        .weight = 35,
        .description = COMPOUND_STRING(
            "Ce Pokémon immobilise ses adversaires grâce à\n"
            "l'énergie psychique qui émane de ses grands yeux.\n"
            "Il est beaucoup plus violent qu'il n'en a l'air."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Rabsca,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Rabsca,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Rabsca,
        .shinyPalette = gMonShinyPalette_Rabsca,
        .iconSprite = gMonIcon_Rabsca,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 14, SHADOW_SIZE_M)
        FOOTPRINT(Rabsca)
        OVERWORLD(
            sPicTable_Rabsca,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Rabsca,
            gShinyOverworldPalette_Rabsca
        )
        .levelUpLearnset = sRabscaLevelUpLearnset,
        .teachableLearnset = sRabscaTeachableLearnset,
    },
#endif //P_FAMILY_RELLOR

#if P_FAMILY_FLITTLE
    [SPECIES_FLITTLE] =
    {
        .baseHP        = 30,
        .baseAttack    = 35,
        .baseDefense   = 30,
        .baseSpeed     = 75,
        .baseSpAttack  = 55,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 120,
        .expYield = 51,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_ANTICIPATION, ABILITY_FRISK, ABILITY_SPEED_BOOST },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Flotillon"),
        .cryId = CRY_FLITTLE,
        .natDexNum = NATIONAL_DEX_FLITTLE,
        .categoryName = _("Froufrou"),
        .height = 2,
        .weight = 15,
        .description = COMPOUND_STRING(
            "Ce Pokémon est beaucoup plus violent qu'il n'y\n"
            "paraît. Il enroule son long corps autour de ses\n"
            "proies pour les attirer dans son nid."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Flittle,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Flittle,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Flittle,
        .shinyPalette = gMonShinyPalette_Flittle,
        .iconSprite = gMonIcon_Flittle,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 2, SHADOW_SIZE_S)
        FOOTPRINT(Flittle)
        OVERWORLD(
            sPicTable_Flittle,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Flittle,
            gShinyOverworldPalette_Flittle
        )
        .levelUpLearnset = sFlittleLevelUpLearnset,
        .teachableLearnset = sFlittleTeachableLearnset,
        .eggMoveLearnset = sFlittleEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_ESPATHRA}),
    },

    [SPECIES_ESPATHRA] =
    {
        .baseHP        = 95,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 105,
        .baseSpAttack  = 101,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 60,
        .expYield = 168,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_OPPORTUNIST, ABILITY_FRISK, ABILITY_SPEED_BOOST },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Cléopsytra"),
        .cryId = CRY_ESPATHRA,
        .natDexNum = NATIONAL_DEX_ESPATHRA,
        .categoryName = _("Autruche"),
        .height = 19,
        .weight = 900,
        .description = COMPOUND_STRING(
            "Comme il n'est pas très doué pour attraper ses\n"
            "proies, ce Pokémon vorace fait équipe avec\n"
            "Nigirigon pour chasser."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Espathra,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Espathra,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Espathra,
        .shinyPalette = gMonShinyPalette_Espathra,
        .iconSprite = gMonIcon_Espathra,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 10, SHADOW_SIZE_M)
        FOOTPRINT(Espathra)
        OVERWORLD(
            sPicTable_Espathra,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Espathra,
            gShinyOverworldPalette_Espathra
        )
        .levelUpLearnset = sEspathraLevelUpLearnset,
        .teachableLearnset = sEspathraTeachableLearnset,
    },
#endif //P_FAMILY_FLITTLE

#if P_FAMILY_TINKATINK
    [SPECIES_TINKATINK] =
    {
        .baseHP        = 50,
        .baseAttack    = 45,
        .baseDefense   = 45,
        .baseSpeed     = 58,
        .baseSpAttack  = 35,
        .baseSpDefense = 64,
        .types = MON_TYPES(TYPE_FAIRY, TYPE_STEEL),
        .catchRate = 190,
        .expYield = 59,
        .evYield_SpDefense = 1,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
        .abilities = { ABILITY_MOLD_BREAKER, ABILITY_OWN_TEMPO, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Forgerette"),
        .cryId = CRY_TINKATINK,
        .natDexNum = NATIONAL_DEX_TINKATINK,
        .categoryName = _("Forge"),
        .height = 4,
        .weight = 89,
        .description = COMPOUND_STRING(
            "Il a évolué grâce à l'armure d'une illustre âme\n"
            "guerrière. Ce Pokémon est extrêmement loyal."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tinkatink,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Tinkatink,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Tinkatink,
        .shinyPalette = gMonShinyPalette_Tinkatink,
        .iconSprite = gMonIcon_Tinkatink,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-3, 1, SHADOW_SIZE_S)
        FOOTPRINT(Tinkatink)
        OVERWORLD(
            sPicTable_Tinkatink,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Tinkatink,
            gShinyOverworldPalette_Tinkatink
        )
        .levelUpLearnset = sTinkatinkLevelUpLearnset,
        .teachableLearnset = sTinkatinkTeachableLearnset,
        .eggMoveLearnset = sTinkatinkEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 24, SPECIES_TINKATUFF}),
    },

    [SPECIES_TINKATUFF] =
    {
        .baseHP        = 65,
        .baseAttack    = 55,
        .baseDefense   = 55,
        .baseSpeed     = 78,
        .baseSpAttack  = 45,
        .baseSpDefense = 82,
        .types = MON_TYPES(TYPE_FAIRY, TYPE_STEEL),
        .catchRate = 90,
        .expYield = 133,
        .evYield_SpDefense = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
        .abilities = { ABILITY_MOLD_BREAKER, ABILITY_OWN_TEMPO, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Forgella"),
        .cryId = CRY_TINKATUFF,
        .natDexNum = NATIONAL_DEX_TINKATUFF,
        .categoryName = _("Marteau"),
        .height = 7,
        .weight = 591,
        .description = COMPOUND_STRING(
            "Les flammes de ses épées sont animées par la\n"
            "rancœur d'une âme guerrière qui a péri avant de\n"
            "pouvoir accomplir son but."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tinkatuff,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Tinkatuff,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Tinkatuff,
        .shinyPalette = gMonShinyPalette_Tinkatuff,
        .iconSprite = gMonIcon_Tinkatuff,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-4, 5, SHADOW_SIZE_L)
        FOOTPRINT(Tinkatuff)
        OVERWORLD(
            sPicTable_Tinkatuff,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Tinkatuff,
            gShinyOverworldPalette_Tinkatuff
        )
        .levelUpLearnset = sTinkatuffLevelUpLearnset,
        .teachableLearnset = sTinkatuffTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_TINKATON}),
    },

    [SPECIES_TINKATON] =
    {
        .baseHP        = 85,
        .baseAttack    = 75,
        .baseDefense   = 77,
        .baseSpeed     = 94,
        .baseSpAttack  = 70,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_FAIRY, TYPE_STEEL),
        .catchRate = 45,
        .expYield = 253,
        .evYield_SpDefense = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
        .abilities = { ABILITY_MOLD_BREAKER, ABILITY_OWN_TEMPO, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Forgelina"),
        .cryId = CRY_TINKATON,
        .natDexNum = NATIONAL_DEX_TINKATON,
        .categoryName = _("Marteau"),
        .height = 7,
        .weight = 1128,
        .description = COMPOUND_STRING(
            "Il vit dans les forêts humides. La partie ondulée\n"
            "qui entoure son abdomen peut se détacher. Elle\n"
            "est croquante et délicieuse."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tinkaton,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Tinkaton,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Tinkaton,
        .shinyPalette = gMonShinyPalette_Tinkaton,
        .iconSprite = gMonIcon_Tinkaton,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-5, 15, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Tinkaton)
        OVERWORLD(
            sPicTable_Tinkaton,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Tinkaton,
            gShinyOverworldPalette_Tinkaton
        )
        .levelUpLearnset = sTinkatonLevelUpLearnset,
        .teachableLearnset = sTinkatonTeachableLearnset,
    },
#endif //P_FAMILY_TINKATINK

#if P_FAMILY_WIGLETT
    [SPECIES_WIGLETT] =
    {
        .baseHP        = 10,
        .baseAttack    = 55,
        .baseDefense   = 25,
        .baseSpeed     = 95,
        .baseSpAttack  = 35,
        .baseSpDefense = 25,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 255,
        .expYield = 49,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = { ABILITY_GOOEY, ABILITY_RATTLED, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Taupikeau"),
        .cryId = CRY_WIGLETT,
        .natDexNum = NATIONAL_DEX_WIGLETT,
        .categoryName = _("Congre"),
        .height = 12,
        .weight = 18,
        .description = COMPOUND_STRING(
            "Il aime utiliser l'anneau d'eau de sa queue quand il\n"
            "joue avec ses congénères et se sert d'ultrasons\n"
            "pour comprendre les émotions des autres."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Wiglett,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Wiglett,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Wiglett,
        .shinyPalette = gMonShinyPalette_Wiglett,
        .iconSprite = gMonIcon_Wiglett,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        NO_SHADOW
        FOOTPRINT(Wiglett)
        OVERWORLD(
            sPicTable_Wiglett,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Wiglett,
            gShinyOverworldPalette_Wiglett
        )
        .levelUpLearnset = sWiglettLevelUpLearnset,
        .teachableLearnset = sWiglettTeachableLearnset,
        .eggMoveLearnset = sWiglettEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 26, SPECIES_WUGTRIO}),
    },

    [SPECIES_WUGTRIO] =
    {
        .baseHP        = 35,
        .baseAttack    = 100,
        .baseDefense   = 50,
        .baseSpeed     = 120,
        .baseSpAttack  = 50,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 50,
        .expYield = 149,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = { ABILITY_GOOEY, ABILITY_RATTLED, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Triopikeau"),
        .cryId = CRY_WUGTRIO,
        .natDexNum = NATIONAL_DEX_WUGTRIO,
        .categoryName = _("Congre"),
        .height = 12,
        .weight = 54,
        .description = COMPOUND_STRING(
            "Il change de forme dès qu'il entend les cris de\n"
            "détresse de ses congénères, mais il ne laissera\n"
            "jamais personne assister à sa transformation."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Wugtrio,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Wugtrio,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Wugtrio,
        .shinyPalette = gMonShinyPalette_Wugtrio,
        .iconSprite = gMonIcon_Wugtrio,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        NO_SHADOW
        FOOTPRINT(Wugtrio)
        OVERWORLD(
            sPicTable_Wugtrio,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Wugtrio,
            gShinyOverworldPalette_Wugtrio
        )
        .levelUpLearnset = sWugtrioLevelUpLearnset,
        .teachableLearnset = sWugtrioTeachableLearnset,
    },
#endif //P_FAMILY_WIGLETT

#if P_FAMILY_BOMBIRDIER
    [SPECIES_BOMBIRDIER] =
    {
        .baseHP        = 70,
        .baseAttack    = 103,
        .baseDefense   = 85,
        .baseSpeed     = 82,
        .baseSpAttack  = 60,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_FLYING, TYPE_DARK),
        .catchRate = 25,
        .expYield = 243,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_BIG_PECKS, ABILITY_KEEN_EYE, ABILITY_ROCKY_PAYLOAD },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Lestombaile"),
        .cryId = CRY_BOMBIRDIER,
        .natDexNum = NATIONAL_DEX_BOMBIRDIER,
        .categoryName = _("Délesteur"),
        .height = 15,
        .weight = 429,
        .description = COMPOUND_STRING(
            "Ce Pokémon est né dans des couches souterraines\n"
            "de sel gemme. Connu pour partager son précieux\n"
            "sel, il était très apprécié autrefois."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Bombirdier,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Bombirdier,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Bombirdier,
        .shinyPalette = gMonShinyPalette_Bombirdier,
        .iconSprite = gMonIcon_Bombirdier,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(8, 12, SHADOW_SIZE_M)
        FOOTPRINT(Bombirdier)
        OVERWORLD(
            sPicTable_Bombirdier,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Bombirdier,
            gShinyOverworldPalette_Bombirdier
        )
        .levelUpLearnset = sBombirdierLevelUpLearnset,
        .teachableLearnset = sBombirdierTeachableLearnset,
        .eggMoveLearnset = sBombirdierEggMoveLearnset,
    },
#endif //P_FAMILY_BOMBIRDIER

#if P_FAMILY_FINIZEN
    [SPECIES_FINIZEN] =
    {
        .baseHP        = 70,
        .baseAttack    = 45,
        .baseDefense   = 40,
        .baseSpeed     = 75,
        .baseSpAttack  = 45,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 200,
        .expYield = 63,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_WATER_2),
        .abilities = { ABILITY_WATER_VEIL, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Dofin"),
        .cryId = CRY_FINIZEN,
        .natDexNum = NATIONAL_DEX_FINIZEN,
        .categoryName = _("Dauphin"),
        .height = 13,
        .weight = 602,
        .description = COMPOUND_STRING(
            "Calme et bienveillant, il partage son huile\n"
            "délicieuse et riche en nutriments avec les\n"
            "Pokémon affaiblis."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Finizen,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Finizen,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Finizen,
        .shinyPalette = gMonShinyPalette_Finizen,
        .iconSprite = gMonIcon_Finizen,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 7, SHADOW_SIZE_S)
        FOOTPRINT(Finizen)
        OVERWORLD(
            sPicTable_Finizen,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Finizen,
            gShinyOverworldPalette_Finizen
        )
        .levelUpLearnset = sFinizenLevelUpLearnset,
        .teachableLearnset = sFinizenTeachableLearnset,
        .eggMoveLearnset = sFinizenEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_PALAFIN_ZERO}),
    },

    [SPECIES_PALAFIN_ZERO] =
    {
        .baseHP        = 100,
        .baseAttack    = 70,
        .baseDefense   = 72,
        .baseSpeed     = 100,
        .baseSpAttack  = 53,
        .baseSpDefense = 62,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = 160,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_WATER_2),
        .abilities = { ABILITY_ZERO_TO_HERO, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Superdofin"),
        .cryId = CRY_FINIZEN,
        .natDexNum = NATIONAL_DEX_PALAFIN,
        .categoryName = _("Dauphin"),
        .height = 13,
        .weight = 602,
        .description = COMPOUND_STRING(
            "Plus ce Pokémon s'expose au soleil, plus son corps\n"
            "produit une substance piquante, ce qui apporte\n"
            "un peu de piment à ses capacités."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PalafinZero,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        /*.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,*/
        .backPic = gMonBackPic_PalafinZero,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PalafinZero,
        .shinyPalette = gMonShinyPalette_PalafinZero,
        .iconSprite = gMonIcon_PalafinZero,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 7, SHADOW_SIZE_S)
        FOOTPRINT(Palafin)
        OVERWORLD(
            sPicTable_PalafinZero,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_PalafinZero,
            gShinyOverworldPalette_PalafinZero
        )
        .levelUpLearnset = sPalafinLevelUpLearnset,
        .teachableLearnset = sPalafinTeachableLearnset,
        .formSpeciesIdTable = sPalafinFormSpeciesIdTable,
        .formChangeTable = sPalafinZeroFormChangeTable,
    },

    [SPECIES_PALAFIN_HERO] =
    {
        .baseHP        = 100,
        .baseAttack    = 160,
        .baseDefense   = 97,
        .baseSpeed     = 100,
        .baseSpAttack  = 106,
        .baseSpDefense = 87,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = 228,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_WATER_2),
        .abilities = { ABILITY_ZERO_TO_HERO, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Superdofin"),
        .cryId = CRY_PALAFIN_HERO,
        .natDexNum = NATIONAL_DEX_PALAFIN,
        .categoryName = _("Super Héros"),
        .height = 18,
        .weight = 974,
        .description = COMPOUND_STRING(
            "Plus ce Pokémon s'expose au soleil, plus son corps\n"
            "produit une substance piquante, ce qui apporte\n"
            "un peu de piment à ses capacités."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_PalafinHero,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        /*.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,*/
        .backPic = gMonBackPic_PalafinHero,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_PalafinHero,
        .shinyPalette = gMonShinyPalette_PalafinHero,
        .iconSprite = gMonIcon_PalafinHero,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 13, SHADOW_SIZE_M)
        FOOTPRINT(Palafin)
        OVERWORLD(
            sPicTable_PalafinHero,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_PalafinHero,
            gShinyOverworldPalette_PalafinHero
        )
        .levelUpLearnset = sPalafinLevelUpLearnset,
        .teachableLearnset = sPalafinTeachableLearnset,
        .formSpeciesIdTable = sPalafinFormSpeciesIdTable,
        .formChangeTable = sPalafinZeroFormChangeTable,
    },
#endif //P_FAMILY_FINIZEN

#if P_FAMILY_VAROOM
    [SPECIES_VAROOM] =
    {
        .baseHP        = 45,
        .baseAttack    = 70,
        .baseDefense   = 63,
        .baseSpeed     = 47,
        .baseSpAttack  = 30,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_STEEL, TYPE_POISON),
        .catchRate = 190,
        .expYield = 60,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_OVERCOAT, ABILITY_NONE, ABILITY_SLOW_START },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Vrombi"),
        .cryId = CRY_VAROOM,
        .natDexNum = NATIONAL_DEX_VAROOM,
        .categoryName = _("Monocylindre"),
        .height = 10,
        .weight = 350,
        .description = COMPOUND_STRING(
            "Ils construisent des nids gigantesques divisés en\n"
            "espaces distincts qui répondent à différents\n"
            "besoins, comme dormir ou s'alimenter."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Varoom,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Varoom,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Varoom,
        .shinyPalette = gMonShinyPalette_Varoom,
        .iconSprite = gMonIcon_Varoom,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 0, SHADOW_SIZE_M)
        FOOTPRINT(Varoom)
        OVERWORLD(
            sPicTable_Varoom,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Varoom,
            gShinyOverworldPalette_Varoom
        )
        .levelUpLearnset = sVaroomLevelUpLearnset,
        .teachableLearnset = sVaroomTeachableLearnset,
        .eggMoveLearnset = sVaroomEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_REVAVROOM}),
    },

    [SPECIES_REVAVROOM] =
    {
        .baseHP        = 80,
        .baseAttack    = 119,
        .baseDefense   = 90,
        .baseSpeed     = 90,
        .baseSpAttack  = 54,
        .baseSpDefense = 67,
        .types = MON_TYPES(TYPE_STEEL, TYPE_POISON),
        .catchRate = 75,
        .expYield = 175,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_OVERCOAT, ABILITY_NONE, ABILITY_FILTER },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Vrombotor"),
        .cryId = CRY_REVAVROOM,
        .natDexNum = NATIONAL_DEX_REVAVROOM,
        .categoryName = _("Polycylindre"),
        .height = 18,
        .weight = 1200,
        .description = COMPOUND_STRING(
            "Ce Pokémon a quitté le milieu marin il y a fort\n"
            "longtemps pour s'installer sur la terre ferme. Il\n"
            "appartiendrait à une espèce proche des Wailmer."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Revavroom,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Revavroom,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 16,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Revavroom,
        .shinyPalette = gMonShinyPalette_Revavroom,
        .iconSprite = gMonIcon_Revavroom,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 7, SHADOW_SIZE_L)
        FOOTPRINT(Revavroom)
        OVERWORLD(
            sPicTable_Revavroom,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Revavroom,
            gShinyOverworldPalette_Revavroom
        )
        .levelUpLearnset = sRevavroomLevelUpLearnset,
        .teachableLearnset = sRevavroomTeachableLearnset,
    },
#endif //P_FAMILY_VAROOM

#if P_FAMILY_CYCLIZAR
    [SPECIES_CYCLIZAR] =
    {
        .baseHP        = 70,
        .baseAttack    = 95,
        .baseDefense   = 65,
        .baseSpeed     = 121,
        .baseSpAttack  = 85,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_NORMAL),
        .catchRate = 190,
        .expYield = 175,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SHED_SKIN, ABILITY_NONE, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Motorizard"),
        .cryId = CRY_CYCLIZAR,
        .natDexNum = NATIONAL_DEX_CYCLIZAR,
        .categoryName = _("Monture"),
        .height = 16,
        .weight = 630,
        .description = COMPOUND_STRING(
            "Les os de ses ailes produisent de l'électricité\n"
            "grâce au vent. Pour chasser, ce Pokémon plonge\n"
            "dans la mer et électrocute ses proies."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cyclizar,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Cyclizar,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Cyclizar,
        .shinyPalette = gMonShinyPalette_Cyclizar,
        .iconSprite = gMonIcon_Cyclizar,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 9, SHADOW_SIZE_M)
        FOOTPRINT(Cyclizar)
        OVERWORLD(
            sPicTable_Cyclizar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cyclizar,
            gShinyOverworldPalette_Cyclizar
        )
        .levelUpLearnset = sCyclizarLevelUpLearnset,
        .teachableLearnset = sCyclizarTeachableLearnset,
        .eggMoveLearnset = sCyclizarEggMoveLearnset,
    },
#endif //P_FAMILY_CYCLIZAR

#if P_FAMILY_ORTHWORM
    [SPECIES_ORTHWORM] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 145,
        .baseSpeed     = 65,
        .baseSpAttack  = 60,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_STEEL),
        .catchRate = 25,
        .expYield = 240,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_EARTH_EATER, ABILITY_NONE, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Ferdeter"),
        .cryId = CRY_ORTHWORM,
        .natDexNum = NATIONAL_DEX_ORTHWORM,
        .categoryName = _("Ver de Terre"),
        .height = 25,
        .weight = 3100,
        .description = COMPOUND_STRING(
            "Il est doté d'une crête dorsale qui peut geler\n"
            "l'air en convertissant la chaleur des capacités\n"
            "Feu en énergie de type Glace."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Orthworm,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Orthworm,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Orthworm,
        .shinyPalette = gMonShinyPalette_Orthworm,
        .iconSprite = gMonIcon_Orthworm,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 10, SHADOW_SIZE_L)
        FOOTPRINT(Orthworm)
        OVERWORLD(
            sPicTable_Orthworm,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Orthworm,
            gShinyOverworldPalette_Orthworm
        )
        .levelUpLearnset = sOrthwormLevelUpLearnset,
        .teachableLearnset = sOrthwormTeachableLearnset,
        .eggMoveLearnset = sOrthwormEggMoveLearnset,
    },
#endif //P_FAMILY_ORTHWORM

#if P_FAMILY_GLIMMET
    [SPECIES_GLIMMET] =
    {
        .baseHP        = 48,
        .baseAttack    = 35,
        .baseDefense   = 42,
        .baseSpeed     = 60,
        .baseSpAttack  = 105,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ROCK, TYPE_POISON),
        .catchRate = 70,
        .expYield = 70,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_TOXIC_DEBRIS, ABILITY_NONE, ABILITY_CORROSION },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Germéclat"),
        .cryId = CRY_GLIMMET,
        .natDexNum = NATIONAL_DEX_GLIMMET,
        .categoryName = _("Minerai"),
        .height = 7,
        .weight = 80,
        .description = COMPOUND_STRING(
            "Le parfum délicieux de son corps provoque chez\n"
            "ses adversaires une faim irrésistible qui diminue\n"
            "leur volonté et leur endurance."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Glimmet,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 11,
        .backPic = gMonBackPic_Glimmet,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Glimmet,
        .shinyPalette = gMonShinyPalette_Glimmet,
        .iconSprite = gMonIcon_Glimmet,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 6, SHADOW_SIZE_S)
        FOOTPRINT(Glimmet)
        OVERWORLD(
            sPicTable_Glimmet,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Glimmet,
            gShinyOverworldPalette_Glimmet
        )
        .levelUpLearnset = sGlimmetLevelUpLearnset,
        .teachableLearnset = sGlimmetTeachableLearnset,
        .eggMoveLearnset = sGlimmetEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_GLIMMORA}),
    },

    [SPECIES_GLIMMORA] =
    {
        .baseHP        = 83,
        .baseAttack    = 55,
        .baseDefense   = 90,
        .baseSpeed     = 86,
        .baseSpAttack  = 130,
        .baseSpDefense = 81,
        .types = MON_TYPES(TYPE_ROCK, TYPE_POISON),
        .catchRate = 25,
        .expYield = 184,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_TOXIC_DEBRIS, ABILITY_NONE, ABILITY_CORROSION },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Floréclat"),
        .cryId = CRY_GLIMMORA,
        .natDexNum = NATIONAL_DEX_GLIMMORA,
        .categoryName = _("Minerai"),
        .height = 15,
        .weight = 450,
        .description = COMPOUND_STRING(
            "Ces Pokémon forment des meutes solidaires. Ils\n"
            "affichent un regard méchant pour intimider leurs\n"
            "adversaires."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Glimmora,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_Glimmora,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Glimmora,
        .shinyPalette = gMonShinyPalette_Glimmora,
        .iconSprite = gMonIcon_Glimmora,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 17, SHADOW_SIZE_M)
        FOOTPRINT(Glimmora)
        OVERWORLD(
            sPicTable_Glimmora,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Glimmora,
            gShinyOverworldPalette_Glimmora
        )
        .levelUpLearnset = sGlimmoraLevelUpLearnset,
        .teachableLearnset = sGlimmoraTeachableLearnset,
        .formSpeciesIdTable = sGlimmoraFormSpeciesIdTable,
        .formChangeTable = sGlimmoraFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_GLIMMORA_MEGA] =
    {
        .baseHP        = 83,
        .baseAttack    = 90,
        .baseDefense   = 105,
        .baseSpeed     = 101,
        .baseSpAttack  = 150,
        .baseSpDefense = 96,
        .types = MON_TYPES(TYPE_ROCK, TYPE_POISON),
        .catchRate = 25,
        .expYield = 184,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_ADAPTABILITY, ABILITY_ADAPTABILITY, ABILITY_ADAPTABILITY },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Floréclat"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_GLIMMORA_MEGA,
    #else
        .cryId = CRY_GLIMMORA,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_GLIMMORA,
        .categoryName = _("Minerai"),
        .height = 15,
        .weight = 450,
        .description = COMPOUND_STRING(
            "Ces Pokémon forment des meutes solidaires. Ils\n"
            "affichent un regard méchant pour intimider leurs\n"
            "adversaires."
        ),
        .frontPic = gMonFrontPic_GlimmoraMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_GlimmoraMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_GlimmoraMega,
        .shinyPalette = gMonShinyPalette_GlimmoraMega,
        .iconSprite = gMonIcon_GlimmoraMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Glimmora)
        SHADOW(1, 18, SHADOW_SIZE_M)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sGlimmoraLevelUpLearnset,
        .teachableLearnset = sGlimmoraTeachableLearnset,
        .formSpeciesIdTable = sGlimmoraFormSpeciesIdTable,
        .formChangeTable = sGlimmoraFormChangeTable,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_GLIMMET

#if P_FAMILY_GREAVARD
    [SPECIES_GREAVARD] =
    {
        .baseHP        = 50,
        .baseAttack    = 61,
        .baseDefense   = 60,
        .baseSpeed     = 34,
        .baseSpAttack  = 30,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 120,
        .expYield = 58,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_PICKUP, ABILITY_NONE, ABILITY_FLUFFY },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Toutombe"),
        .cryId = CRY_GREAVARD,
        .natDexNum = NATIONAL_DEX_GREAVARD,
        .categoryName = _("Fantôchien"),
        .height = 6,
        .weight = 350,
        .description = COMPOUND_STRING(
            "Grâce à la synchronisation des ondes cérébrales\n"
            "de sa tête et de sa queue, ses pouvoirs\n"
            "psychiques sont dix fois plus puissants que ceux\n"
            "de Girafarig."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Greavard,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Greavard,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Greavard,
        .shinyPalette = gMonShinyPalette_Greavard,
        .iconSprite = gMonIcon_Greavard,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(3, 2, SHADOW_SIZE_M)
        FOOTPRINT(Greavard)
        OVERWORLD(
            sPicTable_Greavard,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Greavard,
            gShinyOverworldPalette_Greavard
        )
        .levelUpLearnset = sGreavardLevelUpLearnset,
        .teachableLearnset = sGreavardTeachableLearnset,
        .eggMoveLearnset = sGreavardEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_HOUNDSTONE, CONDITIONS({IF_TIME, TIME_NIGHT})}),
    },

    [SPECIES_HOUNDSTONE] =
    {
        .baseHP        = 72,
        .baseAttack    = 101,
        .baseDefense   = 100,
        .baseSpeed     = 68,
        .baseSpAttack  = 50,
        .baseSpDefense = 97,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 60,
        .expYield = 171,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SAND_RUSH, ABILITY_NONE, ABILITY_FLUFFY },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Tomberro"),
        .cryId = CRY_HOUNDSTONE,
        .natDexNum = NATIONAL_DEX_HOUNDSTONE,
        .categoryName = _("Fantôchien"),
        .height = 20,
        .weight = 150,
        .description = COMPOUND_STRING(
            "Il détecte l'odeur de Délestin à plus de vingt\n"
            "mètres, ce qui lui donne le temps de s'enfouir\n"
            "dans le sable."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Houndstone,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Houndstone,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Houndstone,
        .shinyPalette = gMonShinyPalette_Houndstone,
        .iconSprite = gMonIcon_Houndstone,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 6, SHADOW_SIZE_L)
        FOOTPRINT(Houndstone)
        OVERWORLD(
            sPicTable_Houndstone,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Houndstone,
            gShinyOverworldPalette_Houndstone
        )
        .levelUpLearnset = sHoundstoneLevelUpLearnset,
        .teachableLearnset = sHoundstoneTeachableLearnset,
    },
#endif //P_FAMILY_GREAVARD

#if P_FAMILY_FLAMIGO
    [SPECIES_FLAMIGO] =
    {
        .baseHP        = 82,
        .baseAttack    = 115,
        .baseDefense   = 74,
        .baseSpeed     = 90,
        .baseSpAttack  = 75,
        .baseSpDefense = 64,
        .types = MON_TYPES(TYPE_FLYING, TYPE_FIGHTING),
        .catchRate = 100,
        .expYield = 175,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_SCRAPPY, ABILITY_TANGLED_FEET, ABILITY_COSTAR },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Flamenroule"),
        .cryId = CRY_FLAMIGO,
        .natDexNum = NATIONAL_DEX_FLAMIGO,
        .categoryName = _("Synchro"),
        .height = 16,
        .weight = 370,
        .description = COMPOUND_STRING(
            "Le sel dont il saupoudre les Pokémon blessés en\n"
            "frottant le bout de ses doigts guérit aussitôt\n"
            "toutes les blessures, même les plus graves."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Flamigo,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Flamigo,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Flamigo,
        .shinyPalette = gMonShinyPalette_Flamigo,
        .iconSprite = gMonIcon_Flamigo,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 12, SHADOW_SIZE_S)
        FOOTPRINT(Flamigo)
        OVERWORLD(
            sPicTable_Flamigo,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Flamigo,
            gShinyOverworldPalette_Flamigo
        )
        .levelUpLearnset = sFlamigoLevelUpLearnset,
        .teachableLearnset = sFlamigoTeachableLearnset,
        .eggMoveLearnset = sFlamigoEggMoveLearnset,
    },
#endif //P_FAMILY_FLAMIGO

#if P_FAMILY_CETODDLE
    [SPECIES_CETODDLE] =
    {
        .baseHP        = 108,
        .baseAttack    = 68,
        .baseDefense   = 45,
        .baseSpeed     = 43,
        .baseSpAttack  = 30,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 150,
        .expYield = 67,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_THICK_FAT, ABILITY_SNOW_CLOAK, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Piétacé"),
        .cryId = CRY_CETODDLE,
        .natDexNum = NATIONAL_DEX_CETODDLE,
        .categoryName = _("Baleinapied"),
        .height = 12,
        .weight = 450,
        .description = COMPOUND_STRING(
            "L'air qu'il crache est tellement froid qu'il peut\n"
            "geler instantanément du magma en fusion."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cetoddle,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Cetoddle,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 16,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Cetoddle,
        .shinyPalette = gMonShinyPalette_Cetoddle,
        .iconSprite = gMonIcon_Cetoddle,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 0, SHADOW_SIZE_M)
        FOOTPRINT(Cetoddle)
        OVERWORLD(
            sPicTable_Cetoddle,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cetoddle,
            gShinyOverworldPalette_Cetoddle
        )
        .levelUpLearnset = sCetoddleLevelUpLearnset,
        .teachableLearnset = sCetoddleTeachableLearnset,
        .eggMoveLearnset = sCetoddleEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_ICE_STONE, SPECIES_CETITAN}),
    },

    [SPECIES_CETITAN] =
    {
        .baseHP        = 170,
        .baseAttack    = 113,
        .baseDefense   = 65,
        .baseSpeed     = 73,
        .baseSpAttack  = 45,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 50,
        .expYield = 182,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_THICK_FAT, ABILITY_SLUSH_RUSH, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Balbalèze"),
        .cryId = CRY_CETITAN,
        .natDexNum = NATIONAL_DEX_CETITAN,
        .categoryName = _("Baleinapied"),
        .height = 45,
        .weight = 7000,
        .description = COMPOUND_STRING(
            "Ce petit Pokémon Dragon vit dans la gueule\n"
            "d'Oyacata, à l'abri de ses adversaires."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cetitan,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Cetitan,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Cetitan,
        .shinyPalette = gMonShinyPalette_Cetitan,
        .iconSprite = gMonIcon_Cetitan,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 10, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Cetitan)
        OVERWORLD(
            sPicTable_Cetitan,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cetitan,
            gShinyOverworldPalette_Cetitan
        )
        .levelUpLearnset = sCetitanLevelUpLearnset,
        .teachableLearnset = sCetitanTeachableLearnset,
    },
#endif //P_FAMILY_CETODDLE

#if P_FAMILY_VELUZA
    [SPECIES_VELUZA] =
    {
        .baseHP        = 90,
        .baseAttack    = 102,
        .baseDefense   = 73,
        .baseSpeed     = 70,
        .baseSpAttack  = 78,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_WATER, TYPE_PSYCHIC),
        .catchRate = 100,
        .expYield = 167,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_MOLD_BREAKER, ABILITY_NONE, ABILITY_SHARPNESS },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Délestin"),
        .cryId = CRY_VELUZA,
        .natDexNum = NATIONAL_DEX_VELUZA,
        .categoryName = _("Décharné"),
        .height = 25,
        .weight = 900,
        .description = COMPOUND_STRING(
            "Ce Pokémon partage volontiers son huile fraîche\n"
            "et délicieuse. Il vit en harmonie avec les êtres\n"
            "humains depuis les temps anciens."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Veluza,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_Veluza,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Veluza,
        .shinyPalette = gMonShinyPalette_Veluza,
        .iconSprite = gMonIcon_Veluza,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 5, SHADOW_SIZE_M)
        FOOTPRINT(Veluza)
        OVERWORLD(
            sPicTable_Veluza,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Veluza,
            gShinyOverworldPalette_Veluza
        )
        .levelUpLearnset = sVeluzaLevelUpLearnset,
        .teachableLearnset = sVeluzaTeachableLearnset,
        .eggMoveLearnset = sVeluzaEggMoveLearnset,
    },
#endif //P_FAMILY_VELUZA

#if P_FAMILY_DONDOZO
    [SPECIES_DONDOZO] =
    {
        .baseHP        = 150,
        .baseAttack    = 100,
        .baseDefense   = 115,
        .baseSpeed     = 35,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 25,
        .expYield = 265,
        .evYield_HP = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_UNAWARE, ABILITY_OBLIVIOUS, ABILITY_WATER_VEIL },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Oyacata"),
        .cryId = CRY_DONDOZO,
        .natDexNum = NATIONAL_DEX_DONDOZO,
        .categoryName = _("Grand Silure"),
        .height = 120,
        .weight = 2200,
        .description = COMPOUND_STRING(
            "Le fruit qui surmonte sa tête sécrète une huile\n"
            "qui le protège de ses adversaires. Ce liquide a un\n"
            "goût si désagréable qu'il fait grimacer."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Dondozo,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 1,
        .backPic = gMonBackPic_Dondozo,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Dondozo,
        .shinyPalette = gMonShinyPalette_Dondozo,
        .iconSprite = gMonIcon_Dondozo,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 8, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Dondozo)
        OVERWORLD(
            sPicTable_Dondozo,
            SIZE_64x64,
            SHADOW_SIZE_L,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Dondozo,
            gShinyOverworldPalette_Dondozo
        )
        .levelUpLearnset = sDondozoLevelUpLearnset,
        .teachableLearnset = sDondozoTeachableLearnset,
        .eggMoveLearnset = sDondozoEggMoveLearnset,
    },
#endif //P_FAMILY_DONDOZO

#if P_FAMILY_TATSUGIRI
    [SPECIES_TATSUGIRI_CURLY] =
    {
        .baseHP        = 68,
        .baseAttack    = 50,
        .baseDefense   = 60,
        .baseSpeed     = 82,
        .baseSpAttack  = 120,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_WATER),
        .catchRate = 100,
        .expYield = 166,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_COMMANDER, ABILITY_NONE, ABILITY_STORM_DRAIN },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Nigirigon"),
        .cryId = CRY_TATSUGIRI_CURLY,
        .natDexNum = NATIONAL_DEX_TATSUGIRI,
        .categoryName = _("Mimétisme"),
        .height = 3,
        .weight = 80,
        .description = COMPOUND_STRING(
            "D'ordinaire, ce Pokémon est plutôt calme, mais\n"
            "lorsqu'il se bat, il élimine ses adversaires avec\n"
            "des mouvements rapides comme l'éclair."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_TatsugiriCurly,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        /*.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,*/
        .backPic = gMonBackPic_TatsugiriCurly,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 17,
        /*.backAnimId = BACK_ANIM_NONE,*/
        .palette = gMonPalette_TatsugiriCurly,
        .shinyPalette = gMonShinyPalette_TatsugiriCurly,
        .iconSprite = gMonIcon_TatsugiriCurly,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-2, -1, SHADOW_SIZE_S)
        FOOTPRINT(Tatsugiri)
        OVERWORLD(
            sPicTable_TatsugiriCurly,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_TatsugiriCurly,
            gShinyOverworldPalette_TatsugiriCurly
        )
        .levelUpLearnset = sTatsugiriLevelUpLearnset,
        .teachableLearnset = sTatsugiriTeachableLearnset,
        .eggMoveLearnset = sTatsugiriEggMoveLearnset,
        .formSpeciesIdTable = sTatsugiriFormSpeciesIdTable,
        .formChangeTable = sTatsugiriCurlyFormChangeTable,
    },

    [SPECIES_TATSUGIRI_DROOPY] =
    {
        .baseHP        = 68,
        .baseAttack    = 50,
        .baseDefense   = 60,
        .baseSpeed     = 82,
        .baseSpAttack  = 120,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_WATER),
        .catchRate = 100,
        .expYield = 166,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_COMMANDER, ABILITY_NONE, ABILITY_STORM_DRAIN },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Nigirigon"),
        .cryId = CRY_TATSUGIRI_DROOPY,
        .natDexNum = NATIONAL_DEX_TATSUGIRI,
        .categoryName = _("Mimétisme"),
        .height = 3,
        .weight = 80,
        .description = COMPOUND_STRING(
            "D'ordinaire, ce Pokémon est plutôt calme, mais\n"
            "lorsqu'il se bat, il élimine ses adversaires avec\n"
            "des mouvements rapides comme l'éclair."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_TatsugiriDroopy,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        /*.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,*/
        .backPic = gMonBackPic_TatsugiriDroopy,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 17,
        /*.backAnimId = BACK_ANIM_NONE,*/
        .palette = gMonPalette_TatsugiriDroopy,
        .shinyPalette = gMonShinyPalette_TatsugiriDroopy,
        .iconSprite = gMonIcon_TatsugiriDroopy,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-2, -1, SHADOW_SIZE_S)
        FOOTPRINT(Tatsugiri)
        OVERWORLD(
            sPicTable_TatsugiriDroopy,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_TatsugiriDroopy,
            gShinyOverworldPalette_TatsugiriDroopy
        )
        .levelUpLearnset = sTatsugiriLevelUpLearnset,
        .teachableLearnset = sTatsugiriTeachableLearnset,
        .eggMoveLearnset = sTatsugiriEggMoveLearnset,
        .formSpeciesIdTable = sTatsugiriFormSpeciesIdTable,
        .formChangeTable = sTatsugiriDroopyFormChangeTable,
    },

    [SPECIES_TATSUGIRI_STRETCHY] =
    {
        .baseHP        = 68,
        .baseAttack    = 50,
        .baseDefense   = 60,
        .baseSpeed     = 82,
        .baseSpAttack  = 120,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_WATER),
        .catchRate = 100,
        .expYield = 166,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_COMMANDER, ABILITY_NONE, ABILITY_STORM_DRAIN },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Nigirigon"),
        .cryId = CRY_TATSUGIRI_STRETCHY,
        .natDexNum = NATIONAL_DEX_TATSUGIRI,
        .categoryName = _("Mimétisme"),
        .height = 3,
        .weight = 80,
        .description = COMPOUND_STRING(
            "D'ordinaire, ce Pokémon est plutôt calme, mais\n"
            "lorsqu'il se bat, il élimine ses adversaires avec\n"
            "des mouvements rapides comme l'éclair."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_TatsugiriStretchy,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        /*.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,*/
        .backPic = gMonBackPic_TatsugiriStretchy,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 17,
        /*.backAnimId = BACK_ANIM_NONE,*/
        .palette = gMonPalette_TatsugiriStretchy,
        .shinyPalette = gMonShinyPalette_TatsugiriStretchy,
        .iconSprite = gMonIcon_TatsugiriStretchy,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-2, -1, SHADOW_SIZE_S)
        FOOTPRINT(Tatsugiri)
        OVERWORLD(
            sPicTable_TatsugiriStretchy,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_TatsugiriStretchy,
            gShinyOverworldPalette_TatsugiriStretchy
        )
        .levelUpLearnset = sTatsugiriLevelUpLearnset,
        .teachableLearnset = sTatsugiriTeachableLearnset,
        .eggMoveLearnset = sTatsugiriEggMoveLearnset,
        .formSpeciesIdTable = sTatsugiriFormSpeciesIdTable,
        .formChangeTable = sTatsugiriStretchyFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_TATSUGIRI_CURLY_MEGA] =
    {
        .baseHP        = 68,
        .baseAttack    = 65,
        .baseDefense   = 90,
        .baseSpeed     = 92,
        .baseSpAttack  = 135,
        .baseSpDefense = 125,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_WATER),
        .catchRate = 100,
        .expYield = 166,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_STORM_DRAIN, ABILITY_NONE, ABILITY_STORM_DRAIN },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Nigirigon"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_TATSUGIRI_MEGA,
    #else
        .cryId = CRY_TATSUGIRI_CURLY,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_TATSUGIRI,
        .categoryName = _("Mimétisme"),
        .height = 6,
        .weight = 240,
        .description = COMPOUND_STRING(
            "D'ordinaire, ce Pokémon est plutôt calme, mais\n"
            "lorsqu'il se bat, il élimine ses adversaires avec\n"
            "des mouvements rapides comme l'éclair."
        ),
        .frontPic = gMonFrontPic_TatsugiriCurlyMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_TatsugiriCurlyMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 17,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_TatsugiriMega,
        .shinyPalette = gMonShinyPalette_TatsugiriMega,
        .iconSprite = gMonIcon_TatsugiriCurlyMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Tatsugiri)
        SHADOW(0, 2, SHADOW_SIZE_M)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sTatsugiriLevelUpLearnset,
        .teachableLearnset = sTatsugiriTeachableLearnset,
        .eggMoveLearnset = sTatsugiriEggMoveLearnset,
        .formSpeciesIdTable = sTatsugiriFormSpeciesIdTable,
        .formChangeTable = sTatsugiriCurlyFormChangeTable,
    },

    [SPECIES_TATSUGIRI_DROOPY_MEGA] =
    {
        .baseHP        = 68,
        .baseAttack    = 65,
        .baseDefense   = 90,
        .baseSpeed     = 92,
        .baseSpAttack  = 135,
        .baseSpDefense = 125,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_WATER),
        .catchRate = 100,
        .expYield = 166,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_STORM_DRAIN, ABILITY_NONE, ABILITY_STORM_DRAIN },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Nigirigon"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_TATSUGIRI_MEGA,
    #else
        .cryId = CRY_TATSUGIRI_DROOPY,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_TATSUGIRI,
        .categoryName = _("Mimétisme"),
        .height = 6,
        .weight = 240,
        .description = COMPOUND_STRING(
            "D'ordinaire, ce Pokémon est plutôt calme, mais\n"
            "lorsqu'il se bat, il élimine ses adversaires avec\n"
            "des mouvements rapides comme l'éclair."
        ),
        .frontPic = gMonFrontPic_TatsugiriDroopyMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_TatsugiriDroopyMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 17,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_TatsugiriMega,
        .shinyPalette = gMonShinyPalette_TatsugiriMega,
        .iconSprite = gMonIcon_TatsugiriDroopyMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Tatsugiri)
        SHADOW(0, 2, SHADOW_SIZE_M)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sTatsugiriLevelUpLearnset,
        .teachableLearnset = sTatsugiriTeachableLearnset,
        .eggMoveLearnset = sTatsugiriEggMoveLearnset,
        .formSpeciesIdTable = sTatsugiriFormSpeciesIdTable,
        .formChangeTable = sTatsugiriDroopyFormChangeTable,
    },

    [SPECIES_TATSUGIRI_STRETCHY_MEGA] =
    {
        .baseHP        = 68,
        .baseAttack    = 65,
        .baseDefense   = 90,
        .baseSpeed     = 92,
        .baseSpAttack  = 135,
        .baseSpDefense = 125,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_WATER),
        .catchRate = 100,
        .expYield = 166,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_STORM_DRAIN, ABILITY_NONE, ABILITY_STORM_DRAIN },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Nigirigon"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_TATSUGIRI_MEGA,
    #else
        .cryId = CRY_TATSUGIRI_STRETCHY,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_TATSUGIRI,
        .categoryName = _("Mimétisme"),
        .height = 6,
        .weight = 240,
        .description = COMPOUND_STRING(
            "D'ordinaire, ce Pokémon est plutôt calme, mais\n"
            "lorsqu'il se bat, il élimine ses adversaires avec\n"
            "des mouvements rapides comme l'éclair."
        ),
        .frontPic = gMonFrontPic_TatsugiriStretchyMega,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_TatsugiriStretchyMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 17,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_TatsugiriMega,
        .shinyPalette = gMonShinyPalette_TatsugiriMega,
        .iconSprite = gMonIcon_TatsugiriStretchyMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Tatsugiri)
        SHADOW(0, 2, SHADOW_SIZE_M)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sTatsugiriLevelUpLearnset,
        .teachableLearnset = sTatsugiriTeachableLearnset,
        .eggMoveLearnset = sTatsugiriEggMoveLearnset,
        .formSpeciesIdTable = sTatsugiriFormSpeciesIdTable,
        .formChangeTable = sTatsugiriStretchyFormChangeTable,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_TATSUGIRI

#if P_FAMILY_GREAT_TUSK
    [SPECIES_GREAT_TUSK] =
    {
        .baseHP        = 115,
        .baseAttack    = 131,
        .baseDefense   = 131,
        .baseSpeed     = 87,
        .baseSpAttack  = 53,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_GROUND, TYPE_FIGHTING),
        .catchRate = 30,
        .expYield = 285,
        .evYield_Attack = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PROTOSYNTHESIS, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Fort-Ivoire"),
        .cryId = CRY_GREAT_TUSK,
        .natDexNum = NATIONAL_DEX_GREAT_TUSK,
        .categoryName = _("Paradoxe"),
        .height = 22,
        .weight = 3200,
        .description = COMPOUND_STRING(
            "Ce Pokémon n'avait été aperçu qu'une seule fois\n"
            "jusqu'ici. Il ressemble à une créature mystérieuse\n"
            "évoquée dans un vieux récit d'exploration."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_GreatTusk,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_GreatTusk,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_GreatTusk,
        .shinyPalette = gMonShinyPalette_GreatTusk,
        .iconSprite = gMonIcon_GreatTusk,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 13, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(GreatTusk)
        OVERWORLD(
            sPicTable_GreatTusk,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_GreatTusk,
            gShinyOverworldPalette_GreatTusk
        )
        .isParadox = TRUE,
        .levelUpLearnset = sGreatTuskLevelUpLearnset,
        .teachableLearnset = sGreatTuskTeachableLearnset,
    },
#endif //P_FAMILY_GREAT_TUSK

#if P_FAMILY_SCREAM_TAIL
    [SPECIES_SCREAM_TAIL] =
    {
        .baseHP        = 115,
        .baseAttack    = 65,
        .baseDefense   = 99,
        .baseSpeed     = 111,
        .baseSpAttack  = 65,
        .baseSpDefense = 115,
        .types = MON_TYPES(TYPE_FAIRY, TYPE_PSYCHIC),
        .catchRate = 50,
        .expYield = 285,
        .evYield_HP = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PROTOSYNTHESIS, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Hurle-Queue"),
        .cryId = CRY_SCREAM_TAIL,
        .natDexNum = NATIONAL_DEX_SCREAM_TAIL,
        .categoryName = _("Paradoxe"),
        .height = 12,
        .weight = 80,
        .description = COMPOUND_STRING(
            "Il ressemble beaucoup à une arme sophistiquée qui\n"
            "serait d'origine extraterrestre, selon une revue\n"
            "consacrée aux phénomènes paranormaux."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_ScreamTail,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ScreamTail,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ScreamTail,
        .shinyPalette = gMonShinyPalette_ScreamTail,
        .iconSprite = gMonIcon_ScreamTail,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 3, SHADOW_SIZE_L)
        FOOTPRINT(ScreamTail)
        OVERWORLD(
            sPicTable_ScreamTail,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ScreamTail,
            gShinyOverworldPalette_ScreamTail
        )
        .isParadox = TRUE,
        .levelUpLearnset = sScreamTailLevelUpLearnset,
        .teachableLearnset = sScreamTailTeachableLearnset,
    },
#endif //P_FAMILY_SCREAM_TAIL

#if P_FAMILY_BRUTE_BONNET
    [SPECIES_BRUTE_BONNET] =
    {
        .baseHP        = 111,
        .baseAttack    = 127,
        .baseDefense   = 99,
        .baseSpeed     = 55,
        .baseSpAttack  = 79,
        .baseSpDefense = 99,
        .types = MON_TYPES(TYPE_GRASS, TYPE_DARK),
        .catchRate = 50,
        .expYield = 285,
        .evYield_Attack = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PROTOSYNTHESIS, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Fongus-Furie"),
        .cryId = CRY_BRUTE_BONNET,
        .natDexNum = NATIONAL_DEX_BRUTE_BONNET,
        .categoryName = _("Paradoxe"),
        .height = 12,
        .weight = 210,
        .description = COMPOUND_STRING(
            "Ce Pokémon a des caractéristiques semblables à\n"
            "celles d'une créature évoquée dans un certain\n"
            "livre sous le nom de “ Flotte-Mèche ”."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_BruteBonnet,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_BruteBonnet,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_BruteBonnet,
        .shinyPalette = gMonShinyPalette_BruteBonnet,
        .iconSprite = gMonIcon_BruteBonnet,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 7, SHADOW_SIZE_L)
        FOOTPRINT(BruteBonnet)
        OVERWORLD(
            sPicTable_BruteBonnet,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_BruteBonnet,
            gShinyOverworldPalette_BruteBonnet
        )
        .isParadox = TRUE,
        .levelUpLearnset = sBruteBonnetLevelUpLearnset,
        .teachableLearnset = sBruteBonnetTeachableLearnset,
    },
#endif //P_FAMILY_BRUTE_BONNET

#if P_FAMILY_FLUTTER_MANE
    [SPECIES_FLUTTER_MANE] =
    {
        .baseHP        = 55,
        .baseAttack    = 55,
        .baseDefense   = 55,
        .baseSpeed     = 135,
        .baseSpAttack  = 135,
        .baseSpDefense = 135,
        .types = MON_TYPES(TYPE_GHOST, TYPE_FAIRY),
        .catchRate = 30,
        .expYield = 285,
        .evYield_Speed = 1,
        .evYield_SpAttack = 1,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PROTOSYNTHESIS, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Flotte-Mèche"),
        .cryId = CRY_FLUTTER_MANE,
        .natDexNum = NATIONAL_DEX_FLUTTER_MANE,
        .categoryName = _("Paradoxe"),
        .height = 14,
        .weight = 40,
        .description = COMPOUND_STRING(
            "Il présente de nombreuses similitudes avec le\n"
            "Viridium du futur évoqué dans une revue sur les\n"
            "phénomènes paranormaux."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_FlutterMane,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 18,
        .backPic = gMonBackPic_FlutterMane,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_FlutterMane,
        .shinyPalette = gMonShinyPalette_FlutterMane,
        .iconSprite = gMonIcon_FlutterMane,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 20, SHADOW_SIZE_S)
        FOOTPRINT(FlutterMane)
        OVERWORLD(
            sPicTable_FlutterMane,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_FlutterMane,
            gShinyOverworldPalette_FlutterMane
        )
        .isParadox = TRUE,
        .levelUpLearnset = sFlutterManeLevelUpLearnset,
        .teachableLearnset = sFlutterManeTeachableLearnset,
    },
#endif //P_FAMILY_FLUTTER_MANE

#if P_FAMILY_SLITHER_WING
    [SPECIES_SLITHER_WING] =
    {
        .baseHP        = 85,
        .baseAttack    = 135,
        .baseDefense   = 79,
        .baseSpeed     = 81,
        .baseSpAttack  = 85,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_BUG, TYPE_FIGHTING),
        .catchRate = 30,
        .expYield = 285,
        .evYield_Attack = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PROTOSYNTHESIS, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Rampe-Ailes"),
        .cryId = CRY_SLITHER_WING,
        .natDexNum = NATIONAL_DEX_SLITHER_WING,
        .categoryName = _("Paradoxe"),
        .height = 32,
        .weight = 920,
        .description = COMPOUND_STRING(
            "Il ressemble à une entité étrange décrite dans\n"
            "une revue sur les phénomènes paranormaux.\n"
            "D'après celle-ci, ce serait un ovni qui épie la race\n"
            "humaine."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_SlitherWing,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SlitherWing,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_SlitherWing,
        .shinyPalette = gMonShinyPalette_SlitherWing,
        .iconSprite = gMonIcon_SlitherWing,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 13, SHADOW_SIZE_M)
        FOOTPRINT(SlitherWing)
        OVERWORLD(
            sPicTable_SlitherWing,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_SlitherWing,
            gShinyOverworldPalette_SlitherWing
        )
        .isParadox = TRUE,
        .levelUpLearnset = sSlitherWingLevelUpLearnset,
        .teachableLearnset = sSlitherWingTeachableLearnset,
    },
#endif //P_FAMILY_SLITHER_WING

#if P_FAMILY_SANDY_SHOCKS
    [SPECIES_SANDY_SHOCKS] =
    {
        .baseHP        = 85,
        .baseAttack    = 81,
        .baseDefense   = 97,
        .baseSpeed     = 101,
        .baseSpAttack  = 121,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_GROUND),
        .catchRate = 30,
        .expYield = 285,
        .evYield_SpAttack = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PROTOSYNTHESIS, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Pelage-Sablé"),
        .cryId = CRY_SANDY_SHOCKS,
        .natDexNum = NATIONAL_DEX_SANDY_SHOCKS,
        .categoryName = _("Paradoxe"),
        .height = 23,
        .weight = 600,
        .description = COMPOUND_STRING(
            "Il pourrait s'agir de la créature nommée “\n"
            "Rugit-Lune ”, qui apparaît dans un récit\n"
            "d'exploration très mystérieux."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_SandyShocks,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SandyShocks,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_SandyShocks,
        .shinyPalette = gMonShinyPalette_SandyShocks,
        .iconSprite = gMonIcon_SandyShocks,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 13, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(SandyShocks)
        OVERWORLD(
            sPicTable_SandyShocks,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_SandyShocks,
            gShinyOverworldPalette_SandyShocks
        )
        .isParadox = TRUE,
        .levelUpLearnset = sSandyShocksLevelUpLearnset,
        .teachableLearnset = sSandyShocksTeachableLearnset,
    },
#endif //P_FAMILY_SANDY_SHOCKS

#if P_FAMILY_IRON_TREADS
    [SPECIES_IRON_TREADS] =
    {
        .baseHP        = 90,
        .baseAttack    = 112,
        .baseDefense   = 120,
        .baseSpeed     = 106,
        .baseSpAttack  = 72,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GROUND, TYPE_STEEL),
        .catchRate = 30,
        .expYield = 285,
        .evYield_Defense = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_QUARK_DRIVE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Roue-de-Fer"),
        .cryId = CRY_IRON_TREADS,
        .natDexNum = NATIONAL_DEX_IRON_TREADS,
        .categoryName = _("Paradoxe"),
        .height = 9,
        .weight = 2400,
        .description = COMPOUND_STRING(
            "Il ressemble à un Pokémon qui serait l'enfant d'un\n"
            "Trioxhydre amoureux d'un robot, selon une revue\n"
            "consacrée aux phénomènes paranormaux."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_IronTreads,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_IronTreads,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_IronTreads,
        .shinyPalette = gMonShinyPalette_IronTreads,
        .iconSprite = gMonIcon_IronTreads,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(IronTreads)
        OVERWORLD(
            sPicTable_IronTreads,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_IronTreads,
            gShinyOverworldPalette_IronTreads
        )
        .isParadox = TRUE,
        .levelUpLearnset = sIronTreadsLevelUpLearnset,
        .teachableLearnset = sIronTreadsTeachableLearnset,
    },
#endif //P_FAMILY_IRON_TREADS

#if P_FAMILY_IRON_BUNDLE
    [SPECIES_IRON_BUNDLE] =
    {
        .baseHP        = 56,
        .baseAttack    = 80,
        .baseDefense   = 114,
        .baseSpeed     = 136,
        .baseSpAttack  = 124,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ICE, TYPE_WATER),
        .catchRate = 50,
        .expYield = 285,
        .evYield_Speed = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_QUARK_DRIVE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Hotte-de-Fer"),
        .cryId = CRY_IRON_BUNDLE,
        .natDexNum = NATIONAL_DEX_IRON_BUNDLE,
        .categoryName = _("Paradoxe"),
        .height = 6,
        .weight = 110,
        .description = COMPOUND_STRING(
            "La rancœur d'un être humain puni pour avoir noté\n"
            "les méfaits d'un roi sur des tablettes en bois\n"
            "s'est mêlée à des feuilles mortes et a pris vie."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_IronBundle,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_IronBundle,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_IronBundle,
        .shinyPalette = gMonShinyPalette_IronBundle,
        .iconSprite = gMonIcon_IronBundle,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, 6, SHADOW_SIZE_M)
        FOOTPRINT(IronBundle)
        OVERWORLD(
            sPicTable_IronBundle,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_IronBundle,
            gShinyOverworldPalette_IronBundle
        )
        .isParadox = TRUE,
        .levelUpLearnset = sIronBundleLevelUpLearnset,
        .teachableLearnset = sIronBundleTeachableLearnset,
    },
#endif //P_FAMILY_IRON_BUNDLE

#if P_FAMILY_IRON_HANDS
    [SPECIES_IRON_HANDS] =
    {
        .baseHP        = 154,
        .baseAttack    = 140,
        .baseDefense   = 108,
        .baseSpeed     = 50,
        .baseSpAttack  = 50,
        .baseSpDefense = 68,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_ELECTRIC),
        .catchRate = 50,
        .expYield = 285,
        .evYield_Attack = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_QUARK_DRIVE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Paume-de-Fer"),
        .cryId = CRY_IRON_HANDS,
        .natDexNum = NATIONAL_DEX_IRON_HANDS,
        .categoryName = _("Paradoxe"),
        .height = 18,
        .weight = 3807,
        .description = COMPOUND_STRING(
            "Il ressemble un peu à l'invention d'un cerveau\n"
            "dément mentionnée dans une revue consacrée aux\n"
            "phénomènes paranormaux."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_IronHands,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_IronHands,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_IronHands,
        .shinyPalette = gMonShinyPalette_IronHands,
        .iconSprite = gMonIcon_IronHands,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 8, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(IronHands)
        OVERWORLD(
            sPicTable_IronHands,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_IronHands,
            gShinyOverworldPalette_IronHands
        )
        .isParadox = TRUE,
        .levelUpLearnset = sIronHandsLevelUpLearnset,
        .teachableLearnset = sIronHandsTeachableLearnset,
    },
#endif //P_FAMILY_IRON_HANDS

#if P_FAMILY_IRON_JUGULIS
    [SPECIES_IRON_JUGULIS] =
    {
        .baseHP        = 94,
        .baseAttack    = 80,
        .baseDefense   = 86,
        .baseSpeed     = 108,
        .baseSpAttack  = 122,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_DARK, TYPE_FLYING),
        .catchRate = 30,
        .expYield = 285,
        .evYield_SpAttack = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_QUARK_DRIVE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Têtes-de-Fer"),
        .cryId = CRY_IRON_JUGULIS,
        .natDexNum = NATIONAL_DEX_IRON_JUGULIS,
        .categoryName = _("Paradoxe"),
        .height = 13,
        .weight = 1110,
        .description = COMPOUND_STRING(
            "La peur déversée dans un réceptacle utilisé lors\n"
            "de rites anciens s'est mêlée à de la terre et à\n"
            "des pierres et a pris vie."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_IronJugulis,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_IronJugulis,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_IronJugulis,
        .shinyPalette = gMonShinyPalette_IronJugulis,
        .iconSprite = gMonIcon_IronJugulis,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 15, SHADOW_SIZE_M)
        FOOTPRINT(IronJugulis)
        OVERWORLD(
            sPicTable_IronJugulis,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_IronJugulis,
            gShinyOverworldPalette_IronJugulis
        )
        .isParadox = TRUE,
        .levelUpLearnset = sIronJugulisLevelUpLearnset,
        .teachableLearnset = sIronJugulisTeachableLearnset,
    },
#endif //P_FAMILY_IRON_JUGULIS

#if P_FAMILY_IRON_MOTH
    [SPECIES_IRON_MOTH] =
    {
        .baseHP        = 80,
        .baseAttack    = 70,
        .baseDefense   = 60,
        .baseSpeed     = 110,
        .baseSpAttack  = 140,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_FIRE, TYPE_POISON),
        .catchRate = 30,
        .expYield = 285,
        .evYield_SpAttack = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_QUARK_DRIVE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Mite-de-Fer"),
        .cryId = CRY_IRON_MOTH,
        .natDexNum = NATIONAL_DEX_IRON_MOTH,
        .categoryName = _("Paradoxe"),
        .height = 12,
        .weight = 360,
        .description = COMPOUND_STRING(
            "Sa forme est similaire à celle d'un robot créé par\n"
            "une civilisation antique, d'après un article d'une\n"
            "revue consacrée aux phénomènes paranormaux."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_IronMoth,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_IronMoth,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_IronMoth,
        .shinyPalette = gMonShinyPalette_IronMoth,
        .iconSprite = gMonIcon_IronMoth,
        .iconPalIndex = 3,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 14, SHADOW_SIZE_M)
        FOOTPRINT(IronMoth)
        OVERWORLD(
            sPicTable_IronMoth,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_IronMoth,
            gShinyOverworldPalette_IronMoth
        )
        .isParadox = TRUE,
        .levelUpLearnset = sIronMothLevelUpLearnset,
        .teachableLearnset = sIronMothTeachableLearnset,
    },
#endif //P_FAMILY_IRON_MOTH

#if P_FAMILY_IRON_THORNS
    [SPECIES_IRON_THORNS] =
    {
        .baseHP        = 100,
        .baseAttack    = 134,
        .baseDefense   = 110,
        .baseSpeed     = 72,
        .baseSpAttack  = 70,
        .baseSpDefense = 84,
        .types = MON_TYPES(TYPE_ROCK, TYPE_ELECTRIC),
        .catchRate = 30,
        .expYield = 285,
        .evYield_Attack = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_QUARK_DRIVE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Épine-de-Fer"),
        .cryId = CRY_IRON_THORNS,
        .natDexNum = NATIONAL_DEX_IRON_THORNS,
        .categoryName = _("Paradoxe"),
        .height = 16,
        .weight = 3030,
        .description = COMPOUND_STRING(
            "Ce Pokémon peut contrôler 100 tonnes de neige\n"
            "tombée. Il s'amuse en sautant joyeusement dans\n"
            "les avalanches qu'il provoque."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_IronThorns,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_IronThorns,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_IronThorns,
        .shinyPalette = gMonShinyPalette_IronThorns,
        .iconSprite = gMonIcon_IronThorns,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-9, 12, SHADOW_SIZE_L)
        FOOTPRINT(IronThorns)
        OVERWORLD(
            sPicTable_IronThorns,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_IronThorns,
            gShinyOverworldPalette_IronThorns
        )
        .isParadox = TRUE,
        .levelUpLearnset = sIronThornsLevelUpLearnset,
        .teachableLearnset = sIronThornsTeachableLearnset,
    },
#endif //P_FAMILY_IRON_THORNS

#if P_FAMILY_FRIGIBAX
    [SPECIES_FRIGIBAX] =
    {
        .baseHP        = 65,
        .baseAttack    = 75,
        .baseDefense   = 45,
        .baseSpeed     = 55,
        .baseSpAttack  = 35,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_ICE),
        .catchRate = 45,
        .expYield = 64,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_DRAGON, EGG_GROUP_MINERAL),
        .abilities = { ABILITY_THERMAL_EXCHANGE, ABILITY_NONE, ABILITY_ICE_BODY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Frigodo"),
        .cryId = CRY_FRIGIBAX,
        .natDexNum = NATIONAL_DEX_FRIGIBAX,
        .categoryName = _("Glaçaileron"),
        .height = 5,
        .weight = 170,
        .description = COMPOUND_STRING(
            "Des fresques vieilles de 10 000 ans laissent\n"
            "penser que ce Pokémon transporte des êtres\n"
            "humains sur son dos depuis les temps anciens."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Frigibax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Frigibax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Frigibax,
        .shinyPalette = gMonShinyPalette_Frigibax,
        .iconSprite = gMonIcon_Frigibax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(2, -1, SHADOW_SIZE_S)
        FOOTPRINT(Frigibax)
        OVERWORLD(
            sPicTable_Frigibax,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Frigibax,
            gShinyOverworldPalette_Frigibax
        )
        .levelUpLearnset = sFrigibaxLevelUpLearnset,
        .teachableLearnset = sFrigibaxTeachableLearnset,
        .eggMoveLearnset = sFrigibaxEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_ARCTIBAX}),
    },

    [SPECIES_ARCTIBAX] =
    {
        .baseHP        = 90,
        .baseAttack    = 95,
        .baseDefense   = 66,
        .baseSpeed     = 62,
        .baseSpAttack  = 45,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_ICE),
        .catchRate = 25,
        .expYield = 148,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_DRAGON, EGG_GROUP_MINERAL),
        .abilities = { ABILITY_THERMAL_EXCHANGE, ABILITY_NONE, ABILITY_ICE_BODY },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Cryodo"),
        .cryId = CRY_ARCTIBAX,
        .natDexNum = NATIONAL_DEX_ARCTIBAX,
        .categoryName = _("Glaçaileron"),
        .height = 8,
        .weight = 300,
        .description = COMPOUND_STRING(
            "Les poches sur ses joues sont peu développées.\n"
            "Elles ne produisent de l'électricité que lorsqu'il\n"
            "les frotte avec ses coussinets."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Arctibax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Arctibax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Arctibax,
        .shinyPalette = gMonShinyPalette_Arctibax,
        .iconSprite = gMonIcon_Arctibax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 8, SHADOW_SIZE_M)
        FOOTPRINT(Arctibax)
        OVERWORLD(
            sPicTable_Arctibax,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Arctibax,
            gShinyOverworldPalette_Arctibax
        )
        .levelUpLearnset = sArctibaxLevelUpLearnset,
        .teachableLearnset = sArctibaxTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 54, SPECIES_BAXCALIBUR}),
    },

    [SPECIES_BAXCALIBUR] =
    {
        .baseHP        = 115,
        .baseAttack    = 145,
        .baseDefense   = 92,
        .baseSpeed     = 87,
        .baseSpAttack  = 75,
        .baseSpDefense = 86,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_ICE),
        .catchRate = 10,
        .expYield = 300,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_DRAGON, EGG_GROUP_MINERAL),
        .abilities = { ABILITY_THERMAL_EXCHANGE, ABILITY_NONE, ABILITY_ICE_BODY },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Glaivodo"),
        .cryId = CRY_BAXCALIBUR,
        .natDexNum = NATIONAL_DEX_BAXCALIBUR,
        .categoryName = _("Dragon Glace"),
        .height = 21,
        .weight = 2100,
        .description = COMPOUND_STRING(
            "Quand on attaque son groupe, ce Pokémon est le\n"
            "premier à riposter. Il défait ses adversaires\n"
            "avec un art martial qui repose sur l'électricité."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Baxcalibur,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Baxcalibur,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Baxcalibur,
        .shinyPalette = gMonShinyPalette_Baxcalibur,
        .iconSprite = gMonIcon_Baxcalibur,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 12, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Baxcalibur)
        OVERWORLD(
            sPicTable_Baxcalibur,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Baxcalibur,
            gShinyOverworldPalette_Baxcalibur
        )
        .levelUpLearnset = sBaxcaliburLevelUpLearnset,
        .teachableLearnset = sBaxcaliburTeachableLearnset,
        .formSpeciesIdTable = sBaxcaliburFormSpeciesIdTable,
        .formChangeTable = sBaxcaliburFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_BAXCALIBUR_MEGA] =
    {
        .baseHP        = 115,
        .baseAttack    = 175,
        .baseDefense   = 117,
        .baseSpeed     = 87,
        .baseSpAttack  = 105,
        .baseSpDefense = 101,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_ICE),
        .catchRate = 10,
        .expYield = 300,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_DRAGON, EGG_GROUP_MINERAL),
        .abilities = { ABILITY_THERMAL_EXCHANGE, ABILITY_NONE, ABILITY_ICE_BODY },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Glaivodo"),
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_BAXCALIBUR_MEGA,
    #else
        .cryId = CRY_BAXCALIBUR,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_BAXCALIBUR,
        .categoryName = _("Dragon Glace"),
        .height = 21,
        .weight = 3150,
        .description = COMPOUND_STRING(
            "Quand on attaque son groupe, ce Pokémon est le\n"
            "premier à riposter. Il défait ses adversaires\n"
            "avec un art martial qui repose sur l'électricité."
        ),
        .frontPic = gMonFrontPic_BaxcaliburMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_BaxcaliburMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_BaxcaliburMega,
        .shinyPalette = gMonShinyPalette_BaxcaliburMega,
        .iconSprite = gMonIcon_BaxcaliburMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Baxcalibur)
        SHADOW(4, 14, SHADOW_SIZE_L)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sBaxcaliburLevelUpLearnset,
        .teachableLearnset = sBaxcaliburTeachableLearnset,
        .formSpeciesIdTable = sBaxcaliburFormSpeciesIdTable,
        .formChangeTable = sBaxcaliburFormChangeTable,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_FRIGIBAX

#if P_FAMILY_GIMMIGHOUL
    [SPECIES_GIMMIGHOUL_CHEST] =
    {
        .baseHP        = 45,
        .baseAttack    = 30,
        .baseDefense   = 70,
        .baseSpeed     = 10,
        .baseSpAttack  = 75,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 45,
        .expYield = 60,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_RATTLED, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Mordudor"),
        .cryId = CRY_GIMMIGHOUL_CHEST,
        .natDexNum = NATIONAL_DEX_GIMMIGHOUL,
        .categoryName = _("Coffrotrésor"),
        .height = 3,
        .weight = 50,
        .description = COMPOUND_STRING(
            "Cette créature violente entourée de mystère tire\n"
            "son nom d'un monstre aquatique évoqué dans un\n"
            "vieux récit d'exploration."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_GimmighoulChest,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_GimmighoulChest,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_GimmighoulChest,
        .shinyPalette = gMonShinyPalette_GimmighoulChest,
        .iconSprite = gMonIcon_GimmighoulChest,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, 7, SHADOW_SIZE_M)
        FOOTPRINT(GimmighoulChest)
        OVERWORLD(
            sPicTable_GimmighoulChest,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_GimmighoulChest,
            gShinyOverworldPalette_GimmighoulChest
        )
        .levelUpLearnset = sGimmighoulLevelUpLearnset,
        .teachableLearnset = sGimmighoulTeachableLearnset,
        .formSpeciesIdTable = sGimmighoulFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_GHOLDENGO, CONDITIONS({IF_BAG_ITEM_COUNT, ITEM_GIMMIGHOUL_COIN, 999})}),
    },

    [SPECIES_GIMMIGHOUL_ROAMING] =
    {
        .baseHP        = 45,
        .baseAttack    = 30,
        .baseDefense   = 25,
        .baseSpeed     = 80,
        .baseSpAttack  = 75,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 45,
        .expYield = 60,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_RUN_AWAY, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Mordudor"),
        .cryId = CRY_GIMMIGHOUL_ROAMING,
        .natDexNum = NATIONAL_DEX_GIMMIGHOUL,
        .categoryName = _("Chassotrésor"),
        .height = 1,
        .weight = 1,
        .description = COMPOUND_STRING(
            "Cette créature violente entourée de mystère tire\n"
            "son nom d'un monstre aquatique évoqué dans un\n"
            "vieux récit d'exploration."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_GimmighoulRoaming,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_GimmighoulRoaming,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_GimmighoulRoaming,
        .shinyPalette = gMonShinyPalette_GimmighoulRoaming,
        .iconSprite = gMonIcon_GimmighoulRoaming,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-1, -4, SHADOW_SIZE_S)
        FOOTPRINT(GimmighoulRoaming)
        .levelUpLearnset = sGimmighoulLevelUpLearnset,
        .teachableLearnset = sGimmighoulTeachableLearnset,
        .formSpeciesIdTable = sGimmighoulFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_GHOLDENGO, CONDITIONS({IF_BAG_ITEM_COUNT, ITEM_GIMMIGHOUL_COIN, 999})}),
    },

    [SPECIES_GHOLDENGO] =
    {
        .baseHP        = 87,
        .baseAttack    = 60,
        .baseDefense   = 95,
        .baseSpeed     = 84,
        .baseSpAttack  = 133,
        .baseSpDefense = 91,
        .types = MON_TYPES(TYPE_STEEL, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 275,
        .evYield_SpAttack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_GOOD_AS_GOLD, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Gromago"),
        .cryId = CRY_GHOLDENGO,
        .natDexNum = NATIONAL_DEX_GHOLDENGO,
        .categoryName = _("Trésor Animé"),
        .height = 12,
        .weight = 300,
        .description = COMPOUND_STRING(
            "Ses attributs correspondent à ceux d'une\n"
            "créature évoquée dans un récit d'exploration. On\n"
            "manque de données sur lui, car nul n'en a jamais\n"
            "attrapé."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gholdengo,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gholdengo,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Gholdengo,
        .shinyPalette = gMonShinyPalette_Gholdengo,
        .iconSprite = gMonIcon_Gholdengo,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 13, SHADOW_SIZE_M)
        FOOTPRINT(Gholdengo)
        OVERWORLD(
            sPicTable_Gholdengo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Gholdengo,
            gShinyOverworldPalette_Gholdengo
        )
        .levelUpLearnset = sGholdengoLevelUpLearnset,
        .teachableLearnset = sGholdengoTeachableLearnset,
    },
#endif //P_FAMILY_GIMMIGHOUL

#if P_FAMILY_WO_CHIEN
    [SPECIES_WO_CHIEN] =
    {
        .baseHP        = 85,
        .baseAttack    = 85,
        .baseDefense   = 100,
        .baseSpeed     = 70,
        .baseSpAttack  = 95,
        .baseSpDefense = 135,
        .types = MON_TYPES(TYPE_DARK, TYPE_GRASS),
        .catchRate = 6,
        .expYield = 285,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_TABLETS_OF_RUIN, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Chongjian"),
        .cryId = CRY_WO_CHIEN,
        .natDexNum = NATIONAL_DEX_WO_CHIEN,
        .categoryName = _("Fléau"),
        .height = 15,
        .weight = 742,
        .description = COMPOUND_STRING(
            "Il arrive que ce Pokémon se rende dans les\n"
            "villages pour fouiller les ateliers et les réserves\n"
            "à la recherche de métaux."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_WoChien,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_WoChien,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_WoChien,
        .shinyPalette = gMonShinyPalette_WoChien,
        .iconSprite = gMonIcon_WoChien,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(WoChien)
        OVERWORLD(
            sPicTable_WoChien,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_WoChien,
            gShinyOverworldPalette_WoChien
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sWoChienLevelUpLearnset,
        .teachableLearnset = sWoChienTeachableLearnset,
    },
#endif //P_FAMILY_WO_CHIEN

#if P_FAMILY_CHIEN_PAO
    [SPECIES_CHIEN_PAO] =
    {
        .baseHP        = 80,
        .baseAttack    = 120,
        .baseDefense   = 80,
        .baseSpeed     = 135,
        .baseSpAttack  = 90,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_DARK, TYPE_ICE),
        .catchRate = 6,
        .expYield = 285,
        .evYield_Speed = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_SWORD_OF_RUIN, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Baojian"),
        .cryId = CRY_CHIEN_PAO,
        .natDexNum = NATIONAL_DEX_CHIEN_PAO,
        .categoryName = _("Fléau"),
        .height = 19,
        .weight = 1522,
        .description = COMPOUND_STRING(
            "On manque d'informations à son sujet. Il\n"
            "ressemble à Motorizard, mais en bien plus fort et\n"
            "cruel."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_ChienPao,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ChienPao,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ChienPao,
        .shinyPalette = gMonShinyPalette_ChienPao,
        .iconSprite = gMonIcon_ChienPao,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 8, SHADOW_SIZE_L)
        FOOTPRINT(ChienPao)
        OVERWORLD(
            sPicTable_ChienPao,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ChienPao,
            gShinyOverworldPalette_ChienPao
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sChienPaoLevelUpLearnset,
        .teachableLearnset = sChienPaoTeachableLearnset,
    },
#endif //P_FAMILY_CHIEN_PAO

#if P_FAMILY_TING_LU
    [SPECIES_TING_LU] =
    {
        .baseHP        = 155,
        .baseAttack    = 110,
        .baseDefense   = 125,
        .baseSpeed     = 45,
        .baseSpAttack  = 55,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_DARK, TYPE_GROUND),
        .catchRate = 6,
        .expYield = 285,
        .evYield_Defense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_VESSEL_OF_RUIN, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Dinglu"),
        .cryId = CRY_TING_LU,
        .natDexNum = NATIONAL_DEX_TING_LU,
        .categoryName = _("Fléau"),
        .height = 27,
        .weight = 6997,
        .description = COMPOUND_STRING(
            "Il s'agirait d'“ Ailes-Royales ”, une créature qui,\n"
            "d'après un vieux récit d'exploration, aurait fendu\n"
            "la terre par la force de ses poings."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_TingLu,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_TingLu,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_TingLu,
        .shinyPalette = gMonShinyPalette_TingLu,
        .iconSprite = gMonIcon_TingLu,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(12, 13, SHADOW_SIZE_L)
        FOOTPRINT(TingLu)
        OVERWORLD(
            sPicTable_TingLu,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_TingLu,
            gShinyOverworldPalette_TingLu
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sTingLuLevelUpLearnset,
        .teachableLearnset = sTingLuTeachableLearnset,
    },
#endif //P_FAMILY_TING_LU

#if P_FAMILY_CHI_YU
    [SPECIES_CHI_YU] =
    {
        .baseHP        = 55,
        .baseAttack    = 80,
        .baseDefense   = 80,
        .baseSpeed     = 100,
        .baseSpAttack  = 135,
        .baseSpDefense = 120,
        .types = MON_TYPES(TYPE_DARK, TYPE_FIRE),
        .catchRate = 6,
        .expYield = 285,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_BEADS_OF_RUIN, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Yuyu"),
        .cryId = CRY_CHI_YU,
        .natDexNum = NATIONAL_DEX_CHI_YU,
        .categoryName = _("Fléau"),
        .height = 4,
        .weight = 49,
        .description = COMPOUND_STRING(
            "Ces Pokémon dirigent souvent des groupes de\n"
            "Forgerette et leur enseignent comment frapper le\n"
            "métal pour bien le façonner."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_ChiYu,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 15,
        .backPic = gMonBackPic_ChiYu,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ChiYu,
        .shinyPalette = gMonShinyPalette_ChiYu,
        .iconSprite = gMonIcon_ChiYu,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 16, SHADOW_SIZE_S)
        FOOTPRINT(ChiYu)
        OVERWORLD(
            sPicTable_ChiYu,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_ChiYu,
            gShinyOverworldPalette_ChiYu
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sChiYuLevelUpLearnset,
        .teachableLearnset = sChiYuTeachableLearnset,
    },
#endif //P_FAMILY_CHI_YU

#if P_FAMILY_ROARING_MOON
    [SPECIES_ROARING_MOON] =
    {
        .baseHP        = 105,
        .baseAttack    = 139,
        .baseDefense   = 71,
        .baseSpeed     = 119,
        .baseSpAttack  = 55,
        .baseSpDefense = 101,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_DARK),
        .catchRate = 10,
        .expYield = 295,
        .evYield_Attack = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PROTOSYNTHESIS, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Rugit-Lune"),
        .cryId = CRY_ROARING_MOON,
        .natDexNum = NATIONAL_DEX_ROARING_MOON,
        .categoryName = _("Paradoxe"),
        .height = 20,
        .weight = 3800,
        .description = COMPOUND_STRING(
            "Il ressemble à l'athlète transformé en cyborg\n"
            "dont l'histoire avait été révélée en exclusivité\n"
            "dans une revue sur les phénomènes paranormaux."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_RoaringMoon,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 0,
        .backPic = gMonBackPic_RoaringMoon,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_RoaringMoon,
        .shinyPalette = gMonShinyPalette_RoaringMoon,
        .iconSprite = gMonIcon_RoaringMoon,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 9, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(RoaringMoon)
        OVERWORLD(
            sPicTable_RoaringMoon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_RoaringMoon,
            gShinyOverworldPalette_RoaringMoon
        )
        .isParadox = TRUE,
        .levelUpLearnset = sRoaringMoonLevelUpLearnset,
        .teachableLearnset = sRoaringMoonTeachableLearnset,
    },
#endif //P_FAMILY_ROARING_MOON

#if P_FAMILY_IRON_VALIANT
    [SPECIES_IRON_VALIANT] =
    {
        .baseHP        = 74,
        .baseAttack    = 130,
        .baseDefense   = 90,
        .baseSpeed     = 116,
        .baseSpAttack  = 120,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_FAIRY, TYPE_FIGHTING),
        .catchRate = 10,
        .expYield = 295,
        .evYield_Attack = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_QUARK_DRIVE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Garde-de-Fer"),
        .cryId = CRY_IRON_VALIANT,
        .natDexNum = NATIONAL_DEX_IRON_VALIANT,
        .categoryName = _("Paradoxe"),
        .height = 14,
        .weight = 350,
        .description = COMPOUND_STRING(
            "Ce Pokémon manipule des flammes à 3 000 ºC. Il\n"
            "nage tranquillement dans une mer de magma qu'il a\n"
            "créée en faisant fondre de la roche et du\n"
            "gravier."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_IronValiant,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_IronValiant,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_IronValiant,
        .shinyPalette = gMonShinyPalette_IronValiant,
        .iconSprite = gMonIcon_IronValiant,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 14, SHADOW_SIZE_L)
        FOOTPRINT(IronValiant)
        OVERWORLD(
            sPicTable_IronValiant,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_IronValiant,
            gShinyOverworldPalette_IronValiant
        )
        .isParadox = TRUE,
        .levelUpLearnset = sIronValiantLevelUpLearnset,
        .teachableLearnset = sIronValiantTeachableLearnset,
    },
#endif //P_FAMILY_IRON_VALIANT

#if P_FAMILY_KORAIDON
    [SPECIES_KORAIDON] =
    {
        .baseHP        = 100,
        .baseAttack    = 135,
        .baseDefense   = 115,
        .baseSpeed     = 135,
        .baseSpAttack  = 85,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_DRAGON),
        .catchRate = 3,
        .expYield = 335,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_ORICHALCUM_PULSE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Koraidon"),
        .cryId = CRY_KORAIDON,
        .natDexNum = NATIONAL_DEX_KORAIDON,
        .categoryName = _("Paradoxe"),
        .height = 25,
        .weight = 3030,
        .description = COMPOUND_STRING(
            "Depuis très longtemps, les êtres humains\n"
            "apprécient ce Pokémon pour sa faculté à\n"
            "manipuler le feu."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Koraidon,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Koraidon,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Koraidon,
        .shinyPalette = gMonShinyPalette_Koraidon,
        .iconSprite = gMonIcon_Koraidon,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 13, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Koraidon)
        OVERWORLD(
            sPicTable_Koraidon,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Koraidon,
            gShinyOverworldPalette_Koraidon
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sKoraidonLevelUpLearnset,
        .teachableLearnset = sKoraidonTeachableLearnset,
    },
#endif //P_FAMILY_KORAIDON

#if P_FAMILY_MIRAIDON
    [SPECIES_MIRAIDON] =
    {
        .baseHP        = 100,
        .baseAttack    = 85,
        .baseDefense   = 100,
        .baseSpeed     = 135,
        .baseSpAttack  = 135,
        .baseSpDefense = 115,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_DRAGON),
        .catchRate = 3,
        .expYield = 335,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_HADRON_ENGINE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Miraidon"),
        .cryId = CRY_MIRAIDON,
        .natDexNum = NATIONAL_DEX_MIRAIDON,
        .categoryName = _("Paradoxe"),
        .height = 35,
        .weight = 2400,
        .description = COMPOUND_STRING(
            "Bien qu'il ait juré fidélité à son Dresseur ou à sa\n"
            "Dresseuse, il s'entraîne seul et sans relâche\n"
            "pour apprendre à maîtriser son énergie Psy."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Miraidon,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_Miraidon,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Miraidon,
        .shinyPalette = gMonShinyPalette_Miraidon,
        .iconSprite = gMonIcon_Miraidon,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 20, SHADOW_SIZE_L)
        FOOTPRINT(Miraidon)
        OVERWORLD(
            sPicTable_Miraidon,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Miraidon,
            gShinyOverworldPalette_Miraidon
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sMiraidonLevelUpLearnset,
        .teachableLearnset = sMiraidonTeachableLearnset,
    },
#endif //P_FAMILY_MIRAIDON

#if P_FAMILY_WALKING_WAKE
    [SPECIES_WALKING_WAKE] =
    {
        .baseHP        = 99,
        .baseAttack    = 83,
        .baseDefense   = 91,
        .baseSpeed     = 109,
        .baseSpAttack  = 125,
        .baseSpDefense = 83,
        .types = MON_TYPES(TYPE_WATER, TYPE_DRAGON),
        .catchRate = 5,
        .expYield = 295,
        .evYield_SpAttack = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PROTOSYNTHESIS, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Serpente-Eau"),
        .cryId = CRY_WALKING_WAKE,
        .natDexNum = NATIONAL_DEX_WALKING_WAKE,
        .categoryName = _("Paradoxe"),
        .height = 35,
        .weight = 2800,
        .description = COMPOUND_STRING(
            "Ce Pokémon mystérieux présente des similitudes\n"
            "avec Rampe-Ailes, une créature évoquée dans un\n"
            "livre ancien."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_WalkingWake,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_WalkingWake,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_WalkingWake,
        .shinyPalette = gMonShinyPalette_WalkingWake,
        .iconSprite = gMonIcon_WalkingWake,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 13, SHADOW_SIZE_L)
        FOOTPRINT(WalkingWake)
        OVERWORLD(
            sPicTable_WalkingWake,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_WalkingWake,
            gShinyOverworldPalette_WalkingWake
        )
        .isParadox = TRUE,
        .levelUpLearnset = sWalkingWakeLevelUpLearnset,
        .teachableLearnset = sWalkingWakeTeachableLearnset,
    },
#endif //P_FAMILY_WALKING_WAKE

#if P_FAMILY_IRON_LEAVES
    [SPECIES_IRON_LEAVES] =
    {
        .baseHP        = 90,
        .baseAttack    = 130,
        .baseDefense   = 88,
        .baseSpeed     = 104,
        .baseSpAttack  = 70,
        .baseSpDefense = 108,
        .types = MON_TYPES(TYPE_GRASS, TYPE_PSYCHIC),
        .catchRate = 5,
        .expYield = 295,
        .evYield_Attack = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_QUARK_DRIVE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Vert-de-Fer"),
        .cryId = CRY_IRON_LEAVES,
        .natDexNum = NATIONAL_DEX_IRON_LEAVES,
        .categoryName = _("Paradoxe"),
        .height = 15,
        .weight = 1250,
        .description = COMPOUND_STRING(
            "Son apparence partage des similarités avec celle\n"
            "qu'auront les Tyranocif dans un milliard d'années,\n"
            "selon une revue douteuse."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_IronLeaves,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_IronLeaves,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_IronLeaves,
        .shinyPalette = gMonShinyPalette_IronLeaves,
        .iconSprite = gMonIcon_IronLeaves,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 11, SHADOW_SIZE_M)
        FOOTPRINT(IronLeaves)
        OVERWORLD(
            sPicTable_IronLeaves,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_IronLeaves,
            gShinyOverworldPalette_IronLeaves
        )
        .isParadox = TRUE,
        .levelUpLearnset = sIronLeavesLevelUpLearnset,
        .teachableLearnset = sIronLeavesTeachableLearnset,
    },
#endif //P_FAMILY_IRON_LEAVES

#if P_FAMILY_POLTCHAGEIST
    [SPECIES_POLTCHAGEIST_COUNTERFEIT] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 45,
        .baseSpeed     = 50,
        .baseSpAttack  = 74,
        .baseSpDefense = 54,
        .types = MON_TYPES(TYPE_GRASS, TYPE_GHOST),
        .catchRate = 120,
        .expYield = 62,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_HOSPITALITY, ABILITY_NONE, ABILITY_HEATPROOF },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Poltchageist"),
        .cryId = CRY_POLTCHAGEIST,
        .natDexNum = NATIONAL_DEX_POLTCHAGEIST,
        .categoryName = _("Matcha"),
        .height = 1,
        .weight = 11,
        .description = COMPOUND_STRING(
            "Ce Pokémon serait l'incarnation, sous la forme\n"
            "d'un pot de matcha, des regrets d'une personne\n"
            "décédée avant d'avoir maîtrisé l'art du thé."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Poltchageist,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 10,
        .backPic = gMonBackPic_Poltchageist,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Poltchageist,
        .shinyPalette = gMonShinyPalette_Poltchageist,
        .iconSprite = gMonIcon_Poltchageist,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 12, SHADOW_SIZE_S)
        FOOTPRINT(Poltchageist)
        OVERWORLD(
            sPicTable_Poltchageist,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Poltchageist,
            gShinyOverworldPalette_Poltchageist
        )
        .levelUpLearnset = sPoltchageistLevelUpLearnset,
        .teachableLearnset = sPoltchageistTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_UNREMARKABLE_TEACUP, SPECIES_SINISTCHA_UNREMARKABLE}),
        .formSpeciesIdTable = sPoltchageistFormSpeciesIdTable,
    },

    [SPECIES_POLTCHAGEIST_ARTISAN] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 45,
        .baseSpeed     = 50,
        .baseSpAttack  = 74,
        .baseSpDefense = 54,
        .types = MON_TYPES(TYPE_GRASS, TYPE_GHOST),
        .catchRate = 120,
        .expYield = 62,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_HOSPITALITY, ABILITY_NONE, ABILITY_HEATPROOF },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Poltchageist"),
        .cryId = CRY_POLTCHAGEIST,
        .natDexNum = NATIONAL_DEX_POLTCHAGEIST,
        .categoryName = _("Matcha"),
        .height = 1,
        .weight = 11,
        .description = COMPOUND_STRING(
            "Ce Pokémon serait l'incarnation, sous la forme\n"
            "d'un pot de matcha, des regrets d'une personne\n"
            "décédée avant d'avoir maîtrisé l'art du thé."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Poltchageist,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 10,
        .backPic = gMonBackPic_Poltchageist,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Poltchageist,
        .shinyPalette = gMonShinyPalette_Poltchageist,
        .iconSprite = gMonIcon_Poltchageist,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 12, SHADOW_SIZE_S)
        FOOTPRINT(Poltchageist)
        OVERWORLD(
            sPicTable_Poltchageist,
            SIZE_32x32,
            SHADOW_SIZE_S,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Poltchageist,
            gShinyOverworldPalette_Poltchageist
        )
        .levelUpLearnset = sPoltchageistLevelUpLearnset,
        .teachableLearnset = sPoltchageistTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_MASTERPIECE_TEACUP, SPECIES_SINISTCHA_MASTERPIECE}),
        .formSpeciesIdTable = sPoltchageistFormSpeciesIdTable,
    },

    [SPECIES_SINISTCHA_UNREMARKABLE] =
    {
        .baseHP        = 71,
        .baseAttack    = 60,
        .baseDefense   = 106,
        .baseSpeed     = 70,
        .baseSpAttack  = 121,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_GRASS, TYPE_GHOST),
        .catchRate = 60,
        .expYield = 178,
        .evYield_SpAttack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_HOSPITALITY, ABILITY_NONE, ABILITY_HEATPROOF },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Théffroyable"),
        .cryId = CRY_SINISTCHA,
        .natDexNum = NATIONAL_DEX_SINISTCHA,
        .categoryName = _("Matcha"),
        .height = 2,
        .weight = 22,
        .description = COMPOUND_STRING(
            "Il se fait passer pour un bol de thé afin\n"
            "d'aspirer la force vitale de quiconque ferait\n"
            "l'erreur de le boire, mais en général, personne\n"
            "n'est dupe."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sinistcha,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 10,
        .backPic = gMonBackPic_Sinistcha,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Sinistcha,
        .shinyPalette = gMonShinyPalette_Sinistcha,
        .iconSprite = gMonIcon_Sinistcha,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 16, SHADOW_SIZE_M)
        FOOTPRINT(Sinistcha)
        OVERWORLD(
            sPicTable_Sinistcha,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Sinistcha,
            gShinyOverworldPalette_Sinistcha
        )
        .levelUpLearnset = sSinistchaLevelUpLearnset,
        .teachableLearnset = sSinistchaTeachableLearnset,
        .formSpeciesIdTable = sSinistchaFormSpeciesIdTable,
    },

    [SPECIES_SINISTCHA_MASTERPIECE] =
    {
        .baseHP        = 71,
        .baseAttack    = 60,
        .baseDefense   = 106,
        .baseSpeed     = 70,
        .baseSpAttack  = 121,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_GRASS, TYPE_GHOST),
        .catchRate = 60,
        .expYield = 178,
        .evYield_SpAttack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_HOSPITALITY, ABILITY_NONE, ABILITY_HEATPROOF },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Théffroyable"),
        .cryId = CRY_SINISTCHA,
        .natDexNum = NATIONAL_DEX_SINISTCHA,
        .categoryName = _("Matcha"),
        .height = 2,
        .weight = 22,
        .description = COMPOUND_STRING(
            "Il se fait passer pour un bol de thé afin\n"
            "d'aspirer la force vitale de quiconque ferait\n"
            "l'erreur de le boire, mais en général, personne\n"
            "n'est dupe."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sinistcha,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 10,
        .backPic = gMonBackPic_Sinistcha,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Sinistcha,
        .shinyPalette = gMonShinyPalette_Sinistcha,
        .iconSprite = gMonIcon_Sinistcha,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 16, SHADOW_SIZE_M)
        FOOTPRINT(Sinistcha)
        OVERWORLD(
            sPicTable_Sinistcha,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Sinistcha,
            gShinyOverworldPalette_Sinistcha
        )
        .levelUpLearnset = sSinistchaLevelUpLearnset,
        .teachableLearnset = sSinistchaTeachableLearnset,
        .formSpeciesIdTable = sSinistchaFormSpeciesIdTable,
    },
#endif //P_FAMILY_POLTCHAGEIST

#if P_FAMILY_OKIDOGI
    [SPECIES_OKIDOGI] =
    {
        .baseHP        = 88,
        .baseAttack    = 128,
        .baseDefense   = 115,
        .baseSpeed     = 80,
        .baseSpAttack  = 58,
        .baseSpDefense = 86,
        .types = MON_TYPES(TYPE_POISON, TYPE_FIGHTING),
        .catchRate = 3,
        .expYield = 278,
        .evYield_Attack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_TOXIC_CHAIN, ABILITY_NONE, ABILITY_GUARD_DOG },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Félicanis"),
        .cryId = CRY_OKIDOGI,
        .natDexNum = NATIONAL_DEX_OKIDOGI,
        .categoryName = _("Serviteur"),
        .height = 18,
        .weight = 920,
        .description = COMPOUND_STRING(
            "On raconte que la foudre qui s'échappe de sa\n"
            "fourrure peut brûler tout ce qui l'entoure, mais\n"
            "on en sait peu sur lui."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Okidogi,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Okidogi,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Okidogi,
        .shinyPalette = gMonShinyPalette_Okidogi,
        .iconSprite = gMonIcon_Okidogi,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 11, SHADOW_SIZE_L)
        FOOTPRINT(Okidogi)
        OVERWORLD(
            sPicTable_Okidogi,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Okidogi,
            gShinyOverworldPalette_Okidogi
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sOkidogiLevelUpLearnset,
        .teachableLearnset = sOkidogiTeachableLearnset,
    },
#endif //P_FAMILY_OKIDOGI

#if P_FAMILY_MUNKIDORI
    [SPECIES_MUNKIDORI] =
    {
        .baseHP        = 88,
        .baseAttack    = 75,
        .baseDefense   = 66,
        .baseSpeed     = 106,
        .baseSpAttack  = 130,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_POISON, TYPE_PSYCHIC),
        .catchRate = 3,
        .expYield = 278,
        .evYield_SpAttack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_TOXIC_CHAIN, ABILITY_NONE, ABILITY_FRISK },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Fortusimia"),
        .cryId = CRY_MUNKIDORI,
        .natDexNum = NATIONAL_DEX_MUNKIDORI,
        .categoryName = _("Serviteur"),
        .height = 10,
        .weight = 122,
        .description = COMPOUND_STRING(
            "Ses muscles se sont tant développés qu'il est\n"
            "désormais capable de voler pendant deux semaines\n"
            "sans se reposer."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Munkidori,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Munkidori,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Munkidori,
        .shinyPalette = gMonShinyPalette_Munkidori,
        .iconSprite = gMonIcon_Munkidori,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 8, SHADOW_SIZE_S)
        FOOTPRINT(Munkidori)
        OVERWORLD(
            sPicTable_Munkidori,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Munkidori,
            gShinyOverworldPalette_Munkidori
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sMunkidoriLevelUpLearnset,
        .teachableLearnset = sMunkidoriTeachableLearnset,
    },
#endif //P_FAMILY_MUNKIDORI

#if P_FAMILY_FEZANDIPITI
    [SPECIES_FEZANDIPITI] =
    {
        .baseHP        = 88,
        .baseAttack    = 91,
        .baseDefense   = 82,
        .baseSpeed     = 99,
        .baseSpAttack  = 70,
        .baseSpDefense = 125,
        .types = MON_TYPES(TYPE_POISON, TYPE_FAIRY),
        .catchRate = 3,
        .expYield = 278,
        .evYield_SpDefense = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_TOXIC_CHAIN, ABILITY_NONE, ABILITY_TECHNICIAN },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Favianos"),
        .cryId = CRY_FEZANDIPITI,
        .natDexNum = NATIONAL_DEX_FEZANDIPITI,
        .categoryName = _("Serviteur"),
        .height = 14,
        .weight = 301,
        .description = COMPOUND_STRING(
            "Il ressemble à un Terrakium qui, selon une revue\n"
            "douteuse, aurait été modifié par une organisation\n"
            "maléfique."
        ),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Fezandipiti,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Fezandipiti,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Fezandipiti,
        .shinyPalette = gMonShinyPalette_Fezandipiti,
        .iconSprite = gMonIcon_Fezandipiti,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 10, SHADOW_SIZE_M)
        FOOTPRINT(Fezandipiti)
        OVERWORLD(
            sPicTable_Fezandipiti,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Fezandipiti,
            gShinyOverworldPalette_Fezandipiti
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sFezandipitiLevelUpLearnset,
        .teachableLearnset = sFezandipitiTeachableLearnset,
    },
#endif //P_FAMILY_FEZANDIPITI

#if P_FAMILY_OGERPON
#define OGERPON_SPECIES_INFO(Form1, Form2, type, ability, color, frontYOffset, iconpalette, isTeraform)    \
    {                                                                                                      \
        .baseHP        = 80,                                                                               \
        .baseAttack    = 120,                                                                              \
        .baseDefense   = 84,                                                                               \
        .baseSpeed     = 110,                                                                              \
        .baseSpAttack  = 60,                                                                               \
        .baseSpDefense = 96,                                                                               \
        .types = MON_TYPES(TYPE_GRASS, type),                                                              \
        .forceTeraType = type,                                                                             \
        .catchRate = 5,                                                                                    \
        .expYield = 275,                                                                                   \
        .evYield_Attack = 3,                                                                               \
        .genderRatio = MON_FEMALE,                                                                         \
        .eggCycles = 10,                                                                                   \
        .friendship = STANDARD_FRIENDSHIP,                                                                 \
        .growthRate = GROWTH_SLOW,                                                                         \
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),                                         \
        .abilities = { ability, ABILITY_NONE },                                                            \
        .bodyColor = color,                                                                                \
        .speciesName = _("Ogerpon"),                                                                       \
        .cryId = CRY_OGERPON,                                                                              \
        .natDexNum = NATIONAL_DEX_OGERPON,                                                                 \
        .categoryName = _("Masque"),                                                                         \
        .height = 12,                                                                                      \
        .weight = 398,                                                                                     \
        .description = gOgerpon##Form1##MaskPokedexText,                                                   \
        .pokemonScale = 356,                                                                               \
        .pokemonOffset = 17,                                                                               \
        .trainerScale = 256,                                                                               \
        .trainerOffset = 0,                                                                                \
        .frontPic = gMonFrontPic_Ogerpon##Form2,                                                           \
        .frontPicSize = MON_COORDS_SIZE(64, 64),                                                           \
        .frontPicYOffset = frontYOffset,                                                                   \
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,                                                  \
        /*.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,*/                                                       \
        .backPic = gMonBackPic_Ogerpon##Form2,                                                             \
        .backPicSize = MON_COORDS_SIZE(64, 64),                                                            \
        .backPicYOffset = 0,                                                                               \
        /*.backAnimId = BACK_ANIM_NONE,*/                                                                  \
        .palette = gMonPalette_Ogerpon##Form2,                                                             \
        .shinyPalette = gMonShinyPalette_Ogerpon##Form2,                                                   \
        .iconSprite = gMonIcon_Ogerpon##Form1,                                                             \
        .iconPalIndex = iconpalette,                                                                       \
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,                                                            \
        SHADOW(3, 12, SHADOW_SIZE_M)                                                                       \
        FOOTPRINT(Ogerpon)                                                                                 \
        OVERWORLD(                                                                                         \
            sPicTable_Ogerpon##Form2,                                                                      \
            SIZE_32x32,                                                                                    \
            SHADOW_SIZE_M,                                                                                 \
            TRACKS_FOOT,                                                                                   \
            sAnimTable_Following,                                                                          \
            gOverworldPalette_Ogerpon##Form2,                                                              \
            gShinyOverworldPalette_Ogerpon##Form2                                                          \
        )                                                                                                  \
        .levelUpLearnset = sOgerponLevelUpLearnset,                                                        \
        .teachableLearnset = sOgerponTeachableLearnset,                                                    \
        .formSpeciesIdTable = sOgerponFormSpeciesIdTable,                                                  \
        .formChangeTable = sOgerpon##Form1##FormChangeTable,                                               \
        .isSubLegendary = TRUE,                                                                            \
        .isTeraForm = isTeraform,                                                                          \
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,                                                      \
    }

    [SPECIES_OGERPON_TEAL]             = OGERPON_SPECIES_INFO(Teal,        Teal,            TYPE_GRASS, ABILITY_DEFIANT,                        BODY_COLOR_GREEN, 2, 1, FALSE),
    [SPECIES_OGERPON_WELLSPRING]       = OGERPON_SPECIES_INFO(Wellspring,  Wellspring,      TYPE_WATER, ABILITY_WATER_ABSORB,                   BODY_COLOR_BLUE,  2, 0, FALSE),
    [SPECIES_OGERPON_HEARTHFLAME]      = OGERPON_SPECIES_INFO(Hearthflame, Hearthflame,     TYPE_FIRE,  ABILITY_MOLD_BREAKER,                   BODY_COLOR_RED,   2, 0, FALSE),
    [SPECIES_OGERPON_CORNERSTONE]      = OGERPON_SPECIES_INFO(Cornerstone, Cornerstone,     TYPE_ROCK,  ABILITY_STURDY,                         BODY_COLOR_GRAY,  2, 0, FALSE),
#if P_TERA_FORMS
    [SPECIES_OGERPON_TEAL_TERA]        = OGERPON_SPECIES_INFO(Teal,        TealTera,        TYPE_GRASS, ABILITY_EMBODY_ASPECT_TEAL_MASK,        BODY_COLOR_GREEN, 0, 1, TRUE),
    [SPECIES_OGERPON_WELLSPRING_TERA]  = OGERPON_SPECIES_INFO(Wellspring,  WellspringTera,  TYPE_WATER, ABILITY_EMBODY_ASPECT_WELLSPRING_MASK,  BODY_COLOR_BLUE,  0, 0, TRUE),
    [SPECIES_OGERPON_HEARTHFLAME_TERA] = OGERPON_SPECIES_INFO(Hearthflame, HearthflameTera, TYPE_FIRE,  ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK, BODY_COLOR_RED,   0, 0, TRUE),
    [SPECIES_OGERPON_CORNERSTONE_TERA] = OGERPON_SPECIES_INFO(Cornerstone, CornerstoneTera, TYPE_ROCK,  ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK, BODY_COLOR_GRAY,  0, 0, TRUE),
#endif //P_TERA_FORMS

#endif //P_FAMILY_OGERPON

#if P_FAMILY_GOUGING_FIRE
    [SPECIES_GOUGING_FIRE] =
    {
        .baseHP        = 105,
        .baseAttack    = 115,
        .baseDefense   = 121,
        .baseSpeed     = 91,
        .baseSpAttack  = 65,
        .baseSpDefense = 93,
        .types = MON_TYPES(TYPE_FIRE, TYPE_DRAGON),
        .catchRate = 10,
        .expYield = 295,
        .evYield_Defense = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PROTOSYNTHESIS, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Feu-Perçant"),
        .cryId = CRY_GOUGING_FIRE,
        .natDexNum = NATIONAL_DEX_GOUGING_FIRE,
        .categoryName = _("Paradoxe"),
        .height = 35,
        .weight = 5900,
        .description = COMPOUND_STRING(
            "Il se protège en transformant de l'énergie en\n"
            "cristal solide. Ce Pokémon est à l'origine du\n"
            "phénomène de Téracristallisation."
        ),
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_GougingFire,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_GougingFire,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_GougingFire,
        .shinyPalette = gMonShinyPalette_GougingFire,
        .iconSprite = gMonIcon_GougingFire,
        .iconPalIndex = 5,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 6, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(GougingFire)
        OVERWORLD(
            sPicTable_GougingFire,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_GougingFire,
            gShinyOverworldPalette_GougingFire
        )
        .isParadox = TRUE,
        .levelUpLearnset = sGougingFireLevelUpLearnset,
        .teachableLearnset = sGougingFireTeachableLearnset,
    },
#endif //P_FAMILY_GOUGING_FIRE

#if P_FAMILY_RAGING_BOLT
    [SPECIES_RAGING_BOLT] =
    {
        .baseHP        = 125,
        .baseAttack    = 73,
        .baseDefense   = 91,
        .baseSpeed     = 75,
        .baseSpAttack  = 137,
        .baseSpDefense = 89,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_DRAGON),
        .catchRate = 10,
        .expYield = 295,
        .evYield_SpAttack = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PROTOSYNTHESIS, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Ire-Foudre"),
        .cryId = CRY_RAGING_BOLT,
        .natDexNum = NATIONAL_DEX_RAGING_BOLT,
        .categoryName = _("Paradoxe"),
        .height = 52,
        .weight = 4800,
        .description = COMPOUND_STRING(
            "Il fait manger à sa cible un mochi empoisonné qui\n"
            "éveille les désirs et révèle le potentiel. Il la\n"
            "contrôle ensuite grâce à ses chaînes."
        ),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 345,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_RagingBolt,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_RagingBolt,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_RagingBolt,
        .shinyPalette = gMonShinyPalette_RagingBolt,
        .iconSprite = gMonIcon_RagingBolt,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 14, SHADOW_SIZE_L)
        FOOTPRINT(RagingBolt)
        OVERWORLD(
            sPicTable_RagingBolt,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_RagingBolt,
            gShinyOverworldPalette_RagingBolt
        )
        .isParadox = TRUE,
        .levelUpLearnset = sRagingBoltLevelUpLearnset,
        .teachableLearnset = sRagingBoltTeachableLearnset,
    },
#endif //P_FAMILY_RAGING_BOLT

#if P_FAMILY_IRON_BOULDER
    [SPECIES_IRON_BOULDER] =
    {
        .baseHP        = 90,
        .baseAttack    = 120,
        .baseDefense   = 80,
        .baseSpeed     = 124,
        .baseSpAttack  = 68,
        .baseSpDefense = 108,
        .types = MON_TYPES(TYPE_ROCK, TYPE_PSYCHIC),
        .catchRate = 10,
        .expYield = 295,
        .evYield_Speed = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_QUARK_DRIVE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Roc-de-Fer"),
        .cryId = CRY_IRON_BOULDER,
        .natDexNum = NATIONAL_DEX_IRON_BOULDER,
        .categoryName = _("Paradoxe"),
        .height = 15,
        .weight = 1625,
        .description = COMPOUND_STRING(
            "Ce Pokémon serait l'incarnation, sous la forme\n"
            "d'un pot de matcha, des regrets d'une personne\n"
            "décédée avant d'avoir maîtrisé l'art du thé."
        ),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 336,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_IronBoulder,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_IronBoulder,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_IronBoulder,
        .shinyPalette = gMonShinyPalette_IronBoulder,
        .iconSprite = gMonIcon_IronBoulder,
        .iconPalIndex = 5,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 7, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(IronBoulder)
        OVERWORLD(
            sPicTable_IronBoulder,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_IronBoulder,
            gShinyOverworldPalette_IronBoulder
        )
        .isParadox = TRUE,
        .levelUpLearnset = sIronBoulderLevelUpLearnset,
        .teachableLearnset = sIronBoulderTeachableLearnset,
    },
#endif //P_FAMILY_IRON_BOULDER

#if P_FAMILY_IRON_CROWN
    [SPECIES_IRON_CROWN] =
    {
        .baseHP        = 90,
        .baseAttack    = 72,
        .baseDefense   = 100,
        .baseSpeed     = 98,
        .baseSpAttack  = 122,
        .baseSpDefense = 108,
        .types = MON_TYPES(TYPE_STEEL, TYPE_PSYCHIC),
        .catchRate = 10,
        .expYield = 295,
        .evYield_SpAttack = 3,
        .itemRare = ITEM_BOOSTER_ENERGY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 50,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_QUARK_DRIVE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Chef-de-Fer"),
        .cryId = CRY_IRON_CROWN,
        .natDexNum = NATIONAL_DEX_IRON_CROWN,
        .categoryName = _("Paradoxe"),
        .height = 16,
        .weight = 1560,
        .description = COMPOUND_STRING(
            "Il accumule l'électricité statique alentour. Le\n"
            "rayon qu'il tire quand il se met à quatre pattes\n"
            "est d'une puissance colossale."
        ),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_IronCrown,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_IronCrown,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_IronCrown,
        .shinyPalette = gMonShinyPalette_IronCrown,
        .iconSprite = gMonIcon_IronCrown,
        .iconPalIndex = 3,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 14, SHADOW_SIZE_L)
        FOOTPRINT(IronCrown)
        OVERWORLD(
            sPicTable_IronCrown,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_IronCrown,
            gShinyOverworldPalette_IronCrown
        )
        .isParadox = TRUE,
        .levelUpLearnset = sIronCrownLevelUpLearnset,
        .teachableLearnset = sIronCrownTeachableLearnset,
    },
#endif //P_FAMILY_IRON_CROWN

#if P_FAMILY_TERAPAGOS
    [SPECIES_TERAPAGOS_NORMAL] =
    {
        .baseHP        = 90,
        .baseAttack    = 65,
        .baseDefense   = 85,
        .baseSpeed     = 60,
        .baseSpAttack  = 65,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_NORMAL),
        .forceTeraType = TYPE_STELLAR,
        .catchRate = 255,
        .expYield = 90,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 5,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_TERA_SHIFT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Terapagos"),
        .cryId = CRY_TERAPAGOS,
        .natDexNum = NATIONAL_DEX_TERAPAGOS,
        .categoryName = _("Téracristal"),
        .height = 2,
        .weight = 65,
        .description = COMPOUND_STRING(
            "Il se fait passer pour un bol de thé afin\n"
            "d'aspirer la force vitale de quiconque ferait\n"
            "l'erreur de le boire, mais en général, personne\n"
            "n'est dupe."
        ),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_TerapagosNormal,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_TerapagosNormal,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_TerapagosNormal,
        .shinyPalette = gMonShinyPalette_TerapagosNormal,
        .iconSprite = gMonIcon_TerapagosNormal,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 2, SHADOW_SIZE_M)
        FOOTPRINT(TerapagosNormal)
        OVERWORLD(
            sPicTable_TerapagosNormal,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_TerapagosNormal,
            gShinyOverworldPalette_TerapagosNormal
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sTerapagosLevelUpLearnset,
        .teachableLearnset = sTerapagosTeachableLearnset,
        .formSpeciesIdTable = sTerapagosFormSpeciesIdTable,
        .formChangeTable = sTerapagosFormChangeTable,
    },

    [SPECIES_TERAPAGOS_TERASTAL] =
    {
        .baseHP        = 95,
        .baseAttack    = 95,
        .baseDefense   = 110,
        .baseSpeed     = 85,
        .baseSpAttack  = 105,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_NORMAL),
        .forceTeraType = TYPE_STELLAR,
        .catchRate = 255,
        .expYield = 120,
        .evYield_Defense = 2,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 5,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_TERA_SHELL, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Terapagos"),
        .cryId = CRY_TERAPAGOS,
        .natDexNum = NATIONAL_DEX_TERAPAGOS,
        .categoryName = _("Téracristal"),
        .height = 3,
        .weight = 160,
        .description = COMPOUND_STRING(
            "Il se fait passer pour un bol de thé afin\n"
            "d'aspirer la force vitale de quiconque ferait\n"
            "l'erreur de le boire, mais en général, personne\n"
            "n'est dupe."
        ),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_TerapagosTerastal,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_TerapagosTerastal,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_TerapagosTerastal,
        .shinyPalette = gMonShinyPalette_TerapagosTerastal,
        .iconSprite = gMonIcon_TerapagosTerastal,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 8, SHADOW_SIZE_L)
        FOOTPRINT(TerapagosTerastal)
        OVERWORLD(
            sPicTable_TerapagosTerastal,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_TerapagosTerastal,
            gShinyOverworldPalette_TerapagosTerastal
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sTerapagosLevelUpLearnset,
        .teachableLearnset = sTerapagosTeachableLearnset,
        .formSpeciesIdTable = sTerapagosFormSpeciesIdTable,
        .formChangeTable = sTerapagosFormChangeTable,
    },

    [SPECIES_TERAPAGOS_STELLAR] =
    {
        .baseHP        = 160,
        .baseAttack    = 105,
        .baseDefense   = 110,
        .baseSpeed     = 85,
        .baseSpAttack  = 130,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_NORMAL),
        .forceTeraType = TYPE_STELLAR,
        .catchRate = 255,
        .expYield = 140,
        .evYield_HP = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 5,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_TERAFORM_ZERO, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Terapagos"),
        .cryId = CRY_TERAPAGOS,
        .natDexNum = NATIONAL_DEX_TERAPAGOS,
        .categoryName = _("Téracristal"),
        .height = 17,
        .weight = 770,
        .description = COMPOUND_STRING(
            "Il se fait passer pour un bol de thé afin\n"
            "d'aspirer la force vitale de quiconque ferait\n"
            "l'erreur de le boire, mais en général, personne\n"
            "n'est dupe."
        ),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_TerapagosStellar,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_TerapagosStellar,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_TerapagosStellar,
        .shinyPalette = gMonShinyPalette_TerapagosStellar,
        .iconSprite = gMonIcon_TerapagosStellar,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 12, SHADOW_SIZE_L)
        FOOTPRINT(TerapagosStellar)
        .isRestrictedLegendary = TRUE,
        .isTeraForm = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sTerapagosLevelUpLearnset,
        .teachableLearnset = sTerapagosTeachableLearnset,
        .formSpeciesIdTable = sTerapagosFormSpeciesIdTable,
        .formChangeTable = sTerapagosFormChangeTable,
    },
#endif //P_FAMILY_TERAPAGOS

#if P_FAMILY_PECHARUNT
    [SPECIES_PECHARUNT] =
    {
        .baseHP        = 88,
        .baseAttack    = 88,
        .baseDefense   = 160,
        .baseSpeed     = 88,
        .baseSpAttack  = 88,
        .baseSpDefense = 88,
        .types = MON_TYPES(TYPE_POISON, TYPE_GHOST),
        .catchRate = 3,
        .expYield = 300,
        .evYield_Defense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_POISON_PUPPETEER, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Pêchaminus"),
        .cryId = CRY_PECHARUNT,
        .natDexNum = NATIONAL_DEX_PECHARUNT,
        .categoryName = _("Emprise"),
        .height = 3,
        .weight = 3,
        .description = COMPOUND_STRING(
            "Il fait manger à sa cible un mochi empoisonné qui\n"
            "éveille les désirs et révèle le potentiel. Il la\n"
            "contrôle ensuite grâce à ses chaînes."
        ),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Pecharunt,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Pecharunt,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Pecharunt,
        .shinyPalette = gMonShinyPalette_Pecharunt,
        .iconSprite = gMonIcon_Pecharunt,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 1, SHADOW_SIZE_L)
        FOOTPRINT(Pecharunt)
        OVERWORLD(
            sPicTable_Pecharunt,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Pecharunt,
            gShinyOverworldPalette_Pecharunt
        )
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sPecharuntLevelUpLearnset,
        .teachableLearnset = sPecharuntTeachableLearnset,
    },
#endif //P_FAMILY_PECHARUNT

#ifdef __INTELLISENSE__
};
#endif
