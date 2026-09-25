# Brainstorm: first milestone (prologue through gym 1)

Working notes (see `.claude/skills/brainstorm/SKILL.md`). Firm decisions move into the
design docs: `README.md` milestone, `progression.md`, `characters.md`, `story-outline.md`,
and a location doc per map.

## Decided (from the story docs)

- Scope: prologue in our world → hometown (wakes in Eien, Celebi, Kashiwagi household,
  Haru, journal) → meet Akira → route 1 → first town and gym 1 (Fuyumi, Ice).
- Hero: player-named, fixed male; mostly silent; inner thoughts show his game knowledge.
- Celebi follows him on the map (not in the party) and can't battle.

## Decided (this brainstorm)

- **Prologue:** a small bedroom map in our world built from existing indoor tiles; he's
  playing a Pokémon game. The accident happens in text on a black screen, then Palkia.
- **First Pokémon:** Professor Kashiwagi offers three starters (Fire/Water/Grass) and he
  picks one; as a fan he recognizes them.
- **Gym 1 fairness:** route 1 always has a Pokémon that's good against Ice (e.g. Rock or
  Fighting near the mountain path), and Fuyumi's team is small (2 Pokémon), bulky rather
  than hard-hitting.
- **Fuyumi:** a stern veteran in the gym, softer at home with Akira.
- **Slice ending:** just after gym 1, Nami's first meeting (she helps him when he's lost).
- **Snow look:** find a community snow tileset now; credit it in `asset-credits.md`.
- **Town names:** hometown **Hamakaze** ("sea wind"), first town **Shimotsuki** ("frost month").
- **Regional variants:** Eien has its own variants of some existing Pokémon (not all), which
  can have different types.
- **Shinies are rare**, and both original Pokémon and the variants have shiny forms.
- **Variant count:** a handful for the whole game (5-10), 1-2 in the first milestone.
  (Now in tension with the starter choice; see below.)
- **Variant theme:** mostly "touched by the fading" (Pokémon living where the worlds are thin
  have shifted, toward Ghost/Psychic/Dark), with some adapted to the cold (Ice/Water).
- **Starters:** Eien variants of **Torchic, Bulbasaur and Froakie**.
- **Route 1's anti-Ice Pokémon** is an Eien variant with a Rock or Fighting type.
- **Shiny odds:** 1 in 4,096 (`SHINY_ODDS 16`). The Shiny Charm is a post-game reward.
- **Fuyumi's team:** Spheal and Bergmite (ace).
- **Variant budget:** the 9 starter variants are separate from the 5-10 other variants
  (about 15-19 in total).
- **Starter variant types:** Torchic line Fire/Ghost, Bulbasaur line Grass/Water, Froakie
  line Water/Ice. (Pending the balance issue below.)
- **Starter evolution:** first evolution raised to about Lv 18, so the milestone only needs
  the first stage of each.
- **Route 1 variant:** Poochyena, Rock/Dark, a shrine guardian dog (komainu) touched by the
  fading.
- **Starters in the story:** Akira takes the one strong against the player's; Haru takes the
  third (so Haru can be a tag-battle partner later).
- **Akira:** met at Kashiwagi's lab, battle right after picking starters. A second meeting
  in Shimotsuki, where he shows the player his mother's gym.

## Proposed defaults (not asked; change if wrong)

- **Celebi follower** uses the engine's follower NPC system (`include/follower_npc.h`) with
  Celebi's existing overworld sprite. No engine changes needed.
- **Level curve:** route 1 wild Pokémon Lv 2-5; route trainers Lv 5-8; gym trainers Lv 9-11;
  Fuyumi's ace about Lv 13-14.
- **Palkia** has an overworld sprite in the engine already (`graphics/pokemon/palkia/`).

## Leaning

_(nothing yet)_

## Open questions

1. Fixing the starter type triangle (see below).
2. Gym 1 difficulty now that two starters resist Ice.
3. How variants are labeled in-game ("Eien Poochyena"?).
4. Route 1: encounter table feel and trainer count.
5. The journal's first page.
6. Fakemon: none, a few, or decide later (the user is still thinking).

## Gaps and tensions

- **The starter triangle breaks with these types.** Grass/Water hits both others
  super-effectively and neither hits it back (Water cancels Fire's advantage over Grass;
  Water cancels Ice's too). Fire/Ghost hits neither of the others super-effectively. So the
  Bulbasaur variant is the clear best pick and Torchic the weakest, and "Akira takes the one
  strong against yours" has no answer if the player picks Bulbasaur.
- **Gym 1 got easy.** Fire/Ghost takes half damage from Ice, Water/Ice a quarter; only
  Grass/Water takes normal damage. Fuyumi's Spheal (Ice/Water) is also hit hard by Grass.
- **The milestone needs 4 new variant sprite sets:** the three starters' first stages and
  Eien Poochyena, each with a shiny palette.
- **Ice as gym 1.** Grass starters are weak to Ice; Fire, Fighting, Rock and Steel beat it.
  The starter trio and route 1's wild Pokémon decide whether gym 1 is fair for every pick.
- **No snow tileset in the engine.** Vanilla Emerald and FRLG have no snowy overworld tiles
  (only ice cave floors). A snow-country look needs a community tileset (credited in
  `asset-credits.md`) or custom art.
- **Variant art cost.** Each variant needs a new front sprite, back sprite, icon and shiny
  palette, plus species data (types, stats, moves, evolutions, dex entry). That's close to
  the art cost of a fakemon.
- **Shiny odds today:** `SHINY_ODDS 8` in `include/constants/pokemon.h`, i.e. 1 in 8,192
  (the Gen 3 rate). Modern games use 1 in 4,096.
- **Grass/Flying starters** take 4x damage from Ice; avoid one if gym 1 is Ice.
- **Celebi can't battle**, so he needs a battling Pokémon before the first trainer fight.

## Parked ideas

_(none yet)_

## Rejected

_(none yet)_
