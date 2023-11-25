#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "types.h"

typedef enum {
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE,
    COLOR_BLACK,
    COLOR_WHITE
} color_t;

typedef struct {
    void *frame;
    u16 width;
    u16 height;
} screen_t;

// fill the screen with a color
void gfx_clearScreen(screen_t*, color_t);



#endif // GRAPHICS_H
