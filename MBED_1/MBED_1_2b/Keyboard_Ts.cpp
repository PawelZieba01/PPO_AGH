#include "Keyboard_Ts.h"

#define BTN_WIDTH 80
#define BTN_HEIGHT 80
#define BTN_X_POS 0

#define SCREEN_X_SIZE 240
#define SCREEN_Y_SIZE 320

KeyboardTs::KeyboardTs(void)
{
    TS.Init(SCREEN_X_SIZE, SCREEN_Y_SIZE);
}

eKeyboardState KeyboardTs::eRead(void)
{
    TS_StateTypeDef TS_State;
    eKeyboardState KeyboardState;

    TS.GetState(&TS_State);
    if(TS_State.TouchDetected    &&    (TS_State.X >= BTN_X_POS) && (TS_State.X < BTN_X_POS + BTN_WIDTH))
    {
        uint8_t PressedKey = TS_State.Y / BTN_HEIGHT;
        switch(PressedKey)
        {
            case 0:
                KeyboardState = BUTTON_0;
                break;
            case 1:
                KeyboardState = BUTTON_1;
                break;
            case 2:
                KeyboardState = BUTTON_2;
                break;
            case 3:
                KeyboardState = BUTTON_3;
                break;
        }
    }
    else 
    {
        KeyboardState = RELEASED;
    }

    return KeyboardState;
}

