# Hamakaze

- **Map(s):** `MAP_...` `TODO`: town, Kashiwagi house, Kashiwagi's lab
- **Type:** town (hometown)
- **Connects to:** Route 1. `TODO(design)`: direction.

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
| Celebi | follows player | after waking | Finds him and follows him (follower NPC, `include/follower_npc.h`) |
| Professor Kashiwagi | lab | | Offers the three starters |
| Kashiwagi's husband | house | | Runs the household that takes him in. `TODO(design)`: name |
| Haru Kashiwagi | house / lab | | First friend; takes the third starter |
| Akira | lab | | Takes the starter strong against the player's; battles right after |
| Journal | - | taken in | Key item. First page: "My name is ___. I'm from ___. If I start forgetting, read this." |

## Trainers

| Trainer | Class | Team (levels) | Notes |
| --- | --- | --- | --- |
| Akira | Rival | His starter (`TODO`: level) | Lab battle, right after picking starters |

## Items

| Item | Position | Hidden? |
| --- | --- | --- |
| Journal (key item) | given | no |

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `TODO` | | |

## Screenshot check

`TODO` once the maps exist.
