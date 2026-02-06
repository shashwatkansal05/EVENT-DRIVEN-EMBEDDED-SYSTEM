#ifndef BUTTON_FSM_H
#define BUTTON_FSM_H

#include "events.h"

void ButtonFSM_Init(void);
Event_t ButtonFSM_Update(int button_input);

#endif
