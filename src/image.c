#include <ncurses.h>

#include "image.h"

void downsampleImage(int height, int width, const pixel_t *src, pixel_t *dest)
{
    int scaleY = (DOOMGENERIC_RESY << 16) / height;
    int scaleX = (DOOMGENERIC_RESX << 16) / width;

    for (int y = 0; y < height; y++)
    {
        int srcY = (y * scaleY) >> 16;
        for (int x = 0; x < width; x++)
        {
            int srcX = (x * scaleX) >> 16;
            dest[y * width + x] = src[srcY * DOOMGENERIC_RESX + srcX];
        }
    }
}

void getImageSize(int *height, int *width)
{
    int maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);

    int aspectRatioX = DOOMGENERIC_RESX * 2;
    int aspectRatioY = DOOMGENERIC_RESY;

    if (maxX * aspectRatioY <= maxY * aspectRatioX)
    {
        *width = maxX;
        *height = maxX * aspectRatioY / aspectRatioX;
    }
    else
    {
        *height = maxY;
        *width = maxY * aspectRatioX / aspectRatioY;
    }
}
