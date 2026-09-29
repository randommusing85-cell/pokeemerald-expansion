# Hamakaze

- **Map(s):** `MAP_HAMAKAZE` (town), `MAP_HAMAKAZE_KASHIWAGI_HOUSE`, `MAP_HAMAKAZE_LAB` (map group
  `gMapGroup_Eien`). Placeholder layout: see **Maps** below.
- **Type:** town (hometown)
- **Connects to:** Route 1, north (the gap in the tree line; no connection until Route 1
  exists). North is the placeholder layout's choice, not a design decision yet.

## Purpose

Where he wakes in Eien, finds a home with the Kashiwagi family, and gets his first Pokémon.

## Look

A coastal fishing village ("sea wind"), snowy. Tilesets: `gTileset_General` + `gTileset_EienCoast`
(beach house, Japanese wooden house, small houses).
`TODO(design)`: landmarks, music.

## Story beats here

Act 1 beats 1-3 in [story-outline.md](../story-outline.md).

## NPCs and events

| NPC / event | Position (x,y) | Visible when | Says / does |
| --- | --- | --- | --- |
| Celebi | beach (13,11), then follows | from the start | Drifts down beside him on the beach and follows him (follower NPC). Talking to it gives a hint about where to go next (`data/scripts/eien_celebi.inc`) |
| Fisherman | beach (4,15) | always | Flavor line |
| Villager | town (9,11), wanders | always | Points to the Kashiwagi house, later the lab |
| Professor Kashiwagi | lab | | Offers the three starters |
| Kashiwagi's husband | house | | Runs the household that takes him in. `TODO(design)`: name |
| Haru Kashiwagi | house / lab | | First friend; takes the third starter |
| Akira | lab | | Takes the starter strong against the player's; battles right after |
| Journal | - | taken in | Opens from the start menu (in place of the PokéNav). First page: "My name is (player). I'm from another world. If I start forgetting, read this." |

## Scenes (built)

1. **Waking (town, `Hamakaze_EventScript_WakeUp`):** runs while `VAR_EIEN_STORY` =
   `STORY_PROLOGUE`. He's on the beach at (12,14) (warp 2, the arrival point); Celebi drifts
   down beside him and starts following. Sets `STORY_ARRIVED`.
2. **Taken in (house, `Hamakaze_KashiwagiHouse_EventScript_TakenIn`):** runs on entering at
   `STORY_ARRIVED`. The professor, her husband and Haru; the professor gives him a notebook
   and he writes the first page. Sets `FLAG_RECEIVED_JOURNAL`, `STORY_TAKEN_IN`.
3. **Starters (lab, `Hamakaze_Lab_EventScript_Intro` / `_ChooseStarter`):** at `STORY_TAKEN_IN`
   three balls on the floor (Torchic, Bulbasaur, Froakie, all Eien forms, Lv 5). He picks one;
   Akira takes the one strong against it, Haru the last; Akira battles him at once. Losing is
   fine (early rival battle: healed, no white-out). Akira leaves for Shimotsuki. Sets
   `STORY_GOT_STARTER`.

All lines are drafts in the style guide's voice (`TODO(design)` in the scripts). Choices made
here that the docs didn't settle, all easy to change:
- The professor hands him the notebook ("write down whatever you remember").
- Akira's lab level: 5, like the starters.
- Who is where after each beat: the professor is at the lab from `STORY_TAKEN_IN` on; Haru is at
  the lab during the starter scene and home again after.

## Trainers

| Trainer | Class | Team (levels) | Notes |
| --- | --- | --- | --- |
| Akira (`TRAINER_EIEN_AKIRA_LAB_TORCHIC` / `_BULBASAUR` / `_FROAKIE`) | Rival | The starter strong against the player's, Lv 5 | Lab battle, right after picking starters (`trainerbattle_earlyrival`) |

## Items

| Item | Position | Hidden? |
| --- | --- | --- |
| Journal (start menu entry, `FLAG_RECEIVED_JOURNAL`) | given | no |

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `VAR_EIEN_STORY` = `STORY_ARRIVED` | He wakes on the beach | The journal's Story tab |
| `VAR_EIEN_STORY` = `STORY_TAKEN_IN` | The Kashiwagis take him in | The journal |
| `FLAG_RECEIVED_JOURNAL` | He starts the journal (taken in) | The start menu (JOURNAL entry) |
| `FLAG_JOURNAL_COVER_SEEN` | The journal is opened the first time | The journal (opens on the cover once) |
| `VAR_EIEN_STORY` = `STORY_GOT_STARTER` | After the lab battle with Akira | The journal |
| `QUEST_HARU_MAP` (quest table) | `TODO(design)`: when Haru asks | The journal's Missions tab |

## Maps

- **Town:** a 24x20 placeholder layout (`data/layouts/Hamakaze/`, `gTileset_General` +
  `gTileset_EienCoast`), hand-made for the first playable pass; redraw it in Porymap freely,
  keeping the warps and object positions (or moving them in the map's events). Tree line along
  the top with a gap north; the Kashiwagi house (blue house, door (5,7)) and the lab (yellow
  shop, door (16,7)); a neighbour's Japanese house (not enterable); beach and sea along the
  bottom. Weather snow, map type town (so the night tint and aurora apply).
  `TODO(design)`: landmarks, music (placeholder `MUS_LITTLEROOT`).
- **Kashiwagi house:** reuses Emerald's `LAYOUT_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F` (the stairs
  lead nowhere yet). **Lab:** reuses `LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB`.
- A new game still starts in Emerald's truck; reach Hamakaze with the debug menu's warp
  (`MAP_HAMAKAZE`, warp 2 is the beach). Starting a new game here (or in the prologue) is a
  separate change: it also changes the harness's `new_game.txt`.

## Screenshot check

Played through with the harness (new game, warp to the beach): waking and Celebi, the walk
to the house with Celebi following, the house scene and the journal's first page, the lab,
picking Bulbasaur, Akira taking Torchic and Haru Froakie, the battle (lost on purpose: healed,
scene continues). Shots in `design/art/hamakaze/`.
