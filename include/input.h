#ifndef INPUT_H
#define INPUT_H

#include "types.h"

typedef struct {
    bool pressed;
    bool down;
    bool up;
    u32 frames;
} button_t;

typedef struct {
    button_t *input;
    u8 size;
    bool enabled;
    u8 index;
} controller_t;

typedef enum {
    INPUT_UP,
    INPUT_DOWN,
    INPUT_LEFT,
    INPUT_RIGHT,
    INPUT_A,
    INPUT_B,
    INPUT_Y,
    INPUT_X,
    INPUT_L,
    INPUT_R,
    INPUT_SELECT,
    INPUT_START
} key_index;

// initialize a controller (given its index)
void input_initController(controller_t*, u8 index);

// get the state of a controller
void input_getState(controller_t*);

#endif // INPUT_H
