// mgba-harness: headless mGBA runner that plays a scripted input sequence
// against a ROM and writes PNG screenshots, save states and memory reads.
//
// Usage: mgba-harness [options] ROM SCRIPT
//   -o DIR     output directory for screenshots (default: .)
//   -s FILE    battery save (.sav) to load; it is never written back
//   -t UNIX    fixed RTC start time (default: 946728000, 2000-01-01 12:00 UTC)
//   -b DIR     compare each screenshot with DIR/NAME.png; exit 4 if any differ
//   -g FILE    also write a contact sheet of every screenshot (4 per row, in order)
//   -q         quiet: only print results of read/assert commands
//
// Script commands (one per line; '#' starts a comment; KEYS is e.g. A, START, R+START):
//   wait N                    run N frames with no keys held
//   press KEYS [COUNT]        tap KEYS COUNT times (hold 4 frames, release 12)
//   hold KEYS N               hold KEYS for N frames, then release
//   shot NAME                 write DIR/NAME.png of the current frame
//   savestate PATH            write a save state
//   loadstate PATH            load a save state
//   writesave PATH            write the current battery save (e.g. after saving in-game)
//   read8|read16|read32 ADDR [LABEL]        print a value from the bus
//   write8|write16|write32 ADDR VALUE       write a value to the bus
//   assert8|assert16|assert32 ADDR VALUE [MSG]  fail (exit 3) if the value differs
//   wait_until8|wait_until16|wait_until32 ADDR VALUE MAXFRAMES
//                             run frames until the value matches (exit 3 on timeout)
// Numbers accept decimal or 0x hex. ADDR may be [PTR]+OFFSET to dereference a pointer.
// Symbol names (@gSymbol) and includes are resolved by run.py, not here.

// flags.h must come first: it defines the build options (e.g. USE_DEBUGGERS) that
// change the layout of struct mCore, and the installed headers do not include it.
#include <mgba/flags.h>
#include <mgba/core/core.h>
#include <mgba/core/interface.h>
#include <mgba/core/serialize.h>
#include <mgba/core/log.h>
#include <mgba-util/vfs.h>

#include <errno.h>
#include <fcntl.h>
#include <png.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define TAP_HOLD_FRAMES 4
#define TAP_RELEASE_FRAMES 12

static const char *const sKeyNames[] = {
    "A", "B", "SELECT", "START", "RIGHT", "LEFT", "UP", "DOWN", "R", "L",
};

static struct mCore *sCore;
static color_t *sVideoBuffer;
static unsigned sWidth, sHeight;
static const char *sOutDir = ".";
static bool sQuiet;
static const char *sBaselineDir;
static int sBaselineFailures;
static const char *sSheetPath;
static png_bytep *sSheetFrames;
static size_t sSheetCount;
static unsigned long sFrame;
static time_t sRtcBase = 946728000;
static const char *sScriptPath;
static int sLineNo;

static void DiscardLog(struct mLogger *logger, int category, enum mLogLevel level, const char *format, va_list args)
{
    (void)logger; (void)category; (void)level; (void)format; (void)args;
}

static struct mLogger sLogger = { .log = DiscardLog };

// Deterministic RTC: starts at sRtcBase and advances with emulated frames,
// so clock-dependent events behave the same on every run.
static void RtcSample(struct mRTCSource *rtc) { (void)rtc; }
static time_t RtcUnixTime(struct mRTCSource *rtc) { (void)rtc; return sRtcBase + (time_t)(sFrame / 60); }
static void RtcSerialize(struct mRTCSource *rtc, struct mStateExtdataItem *item) { (void)rtc; (void)item; }
static bool RtcDeserialize(struct mRTCSource *rtc, const struct mStateExtdataItem *item) { (void)rtc; (void)item; return true; }

static struct mRTCSource sRtc = {
    .sample = RtcSample,
    .unixTime = RtcUnixTime,
    .serialize = RtcSerialize,
    .deserialize = RtcDeserialize,
};

static void Die(int code, const char *fmt, ...)
{
    va_list args;
    if (sScriptPath && sLineNo)
        fprintf(stderr, "%s:%d: ", sScriptPath, sLineNo);
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fputc('\n', stderr);
    exit(code);
}

static void Info(const char *fmt, ...)
{
    va_list args;
    if (sQuiet)
        return;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

static uint32_t ParseNumber(const char *text)
{
    char *end;
    unsigned long value;
    if (!text)
        Die(2, "missing number");
    errno = 0;
    value = strtoul(text, &end, 0);
    if (errno || *end)
        Die(2, "bad number '%s'", text);
    return (uint32_t)value;
}

static uint32_t BusRead(int width, uint32_t address);

// An address is a number, or "[PTR]+OFFSET" to follow a 32-bit pointer at PTR
// when the command runs (e.g. [0x03005D8C]+4 for a field of gSaveBlock1Ptr).
static uint32_t ParseAddress(const char *text)
{
    char buffer[128];
    char *close;
    uint32_t address;

    if (!text || text[0] != '[')
        return ParseNumber(text);
    snprintf(buffer, sizeof(buffer), "%s", text + 1);
    close = strchr(buffer, ']');
    if (!close)
        Die(2, "bad address '%s'", text);
    *close = '\0';
    address = BusRead(32, ParseNumber(buffer));
    if (close[1] == '+')
        address += ParseNumber(close + 2);
    else if (close[1] != '\0')
        Die(2, "bad address '%s'", text);
    return address;
}

static uint32_t ParseKeys(const char *text)
{
    uint32_t keys = 0;
    char buffer[128];
    char *save = NULL;
    char *token;

    if (!text)
        Die(2, "missing keys");
    snprintf(buffer, sizeof(buffer), "%s", text);
    for (token = strtok_r(buffer, "+", &save); token; token = strtok_r(NULL, "+", &save))
    {
        size_t i;
        for (i = 0; i < sizeof(sKeyNames) / sizeof(sKeyNames[0]); i++)
        {
            if (strcasecmp(token, sKeyNames[i]) == 0)
                break;
        }
        if (i == sizeof(sKeyNames) / sizeof(sKeyNames[0]))
            Die(2, "unknown key '%s' (use A B SELECT START RIGHT LEFT UP DOWN R L)", token);
        keys |= 1u << i;
    }
    return keys;
}

static void RunFrames(uint32_t keys, unsigned count)
{
    sCore->setKeys(sCore, keys);
    while (count--)
    {
        sCore->runFrame(sCore);
        sFrame++;
    }
    sCore->setKeys(sCore, 0);
}

// mGBA's 32-bit color_t is 0x00BBGGRR; screenshots are 8-bit RGB.
static png_bytep FrameToRgb(void)
{
    png_bytep rgb = malloc((size_t)sWidth * sHeight * 3);
    size_t i;
    for (i = 0; i < (size_t)sWidth * sHeight; i++)
    {
        rgb[i * 3 + 0] = sVideoBuffer[i] & 0xFF;
        rgb[i * 3 + 1] = (sVideoBuffer[i] >> 8) & 0xFF;
        rgb[i * 3 + 2] = (sVideoBuffer[i] >> 16) & 0xFF;
    }
    return rgb;
}

static void WritePng(const char *path, png_bytep rgb, unsigned width, unsigned height)
{
    FILE *file = fopen(path, "wb");
    png_structp png;
    png_infop info;
    unsigned y;

    if (!file)
        Die(1, "cannot write %s", path);
    png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    info = png_create_info_struct(png);
    if (!png || !info || setjmp(png_jmpbuf(png)))
        Die(1, "failed to encode %s", path);
    png_init_io(png, file);
    png_set_IHDR(png, info, width, height, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    png_write_info(png, info);
    for (y = 0; y < height; y++)
        png_write_row(png, rgb + (size_t)y * width * 3);
    png_write_end(png, NULL);
    png_destroy_write_struct(&png, &info);
    fclose(file);
}

// Returns the number of differing pixels, or -1 if the baseline is missing or a different size.
static long CompareWithBaseline(const char *path, png_bytep rgb)
{
    png_image image;
    png_bytep expected;
    long diffs = 0;
    size_t i;

    memset(&image, 0, sizeof(image));
    image.version = PNG_IMAGE_VERSION;
    if (!png_image_begin_read_from_file(&image, path))
        return -1;
    if (image.width != sWidth || image.height != sHeight)
    {
        png_image_free(&image);
        return -1;
    }
    image.format = PNG_FORMAT_RGB;
    expected = malloc(PNG_IMAGE_SIZE(image));
    if (!png_image_finish_read(&image, NULL, expected, 0, NULL))
    {
        free(expected);
        return -1;
    }
    for (i = 0; i < (size_t)sWidth * sHeight; i++)
    {
        if (memcmp(&rgb[i * 3], &expected[i * 3], 3) != 0)
            diffs++;
    }
    free(expected);
    return diffs;
}

static void WriteScreenshot(const char *name)
{
    char path[4096];
    png_bytep rgb = FrameToRgb();

    snprintf(path, sizeof(path), "%s/%s.png", sOutDir, name);
    WritePng(path, rgb, sWidth, sHeight);
    Info("shot %s (frame %lu)\n", path, sFrame);

    if (sBaselineDir)
    {
        char basePath[4096];
        long diffs;
        snprintf(basePath, sizeof(basePath), "%s/%s.png", sBaselineDir, name);
        diffs = CompareWithBaseline(basePath, rgb);
        if (diffs < 0)
        {
            printf("baseline %s: MISSING (%s)\n", name, basePath);
            sBaselineFailures++;
        }
        else if (diffs > 0)
        {
            printf("baseline %s: DIFFERS in %ld pixels\n", name, diffs);
            sBaselineFailures++;
        }
        else
        {
            printf("baseline %s: match\n", name);
        }
    }
    if (sSheetPath)
    {
        sSheetFrames = realloc(sSheetFrames, (sSheetCount + 1) * sizeof(*sSheetFrames));
        sSheetFrames[sSheetCount++] = rgb;
    }
    else
    {
        free(rgb);
    }
}

#define SHEET_COLUMNS 4
#define SHEET_GAP 4

static void WriteSheet(void)
{
    unsigned columns = sSheetCount < SHEET_COLUMNS ? (unsigned)sSheetCount : SHEET_COLUMNS;
    unsigned rows = (unsigned)((sSheetCount + SHEET_COLUMNS - 1) / SHEET_COLUMNS);
    unsigned width = columns * sWidth + (columns + 1) * SHEET_GAP;
    unsigned height = rows * sHeight + (rows + 1) * SHEET_GAP;
    png_bytep sheet = malloc((size_t)width * height * 3);
    size_t i;
    unsigned y;

    memset(sheet, 0x40, (size_t)width * height * 3);
    for (i = 0; i < sSheetCount; i++)
    {
        unsigned left = SHEET_GAP + (unsigned)(i % SHEET_COLUMNS) * (sWidth + SHEET_GAP);
        unsigned top = SHEET_GAP + (unsigned)(i / SHEET_COLUMNS) * (sHeight + SHEET_GAP);
        for (y = 0; y < sHeight; y++)
            memcpy(sheet + ((size_t)(top + y) * width + left) * 3, sSheetFrames[i] + (size_t)y * sWidth * 3, (size_t)sWidth * 3);
        free(sSheetFrames[i]);
    }
    WritePng(sSheetPath, sheet, width, height);
    free(sheet);
    Info("sheet %s (%zu shots)\n", sSheetPath, sSheetCount);
}

static void SaveOrLoadState(const char *path, bool save)
{
    struct VFile *vf = VFileOpen(path, save ? (O_CREAT | O_TRUNC | O_WRONLY) : O_RDONLY);
    bool ok;
    if (!vf)
        Die(1, "cannot open state %s", path);
    // Save data is excluded so a state never overwrites the battery save it was loaded with.
    ok = save ? mCoreSaveStateNamed(sCore, vf, SAVESTATE_SCREENSHOT | SAVESTATE_RTC)
              : mCoreLoadStateNamed(sCore, vf, SAVESTATE_RTC);
    vf->close(vf);
    if (!ok)
        Die(1, "failed to %s state %s", save ? "save" : "load", path);
    Info("%s %s\n", save ? "savestate" : "loadstate", path);
}

static void WriteBatterySave(const char *path)
{
    void *data = NULL;
    size_t size = sCore->savedataClone(sCore, &data);
    FILE *file;
    if (!size || !data)
        Die(1, "no battery save data yet (save in-game first)");
    file = fopen(path, "wb");
    if (!file || fwrite(data, 1, size, file) != size)
        Die(1, "cannot write save %s", path);
    fclose(file);
    free(data);
    Info("writesave %s (%zu bytes)\n", path, size);
}

static uint32_t BusRead(int width, uint32_t address)
{
    switch (width)
    {
    case 8: return sCore->busRead8(sCore, address);
    case 16: return sCore->busRead16(sCore, address);
    default: return sCore->busRead32(sCore, address);
    }
}

static void BusWrite(int width, uint32_t address, uint32_t value)
{
    switch (width)
    {
    case 8: sCore->busWrite8(sCore, address, (uint8_t)value); break;
    case 16: sCore->busWrite16(sCore, address, (uint16_t)value); break;
    default: sCore->busWrite32(sCore, address, value); break;
    }
}

// Returns the access width (8/16/32) if cmd is PREFIX followed by a width, else 0.
static int MatchWidth(const char *cmd, const char *prefix)
{
    size_t len = strlen(prefix);
    if (strncmp(cmd, prefix, len) != 0)
        return 0;
    if (strcmp(cmd + len, "8") == 0) return 8;
    if (strcmp(cmd + len, "16") == 0) return 16;
    if (strcmp(cmd + len, "32") == 0) return 32;
    return 0;
}

static void RunCommand(char *line)
{
    char *save = NULL;
    char *cmd = strtok_r(line, " \t", &save);
    char *arg1 = strtok_r(NULL, " \t", &save);
    char *arg2 = strtok_r(NULL, " \t", &save);
    char *rest = strtok_r(NULL, "", &save);
    int width;

    if (!cmd)
        return;

    if (strcmp(cmd, "wait") == 0)
    {
        RunFrames(0, ParseNumber(arg1));
    }
    else if (strcmp(cmd, "press") == 0)
    {
        uint32_t keys = ParseKeys(arg1);
        uint32_t count = arg2 ? ParseNumber(arg2) : 1;
        while (count--)
        {
            RunFrames(keys, TAP_HOLD_FRAMES);
            RunFrames(0, TAP_RELEASE_FRAMES);
        }
    }
    else if (strcmp(cmd, "hold") == 0)
    {
        RunFrames(ParseKeys(arg1), ParseNumber(arg2));
    }
    else if (strcmp(cmd, "shot") == 0)
    {
        if (!arg1)
            Die(2, "shot needs a name");
        WriteScreenshot(arg1);
    }
    else if (strcmp(cmd, "savestate") == 0 || strcmp(cmd, "loadstate") == 0)
    {
        if (!arg1)
            Die(2, "%s needs a path", cmd);
        SaveOrLoadState(arg1, cmd[0] == 's');
    }
    else if (strcmp(cmd, "writesave") == 0)
    {
        if (!arg1)
            Die(2, "writesave needs a path");
        WriteBatterySave(arg1);
    }
    else if ((width = MatchWidth(cmd, "read")))
    {
        uint32_t address = ParseAddress(arg1);
        uint32_t value = BusRead(width, address);
        printf("read%d 0x%08X = 0x%0*X (%u)%s%s\n", width, address, width / 4, value, value,
               arg2 ? " " : "", arg2 ? arg2 : "");
    }
    else if ((width = MatchWidth(cmd, "write")))
    {
        BusWrite(width, ParseAddress(arg1), ParseNumber(arg2));
    }
    else if ((width = MatchWidth(cmd, "assert")))
    {
        uint32_t address = ParseAddress(arg1);
        uint32_t expected = ParseNumber(arg2);
        uint32_t value = BusRead(width, address);
        if (value != expected)
            Die(3, "assert failed: 0x%08X = 0x%X, expected 0x%X%s%s", address, value, expected,
                rest ? ": " : "", rest ? rest : "");
        printf("assert%d 0x%08X == 0x%X ok%s%s\n", width, address, expected, rest ? ": " : "", rest ? rest : "");
    }
    else if ((width = MatchWidth(cmd, "wait_until")))
    {
        uint32_t address = ParseAddress(arg1);
        uint32_t expected = ParseNumber(arg2);
        uint32_t limit = ParseNumber(rest);
        uint32_t waited = 0;
        while (BusRead(width, address = ParseAddress(arg1)) != expected)
        {
            if (waited++ >= limit)
                Die(3, "wait_until timed out after %u frames: 0x%08X = 0x%X, expected 0x%X",
                    limit, address, BusRead(width, address), expected);
            RunFrames(0, 1);
        }
        Info("wait_until 0x%08X == 0x%X after %u frames\n", address, expected, waited);
    }
    else
    {
        Die(2, "unknown command '%s'", cmd);
    }
}

static void Usage(const char *argv0)
{
    fprintf(stderr, "usage: %s [-o DIR] [-s SAVE] [-t UNIXTIME] [-b BASELINE_DIR] [-g SHEET] [-q] ROM SCRIPT\n", argv0);
    exit(2);
}

int main(int argc, char **argv)
{
    const char *savePath = NULL;
    const char *romPath;
    FILE *script;
    char line[1024];
    int opt;

    while ((opt = getopt(argc, argv, "o:s:t:b:g:q")) != -1)
    {
        switch (opt)
        {
        case 'o': sOutDir = optarg; break;
        case 's': savePath = optarg; break;
        case 't': sRtcBase = (time_t)strtoll(optarg, NULL, 0); break;
        case 'b': sBaselineDir = optarg; break;
        case 'g': sSheetPath = optarg; break;
        case 'q': sQuiet = true; break;
        default: Usage(argv[0]);
        }
    }
    if (argc - optind != 2)
        Usage(argv[0]);
    romPath = argv[optind];
    sScriptPath = argv[optind + 1];

    setvbuf(stdout, NULL, _IOLBF, 0);
    mkdir(sOutDir, 0777);
    mLogSetDefaultLogger(&sLogger);

    sCore = mCoreFind(romPath);
    if (!sCore || !sCore->init(sCore))
        Die(1, "cannot load core for %s", romPath);
    mCoreInitConfig(sCore, NULL);

    sCore->desiredVideoDimensions(sCore, &sWidth, &sHeight);
    sVideoBuffer = calloc((size_t)sWidth * sHeight, BYTES_PER_PIXEL);
    sCore->setVideoBuffer(sCore, sVideoBuffer, sWidth);

    if (!mCoreLoadFile(sCore, romPath))
        Die(1, "cannot load ROM %s", romPath);
    mCoreSetRTC(sCore, &sRtc);

    // Load the battery save into memory only (VFileFromMemory copy), so runs never modify it.
    if (savePath)
    {
        struct VFile *disk = VFileOpen(savePath, O_RDONLY);
        struct VFile *mem;
        ssize_t size;
        void *data;
        if (!disk)
            Die(1, "cannot open save %s", savePath);
        size = disk->size(disk);
        data = malloc(size > 0 ? (size_t)size : 1);
        if (disk->read(disk, data, (size_t)size) != size)
            Die(1, "cannot read save %s", savePath);
        disk->close(disk);
        mem = VFileMemChunk(data, (size_t)size);
        free(data);
        if (!sCore->loadSave(sCore, mem))
            Die(1, "core rejected save %s", savePath);
    }
    else
    {
        sCore->loadSave(sCore, VFileMemChunk(NULL, 0));
    }

    sCore->reset(sCore);

    script = fopen(sScriptPath, "r");
    if (!script)
        Die(1, "cannot open script %s", sScriptPath);
    while (fgets(line, sizeof(line), script))
    {
        char *comment = strchr(line, '#');
        sLineNo++;
        if (comment)
            *comment = '\0';
        line[strcspn(line, "\r\n")] = '\0';
        for (size_t end = strlen(line); end && (line[end - 1] == ' ' || line[end - 1] == '\t'); end--)
            line[end - 1] = '\0';
        RunCommand(line);
    }
    fclose(script);
    sLineNo = 0;

    if (sSheetPath && sSheetCount)
        WriteSheet();
    Info("done: %lu frames\n", sFrame);
    sCore->deinit(sCore);
    free(sVideoBuffer);
    if (sBaselineFailures)
    {
        fprintf(stderr, "%d screenshot(s) differ from baseline %s\n", sBaselineFailures, sBaselineDir);
        return 4;
    }
    return 0;
}
