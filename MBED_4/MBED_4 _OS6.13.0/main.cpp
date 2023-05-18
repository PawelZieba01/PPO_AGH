#include "KeyboardLed.h"
#include "LCD_DISCO_F429ZI.h"

LCD_DISCO_F429ZI LCD;

int main() {
    KeyboardLed Keyboard(0);
    Ledboard * pLedboard  = new Ledboard(2);

    while(1) { 
        switch(Keyboard.eRead())
        {
            case BUTTON_0:
                pLedboard->On(3);
                break;
            
            case BUTTON_1:
                pLedboard->On(2);
                break;
            
            case BUTTON_2:
                pLedboard->On(1);
                break;
            
            case BUTTON_3:
                pLedboard->On(0);
                break;

            default: 
                pLedboard->Off();
                break;
        }

        wait_us(100000);
    } 
}
