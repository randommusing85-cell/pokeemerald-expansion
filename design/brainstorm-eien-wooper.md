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

## Leaning

## Open questions

## Gaps and tensions

- r1 6b plants a thread: what the Survey digs for in the old seams needs a payoff later (the
  door mountain?).

## Parked ideas

- **Trubbish's split (user, with r1):** later in the game, Trubbish branches at Garbodor's level
  (Lv 36): holding something clean evolves it into a new Pokémon instead of Garbodor. The clean
  item is Fresh Water (it can be held: it's in the Items pocket; the engine's `IF_HOLD_ITEM`
  condition supports it on a level-up evolution). `TODO(design)`: where Trubbish is found,
  the new Pokémon itself (name, type, look, stats; its own brainstorm), whether the Fresh Water
  is used up on evolving.

## Rejected
