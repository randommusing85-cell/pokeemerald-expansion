// Eien regional forms (design/variants.md): data the species entries in eien_families.h
// point to. Included by species_info.h before gSpeciesInfo.

// Sprites from the chosen AI drafts (tools/eien_species/convert_art.py); the back sprites are
// placeholders (the original backs in the new colors).
static const u32 sMonFrontPic_TorchicEien[] = INCGFX_U32("graphics/pokemon/eien/torchic/anim_front.png", ".4bpp.smol");
static const u32 sMonBackPic_TorchicEien[] = INCGFX_U32("graphics/pokemon/eien/torchic/back.png", ".4bpp.smol");
static const u32 sMonFrontPic_BulbasaurEien[] = INCGFX_U32("graphics/pokemon/eien/bulbasaur/anim_front.png", ".4bpp.smol");
static const u32 sMonBackPic_BulbasaurEien[] = INCGFX_U32("graphics/pokemon/eien/bulbasaur/back.png", ".4bpp.smol");
static const u32 sMonFrontPic_FroakieEien[] = INCGFX_U32("graphics/pokemon/eien/froakie/anim_front.png", ".4bpp.smol");
static const u32 sMonBackPic_FroakieEien[] = INCGFX_U32("graphics/pokemon/eien/froakie/back.png", ".4bpp.smol");
static const u32 sMonFrontPic_PoochyenaEien[] = INCGFX_U32("graphics/pokemon/eien/poochyena/anim_front.png", ".4bpp.smol");
static const u32 sMonBackPic_PoochyenaEien[] = INCGFX_U32("graphics/pokemon/eien/poochyena/back.png", ".4bpp.smol");
static const u32 sMonFrontPic_MightyenaEien[] = INCGFX_U32("graphics/pokemon/eien/mightyena/anim_front.png", ".4bpp.smol");
static const u32 sMonBackPic_MightyenaEien[] = INCGFX_U32("graphics/pokemon/eien/mightyena/back.png", ".4bpp.smol");

// Icons (tools/eien_species/make_icons.py): the starters use the Eien icon palette (6).
static const u8 sMonIcon_TorchicEien[] = INCGFX_U8("graphics/pokemon/eien/torchic/icon.png", ".4bpp");
static const u8 sMonIcon_BulbasaurEien[] = INCGFX_U8("graphics/pokemon/eien/bulbasaur/icon.png", ".4bpp");
static const u8 sMonIcon_FroakieEien[] = INCGFX_U8("graphics/pokemon/eien/froakie/icon.png", ".4bpp");
static const u8 sMonIcon_PoochyenaEien[] = INCGFX_U8("graphics/pokemon/eien/poochyena/icon.png", ".4bpp");

static const u16 sMonPalette_TorchicEien[] = INCGFX_U16("graphics/pokemon/eien/torchic/normal.pal", ".gbapal");
static const u16 sMonShinyPalette_TorchicEien[] = INCGFX_U16("graphics/pokemon/eien/torchic/shiny.pal", ".gbapal");
static const u16 sMonPalette_BulbasaurEien[] = INCGFX_U16("graphics/pokemon/eien/bulbasaur/normal.pal", ".gbapal");
static const u16 sMonShinyPalette_BulbasaurEien[] = INCGFX_U16("graphics/pokemon/eien/bulbasaur/shiny.pal", ".gbapal");
static const u16 sMonPalette_FroakieEien[] = INCGFX_U16("graphics/pokemon/eien/froakie/normal.pal", ".gbapal");
static const u16 sMonShinyPalette_FroakieEien[] = INCGFX_U16("graphics/pokemon/eien/froakie/shiny.pal", ".gbapal");
static const u16 sMonPalette_PoochyenaEien[] = INCGFX_U16("graphics/pokemon/eien/poochyena/normal.pal", ".gbapal");
static const u16 sMonShinyPalette_PoochyenaEien[] = INCGFX_U16("graphics/pokemon/eien/poochyena/shiny.pal", ".gbapal");
static const u16 sMonPalette_MightyenaEien[] = INCGFX_U16("graphics/pokemon/eien/mightyena/normal.pal", ".gbapal");
static const u16 sMonShinyPalette_MightyenaEien[] = INCGFX_U16("graphics/pokemon/eien/mightyena/shiny.pal", ".gbapal");

// Level-up learnsets: the original's, plus the new-type moves in variants.md.
static const struct LevelUpMove sTorchicEienLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 1, MOVE_SCRATCH),
    LEVEL_UP_MOVE( 1, MOVE_GROWL),
    LEVEL_UP_MOVE( 3, MOVE_EMBER),
    LEVEL_UP_MOVE( 5, MOVE_ASTONISH),
    LEVEL_UP_MOVE( 6, MOVE_QUICK_ATTACK),
    LEVEL_UP_MOVE( 9, MOVE_FLAME_CHARGE),
    LEVEL_UP_MOVE(12, MOVE_DETECT),
    LEVEL_UP_MOVE(14, MOVE_WILL_O_WISP),
    LEVEL_UP_MOVE(15, MOVE_SAND_ATTACK),
    LEVEL_UP_MOVE(18, MOVE_AERIAL_ACE),
    LEVEL_UP_MOVE(21, MOVE_SLASH),
    LEVEL_UP_MOVE(24, MOVE_BOUNCE),
    LEVEL_UP_MOVE(27, MOVE_FOCUS_ENERGY),
    LEVEL_UP_MOVE(30, MOVE_FLAMETHROWER),
    LEVEL_UP_MOVE(33, MOVE_FEATHER_DANCE),
    LEVEL_UP_MOVE(36, MOVE_REVERSAL),
    LEVEL_UP_MOVE(39, MOVE_FLARE_BLITZ),
    LEVEL_UP_END
};

// Confusion takes Vine Whip's early slot; Vine Whip moves later.
static const struct LevelUpMove sBulbasaurEienLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 1, MOVE_TACKLE),
    LEVEL_UP_MOVE( 1, MOVE_GROWL),
    LEVEL_UP_MOVE( 6, MOVE_GROWTH),
    LEVEL_UP_MOVE( 7, MOVE_CONFUSION),
    LEVEL_UP_MOVE( 9, MOVE_LEECH_SEED),
    LEVEL_UP_MOVE(10, MOVE_VINE_WHIP),
    LEVEL_UP_MOVE(12, MOVE_RAZOR_LEAF),
    LEVEL_UP_MOVE(15, MOVE_POISON_POWDER),
    LEVEL_UP_MOVE(15, MOVE_SLEEP_POWDER),
    LEVEL_UP_MOVE(18, MOVE_SEED_BOMB),
    LEVEL_UP_MOVE(21, MOVE_TAKE_DOWN),
    LEVEL_UP_MOVE(24, MOVE_SWEET_SCENT),
    LEVEL_UP_MOVE(27, MOVE_SYNTHESIS),
    LEVEL_UP_MOVE(30, MOVE_WORRY_SEED),
    LEVEL_UP_MOVE(33, MOVE_POWER_WHIP),
    LEVEL_UP_MOVE(36, MOVE_SOLAR_BEAM),
    LEVEL_UP_END
};

static const struct LevelUpMove sFroakieEienLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 1, MOVE_POUND),
    LEVEL_UP_MOVE( 1, MOVE_GROWL),
    LEVEL_UP_MOVE( 5, MOVE_POWDER_SNOW),
    LEVEL_UP_MOVE( 5, MOVE_WATER_GUN),
    LEVEL_UP_MOVE( 8, MOVE_QUICK_ATTACK),
    LEVEL_UP_MOVE(10, MOVE_LICK),
    LEVEL_UP_MOVE(14, MOVE_WATER_PULSE),
    LEVEL_UP_MOVE(15, MOVE_ICE_SHARD),
    LEVEL_UP_MOVE(18, MOVE_SMOKESCREEN),
    LEVEL_UP_MOVE(21, MOVE_ROUND),
    LEVEL_UP_MOVE(25, MOVE_FLING),
    LEVEL_UP_MOVE(29, MOVE_SMACK_DOWN),
    LEVEL_UP_MOVE(35, MOVE_SUBSTITUTE),
    LEVEL_UP_MOVE(39, MOVE_BOUNCE),
    LEVEL_UP_MOVE(43, MOVE_DOUBLE_TEAM),
    LEVEL_UP_MOVE(48, MOVE_HYDRO_PUMP),
    LEVEL_UP_END
};

static const struct LevelUpMove sPoochyenaEienLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 1, MOVE_TACKLE),
    LEVEL_UP_MOVE( 4, MOVE_HOWL),
    LEVEL_UP_MOVE( 7, MOVE_ROCK_THROW),
    LEVEL_UP_MOVE( 7, MOVE_SAND_ATTACK),
    LEVEL_UP_MOVE(10, MOVE_BITE),
    LEVEL_UP_MOVE(13, MOVE_LEER),
    LEVEL_UP_MOVE(16, MOVE_ROCK_TOMB),
    LEVEL_UP_MOVE(16, MOVE_ROAR),
    LEVEL_UP_MOVE(19, MOVE_SWAGGER),
    LEVEL_UP_MOVE(22, MOVE_ASSURANCE),
    LEVEL_UP_MOVE(25, MOVE_SCARY_FACE),
    LEVEL_UP_MOVE(28, MOVE_TAUNT),
    LEVEL_UP_MOVE(31, MOVE_CRUNCH),
    LEVEL_UP_MOVE(34, MOVE_YAWN),
    LEVEL_UP_MOVE(36, MOVE_TAKE_DOWN),
    LEVEL_UP_MOVE(40, MOVE_SUCKER_PUNCH),
    LEVEL_UP_MOVE(44, MOVE_PLAY_ROUGH),
    LEVEL_UP_END
};

// Eien Mightyena: Rock Slide on evolving; Eien Poochyena's Rock moves, then vanilla Mightyena's.
static const struct LevelUpMove sMightyenaEienLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 0, MOVE_ROCK_SLIDE),
    LEVEL_UP_MOVE( 1, MOVE_CRUNCH),
    LEVEL_UP_MOVE( 1, MOVE_FIRE_FANG),
    LEVEL_UP_MOVE( 1, MOVE_ICE_FANG),
    LEVEL_UP_MOVE( 1, MOVE_THUNDER_FANG),
    LEVEL_UP_MOVE( 1, MOVE_THIEF),
    LEVEL_UP_MOVE( 1, MOVE_SAND_ATTACK),
    LEVEL_UP_MOVE( 1, MOVE_BITE),
    LEVEL_UP_MOVE( 1, MOVE_TACKLE),
    LEVEL_UP_MOVE( 7, MOVE_ROCK_THROW),
    LEVEL_UP_MOVE(13, MOVE_HOWL),
    LEVEL_UP_MOVE(13, MOVE_LEER),
    LEVEL_UP_MOVE(16, MOVE_ROCK_TOMB),
    LEVEL_UP_MOVE(16, MOVE_ROAR),
    LEVEL_UP_MOVE(20, MOVE_SWAGGER),
    LEVEL_UP_MOVE(24, MOVE_ASSURANCE),
    LEVEL_UP_MOVE(28, MOVE_SCARY_FACE),
    LEVEL_UP_MOVE(36, MOVE_TAUNT),
    LEVEL_UP_MOVE(44, MOVE_YAWN),
    LEVEL_UP_MOVE(48, MOVE_TAKE_DOWN),
    LEVEL_UP_MOVE(52, MOVE_SUCKER_PUNCH),
    LEVEL_UP_MOVE(56, MOVE_PLAY_ROUGH),
    LEVEL_UP_END
};

// Form tables: the original species and its Eien form.
static const u16 sTorchicFormSpeciesIdTable[] = { SPECIES_TORCHIC, SPECIES_TORCHIC_EIEN, FORM_SPECIES_END };
static const u16 sBulbasaurFormSpeciesIdTable[] = { SPECIES_BULBASAUR, SPECIES_BULBASAUR_EIEN, FORM_SPECIES_END };
static const u16 sFroakieFormSpeciesIdTable[] = { SPECIES_FROAKIE, SPECIES_FROAKIE_EIEN, FORM_SPECIES_END };
static const u16 sPoochyenaFormSpeciesIdTable[] = { SPECIES_POOCHYENA, SPECIES_POOCHYENA_EIEN, FORM_SPECIES_END };
static const u16 sMightyenaFormSpeciesIdTable[] = { SPECIES_MIGHTYENA, SPECIES_MIGHTYENA_EIEN, FORM_SPECIES_END };
