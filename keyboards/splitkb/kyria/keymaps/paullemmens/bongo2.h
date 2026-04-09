#ifndef BONGO2_H_
#define BONGO2_H_

// From https://github.com/pedker/OLED-BongoCat-Revision/blob/main/bongo.h

#define ANIM_FRAME_DURATION 75 // how long each frame lasts in ms
#define ANIM_SIZE 636 // number of bytes in array, minimize for adequate firmware size, max is 1024
#define IDLE_FRAMES 5
#define IDLE_TIMEOUT 750 // the amount of time it takes to return to idle
#define TAP_FRAMES 2
#define KEYS_SIZE 100 // the number of keys stored in the array that tracks keypresses; how many keys are on the board?

enum anim_states
{
    Idle,
    Prep,
    Tap
};

struct pair_int_int
{
    uint8_t first;
    uint8_t second;
};

bool detect_key_down(void);
void eval_anim_state(void);
static void draw_bongo(bool minimal);

#endif // BONGO2_H_
