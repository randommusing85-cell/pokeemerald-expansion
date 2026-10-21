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
- **Delivery:** a Higgsfield export is not a GBA cutscene. Codex measures an in-engine
  adaptation (selected frames, limited animation, 240x160) after the pilot. The master movie
  is kept either way.
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

## Leaning

## Open questions

- Round 1 (below): the overall direction; how the fading looks in motion; character
  proportions; the colour rule; words in the cutscenes; the pilot scene.
- Later: camera language and motion; reference sheets per character; transitions to and
  from gameplay; music and sound; durations; subtitle font; the accident's text (the prologue
  doc).

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
