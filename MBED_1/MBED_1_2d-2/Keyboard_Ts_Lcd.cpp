#include "Keyboard_Ts_Lcd.h"
#include "Keyboard_Ts.h"

KeyboardTsLcd::KeyboardTsLcd(unsigned char _ucColumn)
{
    pLed        =   new LedLcd(_ucColumn);
    pKeyboard   =   new KeyboardTs(_ucColumn);
}

eKeyboardState KeyboardTsLcd::eRead(void)
{
    eKeyboardState eState = pKeyboard->eRead();
    
    switch(eState) { 
        case BUTTON_0: 
            pLed->On(0); 
            break; 
        case BUTTON_1:
            pLed->On(1);
            break; 
        case BUTTON_2:
            pLed->On(2);
            break; 
        case BUTTON_3:
            pLed->On(3);
            break; 
        default :
            pLed->On(4);
            break; 
    } 

    return eState;
}
