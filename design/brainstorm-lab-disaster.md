# Brainstorm: the professor's lab disaster

Working notes. Decisions move into `story-outline.md`, `characters.md`, `side-quests.md` and
`locations/hamakaze.md` when settled; this file stays as the record. **Promoted** into `story-outline.md`, `characters.md`,
`side-quests.md`, `locations/hamakaze.md`, `game-bible.md`, `progression.md` and `whats-left.md`.

## Givens (from the docs)

- **Professor Kashiwagi** (woman): researches the cycle; her family takes the hero in; her husband
  Makoto runs the household; her son Haru is his first friend. Her Altaria sits in the lab from
  Act 1. She gave him the research list (Eien variants, side-quests E1/E2).
- **Act 3 beat 5:** Haru's letter calls him home from Hoshimi ("she's close to a breakthrough"); a
  scene takes him to Hamakaze; she dies in a lab disaster while he's there, leaving the research
  that explains the cycle.
- **Beat 6, right after:** her last research, found with Haru (his step 3: sorting her notes,
  finishing a research entry she started; keepsake Haru's finished map), says plainly why Palkia
  brought him; Celebi shows him a glimpse of the ended world it came from. Haru gives him Altaria
  (fast travel). Then Shimotsuki: Akira at Fuyumi's grave, Kaede's aurora night.
- **What the research must explain:** the cycle (Arceus fading, the world remade); Palkia brought
  him as a test (will an outsider keep the worlds apart or join them?), chosen because a fan sees
  this world from outside; Celebi came from a future where the cycle went wrong and the world
  ended, saw him there and led Palkia to him.
- **Already known by now:** the League's cover-up and Tokoyo's plan (the Hoshimi records); Nami
  chose her world. The tournament disaster was Tokoyo's test of a small machine on a thinning
  (Fuyumi and Hashimoto died holding it back).
- **Tone:** deaths shown plainly and briefly; no deathbed speeches. "Everything ends, and that's
  allowed"; good people can want opposite things.
- **Tools:** the thinning effect is built (`WEATHER_THINNING`), Celebi's flicker, the Altaria
  object in the lab (`LOCALID_LAB_ALTARIA`).

## Decided

- **The cause (r1 1a):** her own experiment. To prove other worlds exist she tunes her instruments
  to a thin place under Hamakaze's shore, and a thinning opens in the lab. No villain: the cost of
  knowing. (The tournament was Tokoyo's disaster; this one is no one's fault.)
- **The breakthrough (r1 2c):** both why he's here (proof of Palkia's door, its test, Celebi's
  future) and how a cycle can end safely (what he does at the door mountain in Act 4). Her death
  hands him his past and his task.
- **Her death (r1 3a):** she sends him and Haru out with her notes and Altaria, and stays to shut
  the instruments down. The lab goes grey, then quiet.
- **Haru (r1 4c):** there; he wants to go back in, and the hero pulls him out.
- **The player (r1 5a):** walks out of the greying lab, the thinning effect on, a few turns of
  time pressure, then the doors.
- **Afterwards (r1 6a):** that evening at the Kashiwagi house: Makoto, Haru and the hero, little
  said. Haru's step 3 the next day.
- **The thin place (r2 1a):** under the beach where he woke up: Palkia set him down at a thin
  place, which is why she studied there and why Celebi found him there. The opening becomes a
  clue; nothing earlier changes.
- **Her notes (r2 2c):** Haru reads the key line aloud (his step 3); the full notes go into the
  journal, one page per topic (the cycle, Palkia's test, Celebi's future, the ending).
- **Celebi's glimpse (r2 3c):** that night Celebi takes him to the beach where he woke; the glimpse
  is that beach with no colour and no snow, the sea not moving (the thinning effect on Hamakaze).
- **Ending a cycle safely (r2 4c), as a principle only:** someone from outside has to carry the
  change (the world can't remake itself from inside; the outsider forgets), and Arceus has to be
  let go, not saved: help the cycle finish instead of feeding it, the opposite of Minato. Details:
  the Act 4 brainstorm.
- **Altaria's name (r2 5a):** Kumo (雲, "cloud"), the professor's nickname for it.
- **The lab afterwards (r2 6b):** grey (the thinning's grey tiles) until the epilogue, but
  enterable; her desk is the one spot still in colour, where Haru's step 3 happens.

## Defaults (not asked; change any)

- **Order:** Haru's letter (Hoshimi) → Hamakaze, a calm scene with the professor and Makoto (she
  shows him the readings; Kumo on its beam) → the next day in the lab, the thinning opens → she
  sends him and Haru out with the notes and Kumo; Haru turns back, he pulls him out; the walk out
  through the greying lab → outside, quiet → evening at the house (Makoto runs from the house when
  it happens) → that night, Celebi and the beach: the glimpse → next day, Haru's step 3 at her
  desk in the grey lab, the key line, the journal pages → Haru gives him Kumo (fast travel) →
  Shimotsuki.
- **The League:** silent this time (no statement); people in Hamakaze talk about "the lab
  accident". `TODO(design)`: if the League should say something.
- **The thin place under the beach** joins the game bible's list of thin places (a scene place,
  not a battle-effect map unless the design adds it).
- **Lines:** the professor's last words and Haru's are drafted at build time, in
  `dialogue-style.md`'s voice (short, plain; no speech).

## Leaning

## Open questions

## Gaps and tensions

- r1 1a adds a thin place under Hamakaze's shore (thin places so far: the shrines and the door
  mountain). It needs to sit in the game bible's list, and maybe a hint earlier (Act 1).

## Parked ideas

## Rejected
