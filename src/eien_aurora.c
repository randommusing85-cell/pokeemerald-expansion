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

#define FRAMES_PER_STEP  4 // Palettes are re-blended every this many frames
#define STEPS_PER_FADE  96 // A fade from one tint to the next: 96 steps * 4 frames, about 6.4 seconds

struct AuroraTint
{
    struct BlendSettings blend;
    u16 holdSteps; // How long the tint holds before fading to the next one
};

// The pulse loops through these tints: a cold night blue, a green glow, a violet glow, and back.
// Green holds for a while; violet passes straight through. The whole loop is about 25 seconds.
// TODO(design): the night palette (an art pass on a real map).
static const struct AuroraTint sAuroraTints[] =
{
    {{.coeff = 10, .blendColor = TINT(0.50, 0.56, 0.80), .isTint = TRUE}, 0},  // Cold night
    {{.coeff = 10, .blendColor = TINT(0.44, 0.96, 0.66), .isTint = TRUE}, 96}, // Green
    {{.coeff = 10, .blendColor = TINT(0.80, 0.48, 0.98), .isTint = TRUE}, 0},  // Violet
};

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

static u32 GetAuroraCycleSteps(void)
{
    u32 i, steps = 0;

    for (i = 0; i < ARRAY_COUNT(sAuroraTints); i++)
        steps += sAuroraTints[i].holdSteps + STEPS_PER_FADE;
    return steps;
}

// Replaces the time-of-day blend with the aurora's at the current point of the pulse.
// Also called whenever the time-of-day blend is recalculated, so the pulse isn't reset.
void SetAuroraTimeBlend(void)
{
    u32 i, step, progress = 0;

    if (!IsAuroraWeatherActive())
        return;

    // Find the tint whose hold or fade sPhase falls in
    step = sPhase;
    for (i = 0; step >= sAuroraTints[i].holdSteps + STEPS_PER_FADE; i++)
        step -= sAuroraTints[i].holdSteps + STEPS_PER_FADE;
    if (step >= sAuroraTints[i].holdSteps)
    {
        // Fading to the next tint, eased: 0 at the start, 256 at the end (half a cosine wave)
        step -= sAuroraTints[i].holdSteps;
        progress = (256 - Cos(step * 128 / STEPS_PER_FADE, 256)) / 2;
    }
    gTimeBlend.startBlend = sAuroraTints[i].blend;
    gTimeBlend.endBlend = sAuroraTints[(i + 1) % ARRAY_COUNT(sAuroraTints)].blend;
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
    if (++sPhase >= GetAuroraCycleSteps())
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
