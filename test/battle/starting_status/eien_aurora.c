#include "global.h"
#include "test/battle.h"

// Eien: the aurora in battle (design/game-bible.md, Eien weather and terrain).

SINGLE_BATTLE_TEST("Aurora: one message at the start of battle, not the rainbow's")
{
    SetStartingStatus(STARTING_STATUS_AURORA);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        NONE_OF {
            MESSAGE("A rainbow appeared in the sky on your side!");
            MESSAGE("A rainbow appeared in the sky on the opposing side!");
        }
        MESSAGE("An aurora shimmers in the sky!");
    } THEN {
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Aurora: moves' secondary effects are twice as likely, for both sides")
{
    bool32 aurora, playerAttacks;

    // Poison Fang's 50% becomes 100%, so it poisons even when the roll fails.
    PARAMETRIZE { aurora = FALSE; playerAttacks = TRUE; }
    PARAMETRIZE { aurora = TRUE;  playerAttacks = TRUE; }
    PARAMETRIZE { aurora = FALSE; playerAttacks = FALSE; }
    PARAMETRIZE { aurora = TRUE;  playerAttacks = FALSE; }

    ResetStartingStatuses();
    if (aurora)
        SetStartingStatus(STARTING_STATUS_AURORA);

    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_POISON_FANG, MOVE_EFFECT_TOXIC) == TRUE);
        ASSUME(GetMoveAdditionalEffectById(MOVE_POISON_FANG, 0)->chance == 50);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (playerAttacks)
            TURN { MOVE(player, MOVE_POISON_FANG, WITH_RNG(RNG_SECONDARY_EFFECT, FALSE)); }
        else
            TURN { MOVE(opponent, MOVE_POISON_FANG, WITH_RNG(RNG_SECONDARY_EFFECT, FALSE)); }
    } SCENE {
        if (playerAttacks)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_FANG, player);
            if (aurora)
                MESSAGE("The opposing Wobbuffet was badly poisoned!");
            else
                NOT MESSAGE("The opposing Wobbuffet was badly poisoned!");
        }
        else
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_FANG, opponent);
            if (aurora)
                MESSAGE("Wobbuffet was badly poisoned!");
            else
                NOT MESSAGE("Wobbuffet was badly poisoned!");
        }
    } THEN {
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Aurora: lasts the whole battle")
{
    SetStartingStatus(STARTING_STATUS_AURORA);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("An aurora shimmers in the sky!");
        NONE_OF {
            MESSAGE("The rainbow on your side disappeared!");
            MESSAGE("The rainbow on the opposing side disappeared!");
        }
    } THEN {
        EXPECT(gSideStatuses[B_SIDE_PLAYER] & SIDE_STATUS_RAINBOW);
        EXPECT(gSideStatuses[B_SIDE_OPPONENT] & SIDE_STATUS_RAINBOW);
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Aurora: works together with a thin place")
{
    SetStartingStatus(STARTING_STATUS_THIN_PLACE);
    SetStartingStatus(STARTING_STATUS_AURORA);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } SCENE {
        MESSAGE("The air feels thin here…");
        MESSAGE("An aurora shimmers in the sky!");
    } THEN {
        EXPECT(gFieldStatuses & STATUS_FIELD_THIN_PLACE);
        EXPECT(gSideStatuses[B_SIDE_PLAYER] & SIDE_STATUS_RAINBOW);
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Aurora: makes a temporary Rainbow from another starting status permanent")
{
    SetStartingStatus(STARTING_STATUS_RAINBOW_PLAYER_TEMPORARY);
    SetStartingStatus(STARTING_STATUS_RAINBOW_OPPONENT_TEMPORARY);
    SetStartingStatus(STARTING_STATUS_AURORA);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("An aurora shimmers in the sky!");
        NONE_OF {
            MESSAGE("The rainbow on your side disappeared!");
            MESSAGE("The rainbow on the opposing side disappeared!");
        }
    } THEN {
        EXPECT(gSideStatuses[B_SIDE_PLAYER] & SIDE_STATUS_RAINBOW);
        EXPECT(gSideStatuses[B_SIDE_OPPONENT] & SIDE_STATUS_RAINBOW);
        ResetStartingStatuses();
    }
}
