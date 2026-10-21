// Eien regional forms (design/variants.md), generated from the original entries and then
// edited by hand. Included inside gSpeciesInfo by species_info.h; their learnsets, sprites,
// palettes and form tables are in eien_forms_data.h. The starters evolve at Lv 18 into their Eien
// middle stages (below); those don't evolve further until the finals exist.

#if P_FAMILY_TORCHIC
    [SPECIES_TORCHIC_EIEN] =
    {
        .baseHP        = 45,
        .baseAttack    = 45,
        .baseDefense   = 40,
        .baseSpeed     = 50,
        .baseSpAttack  = 80,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_FIRE, TYPE_GHOST),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 62 : 65,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Torchic"),
        .cryId = CRY_TORCHIC,
        .natDexNum = NATIONAL_DEX_TORCHIC,
        .categoryName = _("Lantern"),
        .height = 4,
        .weight = 25,
        .description = COMPOUND_STRING(
            "A pale flame burns inside its chest.\n"
            "On snowy nights it sits by old shrines,\n"
            "and travelers follow its light home.\n"
            "It dislikes loud, bright places."),
        .pokemonScale = 566,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = sMonFrontPic_TorchicEien,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_STRETCH : ANIM_V_JUMPS_SMALL,
        .backPic = sMonBackPic_TorchicEien,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(40, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = sMonPalette_TorchicEien,
        .shinyPalette = sMonShinyPalette_TorchicEien,
        .iconSprite = sMonIcon_TorchicEien,
        .iconPalIndex = 6,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, 1, SHADOW_SIZE_S)
        FOOTPRINT(Torchic)
        OVERWORLD(
            sPicTable_Torchic,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Torchic,
            gShinyOverworldPalette_Torchic
        )
        OVERWORLD_FEMALE(
            sPicTable_TorchicF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sTorchicEienLevelUpLearnset,
        .teachableLearnset = sTorchicTeachableLearnset,
        .eggMoveLearnset = sTorchicEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_COMBUSKEN_EIEN}),
        .formSpeciesIdTable = sTorchicFormSpeciesIdTable,
    },
#endif //P_FAMILY_TORCHIC

#if P_FAMILY_BULBASAUR
    [SPECIES_BULBASAUR_EIEN] =
    {
        .baseHP        = 45,
        .baseAttack    = 40,
        .baseDefense   = 49,
        .baseSpeed     = 39,
        .baseSpAttack  = 75,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GRASS, TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = 64,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_FOREWARN },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
        .speciesName = _("Bulbasaur"),
        .cryId = CRY_BULBASAUR,
        .natDexNum = NATIONAL_DEX_BULBASAUR,
        .categoryName = _("Aurora"),
        .height = 7,
        .weight = 69,
        .description = COMPOUND_STRING(
            "The bulb on its back glows faintly,\n"
            "like the aurora. Where the worlds are\n"
            "thin, it fades until it is hard to see,\n"
            "then quietly returns."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = sMonFrontPic_BulbasaurEien,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 40) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = sMonBackPic_BulbasaurEien,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 32) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = sMonPalette_BulbasaurEien,
        .shinyPalette = sMonShinyPalette_BulbasaurEien,
        .iconSprite = sMonIcon_BulbasaurEien,
        .iconPalIndex = 6,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -1, SHADOW_SIZE_S)
        FOOTPRINT(Bulbasaur)
        OVERWORLD(
            sPicTable_Bulbasaur,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Bulbasaur,
            gShinyOverworldPalette_Bulbasaur
        )
        .levelUpLearnset = sBulbasaurEienLevelUpLearnset,
        .teachableLearnset = sBulbasaurTeachableLearnset,
        .eggMoveLearnset = sBulbasaurEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_IVYSAUR_EIEN}),
        .formSpeciesIdTable = sBulbasaurFormSpeciesIdTable,
    },
#endif //P_FAMILY_BULBASAUR

#if P_FAMILY_FROAKIE
    [SPECIES_FROAKIE_EIEN] =
    {
        .baseHP        = 41,
        .baseAttack    = 56,
        .baseDefense   = 40,
        .baseSpeed     = 61,
        .baseSpAttack  = 62,
        .baseSpDefense = 54,
        .types = MON_TYPES(TYPE_WATER, TYPE_ICE),
        .catchRate = 45,
        .expYield = 63,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SNOW_CLOAK },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Froakie"),
        .cryId = CRY_FROAKIE,
        .natDexNum = NATIONAL_DEX_FROAKIE,
        .categoryName = _("Frost Frog"),
        .height = 3,
        .weight = 70,
        .description = COMPOUND_STRING(
            "The frost around its neck is its own\n"
            "frozen breath. It hides in snowdrifts\n"
            "and strikes before its foe can see it\n"
            "move."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = sMonFrontPic_FroakieEien,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 13),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 13),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 13),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 11),
        ),
        .frontAnimId = ANIM_H_JUMPS,
        .backPic = sMonBackPic_FroakieEien,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        .palette = sMonPalette_FroakieEien,
        .shinyPalette = sMonShinyPalette_FroakieEien,
        .iconSprite = sMonIcon_FroakieEien,
        .iconPalIndex = 6,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(2, 0, SHADOW_SIZE_S)
        FOOTPRINT(Froakie)
        OVERWORLD(
            sPicTable_Froakie,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Froakie,
            gShinyOverworldPalette_Froakie
        )
        .levelUpLearnset = sFroakieEienLevelUpLearnset,
        .teachableLearnset = sFroakieTeachableLearnset,
        .eggMoveLearnset = sFroakieEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_FROGADIER_EIEN}),
        .formSpeciesIdTable = sFroakieFormSpeciesIdTable,
    },
#endif //P_FAMILY_FROAKIE

#if P_FAMILY_POOCHYENA
    [SPECIES_POOCHYENA_EIEN] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 50,
        .baseSpeed     = 25,
        .baseSpAttack  = 25,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_ROCK, TYPE_DARK),
        .catchRate = 255,
    #if P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 56,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 44,
    #else
        .expYield = 55,
    #endif
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_STURDY, ABILITY_STAKEOUT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Poochyena"),
        .cryId = CRY_POOCHYENA,
        .natDexNum = NATIONAL_DEX_POOCHYENA,
        .categoryName = _("Guardian"),
        .height = 5,
        .weight = 136,
        .description = COMPOUND_STRING(
            "Its body is as hard as the stone dogs\n"
            "that guard Eien's shrines. It barks at\n"
            "anything it does not trust and never\n"
            "leaves its post on its own."),
        .pokemonScale = 481,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = sMonFrontPic_PoochyenaEien,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 44),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = sMonBackPic_PoochyenaEien,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 11,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = sMonPalette_PoochyenaEien,
        .shinyPalette = sMonShinyPalette_PoochyenaEien,
        .iconSprite = sMonIcon_PoochyenaEien,
        .iconPalIndex = 5,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 2, SHADOW_SIZE_M)
        FOOTPRINT(Poochyena)
        OVERWORLD(
            sPicTable_Poochyena,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Poochyena,
            gShinyOverworldPalette_Poochyena
        )
        .levelUpLearnset = sPoochyenaEienLevelUpLearnset,
        .teachableLearnset = sPoochyenaTeachableLearnset,
        .eggMoveLearnset = sPoochyenaEggMoveLearnset,
        .formSpeciesIdTable = sPoochyenaFormSpeciesIdTable,
        // Evolves only in a shrine area (variants.md): one entry per shrine map.
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_MIGHTYENA_EIEN, CONDITIONS({IF_IN_MAP, MAP_EIEN_ROUTE1_SHRINE})},
                                {EVO_LEVEL, 18, SPECIES_MIGHTYENA_EIEN, CONDITIONS({IF_IN_MAP, MAP_SHIMOTSUKI_KAEDE_SHRINE})}),
    },

    [SPECIES_MIGHTYENA_EIEN] =
    {
        .baseHP        = 70,
        .baseAttack    = 90,
        .baseDefense   = 90,
        .baseSpeed     = 60,
        .baseSpAttack  = 50,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ROCK, TYPE_DARK),
        .catchRate = 127,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 147 : 128,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_STURDY, ABILITY_STAKEOUT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Mightyena"),
        .cryId = CRY_MIGHTYENA,
        .natDexNum = NATIONAL_DEX_MIGHTYENA,
        .categoryName = _("Guardian"),
        .height = 10,
        .weight = 370,
        // TODO(design): dex entry (a placeholder, like the other Eien forms' drafts).
        .description = COMPOUND_STRING(
            "A stone guardian that has grown into\n"
            "its post. It roars at intruders, and\n"
            "faint light shows through the cracks\n"
            "in its body."),
        .pokemonScale = 362,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = sMonFrontPic_MightyenaEien,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 27),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = sMonBackPic_MightyenaEien,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = sMonPalette_MightyenaEien,
        .shinyPalette = sMonShinyPalette_MightyenaEien,
        .iconSprite = sMonIcon_MightyenaEien,
        .iconPalIndex = 5,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 6, SHADOW_SIZE_L)
        FOOTPRINT(Mightyena)
        OVERWORLD(
            sPicTable_Mightyena,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Mightyena,
            gShinyOverworldPalette_Mightyena
        )
        .levelUpLearnset = sMightyenaEienLevelUpLearnset,
        .teachableLearnset = sMightyenaTeachableLearnset,
        .formSpeciesIdTable = sMightyenaFormSpeciesIdTable,
    },
#endif //P_FAMILY_POOCHYENA

// Eien middle stages (design/variants.md, "Evolved stages"): they evolve from the first
// stages at Lv 18. Sprites from the picked AI drafts; icons recolored into the Eien icon palette. They don't evolve further yet (the finals aren't built).

#if P_FAMILY_TORCHIC
    [SPECIES_COMBUSKEN_EIEN] =
    {
        .baseHP        = 60,
        .baseAttack    = 70,
        .baseDefense   = 60,
        .baseSpeed     = 60,
        .baseSpAttack  = 95,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_FIRE, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 142,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Combusken"),
        .cryId = CRY_COMBUSKEN,
        .natDexNum = NATIONAL_DEX_COMBUSKEN,
        .categoryName = _("Festival"),
        .height = 9,
        .weight = 195,
        .description = COMPOUND_STRING(
            "It dances in front of the lantern floats\n"
            "at summer festivals. Its paper feathers\n"
            "glow from the pale flame inside, and it\n"
            "leaps higher the louder the drums play."),
        .pokemonScale = 343,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = sMonFrontPic_CombuskenEien,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 12),
        ),
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = sMonBackPic_CombuskenEien,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 1,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = sMonPalette_CombuskenEien,
        .shinyPalette = sMonShinyPalette_CombuskenEien,
        .iconSprite = sMonIcon_CombuskenEien,
        .iconPalIndex = 6,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 8, SHADOW_SIZE_M)
        FOOTPRINT(Combusken)
        OVERWORLD(
            sPicTable_Combusken,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Combusken,
            gShinyOverworldPalette_Combusken
        )
        OVERWORLD_FEMALE(
            sPicTable_CombuskenF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sCombuskenEienLevelUpLearnset,
        .teachableLearnset = sCombuskenTeachableLearnset,
        .formSpeciesIdTable = sCombuskenFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_BLAZIKEN_EIEN}),
    },
#endif //P_FAMILY_TORCHIC

#if P_FAMILY_BULBASAUR
    [SPECIES_IVYSAUR_EIEN] =
    {
        .baseHP        = 60,
        .baseAttack    = 53,
        .baseDefense   = 63,
        .baseSpeed     = 54,
        .baseSpAttack  = 90,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_GRASS, TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 142 : 141,
        .evYield_SpAttack = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_FOREWARN },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
        .speciesName = _("Ivysaur"),
        .cryId = CRY_IVYSAUR,
        .natDexNum = NATIONAL_DEX_IVYSAUR,
        .categoryName = _("Aurora Bud"),
        .height = 10,
        .weight = 130,
        .description = COMPOUND_STRING(
            "Its bud has half opened. On clear nights\n"
            "a small aurora swirls inside the petals,\n"
            "and it turns its head to the sky as if\n"
            "listening for something far away."),
        .pokemonScale = 335,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = sMonFrontPic_IvysaurEien,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 36),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = sMonBackPic_IvysaurEien,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = sMonPalette_IvysaurEien,
        .shinyPalette = sMonShinyPalette_IvysaurEien,
        .iconSprite = sMonIcon_IvysaurEien,
        .iconPalIndex = 6,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 3, SHADOW_SIZE_L)
        FOOTPRINT(Ivysaur)
        OVERWORLD(
            sPicTable_Ivysaur,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Ivysaur,
            gShinyOverworldPalette_Ivysaur
        )
        .levelUpLearnset = sIvysaurEienLevelUpLearnset,
        .teachableLearnset = sIvysaurTeachableLearnset,
        .formSpeciesIdTable = sIvysaurFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_VENUSAUR_EIEN}),
    },
#endif //P_FAMILY_BULBASAUR

#if P_FAMILY_FROAKIE
    [SPECIES_FROGADIER_EIEN] =
    {
        .baseHP        = 54,
        .baseAttack    = 63,
        .baseDefense   = 52,
        .baseSpeed     = 87,
        .baseSpAttack  = 83,
        .baseSpDefense = 66,
        .types = MON_TYPES(TYPE_WATER, TYPE_ICE),
        .catchRate = 45,
        .expYield = 142,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SNOW_CLOAK },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Frogadier"),
        .cryId = CRY_FROGADIER,
        .natDexNum = NATIONAL_DEX_FROGADIER,
        .categoryName = _("Snow Scout"),
        .height = 6,
        .weight = 109,
        .description = COMPOUND_STRING(
            "It wears a cape of woven straw and walks\n"
            "on the deepest drifts without sinking.\n"
            "It scouts the snow ahead of travelers\n"
            "and vanishes when they look back."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = sMonFrontPic_FrogadierEien,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = sMonBackPic_FrogadierEien,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = sMonPalette_FrogadierEien,
        .shinyPalette = sMonShinyPalette_FrogadierEien,
        .iconSprite = sMonIcon_FrogadierEien,
        .iconPalIndex = 6,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 5, SHADOW_SIZE_M)
        FOOTPRINT(Frogadier)
        OVERWORLD(
            sPicTable_Frogadier,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Frogadier,
            gShinyOverworldPalette_Frogadier
        )
        .levelUpLearnset = sFrogadierEienLevelUpLearnset,
        .teachableLearnset = sFrogadierTeachableLearnset,
        .formSpeciesIdTable = sFrogadierFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_GRENINJA_EIEN}),
    },
#endif //P_FAMILY_FROAKIE

#if P_FAMILY_WOOPER
    [SPECIES_WOOPER_EIEN] =
    {
        .baseHP        = 55,
        .baseAttack    = 45,
        .baseDefense   = 55,
        .baseSpeed     = 5,
        .baseSpAttack  = 15,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_GROUND, TYPE_STEEL),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 42 : 52,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = { ABILITY_STURDY, ABILITY_HEAVY_METAL, ABILITY_UNAWARE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Wooper"),
        .cryId = CRY_WOOPER,
        .natDexNum = NATIONAL_DEX_WOOPER,
        // TODO(design): category, size and dex entry (placeholders, like the other Eien forms' drafts).
        .categoryName = _("Ore Fish"),
        .height = 4,
        .weight = 85,
        .description = COMPOUND_STRING(
            "It lives in the muddy pools of old mine\n"
            "tunnels. Iron and copper ore crusts its\n"
            "skin, and its gills are stiff frills\n"
            "that glint like metal."),
        .pokemonScale = 479,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = sMonFrontPic_WooperEien,
        .frontPicSize = MON_COORDS_SIZE(40, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = sMonBackPic_WooperEien,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 12, // Its own back, framed like the vanilla (non-GBA-style) one
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = sMonPalette_WooperEien,
        .shinyPalette = sMonShinyPalette_WooperEien,
        .iconSprite = sMonIcon_WooperEien,
        .iconPalIndex = 3,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Wooper)
        OVERWORLD(
            sPicTable_Wooper,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Wooper,
            gShinyOverworldPalette_Wooper
        )
        .levelUpLearnset = sWooperEienLevelUpLearnset,
        .teachableLearnset = sWooperTeachableLearnset,
        .eggMoveLearnset = sWooperEggMoveLearnset,
        .formSpeciesIdTable = sWooperFormSpeciesIdTable,
        // Evolves at Lv 20+ only in the mine tunnel (variants.md): an IF_IN_MAP entry for
        // MAP_EIEN_ROUTE3_CAVE. TODO: add it once the map exists (Porymap); until then it doesn't
        // evolve, and the journal notes it.
    },

    [SPECIES_QUAGSIRE_EIEN] =
    {
        .baseHP        = 95,
        .baseAttack    = 85,
        .baseDefense   = 95,
        .baseSpeed     = 25,
        .baseSpAttack  = 55,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_GROUND, TYPE_STEEL),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 151 : 137,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = { ABILITY_STURDY, ABILITY_HEAVY_METAL, ABILITY_UNAWARE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Quagsire"),
        .cryId = CRY_QUAGSIRE,
        .natDexNum = NATIONAL_DEX_QUAGSIRE,
        // TODO(design): category, size and dex entry (placeholders, like the other Eien forms' drafts).
        .categoryName = _("Ore Fish"),
        .height = 14,
        .weight = 750,
        .description = COMPOUND_STRING(
            "Its body is smooth and dark, like a\n"
            "polished iron kettle. It sits in the\n"
            "mine's pools for days with its mouth\n"
            "open, as calm as ever."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        // Its own sprites, framed like the vanilla (non-GBA-style) ones
        .frontPic = sMonFrontPic_QuagsireEien,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 32),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_H_STRETCH,
        .backPic = sMonBackPic_QuagsireEien,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = sMonPalette_QuagsireEien,
        .shinyPalette = sMonShinyPalette_QuagsireEien,
        .iconSprite = sMonIcon_QuagsireEien,
        .iconPalIndex = 3,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 8, SHADOW_SIZE_M)
        FOOTPRINT(Quagsire)
        OVERWORLD(
            sPicTable_Quagsire,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Quagsire,
            gShinyOverworldPalette_Quagsire
        )
        .levelUpLearnset = sQuagsireEienLevelUpLearnset,
        .teachableLearnset = sQuagsireTeachableLearnset,
        .formSpeciesIdTable = sQuagsireFormSpeciesIdTable,
    },
#endif //P_FAMILY_WOOPER

#if P_FAMILY_HOOTHOOT
    [SPECIES_HOOTHOOT_EIEN] =
    {
        .baseHP        = 50,
        .baseAttack    = 30,
        .baseDefense   = 26,
        .baseSpeed     = 60,
        .baseSpAttack  = 60,
        .baseSpDefense = 36,
        .types = MON_TYPES(TYPE_GHOST, TYPE_FLYING),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 52 : 58,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_INSOMNIA, ABILITY_FRISK, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Hoothoot"),
        .cryId = CRY_HOOTHOOT,
        .natDexNum = NATIONAL_DEX_HOOTHOOT,
        // TODO(design): category, size and dex entry (placeholders, like the other Eien forms' drafts).
        .categoryName = _("Owl"),
        .height = 7,
        .weight = 212,
        .description = COMPOUND_STRING(
            "It lives on cold mountain passes. Its\n"
            "wings and tail fade into mist, and on\n"
            "dark nights only its face and its pale\n"
            "eyes can be seen."),
        .pokemonScale = 380,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
        // Its own sprites, framed like the vanilla (non-GBA-style) ones; the mist wings are wider
        .frontPic = sMonFrontPic_HoothootEien,
        .frontPicSize = MON_COORDS_SIZE(56, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
        ),
        .frontAnimId = ANIM_V_SLIDE_SLOW,
        .backPic = sMonBackPic_HoothootEien,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = sMonPalette_HoothootEien,
        .shinyPalette = sMonShinyPalette_HoothootEien,
        .iconSprite = sMonIcon_HoothootEien,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 2, SHADOW_SIZE_S)
        FOOTPRINT(Hoothoot)
        OVERWORLD(
            sPicTable_Hoothoot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Hoothoot,
            gShinyOverworldPalette_Hoothoot
        )
        .isSkyBattleBanned = B_SKY_BATTLE_STRICT_ELIGIBILITY,
        .levelUpLearnset = sHoothootEienLevelUpLearnset,
        .teachableLearnset = sHoothootTeachableLearnset,
        .eggMoveLearnset = sHoothootEggMoveLearnset,
        .formSpeciesIdTable = sHoothootFormSpeciesIdTable,
        // Evolves at Lv 20+ at night on Route 2's upper map only (variants.md): an entry with
        // IF_TIME (night) and IF_IN_MAP MAP_EIEN_ROUTE2_UPPER. TODO: add it once the map exists
        // (Porymap); until then it doesn't evolve, and the journal notes it.
    },

    [SPECIES_NOCTOWL_EIEN] =
    {
        .baseHP        = 90,
        .baseAttack    = 50,
        .baseDefense   = 46,
        .baseSpeed     = 80,
        .baseSpAttack  = 110,
        .baseSpDefense = 76,
        .types = MON_TYPES(TYPE_GHOST, TYPE_FLYING),
        .catchRate = 90,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 158,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 155,
    #else
        .expYield = 162,
    #endif
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_INSOMNIA, ABILITY_FRISK, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Noctowl"),
        .cryId = CRY_NOCTOWL,
        .natDexNum = NATIONAL_DEX_NOCTOWL,
        // TODO(design): category, size and dex entry (placeholders, like the other Eien forms' drafts).
        .categoryName = _("Owl"),
        .height = 16,
        .weight = 408,
        .description = COMPOUND_STRING(
            "Its faded wings hang behind it in long\n"
            "veils of mist, like a shroud. It flies\n"
            "the mountain passes at night without\n"
            "making a sound."),
        .pokemonScale = 278,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        // Its own sprites; the veils fill the frame's width (vanilla's front is 40 wide)
        .frontPic = sMonFrontPic_NoctowlEien,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = sMonBackPic_NoctowlEien,
        .backPicSize = MON_COORDS_SIZE(48, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = sMonPalette_NoctowlEien,
        .shinyPalette = sMonShinyPalette_NoctowlEien,
        .iconSprite = sMonIcon_NoctowlEien,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 10, SHADOW_SIZE_S)
        FOOTPRINT(Noctowl)
        OVERWORLD(
            sPicTable_Noctowl,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Noctowl,
            gShinyOverworldPalette_Noctowl
        )
        .levelUpLearnset = sNoctowlEienLevelUpLearnset,
        .teachableLearnset = sNoctowlTeachableLearnset,
        .formSpeciesIdTable = sNoctowlFormSpeciesIdTable,
    },
#endif //P_FAMILY_HOOTHOOT

#if P_FAMILY_TORCHIC
    [SPECIES_BLAZIKEN_EIEN] =
    {
        .baseHP        = 80,
        .baseAttack    = 105,
        .baseDefense   = 70,
        .baseSpeed     = 85,
        .baseSpAttack  = 120,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_FIRE, TYPE_GHOST),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 265,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 239,
    #else
        .expYield = 209,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Blaziken"),
        .cryId = CRY_BLAZIKEN,
        .natDexNum = NATIONAL_DEX_BLAZIKEN,
        // TODO(design): category, size and dex entry (placeholders, like the other Eien forms' drafts).
        .categoryName = _("Float"),
        .height = 19,
        .weight = 520,
        .description = COMPOUND_STRING(
            "It is a festival float of a warrior, paper\n"
            "stretched over a frame and lit from inside\n"
            "by a pale flame. Its painted face glares\n"
            "at anything that comes near."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 301,
        .trainerOffset = 4,
        // Its own sprites, framed like the vanilla (non-GBA-style) ones
        .frontPic = sMonFrontPic_BlazikenEien,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = sMonBackPic_BlazikenEien,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = sMonPalette_BlazikenEien,
        .shinyPalette = sMonShinyPalette_BlazikenEien,
        .iconSprite = sMonIcon_BlazikenEien,
        .iconPalIndex = 6,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 8, SHADOW_SIZE_M)
        FOOTPRINT(Blaziken)
        OVERWORLD(
            sPicTable_Blaziken,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Blaziken,
            gShinyOverworldPalette_Blaziken
        )
        .levelUpLearnset = sBlazikenEienLevelUpLearnset,
        .teachableLearnset = sBlazikenTeachableLearnset,
        .formSpeciesIdTable = sBlazikenFormSpeciesIdTable,
    },
#endif //P_FAMILY_TORCHIC

#if P_FAMILY_BULBASAUR
    [SPECIES_VENUSAUR_EIEN] =
    {
        .baseHP        = 80,
        .baseAttack    = 73,
        .baseDefense   = 83,
        .baseSpeed     = 74,
        .baseSpAttack  = 110,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_GRASS, TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = VENUSAUR_EXP_YIELD,
        .evYield_SpAttack = 2,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_FOREWARN },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Venusaur"),
        .cryId = CRY_VENUSAUR,
        .natDexNum = NATIONAL_DEX_VENUSAUR,
        // TODO(design): category, size and dex entry (placeholders, like the other Eien forms' drafts).
        .categoryName = _("Aurora"),
        .height = 20,
        .weight = 1000,
        .description = COMPOUND_STRING(
            "Its great flower has opened all the way.\n"
            "On clear winter nights an aurora streams\n"
            "up from it into the sky, and the people\n"
            "who see it stand quiet for a while."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 388,
        .trainerOffset = 6,
        // Its own sprites, framed like the vanilla (non-GBA-style) ones
        .frontPic = sMonFrontPic_VenusaurEien,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0, // the aurora reaches the top of the frame
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_ROTATE_UP_SLAM_DOWN,
        .backPic = sMonBackPic_VenusaurEien,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = sMonPalette_VenusaurEien,
        .shinyPalette = sMonShinyPalette_VenusaurEien,
        .iconSprite = sMonIcon_VenusaurEien,
        .iconPalIndex = 6,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 6, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Venusaur)
        OVERWORLD(
            sPicTable_Venusaur,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Venusaur,
            gShinyOverworldPalette_Venusaur
        )
        .levelUpLearnset = sVenusaurEienLevelUpLearnset,
        .teachableLearnset = sVenusaurTeachableLearnset,
        .formSpeciesIdTable = sVenusaurFormSpeciesIdTable,
    },
#endif //P_FAMILY_BULBASAUR

#if P_FAMILY_FROAKIE
    [SPECIES_GRENINJA_EIEN] =
    {
        .baseHP        = 72,
        .baseAttack    = 95,
        .baseDefense   = 67,
        .baseSpeed     = 112,
        .baseSpAttack  = 103,
        .baseSpDefense = 81,
        .types = MON_TYPES(TYPE_WATER, TYPE_ICE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 265 : 239,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SNOW_CLOAK },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
        .speciesName = _("Greninja"),
        .cryId = CRY_GRENINJA,
        .natDexNum = NATIONAL_DEX_GRENINJA,
        // TODO(design): category, size and dex entry (placeholders, like the other Eien forms' drafts).
        .categoryName = _("Guardian"),
        .height = 15,
        .weight = 400,
        .description = COMPOUND_STRING(
            "It keeps watch over the snowy passes\n"
            "in a straw hat and cape. Travelers lost\n"
            "in blizzards say it led them out, then\n"
            "was gone."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        // Its own sprites, framed like the vanilla (non-GBA-style) ones
        .frontPic = sMonFrontPic_GreninjaEien,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Greninja,
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = sMonBackPic_GreninjaEien,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = sMonPalette_GreninjaEien,
        .shinyPalette = sMonShinyPalette_GreninjaEien,
        .iconSprite = sMonIcon_GreninjaEien,
        .iconPalIndex = 6,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 6, SHADOW_SIZE_L)
        FOOTPRINT(Greninja)
        OVERWORLD(
            sPicTable_Greninja,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Greninja,
            gShinyOverworldPalette_Greninja
        )
        .levelUpLearnset = sGreninjaEienLevelUpLearnset,
        .teachableLearnset = sGreninjaTeachableLearnset,
        .formSpeciesIdTable = sGreninjaFormSpeciesIdTable,
    },
#endif //P_FAMILY_FROAKIE

#if P_FAMILY_LEDYBA
    [SPECIES_LEDYBA_EIEN] =
    {
        .baseHP        = 40,
        .baseAttack    = 20,
        .baseDefense   = 30,
        .baseSpeed     = 55,
        .baseSpAttack  = 70,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_BUG, TYPE_FIRE),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 53 : 54,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_FLAME_BODY, ABILITY_SWARM, ABILITY_ILLUMINATE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Ledyba"),
        .cryId = CRY_LEDYBA,
        .natDexNum = NATIONAL_DEX_LEDYBA,
        // TODO(design): category, size and dex entry (placeholders, like the other Eien forms' drafts).
        .categoryName = _("Firefly"),
        .height = 10,
        .weight = 108,
        .description = COMPOUND_STRING(
            "It lives over summer rice paddies. Its\n"
            "spots glow like embers, and on warm\n"
            "nights the fields fill with their small,\n"
            "drifting lights."),
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        // Its own sprites, framed like the vanilla (non-GBA-style) ones
        .frontPic = sMonFrontPic_LedybaEien,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        .backPic = sMonBackPic_LedybaEien,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = sMonPalette_LedybaEien,
        .shinyPalette = sMonShinyPalette_LedybaEien,
        .iconSprite = sMonIcon_LedybaEien,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 4, SHADOW_SIZE_M)
        FOOTPRINT(Ledyba)
        OVERWORLD(
            sPicTable_Ledyba,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Ledyba,
            gShinyOverworldPalette_Ledyba
        )
        .levelUpLearnset = sLedybaEienLevelUpLearnset,
        .teachableLearnset = sLedybaTeachableLearnset,
        .eggMoveLearnset = sLedybaEggMoveLearnset,
        .formSpeciesIdTable = sLedybaFormSpeciesIdTable,
        // Evolves at Lv 18+ while it's raining (variants.md): fireflies come out after rain.
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_LEDIAN_EIEN, CONDITIONS({IF_WEATHER, WEATHER_RAIN})}),
    },    [SPECIES_LEDIAN_EIEN] =
    {
        .baseHP        = 55,
        .baseAttack    = 35,
        .baseDefense   = 50,
        .baseSpeed     = 75,
        .baseSpAttack  = 95,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_BUG, TYPE_FIRE),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 137 : 134,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_FLAME_BODY, ABILITY_SWARM, ABILITY_ILLUMINATE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Ledian"),
        .cryId = CRY_LEDIAN,
        .natDexNum = NATIONAL_DEX_LEDIAN,
        // TODO(design): category, size and dex entry (placeholders, like the other Eien forms' drafts).
        .categoryName = _("Firefly"),
        .height = 14,
        .weight = 356,
        .description = COMPOUND_STRING(
            "The light on its back glows like a\n"
            "lantern. Farmers say a field it visits\n"
            "will have a good harvest, and leave\n"
            "their lamps dark so it will stay."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        // Its own sprites, framed like the vanilla (non-GBA-style) ones
        .frontPic = sMonFrontPic_LedianEien,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 25),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 25),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 10,
        .backPic = sMonBackPic_LedianEien,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = sMonPalette_LedianEien,
        .shinyPalette = sMonShinyPalette_LedianEien,
        .iconSprite = sMonIcon_LedianEien,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 15, SHADOW_SIZE_S)
        FOOTPRINT(Ledian)
        OVERWORLD(
            sPicTable_Ledian,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Ledian,
            gShinyOverworldPalette_Ledian
        )
        .levelUpLearnset = sLedianEienLevelUpLearnset,
        .teachableLearnset = sLedianTeachableLearnset,
        .formSpeciesIdTable = sLedianFormSpeciesIdTable,
    },
#endif //P_FAMILY_LEDYBA

#if P_FAMILY_STANTLER
    [SPECIES_STANTLER_EIEN] =
    {
        .baseHP        = 73,
        .baseAttack    = 105,
        .baseDefense   = 67,
        .baseSpeed     = 85,
        .baseSpAttack  = 70,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_DARK, TYPE_GHOST),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 165,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_FRISK, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Stantler"),
        .cryId = CRY_STANTLER,
        .natDexNum = NATIONAL_DEX_STANTLER,
        // TODO(design): category, size and dex entry (placeholders, like the other Eien forms' drafts).
        .categoryName = _("Serow"),
        .height = 14,
        .weight = 712,
        .description = COMPOUND_STRING(
            "It lives on snowy high plateaus. The\n"
            "orbs in its antlers have gone grey\n"
            "and hollow. People say that looking\n"
            "into them is like looking at nothing."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        // Its own sprites, framed like the vanilla (non-GBA-style) ones
        .frontPic = sMonFrontPic_StantlerEien,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = sMonBackPic_StantlerEien,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = sMonPalette_StantlerEien,
        .shinyPalette = sMonShinyPalette_StantlerEien,
        .iconSprite = sMonIcon_StantlerEien,
        .iconPalIndex = 6,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 13, SHADOW_SIZE_M)
        FOOTPRINT(Stantler)
        OVERWORLD(
            sPicTable_Stantler,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Stantler,
            gShinyOverworldPalette_Stantler
        )
        .levelUpLearnset = sStantlerEienLevelUpLearnset,
        .teachableLearnset = sStantlerTeachableLearnset,
        .eggMoveLearnset = sStantlerEggMoveLearnset,
        .formSpeciesIdTable = sStantlerFormSpeciesIdTable,
    #if P_GEN_8_CROSS_EVOS
        // Evolves after using Shadow Sneak 20 times (variants.md), as vanilla Wyrdeer does with
        // Psyshield Bash: it learns to slip between worlds.
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_WYRDEER_EIEN, CONDITIONS({IF_USED_MOVE_X_TIMES, MOVE_SHADOW_SNEAK, 20})}),
    #endif
    },

#if P_GEN_8_CROSS_EVOS
    [SPECIES_WYRDEER_EIEN] =
    {
        .baseHP        = 103,
        .baseAttack    = 115,
        .baseDefense   = 77,
        .baseSpeed     = 65,
        .baseSpAttack  = 90,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_DARK, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 263,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_FRISK, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Wyrdeer"),
        .cryId = CRY_WYRDEER,
        .natDexNum = NATIONAL_DEX_WYRDEER,
        // TODO(design): category, size and dex entry (placeholders, like the other Eien forms' drafts).
        .categoryName = _("Old Serow"),
        .height = 18,
        .weight = 951,
        .description = COMPOUND_STRING(
            "An old serow of the snowbound heights.\n"
            "Its antlers have grown like dead winter\n"
            "wood, and its beard trails away like\n"
            "mist. It is seen less every year."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        // Its own sprites, framed like the vanilla (non-GBA-style) ones
        .frontPic = sMonFrontPic_WyrdeerEien,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        // Two frames, unlike vanilla Wyrdeer's single one: the idle frame is drafted like the others'
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = sMonBackPic_WyrdeerEien,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = sMonPalette_WyrdeerEien,
        .shinyPalette = sMonShinyPalette_WyrdeerEien,
        .iconSprite = sMonIcon_WyrdeerEien,
        .iconPalIndex = 6,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 13, SHADOW_SIZE_M)
        FOOTPRINT(Wyrdeer)
        OVERWORLD(
            sPicTable_Wyrdeer,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Wyrdeer,
            gShinyOverworldPalette_Wyrdeer
        )
        .levelUpLearnset = sWyrdeerEienLevelUpLearnset,
        .teachableLearnset = sWyrdeerTeachableLearnset,
        .formSpeciesIdTable = sWyrdeerFormSpeciesIdTable,
    },
#endif //P_GEN_8_CROSS_EVOS
#endif //P_FAMILY_STANTLER

#if P_FAMILY_WINGULL
    [SPECIES_WINGULL_EIEN] =
    {
        .baseHP        = 40,
        .baseAttack    = 30,
        .baseDefense   = 30,
        .baseSpeed     = 70,
        .baseSpAttack  = 70,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_FLYING),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 54 : 64,
        .evYield_Speed = 1,
        .itemCommon = ITEM_PRETTY_FEATHER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FLYING),
        .abilities = { ABILITY_STATIC, ABILITY_KEEN_EYE, ABILITY_DRIZZLE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Wingull"),
        .cryId = CRY_WINGULL,
        .natDexNum = NATIONAL_DEX_WINGULL,
        // TODO(design): category, size and dex entry (placeholders, like the other Eien forms' drafts).
        .categoryName = _("Storm Gull"),
        .height = 6,
        .weight = 95,
        .description = COMPOUND_STRING(
            "It rides the winds ahead of a storm over\n"
            "the strait. Fishermen who see a flock of\n"
            "them turn their boats for home."),
        .pokemonScale = 295,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
        // The vanilla sprites in storm palettes until its own art is picked (variants.md)
        .frontPic = gMonFrontPic_Wingull,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 32) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 24 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 17),
            ANIMCMD_FRAME(1, 23),
            ANIMCMD_FRAME(0, 13),
        ),
        .frontAnimId = ANIM_H_PIVOT,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 16 : 15,
        .backPic = gMonBackPic_Wingull,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 13,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = sMonPalette_WingullEien,
        .shinyPalette = sMonShinyPalette_WingullEien,
        .iconSprite = gMonIcon_Wingull,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 15, SHADOW_SIZE_S)
        FOOTPRINT(Wingull)
        OVERWORLD(
            sPicTable_Wingull,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Wingull,
            gShinyOverworldPalette_Wingull
        )
        .levelUpLearnset = sWingullEienLevelUpLearnset,
        .teachableLearnset = sWingullTeachableLearnset,
        .eggMoveLearnset = sWingullEggMoveLearnset,
        .formSpeciesIdTable = sWingullFormSpeciesIdTable,
        // Evolves after landing 3 critical hits in one battle (variants.md): "struck by lightning",
        // as Galarian Farfetch'd does.
        .evolutions = EVOLUTION({EVO_BATTLE_END, 0, SPECIES_PELIPPER_EIEN, CONDITIONS({IF_CRITICAL_HITS_GE, 3})}),
    },    [SPECIES_PELIPPER_EIEN] =
    {
        .baseHP        = 60,
        .baseAttack    = 50,
        .baseDefense   = 85,
        .baseSpeed     = 65,
        .baseSpAttack  = 110,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_FLYING),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 154,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 151,
    #else
        .expYield = 164,
    #endif
        .evYield_Defense = 2,
        .itemCommon = ITEM_PRETTY_FEATHER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FLYING),
        .abilities = { ABILITY_STATIC, ABILITY_KEEN_EYE, ABILITY_DRIZZLE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Pelipper"),
        .cryId = CRY_PELIPPER,
        .natDexNum = NATIONAL_DEX_PELIPPER,
        // TODO(design): category, size and dex entry (placeholders, like the other Eien forms' drafts).
        .categoryName = _("Storm Gull"),
        .height = 12,
        .weight = 280,
        .description = COMPOUND_STRING(
            "Its bill holds a thundercloud instead\n"
            "of water. When it opens its mouth, the\n"
            "air crackles, and lightning follows."),
        .pokemonScale = 288,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        // The vanilla sprites in storm palettes until its own art is picked (variants.md)
        .frontPic = gMonFrontPic_Pelipper,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_Pelipper,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = sMonPalette_PelipperEien,
        .shinyPalette = sMonShinyPalette_PelipperEien,
        .iconSprite = gMonIcon_Pelipper,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 17, SHADOW_SIZE_M)
        FOOTPRINT(Pelipper)
        OVERWORLD(
            sPicTable_Pelipper,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Pelipper,
            gShinyOverworldPalette_Pelipper
        )
        .levelUpLearnset = sPelipperEienLevelUpLearnset,
        .teachableLearnset = sPelipperTeachableLearnset,
        .formSpeciesIdTable = sPelipperFormSpeciesIdTable,
    },
#endif //P_FAMILY_WINGULL
