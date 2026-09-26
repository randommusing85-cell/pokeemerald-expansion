// Eien's quest table and relationship points (design/side-quests.md).
//
// Each quest is one byte in the save: bits 0-1 are its state (QUEST_STATE_*), bits 2-7 its
// step (0-63), which the journal's log uses. Each person has one byte of points (0-255)
// and a bit for a pending letter. Scripts reach this through the macros in
// asm/macros/event.inc (setquest, checkquest, addpoints, removepoints, ...).

#include "global.h"
#include "eien_quests.h"
#include "event_data.h"
#include "script.h"

#define STATE_MASK  0x03
#define STEP_SHIFT  2

STATIC_ASSERT(QUEST_COUNT <= EIEN_QUEST_CAPACITY, EienQuestCapacity);
STATIC_ASSERT(PERSON_COUNT <= EIEN_PERSON_CAPACITY, EienPersonCapacity);

u32 GetQuestState(u32 quest)
{
    if (quest >= EIEN_QUEST_CAPACITY)
        return QUEST_STATE_NONE;
    return gSaveBlock1Ptr->eienQuests.quests[quest] & STATE_MASK;
}

void SetQuestState(u32 quest, u32 state)
{
    u8 *entry;

    if (quest >= EIEN_QUEST_CAPACITY)
        return;
    entry = &gSaveBlock1Ptr->eienQuests.quests[quest];
    *entry = (*entry & ~STATE_MASK) | (state & STATE_MASK);
}

u32 GetQuestStep(u32 quest)
{
    if (quest >= EIEN_QUEST_CAPACITY)
        return 0;
    return gSaveBlock1Ptr->eienQuests.quests[quest] >> STEP_SHIFT;
}

void SetQuestStep(u32 quest, u32 step)
{
    u8 *entry;

    if (quest >= EIEN_QUEST_CAPACITY)
        return;
    if (step > QUEST_STEP_MAX)
        step = QUEST_STEP_MAX;
    entry = &gSaveBlock1Ptr->eienQuests.quests[quest];
    *entry = (*entry & STATE_MASK) | (step << STEP_SHIFT);
}

u32 GetRelationshipPoints(u32 person)
{
    if (person >= EIEN_PERSON_CAPACITY)
        return 0;
    return gSaveBlock1Ptr->eienQuests.points[person];
}

void AddRelationshipPoints(u32 person, s32 amount)
{
    s32 points;

    if (person >= EIEN_PERSON_CAPACITY)
        return;
    points = gSaveBlock1Ptr->eienQuests.points[person] + amount;
    if (points < 0)
        points = 0;
    if (points > RELATIONSHIP_POINTS_MAX)
        points = RELATIONSHIP_POINTS_MAX;
    gSaveBlock1Ptr->eienQuests.points[person] = points;
}

bool32 HasLetterFrom(u32 person)
{
    if (person >= EIEN_PERSON_CAPACITY)
        return FALSE;
    return (gSaveBlock1Ptr->eienQuests.letters >> person) & 1;
}

void SetLetterFrom(u32 person, bool32 pending)
{
    if (person >= EIEN_PERSON_CAPACITY)
        return;
    if (pending)
        gSaveBlock1Ptr->eienQuests.letters |= 1 << person;
    else
        gSaveBlock1Ptr->eienQuests.letters &= ~(1 << person);
}

// Script natives. Arguments go through VarGet, so a script can pass a number or a var.

void ScrCmd_setquest(struct ScriptContext *ctx)
{
    u32 quest = VarGet(ScriptReadHalfword(ctx));
    u32 state = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    SetQuestState(quest, state);
}

void ScrCmd_checkquest(struct ScriptContext *ctx)
{
    u32 quest = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1);
    gSpecialVar_Result = GetQuestState(quest);
}

void ScrCmd_setqueststep(struct ScriptContext *ctx)
{
    u32 quest = VarGet(ScriptReadHalfword(ctx));
    u32 step = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    SetQuestStep(quest, step);
}

void ScrCmd_checkqueststep(struct ScriptContext *ctx)
{
    u32 quest = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1);
    gSpecialVar_Result = GetQuestStep(quest);
}

// Amounts are positive: a negative number would read as a var id, so subtracting has its
// own command.
void ScrCmd_addpoints(struct ScriptContext *ctx)
{
    u32 person = VarGet(ScriptReadHalfword(ctx));
    u32 amount = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    AddRelationshipPoints(person, amount);
}

void ScrCmd_removepoints(struct ScriptContext *ctx)
{
    u32 person = VarGet(ScriptReadHalfword(ctx));
    u32 amount = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    AddRelationshipPoints(person, -(s32)amount);
}

void ScrCmd_checkpoints(struct ScriptContext *ctx)
{
    u32 person = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1);
    gSpecialVar_Result = GetRelationshipPoints(person);
}

void ScrCmd_setletter(struct ScriptContext *ctx)
{
    u32 person = VarGet(ScriptReadHalfword(ctx));
    u32 pending = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    SetLetterFrom(person, pending);
}

void ScrCmd_checkletter(struct ScriptContext *ctx)
{
    u32 person = VarGet(ScriptReadHalfword(ctx));

    Script_RequestEffects(SCREFF_V1);
    gSpecialVar_Result = HasLetterFrom(person);
}
