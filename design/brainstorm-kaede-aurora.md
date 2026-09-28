# Brainstorm: Kaede's aurora-night tag battle (her quest step 2)

Running notes. Nothing is decided until it's under **Decided**; decisions move into
`side-quests.md`, `characters.md` and the location docs when the user agrees.

## Givens

- Kaede's quest step 2, Act 3, "a thin place on an aurora night": she shows him a folk tale
  "happening": Eien variants act strangely under the aurora. It adds a research step. Points
  come from his answer about whether the tales are true (`side-quests.md`).
- They fight a tag battle side by side (opponents `TODO(design)`), a preview of the finale.
  Her second Pokémon joins her team here (Froslass or Mismagius, `TODO(design)`).
- She keeps the folk version of the tales and doesn't know they're true (`characters.md`).
- Every shrine area is a thin place; the mountain is a thin place but not a shrine area. Thin
  places have a terrain that boosts Ghost and Psychic moves; the aurora is a weather on clear
  nights. Both effects' exact rules are `TODO(design)` (`game-bible.md`).
- Research quest E3: night-only research steps on aurora nights (`side-quests.md`).
- Act 3: Akira has joined Minato; Fuyumi (gym 1, Shimotsuki) died at the tournament. Kaede's
  shrine is in Shimotsuki.
- Engine: partner battles against two trainers (like Steven's); a follower NPC can also join
  the player in wild battles (`include/config/follower_npc.h`, off by default; enabling it
  grows the save block).

## Decided

- **Opponents (1a):** two Eien variants acting strangely under the aurora: a wild double
  battle with Kaede beside him. The tale happening is the battle.
- **Place (2a):** her shrine in Shimotsuki (already a thin place). No new map; Shimotsuki gets
  an Act 3 visit, after Fuyumi's death.
- **The night (3c):** the first aurora night is story-set (she says come back tonight, he
  rests at the shrine); after that, aurora nights come back at random for the E3 night
  research.
- **"Acting strangely" (4a+b):** on the map they move oddly, glow and gather at the shrine;
  and some Eien variants appear only on aurora nights at thin places (aurora-only encounters).
  No new battle rules needed.
- **Her second Pokémon (5a):** Froslass, drawn by the aurora; it stays with her after the
  battle. Mismagius joins before the League (step 3).
- **Default (engine):** a partner in a wild double battle uses the engine's follower-NPC
  partner (`include/config/follower_npc.h`, a config switch; it grows SaveBlock3 a little).

- **The variants (r2 1a):** Eien Poochyena and Eien Mightyena: the stone dogs "wake" under the
  aurora and gather howling at the shrine. No new species. The aurora-only encounter is wild
  Eien Mightyena, which appears in the wild only on aurora nights at thin places (answers
  where wild Eien Mightyena appear). `TODO(design)`: the tale's text.
- **Kaede's reaction (r2 2a):** flatly: "The tales say they do this." Then she asks him whether
  the tales are true (the question that earns her points).
- **Froslass (r2 3a):** after the battle it drifts down with the aurora and settles beside her.
- **Fuyumi's absence (r2 4c):** the gym is closed with a sign; Kaede says one plain line about
  the gym being dark now; a townsperson line or two.

Promoted into `side-quests.md` (Kaede step 2, E3), `characters.md` (her team order and
battles), `variants.md` (wild Eien Mightyena) and the Shimotsuki doc (the Act 3 visit).

## Leaning

_(none)_

## Open questions

- The tale's text (what the stone dogs do on aurora nights).
- Nami's optional aurora-night scene: a different night, or linked to this one.
- Levels of the wild pair and Kaede's two Pokémon at this point.

## Gaps and tensions

- Nami's optional warm scene is also "an aurora night" in Act 3; the two need to be
  different nights or clearly linked.
- She sees a tale happen but "doesn't know they're true": her reaction has to keep that
  (she can wonder without concluding).
- The aurora weather and thin-place terrain have no battle rules yet.

## Parked ideas

_(none yet)_

## Rejected

_(none yet)_
