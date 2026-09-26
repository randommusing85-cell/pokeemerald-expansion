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
