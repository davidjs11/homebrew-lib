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
    consoleDemoInit();
    videoSetMode(MODE_FB0);
    vramSetBankA(VRAM_A_LCD);

    // configure framebuffer for nintendo ds
    screen_t screen;
    screen.frame = (void *) VRAM_A;
    screen.width = 256;
    screen.height = 192;


    // controller
    controller_t controller;
    input_initController(&controller, 0);

    while(1) {
        input_getState(&controller);
        if (controller.input[INPUT_UP].frames > 50)
            gfx_clearScreen(&screen, COLOR_WHITE);
        else 
            gfx_clearScreen(&screen, COLOR_BLACK);
    }

    return 0;
}

#endif // PLATFORM_NDS
