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
    gfx_initScreen(&screen);
    consoleDemoInit();

    // controller
    controller_t controller;
    input_initController(&controller, 0);
    button_t *input = controller.input;

    gfx_fillScreen(&screen, COLOR_BLACK);

    // game loop
    while(true) {
        input_getState(&controller);

        // set some pixels on the screen
        for(int i=0; i<50; i++)gfx_setPixel(&screen, i, i, COLOR_RED);
        for(int i=50; i<100; i++)gfx_setPixel(&screen, i, i, COLOR_BLUE);
        for(int i=100; i<150;i++)gfx_setPixel(&screen, i, i, COLOR_GREEN);
    }

    return 0;
}

#endif // PLATFORM_NDS
