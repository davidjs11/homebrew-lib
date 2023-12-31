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

const u16 SCR_WIDTH = 256;
const u16 SCR_HEIGHT = 192;

#endif // PLATFORM_NDS

void gfx_initScreen(screen_t* screen, u16 width, u16 height)
{
    screen->width = width;
    screen->height = height;

#ifdef PLATFORM_NDS
    // set output to lcd from bank a
    videoSetMode(MODE_FB0);
    vramSetBankA(VRAM_A_LCD);
    // screen->frame = (pixel_t*) malloc(sizeof(pixel_t)*screen->width*screen->height);
#endif // PLATFORM_NDS
}

// fill the screen with a color
void gfx_fillScreen(screen_t *screen, color_t color)
{
    for(size_t i=0; i<screen->width*screen->height; i++)
        ((pixel_t*)screen->frame)[i] = color_map[color];
}

// set a pixel on the screen
void gfx_setPixel(screen_t *screen, u16 x, u16 y, color_t color)
{
    ((pixel_t *)screen->frame)[x+y*screen->width] = color_map[color];
}

void gfx_fillRect(screen_t *screen,u16 x,u16 y,u16 w,u16 h,color_t color){
    u16 finish_x = x+w;
    u16 finish_y = y+h;
    for(u16 i=x; i<finish_x; i++)
        for(u16 j=y; j<finish_y; j++)
            ((pixel_t*)screen->frame)[i+j*screen->width]=color_map[color];
}

void gfx_printScreen(screen_t *screen)
{
#ifdef PLATFORM_NDS
    for(int x=0; x<screen->width; x++)
        for(int y=0; y<screen->height; y++)
            VRAM_A[x+y*SCREEN_WIDTH] = ((pixel_t*)screen->frame)[x+y*SCREEN_WIDTH];
#endif // PLATFORM_NDS
}
