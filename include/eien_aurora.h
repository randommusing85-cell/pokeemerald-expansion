#ifndef GUARD_EIEN_AURORA_H
#define GUARD_EIEN_AURORA_H

// Eien's aurora nights (design/game-bible.md, "Eien weather and terrain").
// On the map: WEATHER_AURORA, a cold night tint with a slow color pulse, on outdoor maps that
// would otherwise be clear or snowing. In battle: the Rainbow effect for both sides.

// One night in this many is an aurora night once FLAG_AURORA_NIGHTS is set.
// TODO(design): how often aurora nights come back.
#define AURORA_NIGHT_CHANCE 4

bool32 IsAuroraNight(void);
u32 GetAuroraNightWeather(u32 weather);
bool32 IsAuroraWeatherActive(void);
void SetAuroraTimeBlend(void);

void Aurora_InitVars(void);
void Aurora_InitAll(void);
void Aurora_Main(void);
bool8 Aurora_Finish(void);

#endif // GUARD_EIEN_AURORA_H
