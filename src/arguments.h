#pragma once

#include <stdbool.h>

extern bool useDefaultPalette;
extern bool useAnsiColoursOnly;
extern bool useAsciiOnly;

extern int frameCounter;

int ParseArguments(int argc, char **argv);
