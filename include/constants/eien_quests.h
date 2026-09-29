#ifndef GUARD_CONSTANTS_EIEN_QUESTS_H
#define GUARD_CONSTANTS_EIEN_QUESTS_H

// Eien's quest table and relationship points (design/side-quests.md). The data lives in
// gSaveBlock1Ptr->eienQuests; scripts use setquest / checkquest / addpoints / ... from
// asm/macros/event.inc. Only #defines here: this file is included by scripts too.

// Room reserved in the save: quests can grow to Unbound's scale without a save change.
#define EIEN_QUEST_CAPACITY    128
#define EIEN_PERSON_CAPACITY   16

// A quest's state. Each quest also has a step (0-63) for its log.
#define QUEST_STATE_NONE       0  // not started (not shown in the journal)
#define QUEST_STATE_OPEN       1
#define QUEST_STATE_DONE       2
#define QUEST_STATE_CLOSED     3  // missed for good (greyed in the journal)
#define QUEST_STEP_MAX         63

// Quests. Append new ones at the end and never renumber: saves store them by number.
#define QUEST_HARU_MAP             0  // Haru 1: note three places on Route 1 for his map
#define QUEST_RESEARCH_POOCHYENA   1  // E1: the professor's Eien Poochyena research
#define QUEST_AKIRA_PRACTICE       2  // Akira 1: a practice battle in Shimotsuki
#define QUEST_COUNT                3

// People with relationship points. Append only, never renumber.
#define PERSON_NAMI    0
#define PERSON_HARU    1
#define PERSON_YUKI    2
#define PERSON_KAEDE   3
#define PERSON_TETSU   4
#define PERSON_REN     5
#define PERSON_AKIRA   6
#define PERSON_COUNT   7

#define RELATIONSHIP_POINTS_MAX  255

#endif // GUARD_CONSTANTS_EIEN_QUESTS_H
