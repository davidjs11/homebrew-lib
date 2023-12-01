#include "input.h"
#include <stdlib.h>

#ifdef PLATFORM_NDS
#include <nds.h>
#define CONTROLLER_SIZE 12
const u32 keymap[] = {
    [INPUT_UP] = KEY_UP,
    [INPUT_DOWN] = KEY_DOWN,
    [INPUT_LEFT] = KEY_LEFT,
    [INPUT_RIGHT] = KEY_RIGHT,
    [INPUT_A] = KEY_A,
    [INPUT_B] = KEY_B,
    [INPUT_X] = KEY_X,
    [INPUT_Y] = KEY_Y,
    [INPUT_SELECT] =  KEY_SELECT,
    [INPUT_START] = KEY_START
};
#endif // PLATFORM_NDS


// initialize a controller (given its index)
// returns a pointer to the input array
button_t *input_initController(controller_t* controller, u8 index)
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

    // return a pointer to the button array
    return controller->input;
}


// get the state of a controller
void input_getState(controller_t* controller)
{

#ifdef PLATFORM_NDS
    // get key state
    scanKeys();
    u32 state[3] = { keysDown(), keysUp(), keysHeld() };
    
    // update each button state
    for(u8 i=0; i<CONTROLLER_SIZE; i++) {
        button_t *button = &controller->input[i];
        button->down = state[0] & keymap[i];
        button->up = state[1] & keymap[i];
        button->pressed = state[2] & keymap[i];
        button->frames = (button->pressed) ? button->frames+1 : 0;
    }
#endif
}
