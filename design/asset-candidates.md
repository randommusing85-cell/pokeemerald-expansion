# Asset candidates

Community assets that might fit Eien. The snow, Johto and Ekat beach-house tiles are now in the
game (see `asset-credits.md`); the rest are not. Once an asset is used, move
it to `asset-credits.md` with its credits.

## Downloaded and checked

`tools/fetch_assets.py` downloads these into `build/community_assets/` (git-ignored).
Terms are quoted from each resource page or the credit file inside the pack.

Tilesets made for RPG Maker / Pokémon Essentials need converting for this engine: 16x16
tiles (halve anything drawn at 2x), at most 16 colors per palette, and the primary/secondary
tileset limits in CLAUDE.md. [Porytiles](https://github.com/grunt-lucas/porytiles) builds
Porymap-ready tilesets from plain PNG layers and handles the palette packing.

| Pack | Author / credit | Terms | Format | What's useful for Eien |
| --- | --- | --- | --- | --- |
| [Gen 3 Snow Tileset](https://eeveeexpo.com/resources/1631/) | CinnaYva (`Credit.txt`: "Credit: Cinna (BannedFootage on reddit)") | Credit required. No other terms stated on the page or in the pack. | RMXP sheet at exact 2x (halves losslessly to 16px); 536 colors in total, so each map's tileset takes a subset | A full snowy-town kit: snowy houses, Pokémon Center, Mart, Gym, pines, cliffs, ice, igloo, statues, a stone tower, snow paths and deep snow |
| [Gen III Johto Tile Set](https://eeveeexpo.com/resources/1858/) | Alistair (aka TheWildDeadHero) | "Credit if used please" / "Credit Required" | Loose 1x sheet, made within GBA limits | Japanese-style houses, a five-story pagoda (shrine landmark), flower beds, water |
| [Ekat's Public Gen 3 Tilesets](https://eeveeexpo.com/resources/621/) | Ekat + per-set credits in `Credits.txt` (e.g. Gen 3 Snow: Ekat, Heartlessdragoon; Pokémon Center - Winter: Ekat, Vurtax) | Credit per set. The pack page states no commercial limit; Ekat's DeviantArt snow post says non-commercial. Treat as non-commercial. | 1x sheets | Gen 3 Snow, Snow_1-6 and Ice autotiles, Snowpoint Temple (shrine / door mountain), Beach Houses (Hamakaze), Mt. Moon Village, winter Pokémon Center interior |
| [Free Fakemon Pack](https://eeveeexpo.com/resources/1517/) | Mikitari | "Feel free to use in any project", with credit | 120 sprites: front, back, icons, and shiny front/back/icons. Gen 4 style (matches this engine's default sprites), exact 2x (halves to fit 64x64) | Fakemon, including a few regional forms of real Pokémon and several ice-themed designs |
| [Accurate FRLG-style NPC Megapack](https://eeveeexpo.com/resources/823/) | Compiled by SoulfulLex; credit the original spriters listed in its `MegaPack Readme.txt` (e.g. Kalarie, MrDollSteak, Spherical Ice, Aveontrainer, Avatar, Daman, Pokésho, Poffin_Case, Delta231, Mimi, M.vit, Kimoras, Mr. Gela, Solo993, hyo-oppa) | "I'd rather you credit the original Spriters." Credit the spriter of each sprite used | 248 RMXP overworld sheets (4 directions x 4 frames, 32x48 at 2x: halves to 16x24, fits the 16x32 GBA frame); 45 have more than 15 colors and need reducing. Playable-character trainer sprites are 2x (128x128) or Gen 4 size (160x160) | Gen 3 overworld NPCs: FRLG trainers, RSE-style townsfolk, HGSS and DPPt characters redrawn in FR style (incl. a snow Ace Trainer), anime characters. No trainer battle sprites for NPC classes (the engine already has FRLG/RSE ones) |
| [Gen 1 Type Changed Pokemon](https://digi5932.itch.io/gen-1-type-changed-pokemon) | digi5932 | "Free to use this pack for all projects, credit would be appreciated but not required." No AI used. | 300 sprites (front + back, all 151), 64x64 indexed, ROM-ready | Bases for Gen 1 variants. Its types differ from ours (e.g. its Bulbasaur is Ground/Ice) and it has none of our 4 milestone Pokémon |

Not reachable from the build environment: PokéCommunity (HTTP 403), so its threads below are
still unverified.

## Not yet checked

Terms below come from search-result summaries. Read each page and readme before importing.

## Snow and terrain

| Asset | Author | Why it fits | Terms (unverified) |
| --- | --- | --- | --- |
| [GBA Snow Tileset](https://eeveeexpo.com/resources/1497/) | `TODO` | GBA-style snow | `TODO` |
| [Gen 3 Snowpoint Temple and Snow Tiles](https://www.deviantart.com/ekat99/art/Gen-3-Snowpoint-Temple-and-Snow-Tiles-878878345) | Ekat99 | Snow tiles plus a temple (shrine / door mountain) | Non-commercial; credit Ekat, Vurtax (trees), Heartlessdragoon (RSE palettes) |

## Towns and structures

| Asset | Author | Why it fits | Terms (unverified) |
| --- | --- | --- | --- |
| [Gen 3 Interior Tileset](https://eeveeexpo.com/resources/1511/) | CinnaYva | Houses, lab, gym interiors | `TODO` |

## Battle backgrounds

| Asset | Author | Why it fits | Terms (unverified) |
| --- | --- | --- | --- |
| [Battle Backgrounds v.2](https://www.deviantart.com/kwharever/art/Battle-Backgrounds-v-2-FREE-TO-USE-768031287) | kWharever | GBA-style, includes snow | Free to use and edit with credit |

## Trainers and overworld sprites

| Asset | Author | Why it fits | Terms (unverified) |
| --- | --- | --- | --- |
| [Platinum OW/Trainer Sprite Pack for pokeemerald](https://www.pokecommunity.com/threads/platinum-ow-trainer-sprite-pack-for-pokeemerald-pokefirered.537257/) | `TODO` | Made for pokeemerald-expansion; snowy Sinnoh outfits | `TODO` |
| [ROM Hacking Sprites Pack (2026)](https://www.pokecommunity.com/threads/rom-hacking-sprites-pack-battle-backgrounds-overworlds-trainer-sprites-and-more-updated-2026.527581/) | LibertyTwins (compiler) | Battle backgrounds, overworlds, trainer sprites | Credit the original artists; folders are named by artist |
| [Gen 4/5 trainers in Gen 3 overworld style](https://eeveeexpo.com/resources/221/) | Mashirosakura | NPC variety | Free to use |

## Pokémon (variants and fakemon)

The engine already has sprites for every official Pokémon and form (`graphics/pokemon/`),
so only Eien variants and any fakemon need new art.

| Asset | Author | Why it fits | Terms (unverified) |
| --- | --- | --- | --- |
| [Fakemon Festival Pack](https://eeveeexpo.com/resources/654/) / [Redux](https://eeveeexpo.com/resources/1871/) | community | Many designers, many fakemon | "Free to Use" per title |
| [Public Fakemon](https://eeveeexpo.com/threads/9011/) | community | Fakemon | `TODO` |
| [Cinna's Fakemon](https://eeveeexpo.com/resources/1757/) | CinnaYva | Same artist as the snow tileset (consistent style) | Read the ReadMe; ask before using anything not in the pack |

## From another fan game's credits list (triaged)

A credits list from a Pokémon Essentials fan game. Being credited there doesn't give us
permission: each resource has its own terms. Engine fit decides most of it: trainer battle
sprites here are 64x64, overworld frames mostly 16x32 (Gen 3), and music must be MIDI.

| Resource | Fit for this engine | Terms (checked where linked) |
| --- | --- | --- |
| ENLS's Pre-Looped Music Library | **No.** Pre-looped audio files; GBA music is MIDI converted at build time | - |
| [Kyledove trainer classes](https://eeveeexpo.com/resources/authors/9232/) (SWSH, XY, ORAS, USUM, Ga-Olé) | Gen 4/5 style, larger than 64x64: needs cropping or resizing | Credit required; "prefers people not edit or recolor without asking" (case by case). Cropping to 64x64 is an edit: **ask first** |
| [Pokémon Showdown trainer sprites](https://play.pokemonshowdown.com/sprites/trainers/?filter=credited) and their artists (Beliot419, hyo-oppa, kyledove, ...) | Gen 4/5 style, needs cropping | "Credit must be given... **DO NOT EDIT without permission**" |
| pokengine trainer battlers / overworlds (Jext, kyledove, hyo, Rald) | Gen 4 style | Only items tagged "public use with credits" |
| Mr Gela's [Gen 4 and 5 trainer sprites](https://eeveeexpo.com/resources/391/) | Gen 4/5 style, needs cropping | `TODO` |
| [Official Gen 4 OWs](https://eeveeexpo.com/resources/404/) (VanillaSunshine and others), [Ultimate Gen 4 OW Pack](https://eeveeexpo.com/resources/609/) (PurpleZaffre), [Gen 5 in Gen 4 OW style](https://eeveeexpo.com/resources/370/) (DiegoWT) | 32x32 frames: the engine can show them, but they're a different look from Gen 3 characters | `TODO` |
| DeviantArt singles (Wolfang62, SirPeaches, Mid117, hyo-oppa, skyin2020, Solo993, PKMNTrainerRick) | Mostly Gen 4 style; Solo993's ORAS protagonists are GBA style | Per post |
| Character Selection by FL | **No.** An Essentials (Ruby) script | - |
| Tales of the Outskirt resource pack, individual artist names | Unknown without links | - |

**Comprehensive Trainer PBS / Pokémon Decades** (from its author, via the user): the pack was
taken down because it included Gen 4 sprites (e.g. the Dragon Tamers) whose artist doesn't want
their work redistributed in other packs. The Decades 3.0.0 repo folders (`Graphics/Trainers`,
`Graphics/Characters`, `Graphics/Transitions`) contain those same sprites, so **don't copy them
wholesale**: take each sprite from its original source, under that artist's terms. The rest of the
pack (PBS files, FL's Character Selector, Animated Trainer Intros, ENLS music) is Essentials-only.

Chosen instead: the Accurate FRLG-style NPC Megapack (Gen 3 style; see "Downloaded and checked").
