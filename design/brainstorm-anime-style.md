# Brainstorm: the anime style for the movie cutscenes

Working notes for the visual style of Eien's movie-like cutscenes, made with Higgsfield
(the user's settled production tool; [cutscenes.md](cutscenes.md)). Decisions move into a
style guide section of `cutscenes.md` when settled; this file stays as the record. Nothing
here is decided until the user picks it.

## Givens (from the docs)

- **Tool:** Higgsfield produces the movie cutscenes (`cutscenes.md`, confirmed 2026-10-21).
  Reachable from this session (ultra plan, about 7,400 credits at the start of this
  brainstorm).
- **Where they're used:** a few major moments; traditional Pokémon scenes everywhere else.
  Candidates in `cutscenes.md`: Palkia's catch and the arrival, the Lake Usurai crossing,
  the tournament thinning, Celebi's death and the renewal, the hospital ending.
- **Canon is fixed:** story, characters and their designs (`characters.md`: the hero's
  short messy dark hair, grey hoodie and jeans; Kaede's red hakama under a navy winter
  coat; Yuki's straw hat and festival cord; Ibuki's gi and prayer beads). Dialogue follows
  `dialogue-style.md`: plain, short, no overdramatic narration.
- **The world:** northern Japan in winter (Tohoku): snow country, a fishing coast, shrines,
  hot-spring towns, a door mountain. Quiet relationships. A world that fades: colour drains,
  snow stops, things stop moving; Celebi flickers. Aurora nights.
- **Delivery:** the game is moving to RPG Maker XP + Pokémon Essentials v21.1 (user,
  2026-11-26), so a movie can play as a movie; the GBA's 240x160 adaptation is no longer a
  constraint. Codex prototypes video playback, skipping and the return to gameplay in
  Essentials before a full cinematic is produced. Essentials' default screen is 512x384 (4:3).
- **Credits:** every AI asset goes in `asset-credits.md`.

## Tensions

- **Two media, one look.** A painterly movie cut against Gen 3 pixel art can feel like a
  different game. Whatever the style, the transitions in and out (and the in-engine
  adaptation) decide whether it reads as one world.
- **Consistency vs generation.** AI video drifts: faces, coats, Celebi's shape. The style
  has to be one that survives drift (strong silhouettes, few details, fixed palette) or the
  shot list has to avoid what drifts (faces in close-up, hands).
- **Quiet tone vs cinematic habit.** The brief forbids speeches and spectacle; the tool is
  good at spectacle. The style should make stillness look intentional.
- **The fading is the motif.** The in-game thinning (grey, snow stopped) already exists; the
  movie version has to be the same idea, recognisably.
- **Palkia** is an official design. It has to be itself, in whatever style; it can't be
  redesigned.

## Decided

Round 1 (user, 2026-11-26: `1a, 2b+d, 3b, 4a, 5a, 6a`):

- **Direction (1a): restrained cel.** Flat cel shading, a thin dark line, gouache-painted
  winter backgrounds, a muted cool palette, a mostly still camera. Stillness is the style.
- **The fading in motion (2b + d):** the paint leaves and the ink stays (the frame turns into a
  line drawing), and everything stops: snow hangs in the air, the sea doesn't move. The same
  idea as the game's grey thinning, said in paint.
- **Proportions (3b):** grounded late teens, about seven heads, plain faces.
- **Colour rule (4a):** cold blue-greys with one warm accent per scene (a lamp, Yuki's cord,
  Kaede's hakama). On aurora nights the aurora is the accent.
- **Words (5a):** the pilot is wordless: music and sound only. The game's text carries the
  words before and after.
- **Pilot (6a):** Palkia's catch and the arrival on Hamakaze's beach. It needs the accident
  settled first (round 2).

## Leaning

- The one warm accent of the arrival scene: Celebi's green (it's the first living colour he
  sees in Eien). A default, proposed in round 2.

## Open questions

- Round 2 (below): the accident; Palkia; where the movie starts and ends; length and
  skipping; frame shape; sound.
- Later: reference sheets (the hero, Celebi, Palkia in this style); the shot list and the
  Higgsfield brief; music for the game as a whole; the later cutscenes.

## Gaps and tensions

- No anime-form references exist yet: the characters are pixel sprites and AI battle pics.
  Reference sheets are a production step after the direction is picked.
- Music and sound: nothing is decided for the game either (placeholder tracks).
- The accident and Palkia's lines are `TODO(design)` in `locations/prologue-bedroom.md`; the
  arrival pilot needs them.

## Parked ideas

## Rejected

## Round 1 (asked 2026-10-21)

1. **Direction.** a) Restrained cel: flat cel shading, thin dark line, gouache-painted winter
   backgrounds, a muted cool palette, mostly still camera. b) Soft watercolour: bleeding
   edges, paper grain, faint line, snow as unpainted paper; motion is slow pans and
   dissolves. c) Crisp cinematic: clean digital line, volumetric light, depth of field,
   moving camera. d) Hybrid: painted backgrounds with the characters kept as enlarged
   pixel sprites with limited animation (a bridge to the GBA). Recommendation: a.
2. **The fading in motion.** a) Desaturation wiping across, as in the game. b) The paint
   leaves and the ink stays: the frame becomes a line drawing. c) Grain and static.
   d) Stillness: everything stops, snow hangs in the air. Recommendation: b + d.
3. **Proportions.** a) Gen 3-like young and soft (about six heads). b) Grounded late teens
   (about seven heads), plain faces. c) Small and stylised. Recommendation: b.
4. **Colour rule.** a) Cold blue-greys with one warm accent per scene (a lamp, Yuki's cord,
   Kaede's hakama). b) Desaturated throughout, the aurora the only saturated thing.
   c) Naturalistic. Recommendation: a, with b's rule on aurora nights.
5. **Words.** a) Wordless: music and sound only; the game's text before and after. b) A few
   subtitles in the game's font. c) Voices (Higgsfield can). Recommendation: a for the pilot.
6. **Pilot scene.** a) Palkia's catch and the arrival on the beach (short, first thing seen,
   sets the style; needs the accident's text). b) The Lake Usurai crossing (Nami, Lapras,
   Celebi: more to keep consistent). c) The Hamakaze wake-up only (no Palkia; safest).
   Recommendation: a.

## Round 2 (asked 2026-11-26)

1. **The accident** (canon: he's playing a Pokémon game when an accident nearly kills him;
   his body lies in a coma all game; he wakes in a hospital). a) Never shown or named: the
   screen cuts to black mid-game, a sound, then nothing. b) Hit by a car on a night walk to
   the shop, game still in his pocket. c) Falls asleep playing; a fire or gas leak in the
   building. d) A sudden collapse at his desk (an illness nobody knew about). Recommendation:
   a (keeps the coma-dream question open, as the outline wants), with the hospital ending
   implying no more than "an accident".
2. **Palkia.** a) Wordless and barely seen: a vast shape and its pearl light in the dark, a
   hand closing. b) Seen clearly, wordless. c) It speaks one line (text over black, before the
   movie). Recommendation: a for the movie; any words Palkia has wait for the ending.
3. **Where the movie starts and ends.** a) Starts on the black screen after the bedroom's last
   text, ends on his closed eyes on the beach; the game picks up with "(…Cold.)". b) Also
   covers Celebi drifting down (the game then starts at "(Is that… a Celebi?)"). c) Only the
   fall and Palkia; the beach stays all in-game. Recommendation: a.
4. **Length and skipping.** a) About 30 seconds, 5-6 shots, skippable from the second viewing
   only. b) About 30 seconds, always skippable. c) About 60 seconds, always skippable.
   Recommendation: b (Codex's handoff asks for skip parity anyway).
5. **Frame shape.** a) 4:3 full screen (Essentials' 512x384). b) 16:9 letterboxed inside 4:3
   (reads "cinema", loses a quarter of the screen). c) 4:3 with soft painted edges, like a
   page. Recommendation: a.
6. **Sound for the pilot.** a) Sound design only (the game's hum cut off, wind, the sea), no
   music. b) A short piano-and-strings cue. c) Sound design, then the Hamakaze town theme
   starts as he wakes. Recommendation: c, once the game has a town theme; a until then.
