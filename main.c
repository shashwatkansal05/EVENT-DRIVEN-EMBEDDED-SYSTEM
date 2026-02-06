#include <stdio.h>
#include "button_fsm.h"
#include "app_fsm.h"

int main(void)
{
    int button_input = 0;
    Event_t event;

    ButtonFSM_Init();
    AppFSM_Init();

    while (1)
    {
        printf("Enter button (1=press, 0=release): ");
        scanf("%d", &button_input);

        event = ButtonFSM_Update(button_input);

        if (event != EVENT_NONE)
        {
            AppFSM_Update(event);
        }
    }

    return 0;
}
