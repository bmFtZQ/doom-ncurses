#pragma once

#include "../doomgeneric/doomgeneric.h"

/**
 * Downsample frame buffer using nearest-neighbor to chosen size.
 * @param height The height of the destination image.
 * @param width The width of the destination image.
 * @param src The source image to downsample.
 * @param dest The destination of the newly downsampled image.
 */
void downsampleImage(int height, int width, const pixel_t *src, pixel_t *dest);

/**
 * Get the desired size of the image by querying ncurses terminal.
 * @param height Pointer to write the height to.
 * @param width Pointer to write the width to.
 */
void getImageSize(int *height, int *width);
