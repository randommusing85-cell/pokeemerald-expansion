# The prologue and the arrival movie (pilot)

The game's opening: his bedroom, the cut to black, the first movie cutscene, and the hand-off
to Hamakaze's beach. This is the pilot for the movie cutscenes; the style rules at the end
apply to every later one. Decided with the user in
[brainstorm-anime-style.md](brainstorm-anime-style.md) (rounds 1 and 2, 2026-11-26). Story
canon: prologue beat 1 and Act 1 beat 1 in [story-outline.md](story-outline.md).

Written for the RPG Maker XP + Pokémon Essentials port: no engine text codes. In dialogue,
each line is one text box and a `/` starts the next box. *Hero* lines are his thoughts.

## 1. The bedroom (in-game, traditional)

**Trigger:** a new game, after the player's name is entered (`TODO(design)`: confirm the name
is asked before the bedroom, as Essentials' intro does by default). Night. He stands in his
room; the player has control. No party, no journal, no Celebi yet.

Things to look at (each optional, any order):

- **Bed.** *Hero:* Not yet. One more gym.
- **Desk and PC.** *Hero:* Nothing new. It's late.
- **TV.** *Hero:* Nothing on.

**The console** (the only way forward). He sits down with the game:

- *Hero:* Where was I. / Right. One more gym and then I'll sl

The last box stops printing in the middle of the word. The game's small music cuts off with
it. The screen goes black at once: no fade, no accident text, nothing named. One low sound,
not identifiable; then silence for about two seconds. (The outline's "accident" is never
shown or explained: the hospital ending implies no more than that there was one.)

**Outcome:** the movie plays.

## 2. The arrival movie

About 30 seconds, six shots, 4:3 full screen (512x384, Essentials' default; mastered larger,
see the brief). Wordless: no text, no subtitles, no voices. Always skippable; watched or
skipped, the game continues from exactly the same state.

| # | Seconds | Shot | Motion | Sound |
| --- | --- | --- | --- | --- |
| 1 | 3 | Black. One small point of light, the handheld's screen, drifting away from us and going out. | The point shrinks and dims; nothing else. | Silence. |
| 2 | 5 | From above: he falls slowly through the dark, small in the frame, on his back, eyes closed, hoodie and hair lifting a little. No ground, no stars. | He drifts down and away; the camera doesn't move. | A low held tone, barely there. |
| 3 | 5 | Below him something vast turns: a curved edge of pearl light, a plated shoulder with a round pearl set in it. Only edges are lit; the rest is dark on dark. | A slow turn; the pearl catches light once. | The tone deepens. |
| 4 | 5 | A huge clawed hand in silhouette rises under him and closes, gently. Pearl light, pale pink-violet, blooms between the fingers and fills the frame. | The hand closes; the light grows to white. | A single soft chime as the light blooms. |
| 5 | 4 | White becomes a grey winter sky, looking straight up. Snow falls toward us. | Snow only. | Wind, far-off sea. |
| 6 | 8 | From above: he lies on the sand at the tide line, eyes closed. Snow settles on the sand and on his hoodie. A wave runs up, stops short of him, and draws back. Hold. | The wave and the snow; he doesn't move. | Sea and wind. Hamakaze's town theme begins quietly under the last seconds (once the game has one; sea only until then). |

Palkia is never shown whole and never named: a shoulder, a pearl, a hand. Anyone who knows
Pokémon will know it; he doesn't see it at all.

**Colour:** shots 1-4 are near-black with one accent, Palkia's pearl light (pale pink-violet).
Shots 5-6 are the cold blue-greys of Hamakaze with no accent at all: the first living colour
in Eien is Celebi's green, and that belongs to the game, a moment later.

**Outcome:** cut (no fade) to the game on Hamakaze's beach, him at the tide line, and the
waking scene in [locations/hamakaze.md](locations/hamakaze.md) starts: "…Cold."

## 3. What Codex needs (Essentials)

- The bedroom map (draft PR #31 is its GBA reference): bed, desk/PC, TV, console; no exits.
- The console interaction as above, with the text box cut off mid-word and the hard cut to
  black. If cutting a text box mid-word is awkward in Essentials, show the full line
  "One more gym and then I'll sl" and cut to black on the button press.
- Movie playback with skip (any confirm/cancel press), returning to the same state either way:
  on Hamakaze's beach, story state Prologue, no party, input locked until the waking scene runs.
- The town theme (or the sea ambience) should already be playing when the game picture
  returns, so the cut is silent-to-same.
- Save/load: no save point exists before the beach, so nothing can strand him mid-prologue.

## 4. Higgsfield production brief

Order of work; each step's prompts, settings, job ids and picks get recorded in
[art/cutscenes/arrival/README.md](art/cutscenes/arrival/README.md) as they're made, and every
used asset is credited in [asset-credits.md](asset-credits.md).

1. **Reference sheets** in the house style (below): the hero; Palkia (edge-lit, for shots 3-4);
   Celebi (not in this movie; made now so later scenes match). Hamakaze's beach as a
   background plate.
2. **Keyframes:** one still per shot (two for shot 4: hand open, light at full), generated
   from the sheets so he and the beach match across shots.
3. **Motion:** image-to-video per shot at the durations above, with the motion column as the
   whole instruction. Reject any take where the camera moves, he moves in shot 6, or Palkia
   shows more than the shot says.
4. **Assembly:** hard cuts between shots, except 4 to 5 (the white carries over). Master at
   1440x1080, 24 fps; deliver a 512x384 copy for the game in whatever format Codex's playback
   prototype settles on.
5. **Sound:** sound design only (tone, chime, wind, sea); no music inside the movie.

## 5. House style for the movie cutscenes

Decided in round 1; applies to every later movie scene.

- **Restrained cel.** Flat cel shading with at most two tones per colour, a thin dark line,
  gouache-painted backgrounds with visible brushwork. No gradients on characters, no glow
  effects except a scene's one light source, no lens effects.
- **Stillness.** The camera is locked off or drifts very slowly. Motion is small and single:
  snow, a wave, hair, one gesture. A held shot is the default, not a pause.
- **People** are late teens, about seven heads tall, with plain faces: small features, little
  blush, no sparkle. Designs follow [characters.md](characters.md) exactly (the hero: short
  messy dark hair with a side fringe, grey hoodie, blue jeans).
- **Pokémon** keep their official designs and proportions, drawn in the same line and flat
  shading as the people.
- **Colour.** Cold blue-greys with one warm (or one saturated) accent per scene. On aurora
  nights the aurora is the accent.
- **The fading** (when a scene has it): the paint leaves and the ink stays, so the frame turns
  into a line drawing on bare paper, and everything stops: snow hangs in the air, the sea
  doesn't move. Never used for anything else.
- **Words.** The pilot is wordless. Whether later movies carry text is decided per scene;
  dialogue otherwise stays in the game.
- **In and out.** Hard cuts to and from the game, with the sound already matched across the
  cut. No title cards, no logos.
