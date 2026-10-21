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
