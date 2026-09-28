#include "global.h"
#include "eien_aurora.h"
#include "event_data.h"
#include "field_weather.h"
#include "overworld.h"
#include "palette.h"
#include "random.h"
#include "rtc.h"
#include "trig.h"
#include "constants/weather.h"

// Aurora nights (design/game-bible.md, "Eien weather and terrain").
//
// Tonight is an aurora night if it's night and either the story set FLAG_AURORA_TONIGHT (the
// first one, Kaede's quest step 2) or FLAG_AURORA_NIGHTS is set and tonight's roll comes up.
// The roll is fixed per night, so every map agrees and re-entering a map doesn't change it.
// The weather is picked when a map loads, so the aurora starts or ends on the next map change
// after nightfall or dawn.

#define AURORA_NIGHT_SALT 0x4155524F // "AURO"

#define TINT(r, g, b) (Q_8_8(r) | Q_8_8(g) << 8 | Q_8_8(b) << 16)

// The pulse loops through these tints: a cold night blue, a green glow, a violet glow, and back.
// TODO(design): the night palette (an art pass on a real map).
static const struct BlendSettings sAuroraBlends[] =
{
    {.coeff = 10, .blendColor = TINT(0.40, 0.46, 0.66), .isTint = TRUE}, // Cold night
    {.coeff = 10, .blendColor = TINT(0.34, 0.80, 0.56), .isTint = TRUE}, // Green
    {.coeff = 10, .blendColor = TINT(0.68, 0.38, 0.86), .isTint = TRUE}, // Violet
};

#define FRAMES_PER_STEP  4 // Palettes are re-blended every this many frames
#define STEPS_PER_LEG  128 // Each leg (one tint to the next) is 128 steps * 4 frames: about 8.5 seconds
#define STEPS_PER_CYCLE (STEPS_PER_LEG * ARRAY_COUNT(sAuroraBlends)) // The whole loop: about 25 seconds

static EWRAM_DATA u16 sPhase = 0; // Step within the cycle
static EWRAM_DATA u8 sStepTimer = 0;

bool32 IsAuroraNight(void)
{
    s32 night;
    rng_value_t rng;

    if (GetTimeOfDay() != TIME_NIGHT)
        return FALSE;
    if (FlagGet(FLAG_AURORA_TONIGHT))
        return TRUE;
    if (!FlagGet(FLAG_AURORA_NIGHTS))
        return FALSE;

    // GetTimeOfDay just updated gLocalTime. The hours after midnight belong to the night before.
    night = gLocalTime.days - (gLocalTime.hours < 12 ? 1 : 0);
    rng = LocalRandomSeed(night ^ AURORA_NIGHT_SALT);
    return LocalRandom32(&rng) % AURORA_NIGHT_CHANCE == 0;
}

// The map's weather, or the aurora on an aurora night if the map is outdoors and clear or
// snowing (aurora nights are clear).
u32 GetAuroraNightWeather(u32 weather)
{
    switch (weather)
    {
    case WEATHER_NONE:
    case WEATHER_SUNNY_CLOUDS:
    case WEATHER_SUNNY:
    case WEATHER_SNOW:
        if (MapHasNaturalLight(gMapHeader.mapType) && IsAuroraNight())
            return WEATHER_AURORA;
        break;
    }
    return weather;
}

bool32 IsAuroraWeatherActive(void)
{
    return gWeatherPtr->currWeather == WEATHER_AURORA && gWeatherPtr->nextWeather == WEATHER_AURORA;
}

// Replaces the time-of-day blend with the aurora's at the current point of the pulse.
// Also called whenever the time-of-day blend is recalculated, so the pulse isn't reset.
void SetAuroraTimeBlend(void)
{
    u32 leg, step, progress;

    if (!IsAuroraWeatherActive())
        return;

    leg = sPhase / STEPS_PER_LEG;
    step = sPhase % STEPS_PER_LEG;
    // Eased: 0 at the start of the leg, 256 at its end (half a cosine wave)
    progress = (256 - Cos(step * 128 / STEPS_PER_LEG, 256)) / 2;
    gTimeBlend.startBlend = sAuroraBlends[leg];
    gTimeBlend.endBlend = sAuroraBlends[(leg + 1) % ARRAY_COUNT(sAuroraBlends)];
    gTimeBlend.weight = 256 - progress;
}

void Aurora_InitVars(void)
{
    gWeatherPtr->initStep = 0;
    gWeatherPtr->targetColorMapIndex = 0;
    gWeatherPtr->colorMapStepDelay = 20;
    Weather_SetBlendCoeffs(8, BASE_SHADOW_INTENSITY); // preserve shadow darkness
    gWeatherPtr->noShadows = FALSE;
    sPhase = 0;
    sStepTimer = 0;
}

void Aurora_InitAll(void)
{
    Aurora_InitVars();
    SetAuroraTimeBlend();
}

void Aurora_Main(void)
{
    if (++sStepTimer < FRAMES_PER_STEP)
        return;
    sStepTimer = 0;
    if (++sPhase >= STEPS_PER_CYCLE)
        sPhase = 0;
    SetAuroraTimeBlend();
    // Don't touch the palettes during a fade (warps, battles, menus fading in)
    if (!gPaletteFade.active)
        ApplyWeatherColorMapIfIdle(gWeatherPtr->colorMapIndex);
}

bool8 Aurora_Finish(void)
{
    // Back to the plain time-of-day blend
    UpdateTimeOfDay(TRUE);
    if (!gPaletteFade.active)
        ApplyWeatherColorMapIfIdle(gWeatherPtr->colorMapIndex);
    return FALSE;
}
