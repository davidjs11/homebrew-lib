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

// global constants
extern const u16 SCR_WIDTH;
extern const u16 SCR_HEIGHT;

// initialize a screen struct
void gfx_initScreen(screen_t*, u16 width, u16 height);

// print a frame into the screen
void gfx_printScreen(screen_t *screen);

// fill the screen with a color
void gfx_fillScreen(screen_t*, color_t);

// set a pixel on the screen
void gfx_setPixel(screen_t *, u16 x, u16 y, color_t);

// fill a rect on the screen
void gfx_fillRect(screen_t *, u16 x, u16 y, u16 w, u16 h, color_t);



#endif // GRAPHICS_H
