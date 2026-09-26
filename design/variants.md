# Regional variants

Eien has its own variants of some existing Pokémon. Named like official regional forms:
**"Eien Poochyena"**. A final form may get its own name when the design calls for it.

- **Theme:** mostly Pokémon *touched by the fading*: living where the worlds are thin has
  shifted them toward Ghost, Psychic or Dark. Some are *adapted to the cold* (Ice, Water).
- **Budget:** the 9 starter variants, plus 5-10 others for the whole game.
- **Shinies:** every variant has a shiny palette. Shiny odds are 1 in 4,096 for all Pokémon
  (`SHINY_ODDS 16`); the Shiny Charm is a post-game reward.
- **Art:** each variant needs a front sprite (2 frames), back sprite, icon, and normal + shiny
  palettes. Workflow and findings: [art/eien_poochyena/README.md](art/eien_poochyena/README.md).

## How they're built

Regional forms of the existing species (like Alolan Rattata): the same dex number, their own
form entry (`SPECIES_TORCHIC_EIEN`, ...). Stats keep the original's total, redistributed to
fit the new typing. Abilities are existing ones that fit the theme; starters keep their pinch
ability as the main one. Starters evolve by level and keep their Eien typing; other variants
evolve by an Eien method (a shrine area, an aurora night, a thin place). Decided in
[brainstorm-eien-species.md](brainstorm-eien-species.md).

## Starters

Given by Professor Kashiwagi in Hamakaze. First evolution at about Lv 18 (not 16).

| Line | Eien type | Idea |
| --- | --- | --- |
| Torchic | Fire/Ghost | A shrine-lantern bird, touched by the fading |
| Bulbasaur | Grass/Psychic | A fading bloom: its bulb is partly translucent and glows faintly like the aurora, as if it's between worlds |
| Froakie | Water/Ice | A snow ninja, adapted to the cold; its frubbles are frost. The one starter the hero doesn't recognize (Gen 6) |

Each beats one other, like the classic starter cycle: Torchic beats Bulbasaur, Bulbasaur
beats Froakie, Froakie beats Torchic. (Grass/Water was tried for Bulbasaur and dropped: it
beat both others and neither beat it back.)

| Player picks | Akira takes (strong against it) | Haru takes |
| --- | --- | --- |
| Torchic | Froakie | Bulbasaur |
| Bulbasaur | Torchic | Froakie |
| Froakie | Bulbasaur | Torchic |

### First stages

Stats are HP / Atk / Def / SpA / SpD / Spe (the original in brackets).

| Form | Stats (total) | Abilities (hidden last) | New early moves |
| --- | --- | --- | --- |
| Eien Torchic | 45 / 45 / 40 / 80 / 50 / 50 (45 / 60 / 40 / 70 / 50 / 45), 310 | Blaze / Cursed Body | Astonish (5), Will-O-Wisp (14) |
| Eien Bulbasaur | 45 / 40 / 49 / 75 / 70 / 39 (45 / 49 / 49 / 65 / 65 / 45), 318 | Overgrow / Forewarn | Confusion (7; Vine Whip moves later) |
| Eien Froakie | 41 / 56 / 40 / 62 / 54 / 61 (41 / 56 / 40 / 62 / 44 / 71), 314 | Torrent / Snow Cloak | Powder Snow (5), Ice Shard (15) |

Otherwise they keep the original learnset.

`TODO(design)`: evolved forms (they don't evolve until those exist), dex entries (drafts are
in the code), the final sprites (placeholders are recolored originals).

## Others

| Pokémon | Eien type | Idea | Where first |
| --- | --- | --- | --- |
| Poochyena | Rock/Dark | A stone shrine guardian dog (komainu), touched by the fading. Beats the Ice gym. | Route 1 (common, ~20%) |

- **Eien Poochyena:** 35 / 55 / 50 / 25 / 30 / 25 (35 / 55 / 35 / 30 / 30 / 35), 220.
  Abilities Intimidate / Sturdy / Stakeout (hidden). New early moves: Rock Throw (7), Rock
  Tomb (16); otherwise the original learnset.
- **Evolves** into Eien Mightyena (Rock/Dark) by leveling up to 18+ in a shrine area.

`TODO(design)`: Eien Mightyena (stats, look; Poochyena doesn't evolve until it exists), Eien
Poochyena's final look (the sprite test is a proposal), which map sections count as shrine
areas.
