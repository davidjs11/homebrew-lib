// currently testing for nintendo DS

#include "input.h"
#include "graphics.h"

#ifdef PLATFORM_NDS
#include <nds.h>


// nds delay function
void delay(int milliseconds)
{
    int frames = milliseconds/16; // a frame takes ~16ms to render
    for(int i=0; i<frames; i++)
        swiWaitForVBlank();
}

int main(void)
{

    screen_t screen;
    gfx_initScreen(&screen, SCR_WIDTH, SCR_HEIGHT);
    consoleDemoInit();

    // controller
    controller_t controller;
    button_t *input = input_initController(&controller, 0);

    // game loop
    while(true) {
        input_getState(&controller);

        // clear the screen
        gfx_fillScreen(&screen, COLOR_BLACK);

        // set some pixels on the screen
        for(int i=0; i<50; i++)gfx_setPixel(&screen, i, i, COLOR_RED);
        for(int i=50; i<100; i++)gfx_setPixel(&screen, i, i, COLOR_BLUE);
        for(int i=100; i<150;i++)gfx_setPixel(&screen, i, i, COLOR_GREEN);

        // fill some rectangles
        gfx_fillRect(&screen,   0,   0, 50, 50, COLOR_GREEN);
        gfx_fillRect(&screen,  50,  50, 50, 50, COLOR_RED);
        gfx_fillRect(&screen, 100, 100, 50, 50, COLOR_BLUE);

        gfx_fillScreen(&screen, COLOR_BLACK);
        gfx_printScreen(&screen);
        swiWaitForVBlank();

    }

    return 0;
}

#endif // PLATFORM_NDS
