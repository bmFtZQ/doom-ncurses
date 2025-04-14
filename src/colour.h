#pragma once

#include <stdint.h>

#include "../doomgeneric/doomgeneric.h"

extern uint16_t paletteMap[256];

void InitColours();
void SetColor(pixel_t pixel);
void CheckForPaletteUpdate();
