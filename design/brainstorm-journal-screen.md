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

Promoted into `game-bible.md` (Mechanics, the journal), `progression.md` and the
milestone list in `README.md`.

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

- **Layout (r2 1c):** an open notebook: the left page is the list, the right page the detail,
  a spine in the middle, bookmark tabs on the right edge. About 14 characters per line on
  each page.
- **Opening (r2 2b):** the first page ("If I start forgetting, read this.") shows the first
  time only; after that the journal opens on the last tab used. The first page stays
  reachable as the cover (it goes blank too at the end).
- **The rest of the PokéNav (r2 3a):** cut. The Town Map is its own key item (Haru's quest
  reward); rematches use the Vs. Seeker (`I_VS_SEEKER_CHARGING`); contests and ribbons go.
- **Mission detail (r2 4b):** the hint, who gave it, its state, and a short log of what's
  happened in his voice. Rewards stay hidden (protects the keepsakes).
- **Closed missions (r2 5a):** greyed out in the person's group, with one line in his voice.
- **First milestone (r2 6b):** all three tabs, bare: placeholder art, working list and detail,
  real data for the three quests, the Eien Poochyena research and a few story entries.
- **Defaults:** L/R and Left/Right switch tabs, B closes.

## Open questions (later)

- Final art: in-house, AI drafts (like the hero sprite) or a credited community asset.
- A handwriting-style font, maybe later.

## Gaps and tensions

- A notebook look needs background art and maybe a handwriting-style font (custom work).
- A new screen is a new C file: fine under CLAUDE.md if isolated, but it's the biggest code
  piece so far.
- Text space: a 240-pixel-wide page fits about 30 characters per line in the normal font.

## Parked ideas

_(none yet)_

## Rejected

_(none yet)_
