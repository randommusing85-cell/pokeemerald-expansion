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

- **Look (1c):** a hybrid: notebook art (paper background, tab bookmarks on the edge) with
  Bag-style controls and the normal font. A handwriting font can come later.
- **Three tabs (2a):** Story, Research, Missions. People are the groups inside Missions (each
  person's header shows their line); letters show as a "new" marker on that person's group;
  lore pages sit inside Story.
- **Story tab (3c):** a "what's next" line on top, then a short entry per story beat in his
  voice, then the lore pages (tablets, folk tales) as a second list.
- **Research (4b):** the data lives in the Pokédex, which shows "???" until each tier unlocks;
  the journal lists each species' research steps and lore notes.
- **Blank pages (5c):** a scripted scene at the end where lines fade out one entry at a
  time; after the ending, the journal shows empty pages; in the epilogue, entries write
  themselves back in as memories return. Both use one "write / erase an entry" effect.
- **Opening it (6c):** the journal replaces the PokéNav in the start menu. Letters replace
  Match Call.

## Open questions (round 2)

1. Screen layout.
2. What opens first (the first page, the last tab).
3. What happens to the rest of the PokéNav (region map, rematches, contests, ribbons).
4. What a mission's detail shows.
5. How closed (missed) missions look.
6. What the first milestone builds.

## Gaps and tensions

- A notebook look needs background art and maybe a handwriting-style font (custom work).
- A new screen is a new C file: fine under CLAUDE.md if isolated, but it's the biggest code
  piece so far.
- Text space: a 240-pixel-wide page fits about 30 characters per line in the normal font.

## Parked ideas

_(none yet)_

## Rejected

_(none yet)_
