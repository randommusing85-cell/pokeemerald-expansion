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

## Starters

Given by Professor Kashiwagi in Hamakaze. First evolution at about Lv 18 (not 16).

| Line | Eien type | Idea |
| --- | --- | --- |
| Torchic | Fire/Ghost | A shrine-lantern bird, touched by the fading |
| Bulbasaur | Grass/Psychic | Touched by the fading |
| Froakie | Water/Ice | A snow ninja, adapted to the cold |

Each beats one other, like the classic starter cycle: Torchic beats Bulbasaur, Bulbasaur
beats Froakie, Froakie beats Torchic. (Grass/Water was tried for Bulbasaur and dropped: it
beat both others and neither beat it back.)

| Player picks | Akira takes (strong against it) | Haru takes |
| --- | --- | --- |
| Torchic | Froakie | Bulbasaur |
| Bulbasaur | Torchic | Froakie |
| Froakie | Bulbasaur | Torchic |

`TODO(design)`: evolved forms, stats, abilities, moves, dex entries.

## Others

| Pokémon | Eien type | Idea | Where first |
| --- | --- | --- | --- |
| Poochyena | Rock/Dark | A stone shrine guardian dog (komainu), touched by the fading. Beats the Ice gym. | Route 1 (common, ~20%) |

`TODO(design)`: Eien Poochyena's final look (the sprite test is a proposal), stats, moves,
evolution (Mightyena variant?).
