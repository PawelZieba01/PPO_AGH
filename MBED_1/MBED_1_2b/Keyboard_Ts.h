#ifndef KEYBOARD_TS_H
#define KEYBOARD_TS_H

#include "TS_DISCO_F429ZI.h"

typedef enum eKeyboardState {RELEASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3} eKeyboardState;

class KeyboardTs{
    private:
        TS_DISCO_F429ZI TS;

    public: 
        KeyboardTs(void);
        eKeyboardState eRead(void);

};

#endif
