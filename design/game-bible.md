# Game bible

## Pitch

A Pokémon fan from our world nearly dies in an accident and wakes up in Eien, a snowbound
region whose god is dying of old age. He travels the gym circuit, falls for a girl on the
other side, loses people he loves, and saves the world at the cost of his memories of it.

## The region

- **Name:** Eien (永遠, "eternity").
- **Inspiration:** northern Honshu's Sea of Japan coast (Tohoku, Aomori).
- **Geography:** snow country and coast: fishing towns (e.g. Hamakaze), snowy inland towns
  (e.g. Shimotsuki), old shrines, and a volcanic mountain
  where the worlds are thin (modeled on Osorezan). `TODO(design)`: map layout, route count.
- **Look and feel:** cold and sparse, long winters, aurora skies. Must feel distinct from
  Sinnoh (which is Hokkaido-based and Palkia's home region). Needs a community snow tileset
  (the engine has none).

## Art style

- **Overworld and characters:** Gen 3 (FRLG/RSE) style: 16x32 overworld frames, 64x64 trainer
  battle sprites. NPC overworlds come from the FRLG-style NPC megapack (see
  `asset-candidates.md`).
- **Pokémon:** Gen 4/5 style, the engine default (`P_GBA_STYLE_SPECIES_GFX FALSE`). It's
  consistent across every generation, and variants and fakemon are drawn to match it.
- **Tilesets:** Gen 3 style (the Eien snow tilesets in `tools/eien_tileset/`).

## Themes

`TODO(design)`: confirm. Drawn from the story decisions:

- **Everything ends, and that's allowed.** Arceus's cycle, the hero's memories, his goodbye.
- **Loyalty isn't the same as being right.** Pokémon are loyal to every trainer, on any side.
- **Good people can want opposite things.** The villains, Nami and the League all act on
  what they believe.

## World rules

- **Pokémon are innately good and loyal** to their trainers. Morality belongs to trainers.
- **Arceus is fading as part of a natural cycle.** It's old; the world will be remade. The
  question is what survives the change.
- **The League and scientists know** about the cycle and hide it. Ordinary people only have
  rumors and folk tales (longer winters, "it's happened before").
- **Other worlds exist**, ours included. Palkia is the door between them. At the thin place
  on the mountain, Minato builds a machine to draw on Palkia's power.
- **Pokémon can die.** Major characters' Pokémon die on-screen; minor NPCs' off-screen. The
  player's party never dies.

## Pokémon

- **Starters:** Eien variants of Torchic (Fire/Ghost), Bulbasaur (Grass/Psychic) and Froakie
  (Water/Ice), given by Professor Kashiwagi. As a fan, the hero recognizes them.
- **Regional variants:** Eien has its own variants of some existing Pokémon, mostly changed
  by the fading (toward Ghost/Psychic/Dark) and some adapted to the cold. See
  [variants.md](variants.md).
- **Shinies** are rare (1 in 4,096) and exist for originals and variants alike.
- **Fakemon:** `TODO(design)`: none, a few, or later.
- **Legendary / myth:**
  - **Arceus:** the fading god whose cycle drives the plot.
  - **Palkia:** the door between worlds. It brought the hero here as a test: will an
    outsider keep the worlds apart or join them? It chose him because a fan sees this world
    from outside.
  - **Celebi:** came from a future where the cycle went wrong and the world ended. It saw the
    hero in that future and led Palkia to him. It guides him but can't travel through time
    again or battle. Its guidance is short glimpses of what's coming (see Mechanics).

## Mechanics

Decided in [brainstorm-mechanics.md](brainstorm-mechanics.md), which also has the research
on what other hacks and fan games do.

- **Fan knowledge (the signature mechanic).** He knows Gen 1-5 Pokémon from the games: their
  Pokédex entries and typing are known from the start, and in battle his moves show
  effectiveness hints against them. Eien variants and Gen 6+ species show "???", and the
  hint shows "?" too, so his instincts can mislead him (Fire is fine against a normal
  Bulbasaur, not against Eien Bulbasaur).
- **Research.** Unknown species fill in by tiers: seeing one gives the name and sprite,
  battling it gives the typing, catching it gives the full entry, and extra steps (seeing a
  certain move, catching one at night) add lore notes. Shrine tablets, folk tales and the
  professor's notes add lore too. `TODO(design)`: the steps per species.
- **The journal** replaces the PokéNav in the start menu. It looks like an open notebook (the
  list on the left page, details on the right, bookmark tabs on the edge) with Bag-style
  controls. Three tabs:
  - **Story:** a "what's next" line, his entry for each story beat, then lore pages (shrine
    tablets, folk tales).
  - **Research:** each species' research steps and notes. The data itself is in the
    Pokédex, which shows "???" until each tier unlocks.
  - **Missions:** side quests grouped by person (each header shows that person's line) plus
    an "Eien" group. Letters show as a "new" marker. A mission shows its hint, who gave it,
    its state and a short log; rewards stay hidden. Missed ones stay, greyed, with one line
    in his voice.

  The first page ("If I start forgetting, read this.") shows the first time it's opened, then
  stays as the cover. At the end the entries fade out one by one and the pages stay blank;
  in the epilogue they write themselves back in. Screen details:
  [brainstorm-journal-screen.md](brainstorm-journal-screen.md).
- **Celebi's glimpses.** In scripted story moments Celebi shows a short vision of what's
  coming (a rival's lead, a disaster site, a hidden path). Talking to Celebi gives a hint
  about where to go next. Both get vaguer as Celebi weakens.
- **Relationship points** with Nami, Haru, Yuki, Kaede, Tetsu, Ren and Akira. Earned through
  answers in story scenes (never an "evil" option; they read as how he treats someone) and
  each friend's quest chain. They change scenes, dialogue, who helps in the finale, gifts and
  the epilogue, never the outcome. Never shown as numbers: only the journal's line per
  person. Details in [side-quests.md](side-quests.md). `TODO(design)`: which friends get tag
  battles; point thresholds.
- **Side quests** (the journal's missions tab): friend chains are the backbone, plus research,
  the fading's small disasters, and lore. About 25 at launch, built to grow to Unbound's
  scale. Quests tied to people who die or leave can be missed for good; the epilogue gives
  them back as memories. See [side-quests.md](side-quests.md).
- **Eien weather and terrain.** Snow on most routes, an aurora weather on clear nights, and a
  "thin place" terrain at shrines and the mountain that boosts Ghost and Psychic moves.
  Built on the engine's weather and terrain. `TODO(design)`: the aurora's battle effect,
  the terrain's exact rules.
- **Difficulty:** see [progression.md](progression.md).
- **Not used:** Mega, Z-Moves, Dynamax and Tera (a lore-tied gimmick may come later);
  follower Pokémon (Celebi already follows him; parked).

## Tone

Grounded, with real losses: a betrayal, on-screen deaths, a bittersweet ending. Kept plain,
not melodramatic (see `dialogue-style.md`).

The game never:

- makes villains cartoonish, gloating or sore losers. They think they're right and lose
  gracefully.
- has villains murder people. Deaths come from disasters their plan causes.
- kills a Pokémon in the player's party.

## Out of scope

`TODO(design)`.
