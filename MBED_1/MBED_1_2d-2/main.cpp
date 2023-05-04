#include "Keyboard_Ts_Lcd.h"


int main() {
    KeyboardTsLcd Keyboard(0);
    LedLcd Led(2);

    while(1) { 
        switch(Keyboard.eRead())
        {
            case BUTTON_0:
                Led.On(3);
                break;
            
            case BUTTON_1:
                Led.On(2);
                break;
            
            case BUTTON_2:
                Led.On(1);
                break;
            
            case BUTTON_3:
                Led.On(0);
                break;

            default: 
                Led.On(4);
                break;
        }

        wait(0.1); 
    } 
}
