#ifndef GUARD_EIEN_THINNING_H
#define GUARD_EIEN_THINNING_H

// Eien's thinning (design/game-bible.md, "The thinning on the map"): where the world thins, the
// screen drains toward grey. WEATHER_THINNING, set by a scene's script (data/scripts/
// eien_thinning.inc): the colour creeps out over a few seconds, then pulses faintly while it's
// open. The hero, his follower (Celebi) and up to two kept objects stay in colour. Battles
// while it's open get the thin-place effect and a grey battle background.

bool32 IsThinningActive(void);
void TintBattleBackgroundForThinning(void);
void KeepObjectInColourInThinning(void);
void StopSnowForThinning(void); // in field_weather_effect.c, next to the snow

void Thinning_InitVars(void);
void Thinning_Main(void);
void Thinning_InitAll(void);
bool8 Thinning_Finish(void);
bool8 FadeInScreen_Thinning(void);

#endif // GUARD_EIEN_THINNING_H
