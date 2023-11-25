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

    // controller
    controller_t controller;
    input_initController(&controller, 0);
    button_t *input = controller.input;

    // game loop
    while(true) {
        input_getState(&controller);

        if (input[INPUT_UP].frames > 50)
            gfx_fillScreen(&screen, COLOR_WHITE);
        else 
            gfx_fillScreen(&screen, COLOR_BLACK);
    }

    return 0;
}

#endif // PLATFORM_NDS
