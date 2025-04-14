#include <string.h>
#include <ncurses.h>

#include "../doomgeneric/doomkeys.h"
#include "arguments.h"
#include "input.h"

uint16_t keyEventsQueue[KEY_QUEUE_LENGTH] = { 0 };
int keyEventReadPtr = 0;
int keyEventWritePtr = 0;
char previousKeys[KEY_QUEUE_LENGTH] = { 0 };

char toDoomKey(int c)
{
    char key = 0;

    switch (c)
    {
    case '\e': case 'q': key = DG_KEY_ESCAPE; break;
    case '\n': key = DG_KEY_ENTER; break;
    case KEY_UP: case 'w': key = DG_KEY_UPARROW; break;
    case KEY_DOWN: case 's': key = DG_KEY_DOWNARROW; break;
    case KEY_LEFT: case 'a': key = DG_KEY_LEFTARROW; break;
    case KEY_RIGHT: case 'd': key = DG_KEY_RIGHTARROW; break;
    case KEY_HOME: case 'e': key = DG_KEY_USE; break;
    case KEY_END: case ' ': key = DG_KEY_FIRE; break;

    case 'y':
    case 'n':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        key = c; break;

    default: break;
    }

    return key;
}

void addKey(bool pressed, unsigned char key)
{
    uint16_t keyEvent = (pressed << 8) | (key);
    keyEventsQueue[keyEventWritePtr++] = keyEvent;
    keyEventWritePtr %= KEY_QUEUE_LENGTH;
}

void GetKeyBoardInput()
{
    if (frameCounter % 5 == 0)
    {
        // Get all keys currently pressed.
        char currentKeys[KEY_QUEUE_LENGTH] = { 0 };
        char currentKeysPtr = 0;
        for (int key; (key = wgetch(stdscr)) != ERR;)
        {
            char doomKey = toDoomKey(key);
            if (doomKey)
            {
                currentKeys[currentKeysPtr++] = doomKey;
            }
        }

        // Look for new keys being pressed.
        for (int i = 0; i < KEY_QUEUE_LENGTH; i++)
        {
            char currentKey = currentKeys[i];
            if (!currentKey) continue;
            bool isInCurrent = false;
            for (int j = 0; j < KEY_QUEUE_LENGTH; j++)
            {
                char previousKey = previousKeys[j];
                if (!previousKey) continue;
                if (currentKey == previousKey)
                {
                    isInCurrent = true;
                    break;
                }
            }
            if (!isInCurrent)
            {
                addKey(true, currentKey);
            }
        }

        // Look for keys being released.
        for (int i = 0; i < KEY_QUEUE_LENGTH; i++)
        {
            char previousKey = previousKeys[i];
            if (!previousKey) continue;
            bool isInPrevious = false;
            for (int j = 0; j < KEY_QUEUE_LENGTH; j++)
            {
                char currentKey = currentKeys[j];
                if (!currentKey) continue;
                if (previousKey == currentKey)
                {
                    isInPrevious = true;
                    break;
                }
            }
            if (!isInPrevious)
            {
                addKey(false, previousKey);
            }
        }

        memcpy(previousKeys, currentKeys, sizeof(currentKeys));

        // if (keyEventReadPtr != keyEventWritePtr)
        // {
        //     printf("Write Ptr: %d, Read Ptr: %d\n", keyEventWritePtr, keyEventReadPtr);
        //     for (int i = 0; i < KEY_QUEUE_LENGTH; i++)
        //     {
        //         printf("%d, ", keyEventsQueue[i]);
        //     }
        //     putchar('\n');
        // }
    }
}
