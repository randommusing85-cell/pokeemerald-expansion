#include "global.h"
#include "event_data.h"
#include "test/battle.h"

// Eien: the thin-place effect (design/game-bible.md, Eien weather and terrain).

SINGLE_BATTLE_TEST("Thin place: a message at the start of battle")
{
    SetStartingStatus(STARTING_STATUS_THIN_PLACE);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        MESSAGE("The air feels thin here…");
    } THEN {
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Thin place: Ghost and Psychic moves do 30% more damage", s16 damage)
{
    enum Move move;
    bool32 thinPlace;

    // Low-power moves, like the engine's Psychic Terrain test, so rounding stays within 1.
    PARAMETRIZE { move = MOVE_ASTONISH;  thinPlace = FALSE; }
    PARAMETRIZE { move = MOVE_ASTONISH;  thinPlace = TRUE; }
    PARAMETRIZE { move = MOVE_CONFUSION; thinPlace = FALSE; }
    PARAMETRIZE { move = MOVE_CONFUSION; thinPlace = TRUE; }

    ResetStartingStatuses();
    if (thinPlace)
        SetStartingStatus(STARTING_STATUS_THIN_PLACE);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        if (thinPlace)
            MESSAGE("The air feels thin here…");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        ResetStartingStatuses();
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(1.3), results[3].damage);
    }
}

SINGLE_BATTLE_TEST("Thin place: other types are not boosted", s16 damage)
{
    bool32 thinPlace;

    PARAMETRIZE { thinPlace = FALSE; }
    PARAMETRIZE { thinPlace = TRUE; }

    ResetStartingStatuses();
    if (thinPlace)
        SetStartingStatus(STARTING_STATUS_THIN_PLACE);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        ResetStartingStatuses();
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Thin place: boosts the opponent's moves too", s16 damage)
{
    bool32 thinPlace;

    PARAMETRIZE { thinPlace = FALSE; }
    PARAMETRIZE { thinPlace = TRUE; }

    ResetStartingStatuses();
    if (thinPlace)
        SetStartingStatus(STARTING_STATUS_THIN_PLACE);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSION); }
    } SCENE {
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        ResetStartingStatuses();
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3), results[1].damage);
    }
}
