#include <getopt.h>
#include <string.h>

#include "arguments.h"

bool useDefaultPalette = false;
bool useAnsiColoursOnly = false;
bool useAsciiOnly = false;
int frameCounter = 0;

static struct option cmdOptions[] =
{
    {"default-palette", no_argument, NULL, 'd'},
    {"ascii", no_argument, NULL, 'c'},
    {"ansi", no_argument, NULL, 'a'},
    {0, 0, 0, 0}
};

int ParseArguments(int argc, char **argv)
{
    int opt;
    while ((opt = getopt_long(argc, argv, "da", cmdOptions, NULL)) != -1)
    {
        switch (opt)
        {
        case 'd':
            useDefaultPalette = true;
            break;

        case 'a':
            useAnsiColoursOnly = true;
        case 'c':
            useAsciiOnly = true;
            break;
        }
    }

    return argc - optind + 1;
}
