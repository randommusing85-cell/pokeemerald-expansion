# Brainstorm: Route 3's trainers and Akari's crew

Working notes. Decisions move into `locations/route-3.md` and `locations/isaribi.md` when
settled; this file stays as the record.

## Givens (from the docs)

- **Route 3** (`route-3.md`): trainers Lv 18-23; the bridge Ace Trainer about Lv 25. Six
  trainers: a Matagi (Tohoku's traditional mountain hunters), a Raftsman (works the river), a
  Hiker, a Pilgrim (heading down from Yunotaki's falls), an Engineer (fixing the telegraph line;
  previews Electric), and the Ace Trainer (vanilla class; League-sponsored, arrogant, heading for
  the tournament). He battles them win or lose; then Yuki beats them (Yuki's design is its own
  brainstorm).
- **Wild on Route 3:** the gorge: Eien Wooper, Psyduck, Marill, Lotad, Taillow, Shinx; the cave:
  Eien Wooper, Zubat, Geodude, Roggenrola.
- **Akari's crew** (`isaribi.md`): a squid-boat fisher and a deckhand, Lv 22-25, from Chinchou,
  Mareep or Pikachu. Akari: Magneton 24, Luxio 24, Lanturn 27.
- **The player's answer:** Eien Wooper / Quagsire (Ground/Steel; weak to Water, Fighting, Fire,
  Ground). Ibuki's TM31 Brick Break is in hand.
- **Pattern so far:** Route 2's trainers are locals with in-character teams (Woodcutter, Porter,
  Charcoaler, Pilgrims), Japanese placeholder names, one double battle; new classes when a
  vanilla one doesn't fit (class names up to 12 characters).
- **Slots:** no spare trainer slots; new trainers alias unreachable vanilla Hoenn trainers
  (`include/constants/opponents.h`). Default, not a question.
- **Vanilla classes that exist:** Hiker, Fisherman, Sailor, Expert, Camper, Guitarist, Kindler,
  and FRLG's Engineer (`TRAINER_CLASS_ENGINEER_FRLG`).

## Decided

- **What the teams teach (r1 1c):** in character, but a few carry Water and Fighting moves, so
  Eien Wooper isn't a free win: the Raftsman's Water, the Hiker's and the Pilgrim's Fighting.
- **Classes (r1 2a, 3a):** two new classes, Matagi and Raftsman; the Engineer uses FRLG's
  `TRAINER_CLASS_ENGINEER_FRLG`.
- **The Ace Trainer (r1 4b):** Kirlia Lv 24, Staravia Lv 24, Machoke Lv 25. Beatable with care;
  Machoke tests Eien Wooper.
- **Akari's crew classes (r1 5a):** two new classes, Squid Fisher and Deckhand.
- **The crew's teams (r1 6a):** the fisher Chinchou and Mareep, the deckhand Pikachu and
  Magnemite (Lv 22-25). Chinchou warns of Lanturn, Magnemite previews Magneton.
- **Matagi (r2 1a):** Herdier Lv 20 (his hunting dog), Teddiursa Lv 19 (a bear cub he raised).
- **Raftsman (r2 2b):** Psyduck Lv 20 (Water Gun), Lotad Lv 20: the river's own Pokémon.
- **Hiker and Pilgrim (r2 3a):** Hiker Geodude Lv 20, Timburr Lv 21; Pilgrim Meditite Lv 21,
  Makuhita Lv 20.
- **Engineer (r2 4b):** Shinx Lv 21, Magnemite Lv 22: previews Luxio and Magneton.
- **No double battle (r2 5c):** six trainers on the route.
- **The Ace Trainer's manner (r2 6a):** boastful about the League's money. Draft: "The League
  covers my travel. You're paying for yours, I guess." Yuki, unsponsored, then beats them.

## Defaults (not asked; change any)

- **Names (placeholders, Route 2 style):** Matagi ISAMU, Raftsman SHIGERU, Hiker NOBORU
  ("to climb"), Pilgrim AYAME (the female pilgrim sprite), Engineer KENTA, Ace Trainer KAITO;
  Akari's crew: Squid Fisher GENTA, Deckhand MIO. None clash with the cast.
- **Sprites:** vanilla stand-ins: the Matagi a Hiker or Ruin Maniac, the Raftsman a Fisherman,
  the Engineer FRLG's Engineer, the Ace Trainer a vanilla Ace Trainer (male), the crew a
  Fisherman and a Sailor. The Pilgrim uses `OBJ_EVENT_GFX_EIEN_PILGRIM_F` / `TRAINER_PIC_EIEN_PILGRIM_F`.
- **Moves:** each Pokémon's level-up moves at its level, except where noted (Psyduck's Water
  Gun). Levels fit the curve (Route 3 18-23, the Ace Trainer 24-25, gym 3's trainers 22-25).
- **Lines:** drafted at build time in `dialogue-style.md`'s voice (`TODO(design)`).

## Leaning

## Open questions

## Gaps and tensions

- The Ace Trainer's team sets the bar Yuki "beats easily": her Act 1 team has to look clearly
  stronger (her own brainstorm).

## Parked ideas

## Rejected
