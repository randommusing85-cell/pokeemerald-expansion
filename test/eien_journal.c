#include "global.h"
#include "eien_journal.h"
#include "eien_quests.h"
#include "event_data.h"
#include "field_weather.h"
#include "constants/weather.h"
#include "pokemon.h"
#include "test/overworld_script.h"
#include "test/test.h"

// Eien: the journal's note on Eien Poochyena not evolving (design/variants.md).

TEST("(Eien journal) the no-evolution note needs an Eien Poochyena at Lv 18+ in the party")
{
    u32 species, level;

    PARAMETRIZE { species = SPECIES_POOCHYENA_EIEN; level = 17; }
    PARAMETRIZE { species = SPECIES_POOCHYENA_EIEN; level = 18; }
    PARAMETRIZE { species = SPECIES_POOCHYENA_EIEN; level = 30; }
    PARAMETRIZE { species = SPECIES_POOCHYENA;      level = 30; }

    ZeroPlayerPartyMons();
    FlagClear(FLAG_JOURNAL_POOCHYENA_NO_EVO);
    VarSet(VAR_TEMP_0, species);
    VarSet(VAR_TEMP_1, level);
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_WOBBUFFET, 50;
        givemon VAR_TEMP_0, VAR_TEMP_1;
    );
    UpdateJournalNotes();
    EXPECT_EQ(FlagGet(FLAG_JOURNAL_POOCHYENA_NO_EVO), species == SPECIES_POOCHYENA_EIEN && level >= 18);
}

TEST("(Eien journal) the no-evolution note stays once noted")
{
    ZeroPlayerPartyMons();
    FlagClear(FLAG_JOURNAL_POOCHYENA_NO_EVO);
    RUN_OVERWORLD_SCRIPT(givemon SPECIES_POOCHYENA_EIEN, 18;);
    UpdateJournalNotes();
    EXPECT(FlagGet(FLAG_JOURNAL_POOCHYENA_NO_EVO));
    ZeroPlayerPartyMons();
    UpdateJournalNotes();
    EXPECT(FlagGet(FLAG_JOURNAL_POOCHYENA_NO_EVO));
}

// Eien Poochyena evolves only in a shrine area (design/variants.md, "Shrine areas").
TEST("(Eien species) Eien Poochyena evolves at Lv 18 only at a shrine")
{
    u32 map, level, shrine;
    struct Pokemon mon;

    PARAMETRIZE { map = MAP_EIEN_ROUTE1_SHRINE;      level = 18; shrine = TRUE; }
    PARAMETRIZE { map = MAP_EIEN_ROUTE1_SHRINE;      level = 17; shrine = TRUE; }
    PARAMETRIZE { map = MAP_SHIMOTSUKI_KAEDE_SHRINE; level = 18; shrine = TRUE; }
    PARAMETRIZE { map = MAP_EIEN_ROUTE1;             level = 18; shrine = FALSE; }
    PARAMETRIZE { map = MAP_SHIMOTSUKI;              level = 18; shrine = FALSE; }

    gSaveBlock1Ptr->location.mapGroup = MAP_GROUP(map);
    gSaveBlock1Ptr->location.mapNum = MAP_NUM(map);
    CreateMon(&mon, SPECIES_POOCHYENA_EIEN, level, 0, OTID_STRUCT_PRESET(0));
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, NULL, CHECK_EVO),
              (shrine && level >= 18) ? SPECIES_MIGHTYENA_EIEN : SPECIES_NONE);
}

// The Eien starters evolve at Lv 18 into their Eien middle stages (design/variants.md).
TEST("(Eien species) the Eien starters evolve at Lv 18 into their Eien middle stages")
{
    u32 species, evolved, level;
    struct Pokemon mon;

    PARAMETRIZE { species = SPECIES_TORCHIC_EIEN;   evolved = SPECIES_COMBUSKEN_EIEN; level = 18; }
    PARAMETRIZE { species = SPECIES_BULBASAUR_EIEN; evolved = SPECIES_IVYSAUR_EIEN;   level = 18; }
    PARAMETRIZE { species = SPECIES_FROAKIE_EIEN;   evolved = SPECIES_FROGADIER_EIEN; level = 18; }
    PARAMETRIZE { species = SPECIES_TORCHIC_EIEN;   evolved = SPECIES_NONE;           level = 17; }
    PARAMETRIZE { species = SPECIES_BULBASAUR_EIEN; evolved = SPECIES_NONE;           level = 17; }
    PARAMETRIZE { species = SPECIES_FROAKIE_EIEN;   evolved = SPECIES_NONE;           level = 17; }

    CreateMon(&mon, species, level, 0, OTID_STRUCT_PRESET(0));
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, NULL, CHECK_EVO), evolved);
}

TEST("(Eien species) the Eien middle stages keep their Eien typing")
{
    u32 species, type1, type2;

    PARAMETRIZE { species = SPECIES_COMBUSKEN_EIEN; type1 = TYPE_FIRE;  type2 = TYPE_GHOST; }
    PARAMETRIZE { species = SPECIES_IVYSAUR_EIEN;   type1 = TYPE_GRASS; type2 = TYPE_PSYCHIC; }
    PARAMETRIZE { species = SPECIES_FROGADIER_EIEN; type1 = TYPE_WATER; type2 = TYPE_ICE; }

    EXPECT_EQ(GetSpeciesType(species, 0), type1);
    EXPECT_EQ(GetSpeciesType(species, 1), type2);
}

TEST("(Eien journal) the Wooper note needs an Eien Wooper at Lv 20+ in the party")
{
    u32 species, level;

    PARAMETRIZE { species = SPECIES_WOOPER_EIEN; level = 19; }
    PARAMETRIZE { species = SPECIES_WOOPER_EIEN; level = 20; }
    PARAMETRIZE { species = SPECIES_WOOPER;      level = 30; }

    ZeroPlayerPartyMons();
    FlagClear(FLAG_JOURNAL_WOOPER_NO_EVO);
    VarSet(VAR_TEMP_0, species);
    VarSet(VAR_TEMP_1, level);
    RUN_OVERWORLD_SCRIPT(givemon VAR_TEMP_0, VAR_TEMP_1;);
    UpdateJournalNotes();
    EXPECT_EQ(FlagGet(FLAG_JOURNAL_WOOPER_NO_EVO), species == SPECIES_WOOPER_EIEN && level >= 20);
}

// Eien Wooper evolves only in the Route 3 mine tunnel, which isn't built yet (design/variants.md).
TEST("(Eien species) Eien Wooper doesn't evolve outside the mine tunnel")
{
    u32 map;
    struct Pokemon mon;

    PARAMETRIZE { map = MAP_EIEN_ROUTE2; }
    PARAMETRIZE { map = MAP_YUNOTAKI; }

    gSaveBlock1Ptr->location.mapGroup = MAP_GROUP(map);
    gSaveBlock1Ptr->location.mapNum = MAP_NUM(map);
    CreateMon(&mon, SPECIES_WOOPER_EIEN, 30, 0, OTID_STRUCT_PRESET(0));
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, NULL, CHECK_EVO), SPECIES_NONE);
}

TEST("(Eien species) Eien Wooper and Quagsire are Ground/Steel")
{
    u32 species;

    PARAMETRIZE { species = SPECIES_WOOPER_EIEN; }
    PARAMETRIZE { species = SPECIES_QUAGSIRE_EIEN; }

    EXPECT_EQ(GetSpeciesType(species, 0), TYPE_GROUND);
    EXPECT_EQ(GetSpeciesType(species, 1), TYPE_STEEL);
}

TEST("(Eien journal) the Hoothoot note needs an Eien Hoothoot at Lv 20+ in the party")
{
    u32 species, level;

    PARAMETRIZE { species = SPECIES_HOOTHOOT_EIEN; level = 19; }
    PARAMETRIZE { species = SPECIES_HOOTHOOT_EIEN; level = 20; }
    PARAMETRIZE { species = SPECIES_HOOTHOOT;      level = 30; }

    ZeroPlayerPartyMons();
    FlagClear(FLAG_JOURNAL_HOOTHOOT_NO_EVO);
    VarSet(VAR_TEMP_0, species);
    VarSet(VAR_TEMP_1, level);
    RUN_OVERWORLD_SCRIPT(givemon VAR_TEMP_0, VAR_TEMP_1;);
    UpdateJournalNotes();
    EXPECT_EQ(FlagGet(FLAG_JOURNAL_HOOTHOOT_NO_EVO), species == SPECIES_HOOTHOOT_EIEN && level >= 20);
}

// Eien Hoothoot evolves only at night on Route 2's upper map, which isn't built yet (variants.md).
TEST("(Eien species) Eien Hoothoot doesn't evolve yet")
{
    u32 map;
    struct Pokemon mon;

    PARAMETRIZE { map = MAP_EIEN_ROUTE2; }
    PARAMETRIZE { map = MAP_YUNOTAKI; }

    gSaveBlock1Ptr->location.mapGroup = MAP_GROUP(map);
    gSaveBlock1Ptr->location.mapNum = MAP_NUM(map);
    CreateMon(&mon, SPECIES_HOOTHOOT_EIEN, 30, 0, OTID_STRUCT_PRESET(0));
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, NULL, CHECK_EVO), SPECIES_NONE);
}

TEST("(Eien species) Eien Hoothoot and Noctowl are Ghost/Flying")
{
    u32 species;

    PARAMETRIZE { species = SPECIES_HOOTHOOT_EIEN; }
    PARAMETRIZE { species = SPECIES_NOCTOWL_EIEN; }

    EXPECT_EQ(GetSpeciesType(species, 0), TYPE_GHOST);
    EXPECT_EQ(GetSpeciesType(species, 1), TYPE_FLYING);
}

// The professor's list (side-quests E2): each entry shows once its region's badge is held.
TEST("(Eien journal) the professor's list shows each entry after its region's badge")
{
    u32 quest, badge;

    PARAMETRIZE { quest = QUEST_RESEARCH_HOOTHOOT; badge = FLAG_BADGE01_GET; }
    PARAMETRIZE { quest = QUEST_RESEARCH_WOOPER;   badge = FLAG_BADGE02_GET; }
    PARAMETRIZE { quest = QUEST_RESEARCH_LEDYBA;   badge = FLAG_BADGE03_GET; }
    PARAMETRIZE { quest = QUEST_RESEARCH_STANTLER; badge = FLAG_BADGE05_GET; }

    SetQuestState(quest, QUEST_STATE_NONE);
    FlagClear(badge);
    EXPECT(!IsQuestShownInJournal(quest));
    SetQuestState(quest, QUEST_STATE_OPEN);
    EXPECT(!IsQuestShownInJournal(quest));
    FlagSet(badge);
    EXPECT(IsQuestShownInJournal(quest));
    FlagClear(badge);
}

TEST("(Eien journal) Poochyena's research shows as soon as it's open")
{
    SetQuestState(QUEST_RESEARCH_POOCHYENA, QUEST_STATE_NONE);
    EXPECT(!IsQuestShownInJournal(QUEST_RESEARCH_POOCHYENA));
    SetQuestState(QUEST_RESEARCH_POOCHYENA, QUEST_STATE_OPEN);
    EXPECT(IsQuestShownInJournal(QUEST_RESEARCH_POOCHYENA));
}

// The Eien middle stages evolve at Lv 36 into their Eien finals (design/variants.md).
TEST("(Eien species) the Eien middle stages evolve at Lv 36 into their Eien finals")
{
    u32 species, evolved, level;
    struct Pokemon mon;

    PARAMETRIZE { species = SPECIES_COMBUSKEN_EIEN; evolved = SPECIES_BLAZIKEN_EIEN; level = 36; }
    PARAMETRIZE { species = SPECIES_IVYSAUR_EIEN;   evolved = SPECIES_VENUSAUR_EIEN; level = 36; }
    PARAMETRIZE { species = SPECIES_FROGADIER_EIEN; evolved = SPECIES_GRENINJA_EIEN; level = 36; }
    PARAMETRIZE { species = SPECIES_COMBUSKEN_EIEN; evolved = SPECIES_NONE;          level = 35; }
    PARAMETRIZE { species = SPECIES_IVYSAUR_EIEN;   evolved = SPECIES_NONE;          level = 35; }
    PARAMETRIZE { species = SPECIES_FROGADIER_EIEN; evolved = SPECIES_NONE;          level = 35; }

    CreateMon(&mon, species, level, 0, OTID_STRUCT_PRESET(0));
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, NULL, CHECK_EVO), evolved);
}

TEST("(Eien species) the Eien finals keep their Eien typing")
{
    u32 species, type1, type2;

    PARAMETRIZE { species = SPECIES_BLAZIKEN_EIEN; type1 = TYPE_FIRE;  type2 = TYPE_GHOST; }
    PARAMETRIZE { species = SPECIES_VENUSAUR_EIEN; type1 = TYPE_GRASS; type2 = TYPE_PSYCHIC; }
    PARAMETRIZE { species = SPECIES_GRENINJA_EIEN; type1 = TYPE_WATER; type2 = TYPE_ICE; }

    EXPECT_EQ(GetSpeciesType(species, 0), type1);
    EXPECT_EQ(GetSpeciesType(species, 1), type2);
}

TEST("(Eien journal) the Ledyba note needs an Eien Ledyba at Lv 18+ in the party")
{
    u32 species, level;

    PARAMETRIZE { species = SPECIES_LEDYBA_EIEN; level = 17; }
    PARAMETRIZE { species = SPECIES_LEDYBA_EIEN; level = 18; }
    PARAMETRIZE { species = SPECIES_LEDYBA;      level = 30; }

    ZeroPlayerPartyMons();
    FlagClear(FLAG_JOURNAL_LEDYBA_NO_EVO);
    VarSet(VAR_TEMP_0, species);
    VarSet(VAR_TEMP_1, level);
    RUN_OVERWORLD_SCRIPT(givemon VAR_TEMP_0, VAR_TEMP_1;);
    UpdateJournalNotes();
    EXPECT_EQ(FlagGet(FLAG_JOURNAL_LEDYBA_NO_EVO), species == SPECIES_LEDYBA_EIEN && level >= 18);
}

// Eien Ledyba evolves at Lv 18+ only while it's raining (design/variants.md).
TEST("(Eien species) Eien Ledyba evolves at Lv 18 only in the rain")
{
    u32 weather, level, evolves;
    struct Pokemon mon;

    PARAMETRIZE { weather = WEATHER_RAIN;               level = 18; evolves = TRUE; }
    PARAMETRIZE { weather = WEATHER_RAIN_THUNDERSTORM;  level = 20; evolves = TRUE; }
    PARAMETRIZE { weather = WEATHER_RAIN;               level = 17; evolves = FALSE; }
    PARAMETRIZE { weather = WEATHER_NONE;               level = 18; evolves = FALSE; }
    PARAMETRIZE { weather = WEATHER_SNOW;               level = 18; evolves = FALSE; }

    gWeatherPtr->currWeather = weather;
    CreateMon(&mon, SPECIES_LEDYBA_EIEN, level, 0, OTID_STRUCT_PRESET(0));
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, NULL, CHECK_EVO),
              evolves ? SPECIES_LEDIAN_EIEN : SPECIES_NONE);
    gWeatherPtr->currWeather = WEATHER_NONE;
}

TEST("(Eien species) Eien Ledyba and Ledian are Bug/Fire")
{
    u32 species;

    PARAMETRIZE { species = SPECIES_LEDYBA_EIEN; }
    PARAMETRIZE { species = SPECIES_LEDIAN_EIEN; }

    EXPECT_EQ(GetSpeciesType(species, 0), TYPE_BUG);
    EXPECT_EQ(GetSpeciesType(species, 1), TYPE_FIRE);
}

// A save made after the lab scene still gets research entries added to the list later.
TEST("(Eien journal) list entries added later open once the professor's list was given")
{
    u32 given;

    PARAMETRIZE { given = TRUE; }
    PARAMETRIZE { given = FALSE; }

    ZeroPlayerPartyMons();
    SetQuestState(QUEST_RESEARCH_POOCHYENA, given ? QUEST_STATE_OPEN : QUEST_STATE_NONE);
    SetQuestState(QUEST_RESEARCH_LEDYBA, QUEST_STATE_NONE);
    SetQuestState(QUEST_RESEARCH_HOOTHOOT, QUEST_STATE_DONE);
    UpdateJournalNotes();
    EXPECT_EQ(GetQuestState(QUEST_RESEARCH_LEDYBA), given ? QUEST_STATE_OPEN : QUEST_STATE_NONE);
    EXPECT_EQ(GetQuestState(QUEST_RESEARCH_HOOTHOOT), QUEST_STATE_DONE);
}

TEST("(Eien journal) the Stantler hint needs an Eien Stantler at Lv 38+ in the party")
{
    u32 species, level;

    PARAMETRIZE { species = SPECIES_STANTLER_EIEN; level = 37; }
    PARAMETRIZE { species = SPECIES_STANTLER_EIEN; level = 38; }
    PARAMETRIZE { species = SPECIES_STANTLER;      level = 50; }

    ZeroPlayerPartyMons();
    FlagClear(FLAG_JOURNAL_STANTLER_NO_EVO);
    VarSet(VAR_TEMP_0, species);
    VarSet(VAR_TEMP_1, level);
    RUN_OVERWORLD_SCRIPT(givemon VAR_TEMP_0, VAR_TEMP_1;);
    UpdateJournalNotes();
    EXPECT_EQ(FlagGet(FLAG_JOURNAL_STANTLER_NO_EVO), species == SPECIES_STANTLER_EIEN && level >= 38);
}

// Eien Stantler evolves after using Shadow Sneak 20 times (design/variants.md).
TEST("(Eien species) Eien Stantler evolves after using Shadow Sneak 20 times")
{
    u32 uses, evolves;
    struct Pokemon mon;

    // The tracker counts Shadow Sneak uses in battle (test/battle/eien_research.c)
    PARAMETRIZE { uses = 20; evolves = TRUE; }
    PARAMETRIZE { uses = 19; evolves = FALSE; }

    CreateMon(&mon, SPECIES_STANTLER_EIEN, 40, 0, OTID_STRUCT_PRESET(0));
    SetMonData(&mon, MON_DATA_EVOLUTION_TRACKER, &uses);
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, NULL, CHECK_EVO),
              evolves ? SPECIES_WYRDEER_EIEN : SPECIES_NONE);
}

TEST("(Eien species) Eien Stantler and Wyrdeer are Dark/Ghost")
{
    u32 species;

    PARAMETRIZE { species = SPECIES_STANTLER_EIEN; }
    PARAMETRIZE { species = SPECIES_WYRDEER_EIEN; }

    EXPECT_EQ(GetSpeciesType(species, 0), TYPE_DARK);
    EXPECT_EQ(GetSpeciesType(species, 1), TYPE_GHOST);
}
