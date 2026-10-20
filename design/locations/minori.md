# Minori

- **Map(s):** made in Porymap (placeholder constants `MAP_MINORI`, `MAP_MINORI_YUKI_HOUSE`, the
  terraces; `TODO(design)`: whether it has a Pokémon Center). Vanilla layouts can stand in.
- **Type:** town (a farming village)
- **Connects to:** west: Route 6 ([route-6.md](route-6.md)) from Kanaya. Up: Route 7, the highland
  plateau, to Hoshimi, gym 6 ([route-7.md](route-7.md), [hoshimi.md](hoshimi.md)).

Decided in [brainstorm-yuki-hometown.md](../brainstorm-yuki-hometown.md). Minori (実り, "harvest, ripening"): Yuki's hometown.

## Purpose

Yuki's step 2 ([side-quests.md](../side-quests.md), E6): one of the fading's small disasters hits
the town she competes for, and helping is how they become friends. A warm night in Act 3, with
a cost.

## Look

A small, struggling village of rice terraces on a hillside. **The festival:** *mushi-okuri*
(insect-sending), a real Tohoku rite: at night torches are carried along the paddies to drive
the pests away. The torch-bearers wear cords; Yuki's festival cord (her keepsake) is one.
The thinning uses the shared thinning look ([game-bible.md](../game-bible.md), Eien weather and terrain): the screen drains on festival night (Yuki and
Celebi stay in colour with him), and the terraces are grey tiles afterwards, until the epilogue.
`TODO(design)`: tilesets, music.

## Story beats here

Act 3 beat 2 in [story-outline.md](../story-outline.md).

1. **The letter:** after gym 5, Yuki writes: her Absol sensed something coming. He arrives on
   festival day, in time.
2. **Her family:** a calm scene first. Her parents farm the terraces; her little brother wants to
   be a trainer like her.
3. **The festival:** the torch procession along the paddies at night. Mid-procession a thinning
   opens at the terraces, and the village's Pokémon walk into it, grey, as if called.
4. **The grey:** Celebi flickers and waits at the edge. Yuki's Absol leads, sensing where each
   Pokémon is. He calms four or five of them (a wild battle each, Lv 36-38) and brings them back.
5. **The centre:** two ordinary Tokoyo members (new faces), there to measure the thinning rather
   than close it ("we'll close it after the readings"), stand in the way of the last Pokémon. A
   tag battle beside Yuki (Lv 37-40).
6. **After:** the Pokémon come back in colour and the festival finishes late that night, but the
   terraces stay grey for the year. Her brother gets his first Pokémon: one of the saved ones
   chooses to stay with him.
7. **Her question:** "Will you come to the festival next year?" (yes / I'll try / I don't know).
   The answer gives her points. Light on the surface; the player knows he goes home. Her "next
   year" carries the warmth and the cost.

## NPCs and events

| NPC / event | Where | Visible when | Says / does |
| --- | --- | --- | --- |
| Yuki | the village; the grey | her step 2 | See above; her partner for the tag battle |
| Her parents | their house, the terraces | always | Farm the terraces (`TODO(design)`: names, lines) |
| Her little brother | their house | always | Wants to be a trainer; gets a Pokémon after (`TODO(design)`: name) |
| The village's Pokémon | the grey | the thinning | Farm Pokémon, grey (Mareep, Miltank, Skiddo, Lillipup, Hoppip; `TODO(design)`) |
| Tokoyo pair | the grey's centre | the thinning | The tag battle (`TODO(design)`: names, teams) |

## Trainers

| Trainer | Team (levels) | Notes |
| --- | --- | --- |
| Tokoyo member 1 and 2 | Lv 37-40 | Tag battle; `TODO(design)`: teams |
| Yuki (partner) | Absol and her team, about Lv 38 | A `PARTNER_` entry in `src/data/battle_partners.party`, through the follower-NPC partner system (as Kaede's) |

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `TODO` | Yuki's letter (after `FLAG_BADGE05_GET`) | Opens her step 2 |
| `TODO` | The thinning is closed | The festival's end; the grey terraces |
| `TODO` | Her question answered | Her points |

## Screenshot check

`TODO` once the maps exist.
