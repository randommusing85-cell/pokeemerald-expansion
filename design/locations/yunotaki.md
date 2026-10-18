# Yunotaki

- **Map(s):** made in Porymap (placeholder constants): the town, its gym, Pokémon Center,
  Mart and inn.
- **Type:** town
- **Connects to:** south: Route 2's mountain pass ([route-2.md](route-2.md)). `TODO(design)`:
  north/onward.

Decided in [brainstorm-route-2.md](../brainstorm-route-2.md). Named in
[brainstorm-names.md](../brainstorm-names.md): Yunotaki (湯の滝, "hot-water falls"), after the falls
where Ibuki trains.

## Purpose

Gym 2 (Fighting). Warmth and steam after the Ice gym; the vents foreshadow the volcanic door
mountain.

## Look

A mountain hot-spring town, steam vents, a waterfall where the leader trains. `TODO(design)`:
tilesets, landmarks, music.

## Story beats here

Act 1 beat 8 in [story-outline.md](../story-outline.md) (gyms 2-4).

- **Akira** battles him at the town entrance before the gym. He's just lost to Ibuki and wants
  a warm-up (his team below).
- **Gym 2: Ibuki.** A man in his 40s, a former League fighter who walked away after a season
  that ended badly and won't say why. He trains under the hot waterfalls. Two pilgrims (Daichi
  and Shizuka), then Ibuki. Winning gives the Misogi Badge (named for the waterfall purification rite) and TM31
  Brick Break. When he loses he says one quiet line about the League (draft: "The League
  likes its stories tidy."); townsfolk gossip about why he quit. That's the whole seed for the
  cover-up here.
- **The gym's inside:** a vanilla gym layout reused for now, Fighting only in the text. A
  waterfall hall or a climbing gauntlet can come with the Porymap redraw.

## NPCs and events

| NPC / event | Where | Visible when | Says / does |
| --- | --- | --- | --- |
| Inn and its hot spring | the inn | always | The hot spring heals the team: a second heal spot besides the Pokémon Center |
| Ibuki | the gym | always | See above |
| Akira | the town entrance | arriving, before gym 2 | Battles him (see Trainers) |
| Townsfolk | around town | always | Gossip about why Ibuki left the League. `TODO(design)`: lines |

Yuki's cameo is on the next route, after gym 2 ([side-quests.md](../side-quests.md)).

## Trainers

Decided in [brainstorm-gym-2.md](../brainstorm-gym-2.md). Each of Ibuki's Pokémon carries one
move against a different answer to Fighting, like Fuyumi's: Rock Tomb hits Eien Hoothoot and
the Torchic line, Bite hits Ghost and Psychic types, Medicham has its own Psychic. No single
Pokémon shuts down every answer.

| Trainer | Class | Team (levels) | Notes |
| --- | --- | --- | --- |
| Akira | Rival | His starter Lv 17 (unevolved; the evolved Eien starters aren't designed yet), Staravia Lv 18, Machop Lv 17 | At the town entrance, before the gym. Machop is his answer to Ice, learned from his mum's gym. One entry per starter he took |
| Daichi | Pilgrim (new class) | Makuhita Lv 17 | Here to learn from Ibuki. His name means "earth" |
| Shizuka | Pilgrim (new class) | Meditite Lv 18 | Foreshadows Medicham. Her name means "quiet" |
| Ibuki | Leader | Throh Lv 19 (Seismic Toss, Rock Tomb, Bulk Up, Vital Throw), Sawk Lv 19 (Double Kick, Bite, Low Kick, Bulk Up), Medicham Lv 21 @ Sitrus Berry (Brick Break, Confusion, Meditate, Detect) | Throh and Sawk are like his disciples; Medicham the meditating ascetic. The Misogi Badge and TM31 Brick Break |

No spare trainer slots are left: these reuse vanilla Hoenn slots, like Shimotsuki's
(`include/constants/opponents.h`). Ibuki and the pilgrims need sprites: an overworld sprite
and a battle pic for Ibuki (AI drafts, like Fuyumi's); the pilgrims can share the route's
pilgrim sprite.

## Flags and vars

| Name | Set when | Checked by |
| --- | --- | --- |
| `FLAG_BADGE02_GET` | He beats the gym 2 leader | The badge |

## Screenshot check

`TODO` once the maps exist.
