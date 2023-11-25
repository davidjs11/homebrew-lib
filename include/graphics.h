#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>

typedef enum {
    COLOR_RED,
    COLOR_GREEN,
    COLOR_BLUE,
    COLOR_BLACK,
    COLOR_WHITE
} color_t;

typedef struct {
    void *frame;
    uint16_t width;
    uint16_t height;
} screen_t;

// clear the screen
void gfx_clearScreen(screen_t*, color_t);



#endif // GRAPHICS_H
