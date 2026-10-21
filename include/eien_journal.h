#ifndef GUARD_EIEN_JOURNAL_H
#define GUARD_EIEN_JOURNAL_H

// Opens the hero's journal (src/eien_journal.c); returns to the field with the start menu.
void CB2_OpenJournal(void);
// Notes he makes when he opens the journal (e.g. an Eien Poochyena that didn't evolve).
void UpdateJournalNotes(void);
void UpdateResearchAfterBattle(void);
// Whether a quest shows in the journal: started, and for the professor's list, its badge held.
bool32 IsQuestShownInJournal(u32 quest);

#endif // GUARD_EIEN_JOURNAL_H
