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
#define QUEST_KAEDE_TABLETS        3  // E7 / Kaede 1: shrine tablets read; one step bit per tablet
#define QUEST_RESEARCH_WOOPER      4  // E2: the professor's list, Eien Wooper (shown after gym 2)
#define QUEST_RESEARCH_HOOTHOOT    5  // E2: the professor's list, Eien Hoothoot (shown after gym 1)
#define QUEST_RESEARCH_LEDYBA      6  // E2: the professor's list, Eien Ledyba (shown after gym 3)
#define QUEST_RESEARCH_STANTLER    7  // E2: the professor's list, Eien Stantler (shown after gym 5)
#define QUEST_COUNT                8

// QUEST_KAEDE_TABLETS step bits. Reading a tablet sets its bit even before Kaede opens the
// quest. A step has 6 bits; more tablets than that need a second quest entry.
#define TABLET_ROUTE1_SHRINE   0

// QUEST_HARU_MAP step bits: the three places on Route 1.
#define HARU_MAP_COAST         0
#define HARU_MAP_FIELDS        1
#define HARU_MAP_SHRINE        2

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
