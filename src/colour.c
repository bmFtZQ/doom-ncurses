#include <ncurses.h>

#include "arguments.h"
#include "colour.h"
#include "default_palette.h"
#include "../doomgeneric/i_video.h"

uint16_t paletteMap[256];

void InitColours()
{
    if (useAsciiOnly)
    {
        static char table[] =
        {
            ' ', '`', '.', '\'', ',', '"', ':', 'I', 'Y', 'E', 'O', 'G', '@'
        };

        for (int i = 0; i < 256; i++)
        {
            uint8_t brightness;
            struct color col = colors[i];
            brightness = (col.r + col.g + col.b) / 3;
            uint16_t value = 0;
            value |= (unsigned)table[brightness * (sizeof(table) - 1) / 255];

            uint8_t r = (col.r + 64) / 127 & 0x03;
            uint8_t g = (col.g + 64) / 127 & 0x03;
            uint8_t b = (col.b + 64) / 127 & 0x03;
            uint8_t combined = r << 4 | g << 2 | b;

            uint8_t ansi;
            switch (combined)
            {
            case 0b000000: ansi = 8; break;
            case 0b000001: ansi = 4; break;
            case 0b000010: ansi = 12; break;
            case 0b000100: ansi = 2; break;
            case 0b000101: ansi = 6; break;
            case 0b000110: ansi = 6; break;
            case 0b001000: ansi = 10; break;
            case 0b001001: ansi = 14; break;
            case 0b001010: ansi = 14; break;

            case 0b010000: ansi = 1; break;
            case 0b010001: ansi = 5; break;
            case 0b010010: ansi = 5; break;
            case 0b010100: ansi = 3; break;
            case 0b010101: ansi = 7; break;
            case 0b010110: ansi = 6; break;
            case 0b011000: ansi = 3; break;
            case 0b011001: ansi = 10; break;
            case 0b011010: ansi = 14; break;

            case 0b100000: ansi = 9; break;
            case 0b100001: ansi = 9; break;
            case 0b100010: ansi = 13; break;
            case 0b100100: ansi = 3; break;
            case 0b100101: ansi = 9; break;
            case 0b100110: ansi = 13; break;
            case 0b101000: ansi = 11; break;
            case 0b101001: ansi = 11; break;
            case 0b101010: ansi = 15; break;

            default: ansi = 13; break;
            }

            value |= ansi << 8;

            paletteMap[i] = value;
        }

        return;
    }

    for (int i = 0; i < 256; i++)
    {
        short r;
        short g;
        short b;

        if (useDefaultPalette)
        {
            uint32_t c = defaultPalette[i];
            r = (c >> 16 & 0xff) * 1000 / 255;
            g = (c >> 8 & 0xff) * 1000 / 255;
            b = (c & 0xff) * 1000 / 255;
        }
        else
        {
            struct color col = colors[i];
            r = (col.r) * 1000 / 255;
            g = (col.g) * 1000 / 255;
            b = (col.b) * 1000 / 255;
        }

        init_color(i, r, g, b);
        init_pair(i, i, 0);
    }
}

void SetColor(pixel_t pixel)
{
    if (useAnsiColoursOnly)
    {
        wcolor_set(stdscr, ((paletteMap[pixel] >> 8) & 0x0f) + 1, NULL);
    }
    else if (!useAsciiOnly)
    {
        wcolor_set(stdscr, pixel, NULL);
    }
}

void CheckForPaletteUpdate()
{
    if (palette_changed && !useDefaultPalette)
    {
        InitColours();
        palette_changed = false;
        return;
    }
}
