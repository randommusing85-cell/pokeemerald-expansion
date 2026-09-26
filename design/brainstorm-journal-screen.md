# Brainstorm: the journal screen

Running notes. Nothing is decided until it's under **Decided**.

## Givens

- The journal is a key item from Act 1 (Hamakaze). Its first page: "My name is ___. I'm from
  ___. If I start forgetting, read this."
- Three tabs are decided: story, research, missions (game bible, Mechanics).
- Missions: title, one-line hint, state (open / done / closed), who gave it; grouped by
  person plus an "Eien" group; filters once there are about 40 (side-quests.md).
- One line per person that changes with relationship points; never numbers.
- Letters arrive in the journal when a friend wants to see him.
- Lore pages come from shrine tablets and folk tales.
- Research tiers: seen (name, sprite), battled (typing), caught (full entry), extra steps
  (lore notes). Eien variants and Gen 6+ species start as "???".
- The pages go blank at the end and refill in the epilogue.
- GBA screen: 240x160 (30x20 tiles). The engine has a list menu (`src/list_menu.c`) and the
  HGSS-style Pokédex (`src/pokedex_plus_hgss.c`) to learn from.

## Decided

_(none yet)_

## Open questions (round 1)

1. Overall look.
2. Where people, letters and lore live among the three tabs.
3. What the story tab shows.
4. Research: in the journal, the Pokédex, or both.
5. How the pages going blank (and refilling) is shown.
6. How the player opens it.

## Gaps and tensions

- A notebook look needs background art and maybe a handwriting-style font (custom work).
- A new screen is a new C file: fine under CLAUDE.md if isolated, but it's the biggest code
  piece so far.
- Text space: a 240-pixel-wide page fits about 30 characters per line in the normal font.

## Parked ideas

_(none yet)_

## Rejected

_(none yet)_
