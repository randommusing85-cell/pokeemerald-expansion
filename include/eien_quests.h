#ifndef GUARD_EIEN_QUESTS_H
#define GUARD_EIEN_QUESTS_H

#include "constants/eien_quests.h"

u32 GetQuestState(u32 quest);
void SetQuestState(u32 quest, u32 state);
u32 GetQuestStep(u32 quest);
void SetQuestStep(u32 quest, u32 step);

u32 GetRelationshipPoints(u32 person);
void AddRelationshipPoints(u32 person, s32 amount);

bool32 HasLetterFrom(u32 person);
void SetLetterFrom(u32 person, bool32 pending);

// Script natives, called by the macros in asm/macros/event.inc.
struct ScriptContext;
void ScrCmd_setquest(struct ScriptContext *ctx);
void ScrCmd_checkquest(struct ScriptContext *ctx);
void ScrCmd_setqueststep(struct ScriptContext *ctx);
void ScrCmd_checkqueststep(struct ScriptContext *ctx);
void ScrCmd_addpoints(struct ScriptContext *ctx);
void ScrCmd_removepoints(struct ScriptContext *ctx);
void ScrCmd_checkpoints(struct ScriptContext *ctx);
void ScrCmd_setletter(struct ScriptContext *ctx);
void ScrCmd_checkletter(struct ScriptContext *ctx);

#endif // GUARD_EIEN_QUESTS_H
