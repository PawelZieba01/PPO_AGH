#include "KeyboardLed.h"
#include "Keyboard.h"
#include "Ledboard.h"

KeyboardLed::KeyboardLed(unsigned char _ucColumn)
{
    pLed        =   new Ledboard(_ucColumn);
    pKeyboard   =   new Keyboard(_ucColumn);
}

eKeyboardState KeyboardLed::eRead(void)
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
            pLed->Off();
            break; 
    } 

    return eState;
}
