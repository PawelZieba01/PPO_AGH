#include "Keyboard_Ts.h"

#define BTN_WIDTH 80
#define BTN_HEIGHT 80

#define SCREEN_X_SIZE 240
#define SCREEN_Y_SIZE 320

KeyboardTs::KeyboardTs(uint8_t Column)
{
    ColumnNum = Column;

    TS.Init(SCREEN_X_SIZE, SCREEN_Y_SIZE);
}

eKeyboardState KeyboardTs::eRead(void)
{
    TS_StateTypeDef TS_State;
    eKeyboardState KeyboardState[4] = {BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};

    TS.GetState(&TS_State);
    if(TS_State.TouchDetected    &&    (TS_State.X >= ColumnNum*BTN_WIDTH) && (TS_State.X < (ColumnNum*BTN_WIDTH) + BTN_WIDTH))
    {
        uint8_t PressedKey = TS_State.Y / BTN_HEIGHT;
        return KeyboardState[PressedKey];
    }
    else 
    {
        return RELEASED;
    }
}

