#include "Keyboard_Ts_Lcd.h"
#include "Keyboard_Ts.h"

KeyboardTsLcd::KeyboardTsLcd(unsigned char _ucColumn)
{
    pLed        =   new LedLcd(_ucColumn);
    pKeyboard   =   new KeyboardTs(_ucColumn);
}

eKeyboardState KeyboardTsLcd::eRead(void)
{
    eKeyboardState eState;
    switch(pKeyboard->eRead()) { 
        case BUTTON_0: 
            pLed->On(0); 
            eState = BUTTON_0;
            break; 
        case BUTTON_1:
            pLed->On(1);
            eState = BUTTON_1;
            break; 
        case BUTTON_2:
            pLed->On(2);
            eState = BUTTON_2;
            break; 
        case BUTTON_3:
            pLed->On(3);
            eState = BUTTON_3;
            break; 
        default :
            pLed->On(4);
            eState = RELEASED;
            break; 
    } 

    return eState;
}
