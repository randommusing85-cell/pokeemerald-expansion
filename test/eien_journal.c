#include "global.h"
#include "eien_journal.h"
#include "eien_quests.h"
#include "event_data.h"
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
