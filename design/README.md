# Design docs

The single source of truth for the game's world, story and progression. Code follows these
docs: when the design changes, the doc changes in the same commit.

| Doc | What it holds |
| --- | --- |
| [game-bible.md](game-bible.md) | The region, its themes and rules. Read this first. |
| [story-outline.md](story-outline.md) | The plot, beat by beat, and what the player learns when |
| [characters.md](characters.md) | Player, rival, professor, gym leaders, factions |
| [progression.md](progression.md) | Route order, badges, level curve, what gates what |
| [dialogue-style.md](dialogue-style.md) | How characters talk, with examples |
| [variants.md](variants.md) | Eien's regional variants of existing Pokémon, and shiny rules |
| [side-quests.md](side-quests.md) | Side quests, friend chains and relationship points |
| [locations/](locations/) | One doc per town, route or dungeon (copy `_template.md`) |
| [asset-credits.md](asset-credits.md) | Every community asset used, with its author |
| [asset-candidates.md](asset-candidates.md) | Community assets we might use, not yet checked |

## Current milestone

**Vertical slice: prologue through gym 1.** Everything outside this scope waits.

- [ ] Prologue: bedroom in our world, the accident, Palkia ([prologue](locations/prologue-bedroom.md))
- [ ] Engine: remove the boy/girl choice, keep the naming screen
- [ ] Hamakaze: he wakes in Eien, Celebi follows him, the Kashiwagi household, Haru, the
      journal ([Hamakaze](locations/hamakaze.md))
- [ ] Kashiwagi's lab: pick a starter, Akira and Haru take the others, first battle with Akira
- [ ] Route 1: coast, snowy fields, shrine; Eien Poochyena ([Route 1](locations/route-1.md))
- [ ] Shimotsuki and gym 1 (Fuyumi, Ice); Akira shows him the gym ([Shimotsuki](locations/shimotsuki.md))
- [ ] Nami's first meeting, just after gym 1 (end of the slice)
- [ ] Species: Eien Torchic, Bulbasaur, Froakie, Poochyena ([variants](variants.md))
- [ ] Sprites for those 4 (front, back, icon, normal + shiny palettes)
- [x] Community snow tileset, credited in `asset-credits.md` (`tools/eien_tileset/README.md`)
- [x] Door behaviors/animations and tree-top layering for the Eien tilesets
- [ ] Quest table in the save file with `setquest` / `checkquest` script commands (quest
      state and relationship points; [side-quests](side-quests.md))
- [ ] Three quests to prove it: Haru step 1 (Hamakaze), the professor's Eien Poochyena
      research (Route 1), Akira step 1 (Shimotsuki)
- [ ] Journal screen, bare: three tabs with placeholder art, replacing the PokéNav in the start
      menu; real data for the quests above, the Poochyena research and a few story entries
- [ ] Shiny odds 1 in 4,096 (`SHINY_ODDS 16` in `include/constants/pokemon.h`)
- [ ] Maps made in Porymap; map constants filled into the location docs

## Conventions

- Names in docs match the code: a location doc names its map (`MAP_...`) and every story flag
  or var it uses.
- Unknowns are written as `TODO(design): question` so they're easy to find (`grep -rF 'TODO(design)' design`).
- Keep docs short. Bullet points over prose; a doc nobody reads doesn't help.
