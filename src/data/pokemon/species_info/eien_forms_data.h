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
static const u32 sMonFrontPic_CombuskenEien[] = INCGFX_U32("graphics/pokemon/eien/combusken/anim_front.png", ".4bpp.smol");
static const u32 sMonBackPic_CombuskenEien[] = INCGFX_U32("graphics/pokemon/eien/combusken/back.png", ".4bpp.smol");
static const u32 sMonFrontPic_IvysaurEien[] = INCGFX_U32("graphics/pokemon/eien/ivysaur/anim_front.png", ".4bpp.smol");
static const u32 sMonBackPic_IvysaurEien[] = INCGFX_U32("graphics/pokemon/eien/ivysaur/back.png", ".4bpp.smol");
static const u32 sMonFrontPic_FrogadierEien[] = INCGFX_U32("graphics/pokemon/eien/frogadier/anim_front.png", ".4bpp.smol");
static const u32 sMonBackPic_FrogadierEien[] = INCGFX_U32("graphics/pokemon/eien/frogadier/back.png", ".4bpp.smol");
static const u32 sMonFrontPic_MightyenaEien[] = INCGFX_U32("graphics/pokemon/eien/mightyena/anim_front.png", ".4bpp.smol");
static const u32 sMonBackPic_MightyenaEien[] = INCGFX_U32("graphics/pokemon/eien/mightyena/back.png", ".4bpp.smol");

// Icons (tools/eien_species/make_icons.py): the starters use the Eien icon palette (6).
static const u8 sMonIcon_TorchicEien[] = INCGFX_U8("graphics/pokemon/eien/torchic/icon.png", ".4bpp");
static const u8 sMonIcon_BulbasaurEien[] = INCGFX_U8("graphics/pokemon/eien/bulbasaur/icon.png", ".4bpp");
static const u8 sMonIcon_FroakieEien[] = INCGFX_U8("graphics/pokemon/eien/froakie/icon.png", ".4bpp");
static const u8 sMonIcon_CombuskenEien[] = INCGFX_U8("graphics/pokemon/eien/combusken/icon.png", ".4bpp");
static const u8 sMonIcon_IvysaurEien[] = INCGFX_U8("graphics/pokemon/eien/ivysaur/icon.png", ".4bpp");
static const u8 sMonIcon_FrogadierEien[] = INCGFX_U8("graphics/pokemon/eien/frogadier/icon.png", ".4bpp");
static const u8 sMonIcon_PoochyenaEien[] = INCGFX_U8("graphics/pokemon/eien/poochyena/icon.png", ".4bpp");
static const u8 sMonIcon_MightyenaEien[] = INCGFX_U8("graphics/pokemon/eien/mightyena/icon.png", ".4bpp");

// Middle stages: the picked AI fronts, idle frames, backs and shinies (convert_art.py); their
// icons are the vanilla ones recolored into the Eien icon palette (make_icons.py).
static const u16 sMonPalette_CombuskenEien[] = INCGFX_U16("graphics/pokemon/eien/combusken/normal.pal", ".gbapal");
static const u16 sMonShinyPalette_CombuskenEien[] = INCGFX_U16("graphics/pokemon/eien/combusken/shiny.pal", ".gbapal");
static const u16 sMonPalette_IvysaurEien[] = INCGFX_U16("graphics/pokemon/eien/ivysaur/normal.pal", ".gbapal");
static const u16 sMonShinyPalette_IvysaurEien[] = INCGFX_U16("graphics/pokemon/eien/ivysaur/shiny.pal", ".gbapal");
static const u16 sMonPalette_FrogadierEien[] = INCGFX_U16("graphics/pokemon/eien/frogadier/normal.pal", ".gbapal");
static const u16 sMonShinyPalette_FrogadierEien[] = INCGFX_U16("graphics/pokemon/eien/frogadier/shiny.pal", ".gbapal");

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

// Eien Wooper and Quagsire: the picked AI fronts, idle frames, backs and gold shinies
// (convert_art.py, design/art/eien_wooper_drafts.md); icons in vanilla icon palette 3.
static const u32 sMonFrontPic_WooperEien[] = INCGFX_U32("graphics/pokemon/eien/wooper/anim_front.png", ".4bpp.smol");
static const u32 sMonBackPic_WooperEien[] = INCGFX_U32("graphics/pokemon/eien/wooper/back.png", ".4bpp.smol");
static const u8 sMonIcon_WooperEien[] = INCGFX_U8("graphics/pokemon/eien/wooper/icon.png", ".4bpp");
static const u32 sMonFrontPic_QuagsireEien[] = INCGFX_U32("graphics/pokemon/eien/quagsire/anim_front.png", ".4bpp.smol");
static const u32 sMonBackPic_QuagsireEien[] = INCGFX_U32("graphics/pokemon/eien/quagsire/back.png", ".4bpp.smol");
static const u8 sMonIcon_QuagsireEien[] = INCGFX_U8("graphics/pokemon/eien/quagsire/icon.png", ".4bpp");
static const u16 sMonPalette_WooperEien[] = INCGFX_U16("graphics/pokemon/eien/wooper/normal.pal", ".gbapal");
static const u16 sMonShinyPalette_WooperEien[] = INCGFX_U16("graphics/pokemon/eien/wooper/shiny.pal", ".gbapal");
static const u16 sMonPalette_QuagsireEien[] = INCGFX_U16("graphics/pokemon/eien/quagsire/normal.pal", ".gbapal");
static const u16 sMonShinyPalette_QuagsireEien[] = INCGFX_U16("graphics/pokemon/eien/quagsire/shiny.pal", ".gbapal");

// Eien Hoothoot and Noctowl: the picked AI fronts, idle frames, backs and aurora shinies
// (convert_art.py, design/art/eien_hoothoot_drafts.md); icons in vanilla icon palette 2.
static const u32 sMonFrontPic_HoothootEien[] = INCGFX_U32("graphics/pokemon/eien/hoothoot/anim_front.png", ".4bpp.smol");
static const u32 sMonBackPic_HoothootEien[] = INCGFX_U32("graphics/pokemon/eien/hoothoot/back.png", ".4bpp.smol");
static const u8 sMonIcon_HoothootEien[] = INCGFX_U8("graphics/pokemon/eien/hoothoot/icon.png", ".4bpp");
static const u32 sMonFrontPic_NoctowlEien[] = INCGFX_U32("graphics/pokemon/eien/noctowl/anim_front.png", ".4bpp.smol");
static const u32 sMonBackPic_NoctowlEien[] = INCGFX_U32("graphics/pokemon/eien/noctowl/back.png", ".4bpp.smol");
static const u8 sMonIcon_NoctowlEien[] = INCGFX_U8("graphics/pokemon/eien/noctowl/icon.png", ".4bpp");
static const u16 sMonPalette_HoothootEien[] = INCGFX_U16("graphics/pokemon/eien/hoothoot/normal.pal", ".gbapal");
static const u16 sMonShinyPalette_HoothootEien[] = INCGFX_U16("graphics/pokemon/eien/hoothoot/shiny.pal", ".gbapal");
static const u16 sMonPalette_NoctowlEien[] = INCGFX_U16("graphics/pokemon/eien/noctowl/normal.pal", ".gbapal");
static const u16 sMonShinyPalette_NoctowlEien[] = INCGFX_U16("graphics/pokemon/eien/noctowl/shiny.pal", ".gbapal");

// The finals: the vanilla sprites in their line's placeholder palette until their art is picked.
static const u16 sMonPalette_BlazikenEien[] = INCGFX_U16("graphics/pokemon/eien/blaziken/normal.pal", ".gbapal");
static const u16 sMonShinyPalette_BlazikenEien[] = INCGFX_U16("graphics/pokemon/eien/blaziken/shiny.pal", ".gbapal");
static const u16 sMonPalette_VenusaurEien[] = INCGFX_U16("graphics/pokemon/eien/venusaur/normal.pal", ".gbapal");
static const u16 sMonShinyPalette_VenusaurEien[] = INCGFX_U16("graphics/pokemon/eien/venusaur/shiny.pal", ".gbapal");
static const u16 sMonPalette_GreninjaEien[] = INCGFX_U16("graphics/pokemon/eien/greninja/normal.pal", ".gbapal");
static const u16 sMonShinyPalette_GreninjaEien[] = INCGFX_U16("graphics/pokemon/eien/greninja/shiny.pal", ".gbapal");

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

// Middle stages: the evolution move at 0, the first stage's new moves at the same levels, then
// the vanilla middle stage's learnset.
static const struct LevelUpMove sCombuskenEienLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 0, MOVE_FIERY_DANCE),
    LEVEL_UP_MOVE( 1, MOVE_FLAMETHROWER),
    LEVEL_UP_MOVE( 1, MOVE_FEATHER_DANCE),
    LEVEL_UP_MOVE( 1, MOVE_SCRATCH),
    LEVEL_UP_MOVE( 1, MOVE_GROWL),
    LEVEL_UP_MOVE( 1, MOVE_EMBER),
    LEVEL_UP_MOVE( 1, MOVE_QUICK_ATTACK),
    LEVEL_UP_MOVE( 5, MOVE_ASTONISH),
    LEVEL_UP_MOVE( 9, MOVE_FLAME_CHARGE),
    LEVEL_UP_MOVE(12, MOVE_DETECT),
    LEVEL_UP_MOVE(14, MOVE_WILL_O_WISP),
    LEVEL_UP_MOVE(15, MOVE_SAND_ATTACK),
    LEVEL_UP_MOVE(20, MOVE_AERIAL_ACE),
    LEVEL_UP_MOVE(25, MOVE_SLASH),
    LEVEL_UP_MOVE(30, MOVE_BOUNCE),
    LEVEL_UP_MOVE(35, MOVE_FOCUS_ENERGY),
    LEVEL_UP_MOVE(40, MOVE_BLAZE_KICK),
    LEVEL_UP_MOVE(45, MOVE_BULK_UP),
    LEVEL_UP_MOVE(50, MOVE_REVERSAL),
    LEVEL_UP_MOVE(55, MOVE_FLARE_BLITZ),
    LEVEL_UP_END
};

static const struct LevelUpMove sIvysaurEienLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 0, MOVE_PSYBEAM),
    LEVEL_UP_MOVE( 1, MOVE_TACKLE),
    LEVEL_UP_MOVE( 1, MOVE_GROWL),
    LEVEL_UP_MOVE( 1, MOVE_GROWTH),
    LEVEL_UP_MOVE( 7, MOVE_CONFUSION),
    LEVEL_UP_MOVE( 9, MOVE_LEECH_SEED),
    LEVEL_UP_MOVE(10, MOVE_VINE_WHIP),
    LEVEL_UP_MOVE(12, MOVE_RAZOR_LEAF),
    LEVEL_UP_MOVE(15, MOVE_POISON_POWDER),
    LEVEL_UP_MOVE(15, MOVE_SLEEP_POWDER),
    LEVEL_UP_MOVE(20, MOVE_SEED_BOMB),
    LEVEL_UP_MOVE(25, MOVE_TAKE_DOWN),
    LEVEL_UP_MOVE(30, MOVE_SWEET_SCENT),
    LEVEL_UP_MOVE(35, MOVE_SYNTHESIS),
    LEVEL_UP_MOVE(40, MOVE_WORRY_SEED),
    LEVEL_UP_MOVE(45, MOVE_POWER_WHIP),
    LEVEL_UP_MOVE(50, MOVE_SOLAR_BEAM),
    LEVEL_UP_END
};

static const struct LevelUpMove sFrogadierEienLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 0, MOVE_ICY_WIND),
    LEVEL_UP_MOVE( 1, MOVE_POUND),
    LEVEL_UP_MOVE( 1, MOVE_GROWL),
    LEVEL_UP_MOVE( 5, MOVE_POWDER_SNOW),
    LEVEL_UP_MOVE( 5, MOVE_WATER_GUN),
    LEVEL_UP_MOVE( 8, MOVE_QUICK_ATTACK),
    LEVEL_UP_MOVE(10, MOVE_LICK),
    LEVEL_UP_MOVE(14, MOVE_WATER_PULSE),
    LEVEL_UP_MOVE(15, MOVE_ICE_SHARD),
    LEVEL_UP_MOVE(19, MOVE_SMOKESCREEN),
    LEVEL_UP_MOVE(23, MOVE_ROUND),
    LEVEL_UP_MOVE(28, MOVE_FLING),
    LEVEL_UP_MOVE(33, MOVE_SMACK_DOWN),
    LEVEL_UP_MOVE(40, MOVE_SUBSTITUTE),
    LEVEL_UP_MOVE(45, MOVE_BOUNCE),
    LEVEL_UP_MOVE(50, MOVE_DOUBLE_TEAM),
    LEVEL_UP_MOVE(56, MOVE_HYDRO_PUMP),
    LEVEL_UP_END
};

// The finals (brainstorm-eien-starters-finals.md): the evolution move at 0, the line's new moves
// carried, a signature move at Lv 42; otherwise vanilla.
static const struct LevelUpMove sBlazikenEienLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 0, MOVE_SHADOW_BALL),
    LEVEL_UP_MOVE( 1, MOVE_BLAZE_KICK),
    LEVEL_UP_MOVE( 1, MOVE_FIERY_DANCE),
    LEVEL_UP_MOVE( 1, MOVE_FIRE_PUNCH),
    LEVEL_UP_MOVE( 1, MOVE_EMBER),
    LEVEL_UP_MOVE( 1, MOVE_FLAMETHROWER),
    LEVEL_UP_MOVE( 1, MOVE_FEATHER_DANCE),
    LEVEL_UP_MOVE( 1, MOVE_SCRATCH),
    LEVEL_UP_MOVE( 1, MOVE_GROWL),
    LEVEL_UP_MOVE( 1, MOVE_QUICK_ATTACK),
    LEVEL_UP_MOVE( 5, MOVE_ASTONISH),
    LEVEL_UP_MOVE( 9, MOVE_FLAME_CHARGE),
    LEVEL_UP_MOVE(12, MOVE_DETECT),
    LEVEL_UP_MOVE(14, MOVE_WILL_O_WISP),
    LEVEL_UP_MOVE(15, MOVE_SAND_ATTACK),
    LEVEL_UP_MOVE(20, MOVE_AERIAL_ACE),
    LEVEL_UP_MOVE(25, MOVE_SLASH),
    LEVEL_UP_MOVE(30, MOVE_BOUNCE),
    LEVEL_UP_MOVE(35, MOVE_FOCUS_ENERGY),
    LEVEL_UP_MOVE(42, MOVE_INFERNAL_PARADE),
    LEVEL_UP_MOVE(42, MOVE_BULK_UP),
    LEVEL_UP_MOVE(49, MOVE_REVERSAL),
    LEVEL_UP_MOVE(56, MOVE_FLARE_BLITZ),
    LEVEL_UP_MOVE(63, MOVE_BRAVE_BIRD),
    LEVEL_UP_END
};

static const struct LevelUpMove sVenusaurEienLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 0, MOVE_PSYCHIC),
    LEVEL_UP_MOVE( 1, MOVE_PETAL_BLIZZARD),
    LEVEL_UP_MOVE( 1, MOVE_PSYBEAM),
    LEVEL_UP_MOVE( 1, MOVE_GROWTH),
    LEVEL_UP_MOVE( 1, MOVE_PETAL_DANCE),
    LEVEL_UP_MOVE( 1, MOVE_TACKLE),
    LEVEL_UP_MOVE( 1, MOVE_GROWL),
    LEVEL_UP_MOVE( 7, MOVE_CONFUSION),
    LEVEL_UP_MOVE( 9, MOVE_LEECH_SEED),
    LEVEL_UP_MOVE(10, MOVE_VINE_WHIP),
    LEVEL_UP_MOVE(12, MOVE_RAZOR_LEAF),
    LEVEL_UP_MOVE(15, MOVE_SLEEP_POWDER),
    LEVEL_UP_MOVE(15, MOVE_POISON_POWDER),
    LEVEL_UP_MOVE(20, MOVE_SEED_BOMB),
    LEVEL_UP_MOVE(25, MOVE_TAKE_DOWN),
    LEVEL_UP_MOVE(30, MOVE_SWEET_SCENT),
    LEVEL_UP_MOVE(37, MOVE_SYNTHESIS),
    LEVEL_UP_MOVE(42, MOVE_LUMINA_CRASH),
    LEVEL_UP_MOVE(44, MOVE_WORRY_SEED),
    LEVEL_UP_MOVE(51, MOVE_POWER_WHIP),
    LEVEL_UP_MOVE(58, MOVE_SOLAR_BEAM),
    LEVEL_UP_END
};

static const struct LevelUpMove sGreninjaEienLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 0, MOVE_FREEZE_DRY),
    LEVEL_UP_MOVE( 1, MOVE_WATER_SHURIKEN),
    LEVEL_UP_MOVE( 1, MOVE_ICY_WIND),
    LEVEL_UP_MOVE( 1, MOVE_NIGHT_SLASH),
    LEVEL_UP_MOVE( 1, MOVE_ROLE_PLAY),
    LEVEL_UP_MOVE( 1, MOVE_HAZE),
    LEVEL_UP_MOVE( 1, MOVE_POUND),
    LEVEL_UP_MOVE( 1, MOVE_GROWL),
    LEVEL_UP_MOVE( 1, MOVE_QUICK_ATTACK),
    LEVEL_UP_MOVE( 5, MOVE_POWDER_SNOW),
    LEVEL_UP_MOVE( 5, MOVE_WATER_GUN),
    LEVEL_UP_MOVE(10, MOVE_LICK),
    LEVEL_UP_MOVE(14, MOVE_WATER_PULSE),
    LEVEL_UP_MOVE(15, MOVE_ICE_SHARD),
    LEVEL_UP_MOVE(19, MOVE_SMOKESCREEN),
    LEVEL_UP_MOVE(23, MOVE_SHADOW_SNEAK),
    LEVEL_UP_MOVE(28, MOVE_SPIKES),
    LEVEL_UP_MOVE(33, MOVE_AERIAL_ACE),
    LEVEL_UP_MOVE(42, MOVE_TRIPLE_AXEL),
    LEVEL_UP_MOVE(42, MOVE_SUBSTITUTE),
    LEVEL_UP_MOVE(49, MOVE_EXTRASENSORY),
    LEVEL_UP_MOVE(56, MOVE_DOUBLE_TEAM),
    LEVEL_UP_MOVE(68, MOVE_HYDRO_PUMP),
    LEVEL_UP_END
};

static const struct LevelUpMove sWooperEienLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 1, MOVE_TAIL_WHIP),
    LEVEL_UP_MOVE( 1, MOVE_MUD_SLAP),
    LEVEL_UP_MOVE( 4, MOVE_RAIN_DANCE),
    LEVEL_UP_MOVE( 8, MOVE_MUD_SHOT),
    LEVEL_UP_MOVE(12, MOVE_MIST),
    LEVEL_UP_MOVE(12, MOVE_HAZE),
    LEVEL_UP_MOVE(16, MOVE_METAL_CLAW),
    LEVEL_UP_MOVE(21, MOVE_YAWN),
    LEVEL_UP_MOVE(24, MOVE_AQUA_TAIL),
    LEVEL_UP_MOVE(28, MOVE_MUDDY_WATER),
    LEVEL_UP_MOVE(32, MOVE_AMNESIA),
    LEVEL_UP_MOVE(36, MOVE_TOXIC),
    LEVEL_UP_MOVE(40, MOVE_EARTHQUAKE),
    LEVEL_UP_END
};

static const struct LevelUpMove sQuagsireEienLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 0, MOVE_IRON_HEAD),
    LEVEL_UP_MOVE( 1, MOVE_TAIL_WHIP),
    LEVEL_UP_MOVE( 1, MOVE_MUD_SLAP),
    LEVEL_UP_MOVE( 1, MOVE_RAIN_DANCE),
    LEVEL_UP_MOVE( 1, MOVE_MUD_SHOT),
    LEVEL_UP_MOVE(12, MOVE_MIST),
    LEVEL_UP_MOVE(12, MOVE_HAZE),
    LEVEL_UP_MOVE(16, MOVE_METAL_CLAW),
    LEVEL_UP_MOVE(23, MOVE_YAWN),
    LEVEL_UP_MOVE(28, MOVE_AQUA_TAIL),
    LEVEL_UP_MOVE(34, MOVE_MUDDY_WATER),
    LEVEL_UP_MOVE(40, MOVE_AMNESIA),
    LEVEL_UP_MOVE(46, MOVE_TOXIC),
    LEVEL_UP_MOVE(52, MOVE_EARTHQUAKE),
    LEVEL_UP_END
};

static const struct LevelUpMove sHoothootEienLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 1, MOVE_GROWL),
    LEVEL_UP_MOVE( 1, MOVE_PECK),
    LEVEL_UP_MOVE( 1, MOVE_ASTONISH),
    LEVEL_UP_MOVE( 3, MOVE_TACKLE),
    LEVEL_UP_MOVE( 6, MOVE_GUST),
    LEVEL_UP_MOVE( 9, MOVE_CONFUSION),
    LEVEL_UP_MOVE(12, MOVE_REFLECT),
    LEVEL_UP_MOVE(15, MOVE_OMINOUS_WIND),
    LEVEL_UP_MOVE(18, MOVE_AIR_SLASH),
    LEVEL_UP_MOVE(21, MOVE_EXTRASENSORY),
    LEVEL_UP_MOVE(24, MOVE_TAKE_DOWN),
    LEVEL_UP_MOVE(27, MOVE_UPROAR),
    LEVEL_UP_MOVE(30, MOVE_ROOST),
    LEVEL_UP_MOVE(33, MOVE_MOONBLAST),
    LEVEL_UP_MOVE(36, MOVE_HYPNOSIS),
    LEVEL_UP_MOVE(39, MOVE_DREAM_EATER),
    LEVEL_UP_END
};

static const struct LevelUpMove sNoctowlEienLevelUpLearnset[] = {
    LEVEL_UP_MOVE( 0, MOVE_HEX),
    LEVEL_UP_MOVE( 1, MOVE_TACKLE),
    LEVEL_UP_MOVE( 1, MOVE_GROWL),
    LEVEL_UP_MOVE( 1, MOVE_PECK),
    LEVEL_UP_MOVE( 1, MOVE_ASTONISH),
    LEVEL_UP_MOVE( 1, MOVE_SKY_ATTACK),
    LEVEL_UP_MOVE( 1, MOVE_GUST),
    LEVEL_UP_MOVE( 9, MOVE_CONFUSION),
    LEVEL_UP_MOVE(12, MOVE_REFLECT),
    LEVEL_UP_MOVE(15, MOVE_OMINOUS_WIND),
    LEVEL_UP_MOVE(18, MOVE_AIR_SLASH),
    LEVEL_UP_MOVE(23, MOVE_EXTRASENSORY),
    LEVEL_UP_MOVE(28, MOVE_TAKE_DOWN),
    LEVEL_UP_MOVE(33, MOVE_UPROAR),
    LEVEL_UP_MOVE(38, MOVE_ROOST),
    LEVEL_UP_MOVE(43, MOVE_MOONBLAST),
    LEVEL_UP_MOVE(48, MOVE_HYPNOSIS),
    LEVEL_UP_MOVE(53, MOVE_DREAM_EATER),
    LEVEL_UP_END
};

// Form tables: the original species and its Eien form.
static const u16 sTorchicFormSpeciesIdTable[] = { SPECIES_TORCHIC, SPECIES_TORCHIC_EIEN, FORM_SPECIES_END };
static const u16 sBulbasaurFormSpeciesIdTable[] = { SPECIES_BULBASAUR, SPECIES_BULBASAUR_EIEN, FORM_SPECIES_END };
static const u16 sFroakieFormSpeciesIdTable[] = { SPECIES_FROAKIE, SPECIES_FROAKIE_EIEN, FORM_SPECIES_END };
static const u16 sPoochyenaFormSpeciesIdTable[] = { SPECIES_POOCHYENA, SPECIES_POOCHYENA_EIEN, FORM_SPECIES_END };
static const u16 sMightyenaFormSpeciesIdTable[] = { SPECIES_MIGHTYENA, SPECIES_MIGHTYENA_EIEN, FORM_SPECIES_END };
static const u16 sCombuskenFormSpeciesIdTable[] = { SPECIES_COMBUSKEN, SPECIES_COMBUSKEN_EIEN, FORM_SPECIES_END };
static const u16 sIvysaurFormSpeciesIdTable[] = { SPECIES_IVYSAUR, SPECIES_IVYSAUR_EIEN, FORM_SPECIES_END };
static const u16 sFrogadierFormSpeciesIdTable[] = { SPECIES_FROGADIER, SPECIES_FROGADIER_EIEN, FORM_SPECIES_END };
// (Eien Wooper is in sWooperFormSpeciesIdTable, form_species_tables.h, with Paldean Wooper.)
static const u16 sQuagsireFormSpeciesIdTable[] = { SPECIES_QUAGSIRE, SPECIES_QUAGSIRE_EIEN, FORM_SPECIES_END };
static const u16 sHoothootFormSpeciesIdTable[] = { SPECIES_HOOTHOOT, SPECIES_HOOTHOOT_EIEN, FORM_SPECIES_END };
static const u16 sNoctowlFormSpeciesIdTable[] = { SPECIES_NOCTOWL, SPECIES_NOCTOWL_EIEN, FORM_SPECIES_END };
