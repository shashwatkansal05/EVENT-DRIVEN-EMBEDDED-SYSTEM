#include "app_fsm.h"
#include <stdio.h>

typedef enum
{
    APP_OFF,
    APP_ON,
    APP_BLINK_SLOW,
    APP_BLINK_FAST
} AppState_t;

static AppState_t state;

void AppFSM_Init(void)
{
    state = APP_OFF;
}

void AppFSM_Update(Event_t event)
{
    switch (state)
    {
        case APP_OFF:
            if (event == EVENT_SHORT_PRESS)
            {
                printf("LED ON\n");
                state = APP_ON;
            }
            break;

        case APP_ON:
            if (event == EVENT_SHORT_PRESS)
            {
                printf("BLINK SLOW\n");
                state = APP_BLINK_SLOW;
            }
            else if (event == EVENT_LONG_PRESS)
            {
                printf("LED OFF\n");
                state = APP_OFF;
            }
            break;

        case APP_BLINK_SLOW:
            if (event == EVENT_TIMEOUT)
            {
                printf("SLOW TOGGLE\n");
            }
            else if (event == EVENT_SHORT_PRESS)
            {
                printf("BLINK FAST\n");
                state = APP_BLINK_FAST;
            }
            else if (event == EVENT_LONG_PRESS)
            {
                printf("LED OFF\n");
                state = APP_OFF;
            }
            break;

        case APP_BLINK_FAST:
            if (event == EVENT_TIMEOUT)
            {
                printf("FAST TOGGLE\n");
            }
            else if (event == EVENT_LONG_PRESS)
            {
                printf("LED OFF\n");
                state = APP_OFF;
            }
            break;
    }
}
