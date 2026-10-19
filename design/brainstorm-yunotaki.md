# Brainstorm: Yunotaki's map and NPCs

Working notes for Yunotaki, the hot-spring town of gym 2 (`locations/yunotaki.md`). Decisions
move into the town doc when settled; this file stays as the record.

## Givens (from the docs)

- A mountain hot-spring town: steam vents, a waterfall where Ibuki trains. North end of Route 2's
  upper map (steam vents, bare rock). The vents foreshadow the volcanic door mountain.
- Buildings: Pokémon Center, Mart, gym, houses, and an inn whose hot spring heals the team (a
  second heal spot). Onward route north: `TODO(design)`.
- Gym 2: Ibuki (Fighting), two pilgrims (Daichi, Shizuka), the Misogi Badge and TM31 Brick Break.
  The gym's inside reuses a vanilla layout for now.
- Akira battles him at the town entrance (he just lost to Ibuki). Townsfolk gossip about why
  Ibuki left the League; his losing line "The League likes its stories tidy." is the whole
  cover-up seed here.
- Ren's cameo: a by-the-book League trainer at gym 2 or 3 (`side-quests.md`). Yuki's cameo is
  on the next route, after gym 2.
- New maps are made by the user in Porymap, unless asked; Shimotsuki was built on hand-made
  placeholder layouts. Vanilla Lavaridge Town (a hot-spring town with a gym) exists in the repo.

## Decided

- **The map (r1 1c):** reuse vanilla Lavaridge Town's layout (a hot-spring town with a gym,
  Pokémon Center, Mart, herb shop, a house and an outdoor hot spring), as our own map with our
  own scripts. The user can swap in a Porymap map any time.
- **The falls (r1 2a):** at the town's edge beside the gym; Ibuki is seen standing under them
  before the gym battle.
- **Inn and bath (r1 3c):** both: an inn for flavour and gossip, and the outdoor bath heals.
- **Gossip (r1 4a):** three townsfolk, three different rumours about why Ibuki quit (an injury,
  a loss to the Champion, "he saw something at the League"). Nobody agrees.
- **Akira (r1 5b):** waits by the gym door; the battle is forced before you can enter, so you
  can heal first. (The design said "at the town entrance"; this moves him.)
- **Ren (r1 6b):** at gym 2, in town, waiting to challenge Ibuki officially. No battle, one dry
  line.
- **Fitting the layout (r2 1a):** copy Lavaridge's layout and make small edits: cut a south
  entrance for Route 2, and put a short waterfall on the west edge by the gym (general tileset
  waterfall metatiles, to confirm at build time). Everything else stays.
- **The inn (r2 2a):** the house becomes the inn; the herb shop stays a herb shop (bitter
  mountain medicine).
- **The bath's heal (r2 3a):** one of the old women in the bath is the attendant: "Sit. Soak."
  Talking to her heals the team.
- **Gossips (r2 4c):** two in town and one in the inn, plus the herb-shop keeper, who won't
  gossip: "Ask him yourself."
- **Vanilla extras (r2 5a):** both gifts dropped (no egg, no Charcoal); the herb shop only sells.
- **Ibuki at the falls (r2 6b):** always under the falls before the badge ("The gym's open. Go
  in."); also in the gym.

## Leaning

## Open questions

## Gaps and tensions

- Ren's cameo: gym 2 or gym 3? (settled by r1 6b: gym 2, in town)
- Lavaridge's layout: the only exit is east (Route 112 joined there); no south entrance from
  Route 2, no waterfall tiles (the general tileset has waterfall metatiles), the gym door is at
  the bottom-left (5,15). The hot spring water doesn't heal in vanilla; healing needs a script.
- Lavaridge's vanilla extras: the egg gift (Wynaut), the herb shop (herbs, and its Charcoal gift).
- r1 2a + 5b: Ibuki under the falls and in the gym are two objects (settled by r2 6b: both
  before the badge).
- The pilgrims' sprite is shared with Route 2's pilgrims.
- Music for the town (placeholder).

## Parked ideas

## Rejected
