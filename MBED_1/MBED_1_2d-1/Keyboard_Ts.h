#ifndef KEYBOARD_TS_H
#define KEYBOARD_TS_H

#include "TS_DISCO_F429ZI.h"

typedef enum eKeyboardState {RELEASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3} eKeyboardState;

class KeyboardTs{
    private:
        TS_DISCO_F429ZI TS;

        uint8_t ColumnNum;

    public: 
        KeyboardTs(uint8_t Column = 0);
        eKeyboardState eRead(void);

};

#endif
