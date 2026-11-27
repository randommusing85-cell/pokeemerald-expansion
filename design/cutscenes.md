# Cutscene plan

Status: presentation proposal for Claude and the user, 2026-10-21. The user wants a mix
of movie-like scenes for important moments and traditional Pokémon scenes elsewhere.
Story canon remains in `story-outline.md` and the location docs. No cinematic player or
new scene assets have been implemented. Later scenes remain outside the current milestone.

## User direction to Claude: Higgsfield and anime style

Confirmed on 2026-10-21: use **Higgsfield** for the movie game cutscenes. Use **your
brainstorm skill** to work out the anime visual style with the user before production.
This production-tool choice is settled; the visual treatment and specific shots are open.

Claude's next creative deliverable:

1. Invoke your available brainstorm skill and explore two or three distinct anime
   directions suited to Eien's snow country, quiet relationships and fading world.
   Compare linework, character proportions, background painting, palette, lighting,
   motion and emotional tone. Describe visual properties rather than relying only on
   studio names. Suggested starting points: restrained cel animation with painted winter
   backgrounds; soft watercolor atmosphere; crisp cinematic anime with cool lighting.
   These are prompts for exploration, not a chosen style.
2. Recommend a direction and work through the choice with the user. Define a reusable
   style guide: character/creature consistency, reference sheets, color script, camera
   language, motion, subtitle readability, and transitions to/from Gen 3 gameplay.
3. Choose one existing story beat for a short pilot and write its storyboard and
   Higgsfield production brief: shot prompts, references, duration, framing, continuity,
   sound/music needs and export settings. Preserve existing lore and character designs.
4. Use the available Higgsfield integration for production. Record prompts, reference
   assets, generation settings/IDs, selected outputs and credits so later scenes match.
   If your brainstorm skill or Higgsfield access is missing, report it explicitly; do not
   substitute a claimed invocation or pretend generated assets exist.

Codex will evaluate the pilot for game integration. A Higgsfield movie export is not
automatically playable in a GBA ROM: measure a short conversion/playback prototype first.
Keep the master movie and assess an in-engine adaptation using selected frames, limited
animation and sound if required. Report fidelity and resource tradeoffs to the user before
settling delivery. Traditional Pokémon scenes remain the default for other story points.

## Presentation

- Traditional scenes are the default: overworld sprites, movement, dialogue, cries, music
  and battles. Use them for conversations, quests, gym introductions and everyday travel.
- For a few major moments, propose illustrated sequences: full-screen pixel artwork,
  held shots, fades, modest movement and sound. Target the GBA's 240×160 display and
  measure palette, tile, memory and ROM costs before choosing final asset budgets.
  Baseline build on 2026-10-21 uses 80.23% of the 32 MiB ROM, 86.45% EWRAM and 86.62%
  IWRAM. Free capacity alone does not prove a scene fits: measure peak runtime allocations
  and graphics memory use in the prototype.
- Start with a small in-engine proof of concept after the first scene's treatment is
  settled. Full-motion video is not assumed; external movie storyboards could guide the
  in-game adaptation, but must not become required viewing outside the game.
- Match the established art direction. Favor readable silhouettes and quiet pacing over
  dense subtitles or constant effects. Dialogue follows `dialogue-style.md`.

## Candidate treatments

| Existing story moment | Proposed treatment | Scope / decision needed |
| --- | --- | --- |
| Bedroom and accident | Traditional bedroom; existing black-screen accident text | Current slice. Preserve the location doc's no-new-art treatment; Claude must settle the accident and lines. |
| Palkia catches him / arrival in Eien | Candidate for a brief cinematic transition, followed by the existing Hamakaze wake-up | Current slice. Existing plan uses Palkia's overworld sprite. An illustrated version is an optional revision for Claude/user to settle, not a replacement already approved. |
| Starter selection, Akira, gym 1, Kaede's cameo | Traditional Pokémon scenes | Current slice. Keep interaction and battles playable. |
| Lake Usurai: Celebi falls, Lapras carries them to shelter | Candidate for one short lake-crossing insert; retain conversation in the overworld | Current slice. Settle the shot list and relationship to the existing script before adding art. |
| Tournament thinning and its aftermath | Brief cinematic emphasis around the disaster; keep rescue traversal and battles playable | Later. Follow the outline's plain, brief treatment of the deaths. |
| Minori's festival thinning | In-map weather/effects with a possible establishing shot | Later. Reuse the implemented thinning effect; preserve the playable rescue. |
| Celebi's sacrifice, renewal, blank journal, goodbye | A few distinct cinematic moments separated by gameplay and dialogue | Later. Timing and shot list remain open. |
| Hospital ending and memory epilogue | Short illustrated ending; traditional exploration as memories return | Later. Preserve the story's unresolved ambiguity. |

## Scene handoff from Claude to Codex

For each scene, record in its location doc: trigger and prerequisites, existing story beat,
shot order, exact dialogue, characters, entry/exit positions, required art/audio, state changes,
and which parts remain interactive. Mark unresolved choices `TODO(design)`.

Codex then implements and checks:

- The scene triggers once at the intended point and returns control to the correct map.
- If skipping is supported, watched and skipped paths produce identical story state,
  rewards, party/follower state and positions. Choices stay interactive.
- Music, palettes, weather, sprites and input recover after the scene.
- Saving/reloading before and after does not replay rewards or strand the player.
- Screenshots demonstrate transitions and readable text; a playthrough checks pacing.

## Next decisions for Claude

- TODO(design): settle the accident and Palkia's lines in the prologue location doc.
- TODO(design): select the first cinematic prototype (Palkia transition or lake crossing)
  and decide whether to revise the existing no-new-art prologue plan.
- TODO(design): choose advance/skip behavior and a short target duration for that prototype.
