# Brainstorm: Eien Wooper's design

Working notes for the Route 3 variant (`variants.md`, `locations/route-3.md`). Decisions move into
`variants.md` when settled; this file stays as the record.

## Givens (from the docs)

- Eien Wooper lives on Route 3: rarer in the gorge's grass by the river, more common in the muddy
  pools of the Eien Survey's cleared mine tunnel. It's the answer to gym 3 (Akari, Electric:
  Magneton with Flash Cannon, Luxio with Ice Fang, Lanturn Lv 27 with Water moves), so it must
  be Ground (immune to Electric).
- Variant rules (`brainstorm-eien-species.md`): regional forms; the same stat total as the
  original; existing abilities that fit the theme. Some variants are touched by the fading
  (Poochyena, Hoothoot, Bulbasaur), some aren't (Froakie).
- Vanilla Wooper: Water/Ground, 55 / 45 / 45 / 25 / 25 / 15 (210); Damp / Water Absorb / Unaware;
  evolves into Quagsire at Lv 20. Learnset: Tail Whip, Water Gun (1), Rain Dance (4), Mud Shot
  (8), Mist / Haze (12), Slam (16), Yawn (21), Aqua Tail (24) ... Paldean Wooper (Poison/Ground)
  already exists in the engine.
- Pattern so far: each variant evolves with a place-based twist (Poochyena at its shrine,
  Hoothoot at night on its pass), has seen / battled / caught research steps and a journal note
  for the rule.

## Decided

- **Type and look (r1 1a):** Ground/Steel, a mine Wooper: it lives in the old tunnel's pools, its
  skin crusted with iron and copper ore, its gills glinting metal frills. Against Akari:
  Lanturn's Water 2x, Ice Fang neutral, Flash Cannon resisted.
- **Stats (r1 2b):** balanced bulk: 55 / 45 / 55 / 15 / 35 / 5 (HP / Atk / Def / SpA / SpD / Spe),
  210.
- **Abilities (r1 3a):** Sturdy / Heavy Metal / Unaware (hidden).
- **Early moves (r1 4b):** Mud-Slap (1, replacing Water Gun), Mud Shot (8, as vanilla), Metal
  Claw (16, replacing Slam); otherwise vanilla.
- **Evolution (r1 5b):** into Eien Quagsire at Lv 20+ in the mine tunnel only.
- **Research (r1 6b):** seen / battled / caught, plus a journal note when one reaches Lv 20
  outside the tunnel; a Survey member at the tunnel says they found them "in the old seams" when
  they cleared it (a hint at what the Survey digs for).
- **Eien Quagsire's look (r2 1c):** smooth polished metal, like a Nanbu *tetsubin* (the cast-iron
  kettle of Iwate's ironware craft), with Quagsire's goofy face kept. Ground/Steel.
- **Eien Quagsire's stats (r2 2a):** the same shift as Eien Wooper's on vanilla 95 / 85 / 85 / 65
  / 65 / 35: 95 / 85 / 95 / 55 / 75 / 25 (430).
- **On evolving (r2 3a):** learns Iron Head.
- **Wild rates (r2 4b):** the gorge's grass 10%, the cave 30% (day and night alike).
- **Shiny (r2 5a):** gold ore: a gleaming gold crust instead of iron and copper.
- **Trubbish's split, first pin (r2 6a):** the Fresh Water is used up on evolving, as with
  vanilla held-item evolutions.

## Leaning

- Eien Quagsire's shiny follows Wooper's: gold instead of iron (a gilded kettle). Default, not
  asked.
- Abilities carry over to Eien Quagsire (Sturdy / Heavy Metal / Unaware), as vanilla Quagsire
  keeps Wooper's. Default, not asked.

## Open questions

- Sprites: Eien Wooper and Eien Quagsire as AI drafts, like the trainer pics (its own pass).

## Gaps and tensions

- r1 6b plants a thread: what the Survey digs for in the old seams needs a payoff later (the
  door mountain?).

## Parked ideas

- **Trubbish's split (user, with r1):** later in the game, Trubbish branches at Garbodor's level
  (Lv 36): holding something clean evolves it into a new Pokémon instead of Garbodor. The clean
  item is Fresh Water (it can be held: it's in the Items pocket; the engine's `IF_HOLD_ITEM`
  condition supports it on a level-up evolution). The Fresh Water is used up (r2 6a).
  `TODO(design)`: where Trubbish is found (a later act), the new Pokémon itself (name, type,
  look, stats; its own brainstorm).

## Rejected
