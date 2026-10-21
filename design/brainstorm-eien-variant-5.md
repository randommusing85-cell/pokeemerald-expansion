# Brainstorm: the fifth Eien variant

Working notes for the Eien variant after Eien Ledyba. Decisions move into `variants.md` (and the
location doc) when settled; this file stays as the record. **Promoted** into `variants.md`,
`locations/route-6.md`, `route-7.md`, `minori.md` and `whats-left.md`.

## Givens (from the docs)

- **The variants so far** (`variants.md`, "Others"): each answers the gym after its route, and
  each has an evolution rule tied to a place or a condition, research on the professor's list
  (shown after the gym before it), and a journal note.
  - Eien Poochyena (Rock/Dark): Route 1, before the Ice gym. Touched by the fading.
  - Eien Hoothoot (Ghost/Flying): Route 2, before the Fighting gym. Touched.
  - Eien Wooper (Ground/Steel): Route 3, before the Electric gym. Adapted to the mine.
  - Eien Ledyba (Bug/Fire): Route 4, before the Grass gym. Not touched: keeps its colour in
    the greyed orchard.
- **How many are left** (`brainstorm-eien-variant-4.md` r1 4b): about three more, one for each
  remaining gym a variant answers well, plus Trubbish's split.
- **The remaining gyms** (`characters.md`):
  - 5, Kanaya: Takumi (Fire), Magcargo / Bronzong / Coalossal, Lv 35-38. The route before it
    is Route 5, the snowy beech forest (Lv 30-35, Act 3's first road). Its planned species are
    Pinsir, Heracross, Teddiursa, Stantler and Hoothoot, with Duskull in a greyed patch.
  - 6, Hoshimi: Tsukiko (Psychic), Xatu / Solrock / Lunatone, Lv 42-45. Before it: Route 6,
    the terraced hillside (Lv 34-37), and Route 7, the highland plateau (Lv 38-42).
  - 7, Uminari: Ushio (Water), Kingdra / Sharpedo / Wailord, Lv 48-50. Before it: Route 8,
    down to the strait (Lv 44-47).
  - 8, Kawara: Tome (Ghost), Chandelure / Banette / Dusknoir, Lv 52-55. Before it: Route 9,
    inland to the mountain (Lv 48-51).
- **Act 3:** the fading shows more (greyed patches on Route 5); Tokoyo is open now.

## Decided

- **Gym (r1 1b):** it answers gym 6 (Tsukiko, Psychic), on Route 6 or 7. Route 5's forest is
  left without a variant: Eien Wooper already answers gym 5.
- **Species (r1 2d):** Stantler as a Japanese serow (*kamoshika*) of the high country, a
  protected Tohoku animal, Dark/Ghost.
- **Fading (r1 3a):** touched by the fading. That makes three touched, two not.
- **The last variants (r1 4a):** this one (gym 6), then one for gym 7 and one for gym 8, plus
  Trubbish's split.

- **Route (r2 1c):** both. It's rare on Route 6 near the terraces, where the hero first glimpses
  it around Minori's festival thinning, and common on Route 7's plateau, before the gym.
- **Evolution (r2 2b):** Eien Wyrdeer, the engine's Wyrdeer (Gen 8, 525) as its evolved form,
  Dark/Ghost too, with an Eien rule instead of vanilla's (using Psyshield Bash 20 times). It's
  "???" to the hero, and it needs no new name.
- **Look (r2 3a):** a faded serow.
  - A shaggy dark-grey coat and a pale face mask (real serow have pale faces).
  - Its antler orbs are dim, hollow grey, like holes in the world.
- **Stats (r2 4a):** a physical Dark attacker. Eien Stantler is 73 / 105 / 67 / 70 / 65 / 85
  (HP / Atk / Def / SpA / SpD / Spe), 465.
- **Abilities and moves (r2 5a):**
  - Abilities: Intimidate / Frisk / Cursed Body (hidden).
  - Moves: Bite (1, replacing Tackle), Shadow Sneak (16, replacing Sand Attack), Crunch (37,
    replacing Zen Headbutt). It keeps Astonish, Hypnosis and Confuse Ray.
- **Defaults (r2 6):**
  - Research on the professor's list, shown after gym 5's badge.
  - A journal note for its evolution rule.
  - The shiny is a snow-white winter coat.

- **Evolution rule (r3 1a):** into Eien Wyrdeer after using Shadow Sneak 20 times (the engine's
  `IF_USED_MOVE_X_TIMES`, as vanilla Wyrdeer does with Psyshield Bash), as if it learns to slip
  between worlds. The journal note hints at it (draft: "It slips into shadow when it moves.").
- **Eien Wyrdeer's look (r3 2a):** the old serow.
  - Bigger, with a heavier, frosted coat.
  - Antlers branching like dead winter wood, with wider hollow grey orbs.
  - A long grey mist of a beard.
- **Eien Wyrdeer's stats (r3 3a):** the same shift on vanilla Wyrdeer (103 / 105 / 72 / 105 / 75
  / 65): 103 / 115 / 77 / 90 / 75 / 65, 525. The same abilities.
- **Evolution move (r3 4a):** Phantom Force.
- **The glimpse at Minori (r3 5b):** during the festival thinning, a grey serow stands on a terrace
  edge watching, the only thing not walking into it, then leaves. It's an overworld object, not
  a battle.

## Leaning

## Open questions

- Routes 6 and 7's wild tables (rates); Route 6's terrace slot is rare.
- The serow's overworld sprite for the Minori glimpse (vanilla Stantler's recoloured, or its
  follower sprite).
- Both dex entries and the research tier lines, drafted at build time.
- When the user wants it: the journal note's wording.

## Gaps and tensions

- r3 1a: the journal note can't easily say "used 20 times" as a level would; it's a hint line
  shown once Eien Stantler reaches some level without evolving (the build sets the level, about
  Lv 38).
- Vanilla Stantler: 73 / 95 / 62 / 85 / 65 / 85 (HP / Atk / Def / SpA / SpD / Spe), 465;
  Intimidate / Frisk / Sap Sipper. Learnset: Tackle 1, Leer 3, Astonish 7, Hypnosis 10, Stomp 13,
  Sand Attack 16, Take Down 21, Confuse Ray 23, Calm Mind 27, Role Play 32, Zen Headbutt 37.
- In this engine, Stantler evolves into Wyrdeer (Gen 8, Normal/Psychic, 525) after using
  Psyshield Bash 20 times. The hero doesn't know Gen 6+, so Wyrdeer is "???" to him.

- Eien Wooper (Ground/Steel) already hits gym 5's Magcargo and Coalossal 4x with Ground. A gym 5
  variant would overlap it, unless it's a different answer (Water, Fighting) or Wooper's
  Steel weakness to Fire is the point.
- Routes 6-9 have no species planned yet, so a later gym's variant is open ground.

## Parked ideas

- Trubbish's Fresh Water split (planned, its own brainstorm).

## Rejected
