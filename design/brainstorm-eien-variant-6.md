# Brainstorm: the sixth Eien variant

Working notes for the Eien variant after Eien Stantler, the answer to gym 7. Decisions move into
`variants.md` (and the location doc) when settled; this file stays as the record.

## Givens (from the docs)

- **The variants so far** (`variants.md`, "Others"): each answers the gym after its route, with
  an evolution twist, research on the professor's list (shown after the gym before it) and a
  journal note.
  - Eien Poochyena (Rock/Dark, touched by the fading): Ice gym.
  - Eien Hoothoot (Ghost/Flying, touched): Fighting gym.
  - Eien Wooper (Ground/Steel, adapted to the mine): Electric gym.
  - Eien Ledyba (Bug/Fire, not touched: keeps its colour in the greyed orchard): Grass gym.
  - Eien Stantler (Dark/Ghost, touched): Psychic gym.
- **What's left** (`brainstorm-eien-variant-5.md` r1 4a): one variant for gym 7, one for gym 8,
  and Trubbish's split.
- **Gym 7** (`characters.md`, `locations/uminari.md`): Ushio (Water) in Uminari, a tuna port on
  a rough strait, Lv 48-50. Her team is Sharpedo (Water/Dark), Wailord (Water) and Kingdra
  (Water/Dragon). She openly sides with Minato: she lost her husband to the strait.
- **Route 8** (`locations/route-8.md`): down from the highland plateau (Hoshimi) onto the door
  mountain's peninsula, from moor to sea cliffs above the strait, Lv 44-47. No species are
  planned yet. Act 3, after gym 6.

## Decided

- **Species (r1 1b):** Wingull / Pelipper as Electric/Flying: storm gulls of the sea cliffs,
  riding the lightning over the strait. They hit Sharpedo and Wailord hard and Kingdra
  neutrally. Electric/Flying is a type no variant has yet.
- **Fading (r1 2a):** not touched; a creature of the strait's storms. That makes three touched,
  three not.
- **Where (r1 3a):** in the grass by the cliff edge at Route 8's end; common, more common in rain.
- **First sighting (r1 4b):** on the way down, a flock riding a storm front above the cliffs, as
  overworld objects, before the player reaches the grass.

- **Look (r2 1a):** storm gulls.
  - Eien Wingull: a white gull with storm-grey wings and wingtips streaked with yellow lightning.
  - Eien Pelipper: its big bill holds a crackling thundercloud instead of water.
- **Stats (r2 2a):** fast special attackers, shifted toward SpA.
  - Eien Wingull: 40 / 30 / 30 / 70 / 30 / 70 (HP / Atk / Def / SpA / SpD / Spe), 270.
  - Eien Pelipper: 60 / 50 / 85 / 110 / 70 / 65, 440.
- **Abilities (r2 3c):** Static / Keen Eye / Drizzle (hidden) for both stages. With Drizzle, its
  Thunder never misses in rain.
- **Moves (r2 4a):** Thunder Shock (1, replacing Water Gun), Shock Wave (20, replacing Water
  Pulse); Eien Pelipper learns Thunder on evolving; otherwise vanilla.
- **Evolution (r2 5c):** into Eien Pelipper after landing 3 critical hits in one battle
  ("struck by lightning"), the engine's `IF_CRITICAL_HITS_GE` (as Galarian Farfetch'd uses).
  The journal hint (draft: "It's waiting for the right strike.") shows once one reaches Lv 25
  without evolving.
- **Research and shiny (r2 6, defaults):**
  - Research on the professor's list, shown after gym 6's badge.
  - Shiny: a night-storm gull, a dark body with violet lightning.

## Leaning

- Eien Pelipper keeps Eien Wingull's abilities (as decided in r2 3c).

## Open questions

- Route 8's wild table: Eien Wingull common at the cliffs, more in rain; Eien Pelipper likely
  wild too at Lv 44-47.
- The flock's overworld sprite for the first sighting (vanilla Wingull's recoloured).
- Both dex entries and the research tier lines, drafted at build time.

## Gaps and tensions

- The evolution rule shouldn't repeat Eien Ledyba's rain rule: settled by r2 5c (critical hits).
- r2 5c: three critical hits in one battle is hard without help (Galarian Farfetch'd has its
  Leek). The player needs a Scope Lens, Focus Energy or a high-crit move. Eien Wingull learns
  none by level; the build could add one (e.g. Focus Energy), or the hint could point to it.
- r2 3c: Drizzle also powers Ushio's Water moves if she moves in the rain.
- Vanilla Wingull: 40 / 30 / 30 / 55 / 30 / 85 (HP / Atk / Def / SpA / SpD / Spe), 270; Keen Eye /
  Hydration / Rain Dish; Growl and Water Gun 1, Quick Attack 5, Supersonic 10, Wing Attack 15,
  Water Pulse 20; Pelipper at Lv 25: 60 / 50 / 100 / 95 / 70 / 65, 440, Keen Eye / Drizzle /
  Rain Dish.
- Route 8 is Lv 44-47, far above Wingull's Lv 25 evolution, so Eien Pelipper is likely wild there
  too.

- Kingdra is only weak to Dragon and Fairy. A Grass or Electric variant hits Sharpedo and
  Wailord hard but Kingdra only neutrally.

## Parked ideas

- Trubbish's Fresh Water split (planned, its own brainstorm).

## Rejected
