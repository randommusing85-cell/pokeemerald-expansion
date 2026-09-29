#include "global.h"
#include "eien_quests.h"
#include "event_data.h"
#include "test/overworld_script.h"
#include "test/test.h"

static void ClearEienQuests(void)
{
    memset(&gSaveBlock1Ptr->eienQuests, 0, sizeof(gSaveBlock1Ptr->eienQuests));
}

TEST("(Eien quests) setquest and checkquest store a quest's state")
{
    ClearEienQuests();
    EXPECT_EQ(GetQuestState(QUEST_HARU_MAP), QUEST_STATE_NONE);
    RUN_OVERWORLD_SCRIPT(
        setquest QUEST_HARU_MAP, QUEST_STATE_OPEN;
        checkquest QUEST_HARU_MAP;
    );
    EXPECT_EQ(gSpecialVar_Result, QUEST_STATE_OPEN);
    EXPECT_EQ(GetQuestState(QUEST_HARU_MAP), QUEST_STATE_OPEN);
    EXPECT_EQ(GetQuestState(QUEST_AKIRA_PRACTICE), QUEST_STATE_NONE);
}

TEST("(Eien quests) a quest's state and step don't overwrite each other")
{
    ClearEienQuests();
    RUN_OVERWORLD_SCRIPT(
        setquest QUEST_RESEARCH_POOCHYENA, QUEST_STATE_OPEN;
        setqueststep QUEST_RESEARCH_POOCHYENA, 5;
        setquest QUEST_RESEARCH_POOCHYENA, QUEST_STATE_CLOSED;
        checkqueststep QUEST_RESEARCH_POOCHYENA;
    );
    EXPECT_EQ(gSpecialVar_Result, 5);
    EXPECT_EQ(GetQuestState(QUEST_RESEARCH_POOCHYENA), QUEST_STATE_CLOSED);
    SetQuestStep(QUEST_RESEARCH_POOCHYENA, 100);
    EXPECT_EQ(GetQuestStep(QUEST_RESEARCH_POOCHYENA), QUEST_STEP_MAX);
    EXPECT_EQ(GetQuestState(QUEST_RESEARCH_POOCHYENA), QUEST_STATE_CLOSED);
}

TEST("(Eien quests) arguments can be vars")
{
    ClearEienQuests();
    RUN_OVERWORLD_SCRIPT(
        setvar VAR_TEMP_0, QUEST_AKIRA_PRACTICE;
        setvar VAR_TEMP_1, QUEST_STATE_DONE;
        setquest VAR_TEMP_0, VAR_TEMP_1;
    );
    EXPECT_EQ(GetQuestState(QUEST_AKIRA_PRACTICE), QUEST_STATE_DONE);
}

TEST("(Eien quests) relationship points add up and stay within 0-255")
{
    ClearEienQuests();
    RUN_OVERWORLD_SCRIPT(
        addpoints PERSON_HARU, 10;
        addpoints PERSON_HARU, 5;
        checkpoints PERSON_HARU;
    );
    EXPECT_EQ(gSpecialVar_Result, 15);
    RUN_OVERWORLD_SCRIPT(
        removepoints PERSON_HARU, 20;
        addpoints PERSON_AKIRA, 200;
        addpoints PERSON_AKIRA, 200;
    );
    EXPECT_EQ(GetRelationshipPoints(PERSON_HARU), 0);
    EXPECT_EQ(GetRelationshipPoints(PERSON_AKIRA), RELATIONSHIP_POINTS_MAX);
    EXPECT_EQ(GetRelationshipPoints(PERSON_NAMI), 0);
}

TEST("(Eien quests) letters are set and cleared per person")
{
    ClearEienQuests();
    RUN_OVERWORLD_SCRIPT(
        setletter PERSON_KAEDE, TRUE;
        setletter PERSON_REN, TRUE;
        setletter PERSON_REN, FALSE;
        checkletter PERSON_KAEDE;
    );
    EXPECT_EQ(gSpecialVar_Result, TRUE);
    EXPECT_EQ(HasLetterFrom(PERSON_REN), FALSE);
    EXPECT_EQ(HasLetterFrom(PERSON_HARU), FALSE);
}

TEST("(Eien quests) out-of-range ids are ignored")
{
    ClearEienQuests();
    SetQuestState(EIEN_QUEST_CAPACITY, QUEST_STATE_OPEN);
    AddRelationshipPoints(EIEN_PERSON_CAPACITY, 10);
    SetLetterFrom(EIEN_PERSON_CAPACITY, TRUE);
    EXPECT_EQ(GetQuestState(EIEN_QUEST_CAPACITY), QUEST_STATE_NONE);
    EXPECT_EQ(GetRelationshipPoints(EIEN_PERSON_CAPACITY), 0);
    EXPECT_EQ(gSaveBlock1Ptr->eienQuests.letters, 0);
}
