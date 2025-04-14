#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <ncurses.h>

#include "../doomgeneric/doomgeneric.h"
#include "arguments.h"
#include "colour.h"
#include "image.h"
#include "input.h"

int main(int argc, char **argv)
{
    int doomArgc = ParseArguments(argc, argv);
    char *doomArgv[doomArgc];

    // Copy remaining args so they can be passed to doom.
    doomArgv[0] = argv[0];
    memcpy(doomArgv + 1, argv + optind, (doomArgc - 1) * sizeof(*argv));

    doomgeneric_Create(doomArgc, doomArgv);

    while (1)
    {
        doomgeneric_Tick();
        frameCounter++;
    }
}

/**
 * Performs initialization for NCurses, used by doom generic.
 */
void DG_Init()
{
    initscr();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    noecho();
    curs_set(0);

    if (!useAsciiOnly)
    {
        start_color();
    }

    if (useAnsiColoursOnly)
    {
        start_color();
        for (int i = 0; i < 16; i++)
        {
            init_pair(i + 1, i, 0);
        }
    }

    InitColours();
}

/**
 * Draws a single frame onto the terminal, used by doom generic.
 */
void DG_DrawFrame()
{
    CheckForPaletteUpdate();
    GetKeyBoardInput();

    int height, width;
    getImageSize(&height, &width);

    size_t bufferSize = height * width;
    pixel_t buffer[bufferSize];
    downsampleImage(height, width, DG_ScreenBuffer, buffer);

    for (int y = 0; y < height; y++)
    {
        pixel_t *row = buffer + y * width;
        for (int x = 0; x < width; x++)
        {
            pixel_t pixel = row[x];
            wmove(stdscr, y, x);
            SetColor(pixel);
            if (useAsciiOnly || useAnsiColoursOnly)
            {
                waddch(stdscr, paletteMap[pixel] & 0xff);
            }
            else
            {
                waddch(stdscr, '@');
            }
        }
    }

    wrefresh(stdscr);
}

/**
 * Sleep for specified number of milliseconds used by doom generic.
 * @param ms The number of milliseconds to sleep for.
 */
void DG_SleepMs(uint32_t ms)
{
    usleep(ms * 1000);
}

/**
 * Get the number of milliseconds passed from program start, used by doom
 * generic.
 * @returns The number of milliseconds passed since the start of the program.
 */
uint32_t DG_GetTicksMs()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

int DG_GetKey(int *pressed, unsigned char *key)
{
    if (keyEventReadPtr == keyEventWritePtr)
    {
        return 0;
    }

    uint16_t keyEvent = keyEventsQueue[keyEventReadPtr++];
    keyEventReadPtr %= KEY_QUEUE_LENGTH;

    *pressed = keyEvent >> 8;
    *key = keyEvent & 0xff;
    return 1;
}

void DG_SetWindowTitle(const char *title)
{
    printf("\e]0;%s\x07", title);
}
