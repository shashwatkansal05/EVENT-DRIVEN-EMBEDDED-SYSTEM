#include "button_fsm.h"

typedef enum
{
    BUTTON_IDLE,
    BUTTON_PRESSED
} ButtonState_t;

static ButtonState_t state;
static int press_time;

#define LONG_PRESS_TIME 5   // fake time units

void ButtonFSM_Init(void)
{
    state = BUTTON_IDLE;
    press_time = 0;
}

Event_t ButtonFSM_Update(int button_input)
{
    Event_t event = EVENT_NONE;

    switch (state)
    {
        case BUTTON_IDLE:
            if (button_input == 1)
            {
                press_time = 0;
                state = BUTTON_PRESSED;
            }
            break;

        case BUTTON_PRESSED:
            if (button_input == 1)
            {
                press_time++;

                if (press_time >= LONG_PRESS_TIME)
                {
                    event = EVENT_LONG_PRESS;
                    state = BUTTON_IDLE;
                }
            }
            else
            {
                event = EVENT_SHORT_PRESS;
                state = BUTTON_IDLE;
            }
            break;
    }

    return event;
}
