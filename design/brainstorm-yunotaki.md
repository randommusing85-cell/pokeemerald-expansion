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
  waterfall metatiles, confirmed at build time). Everything else stays.
- **The inn (r2 2a):** the house becomes the inn; the herb shop stays a herb shop (bitter
  mountain medicine).
- **The bath's heal (r2 3a):** one of the old women in the bath is the attendant: "Sit. Soak."
  Talking to her heals the team.
- **Gossips (r2 4c):** two in town and one in the inn, plus the herb-shop keeper, who won't
  gossip: "Ask him yourself."
- **Vanilla extras (r2 5a):** both gifts dropped (no egg, no Charcoal); the herb shop only sells.
- **Ibuki at the falls (r2 6b):** always under the falls before the badge ("The gym's open. Go
  in."); also in the gym.
- **Ren (r3 1b):** arrives as you leave the gym with the badge: a nod, "Next.", and he walks in.
- **The gym's inside (r3 2c):** Dewford's gym (the vanilla Fighting gym): dark at first, the
  light grows as you beat trainers, like reaching clarity under the falls (misogi).
- **The gym guide (r3 3b):** a retired pilgrim who trained under Ibuki; the guide's tips in his
  own voice. Uses the pilgrim sprite.
- **The inn (r3 4a):** the innkeeper (the inn's gossip) and JIRO, Route 2's porter, unloading
  baskets.
- **The way onward (r3 5a):** Lavaridge's east exit stays, blocked for now ("The road east is
  shut for the thaw."); where it leads is `TODO(design)`.
- **Music (r3 6b, vanilla placeholder):** Fallarbor's track.
- **Defaults (r3):** Ren uses a vanilla Ace Trainer sprite for now; the Pokémon Center keeps
  Lavaridge's back door from the hot-spring side; Akira's, Ibuki's, the gossips' and Ren's lines
  are drafted at build time (`TODO(design)`).

## Leaning

## Open questions

Promoted into `locations/yunotaki.md`, `story-outline.md`, `side-quests.md` and
`whats-left.md`. Nothing open from rounds 1-3. Later: the onward route, the lines, Ibuki's and the pilgrims'
sprites, a waterfall hall or climbing gym in a Porymap redraw.

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
