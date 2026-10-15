#include "global.h"
#include "eien_journal.h"
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
TEST("(Eien species) Eien Poochyena evolves at Lv 18 only at the Route 1 shrine")
{
    u32 map, level;
    struct Pokemon mon;

    PARAMETRIZE { map = MAP_EIEN_ROUTE1_SHRINE; level = 18; }
    PARAMETRIZE { map = MAP_EIEN_ROUTE1_SHRINE; level = 17; }
    PARAMETRIZE { map = MAP_EIEN_ROUTE1;        level = 18; }

    gSaveBlock1Ptr->location.mapGroup = MAP_GROUP(map);
    gSaveBlock1Ptr->location.mapNum = MAP_NUM(map);
    CreateMon(&mon, SPECIES_POOCHYENA_EIEN, level, 0, OTID_STRUCT_PRESET(0));
    EXPECT_EQ(GetEvolutionTargetSpecies(&mon, EVO_MODE_NORMAL, ITEM_NONE, NULL, NULL, CHECK_EVO),
              (map == MAP_EIEN_ROUTE1_SHRINE && level >= 18) ? SPECIES_MIGHTYENA_EIEN : SPECIES_NONE);
}
