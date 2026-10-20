#include "global.h"
#include "eien_quests.h"
#include "test/battle.h"

// Eien: research tiers set by battles (design/locations/route-1.md, QUEST_RESEARCH_POOCHYENA).
// The tier bits match RESEARCH_TIER_* in src/data/eien_journal.h.
#define SEEN    (1 << 0)
#define BATTLED (1 << 1)
#define CAUGHT  (1 << 2)

WILD_BATTLE_TEST("Eien research: catching an Eien Poochyena marks it seen, battled and caught")
{
    GIVEN {
        SetQuestStep(QUEST_RESEARCH_POOCHYENA, 0);
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_7);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_POOCHYENA_EIEN);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_MASTER_BALL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW, player);
    } THEN {
        EXPECT_EQ(GetQuestStep(QUEST_RESEARCH_POOCHYENA), SEEN | BATTLED | CAUGHT);
    }
}

WILD_BATTLE_TEST("Eien research: knocking out an Eien Poochyena marks it seen and battled")
{
    GIVEN {
        SetQuestStep(QUEST_RESEARCH_POOCHYENA, 0);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_POOCHYENA_EIEN) { HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("The wild Poochyena fainted!");
    } THEN {
        EXPECT_EQ(GetQuestStep(QUEST_RESEARCH_POOCHYENA), SEEN | BATTLED);
    }
}

WILD_BATTLE_TEST("Eien research: a regular Poochyena doesn't count")
{
    GIVEN {
        SetQuestStep(QUEST_RESEARCH_POOCHYENA, 0);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_POOCHYENA) { HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("The wild Poochyena fainted!");
    } THEN {
        EXPECT_EQ(GetQuestStep(QUEST_RESEARCH_POOCHYENA), 0);
    }
}

AI_SINGLE_BATTLE_TEST("Eien research: a trainer's Eien Poochyena counts once it faints")
{
    GIVEN {
        SetQuestStep(QUEST_RESEARCH_POOCHYENA, 0);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_POOCHYENA_EIEN) { HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        MESSAGE("The opposing Poochyena fainted!");
    } THEN {
        EXPECT_EQ(GetQuestStep(QUEST_RESEARCH_POOCHYENA), SEEN | BATTLED);
    }
}

WILD_BATTLE_TEST("Eien research: catching an Eien Wooper marks it seen, battled and caught")
{
    GIVEN {
        SetQuestStep(QUEST_RESEARCH_WOOPER, 0);
        WITH_CONFIG(B_MISSING_BADGE_CATCH_MALUS, GEN_7);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOOPER_EIEN);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_MASTER_BALL); }
    } SCENE {
        ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW, player);
    } THEN {
        EXPECT_EQ(GetQuestStep(QUEST_RESEARCH_WOOPER), SEEN | BATTLED | CAUGHT);
    }
}
