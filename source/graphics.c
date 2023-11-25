#include "graphics.h"

/* NINTENDO DS */
#ifdef PLATFORM_NDS

#include <nds.h>

// define color map and framebuffer resolution
typedef u16 pixel_t;
const pixel_t color_map[] = {
    [COLOR_RED]     = RGB15(31, 00, 00),
    [COLOR_GREEN]   = RGB15(00, 31, 00),
    [COLOR_BLUE]    = RGB15(00, 00, 31),
    [COLOR_BLACK]   = RGB15(00, 00, 00),
    [COLOR_WHITE]   = RGB15(31, 31, 31) 
};

#endif // PLATFORM_NDS

// fill the screen with a color
void gfx_clearScreen(screen_t *screen, color_t color)
{
    for(size_t i=0; i<screen->width*screen->height; i++)
        ((pixel_t*)screen->frame)[i] = color_map[color];
}
