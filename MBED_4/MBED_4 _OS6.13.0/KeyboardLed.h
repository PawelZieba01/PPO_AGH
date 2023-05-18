#ifndef KEYBOARD_LED_H
#define KEYBOARD_LED_H

#include "Keyboard.h"
#include "Ledboard.h"

class KeyboardLed
{
    private:
        Keyboard * pKeyboard;
        Ledboard * pLed;
    public:
        KeyboardLed(unsigned char _ucColumn);
        eKeyboardState eRead(void);
};

#endif
