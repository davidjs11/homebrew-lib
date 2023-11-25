#include "input.h"
#include <stdlib.h>

#ifdef PLATFORM_NDS
#include <nds.h>
#define CONTROLLER_SIZE 12
#endif // PLATFORM_NDS

// initialize a controller (given its index)
void input_initController(controller_t* controller, u8 index)
{
    // init values 
    controller->enabled = true;
    controller->size = CONTROLLER_SIZE;
    controller->input = malloc(sizeof(button_t)*CONTROLLER_SIZE);
    controller->index = index;

    // initialize each button
    for(u8 i=0; i<CONTROLLER_SIZE; i++) {
        controller->input->pressed = false;
        controller->input->up = false;
        controller->input->down = false;
        controller->input->frames = 0;
    }
}

void input_getState(controller_t* controller)
{
#ifdef PLATFORM_NDS
    scanKeys();
    u32 keys = keysDown();
    if (keys & KEY_UP) controller->input[INPUT_UP].pressed = true;
    if (keys & KEY_DOWN) controller->input[INPUT_DOWN].pressed = true;
    if (keys & KEY_LEFT) controller->input[INPUT_LEFT].pressed = true;
    if (keys & KEY_RIGHT) controller->input[INPUT_RIGHT].pressed = true;
    if (keys & KEY_A) controller->input[INPUT_A].pressed = true;
    if (keys & KEY_B) controller->input[INPUT_B].pressed = true;
    if (keys & KEY_X) controller->input[INPUT_X].pressed = true;
    if (keys & KEY_Y) controller->input[INPUT_Y].pressed = true;
    if (keys & KEY_B) controller->input[INPUT_B].pressed = true;

    keys = keysUp();
    if (keys & KEY_UP) controller->input[INPUT_UP].pressed = false;
    if (keys & KEY_DOWN) controller->input[INPUT_DOWN].pressed = false;
    if (keys & KEY_LEFT) controller->input[INPUT_LEFT].pressed = false;
    if (keys & KEY_RIGHT) controller->input[INPUT_RIGHT].pressed = false;
    if (keys & KEY_A) controller->input[INPUT_A].pressed = false;
    if (keys & KEY_B) controller->input[INPUT_B].pressed = false;
    if (keys & KEY_X) controller->input[INPUT_X].pressed = false;
    if (keys & KEY_Y) controller->input[INPUT_Y].pressed = false;
    if (keys & KEY_B) controller->input[INPUT_B].pressed = false;
#endif
}
