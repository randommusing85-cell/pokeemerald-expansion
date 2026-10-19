# Yunotaki

- **Map(s):** the town reuses vanilla Lavaridge Town's layout, copied as our own with small
  edits (see **Maps** below); its gym, Pokémon Center, Mart, herb shop and inn reuse vanilla
  interiors. Our own maps and scripts (placeholder constants `MAP_YUNOTAKI`, `MAP_YUNOTAKI_GYM`,
  `MAP_YUNOTAKI_POKEMON_CENTER_1F`, `MAP_YUNOTAKI_MART`, `MAP_YUNOTAKI_HERB_SHOP`,
  `MAP_YUNOTAKI_INN`). A Porymap map can replace it any time.
- **Type:** town
- **Connects to:** south: Route 2's mountain pass ([route-2.md](route-2.md)). `TODO(design)`:
  where the road onward leads. Lavaridge's east exit stays, blocked for now: "The road east is
  shut for the thaw." 

Decided in [brainstorm-route-2.md](../brainstorm-route-2.md). Named in
[brainstorm-names.md](../brainstorm-names.md): Yunotaki (湯の滝, "hot-water falls"), after the falls
where Ibuki trains. Map and NPCs decided in [brainstorm-yunotaki.md](../brainstorm-yunotaki.md).

## Purpose

Gym 2 (Fighting). Warmth and steam after the Ice gym; the vents foreshadow the volcanic door
mountain.

## Look

A mountain hot-spring town, steam vents, a waterfall where the leader trains: Lavaridge's
tiles (`gTileset_Lavaridge`), its outdoor hot spring, and a short waterfall on the west edge by
the gym. Music (vanilla placeholder): Fallarbor's track.

## Story beats here

Act 1 beat 8 in [story-outline.md](../story-outline.md) (gyms 2-4).

- **Ibuki under the falls:** before the badge he stands under the waterfall by the gym. Talking
  to him: "The gym's open. Go in." He's also in the gym (two objects).
- **Akira** waits by the gym door; the battle is forced before you can enter, so you can heal
  first. He's just lost to Ibuki and wants a warm-up (his team below).
- **Gym 2: Ibuki.** A man in his 40s, a former League fighter who walked away after a season
  that ended badly and won't say why. He trains under the hot waterfalls. Two pilgrims (Daichi
  and Shizuka), then Ibuki. Winning gives the Misogi Badge (named for the waterfall purification rite) and TM31
  Brick Break. When he loses he says one quiet line about the League (draft: "The League
  likes its stories tidy."); townsfolk gossip about why he quit. That's the whole seed for the
  cover-up here.
- **The gym's inside:** Dewford's gym (the vanilla Fighting gym): dark at first, the light
  grows as you beat trainers, like reaching clarity under the falls (misogi). The guide is a
  retired pilgrim who trained under Ibuki. A waterfall hall or a climbing gauntlet can come with
  a Porymap redraw.
- **Ren** (cameo; [side-quests.md](../side-quests.md)) arrives as you leave the gym with the
  badge: a nod, "Next.", and he walks in to challenge Ibuki officially. No battle. Sprite: a
  vanilla Ace Trainer for now.

## NPCs and events

| NPC / event | Where | Visible when | Says / does |
| --- | --- | --- | --- |
| Bath attendant | the outdoor hot spring | always | An old woman in the water: "Sit. Soak." Heals the team: a second heal spot besides the Pokémon Center |
| Innkeeper | the inn (Lavaridge's house) | always | Gossip: Ibuki lost to the Champion |
| JIRO | the inn | after Route 2 | Route 2's porter, unloading baskets he carried up |
| Gossip 1 | by the bath | always | Ibuki quit over an injury |
| Gossip 2 | by the gym | always | A kid: "he saw something" at the League |
| Herb-shop keeper | the herb shop | always | Sells bitter mountain medicine (vanilla herbs); won't gossip: "Ask him yourself." No gifts |
| Ibuki | under the falls | before the badge | "The gym's open. Go in." |
| Ibuki | the gym | always | See above |
| Gym guide | inside the gym door | always | A retired pilgrim; the gym tips in his own voice |
| Akira | the gym door | before gym 2, until his battle | Battles him (see Trainers) |
| Ren | outside the gym | as he leaves with the badge | "Next." and walks in |
| East exit block | the east edge | until `TODO(design)` | "The road east is shut for the thaw." |

The three rumours disagree; nothing is spelled out. All lines are drafts at build time
(`TODO(design)`). Lavaridge's vanilla gifts (the egg, the herb shop's Charcoal) are dropped.

Yuki's cameo is on the next route, after gym 2 ([side-quests.md](../side-quests.md)).

## Trainers

Decided in [brainstorm-gym-2.md](../brainstorm-gym-2.md). Each of Ibuki's Pokémon carries one
move against a different answer to Fighting, like Fuyumi's: Rock Tomb hits Eien Hoothoot and
the Torchic line, Bite hits Ghost and Psychic types, Medicham has its own Psychic. No single
Pokémon shuts down every answer.

| Trainer | Class | Team (levels) | Notes |
| --- | --- | --- | --- |
| Akira | Rival | His starter Lv 17 (unevolved; the evolved Eien starters aren't designed yet), Staravia Lv 18, Machop Lv 17 | By the gym door, before the gym. Machop is his answer to Ice, learned from his mum's gym. One entry per starter he took |
| Daichi | Pilgrim (new class) | Makuhita Lv 17 | Here to learn from Ibuki. His name means "earth" |
| Shizuka | Pilgrim (new class) | Meditite Lv 18 | Foreshadows Medicham. Her name means "quiet" |
| Ibuki | Leader | Throh Lv 19 (Seismic Toss, Rock Tomb, Bulk Up, Vital Throw), Sawk Lv 19 (Double Kick, Bite, Low Kick, Bulk Up), Medicham Lv 21 @ Sitrus Berry (Brick Break, Confusion, Meditate, Detect) | Throh and Sawk are like his disciples; Medicham the meditating ascetic. The Misogi Badge and TM31 Brick Break |

No spare trainer slots are left: these reuse vanilla Hoenn slots, like Shimotsuki's
(`include/constants/opponents.h`). Ibuki and the pilgrims need sprites: an overworld sprite
and a battle pic for Ibuki (AI drafts, like Fuyumi's); the pilgrims can share the route's
pilgrim sprite.

## Maps

- **Town:** Lavaridge's layout (20x20, `gTileset_General` + `gTileset_Lavaridge`) copied to our
  own layout, with two edits: a south entrance for Route 2's upper map, and a short waterfall on
  the west edge by the gym door (general tileset waterfall metatiles, to confirm at build time).
  Doors as in Lavaridge: gym (5,15), Pokémon Center (9,6, and its back door at 9,2 from the hot
  spring side), Mart (15,5), herb shop (12,15), inn (the house, 16,15).
- **Gym:** Dewford's gym layout. **Pokémon Center, Mart, herb shop, inn:** Lavaridge's
  interiors.

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `FLAG_BADGE02_GET` | He beats the gym 2 leader | The badge |

## Screenshot check

`TODO` once the maps exist.
