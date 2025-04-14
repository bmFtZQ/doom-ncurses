#pragma once

#include <stdint.h>

#define KEY_QUEUE_LENGTH 16

extern uint16_t keyEventsQueue[KEY_QUEUE_LENGTH];
extern int keyEventReadPtr;
extern int keyEventWritePtr;
extern char previousKeys[KEY_QUEUE_LENGTH];

void GetKeyBoardInput();
