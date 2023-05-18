#ifndef LED_H
#define LED_H

#include "mbed.h"

class Led{
    private: 
        void Redraw(uint32_t Color);

        unsigned char ucColumn;
        unsigned char ucRow;
    
    public:
        Led(unsigned char ucColumn, unsigned char ucRow);
        void On(void);
        void Off(void);
};

#endif
