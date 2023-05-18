#ifndef LEDBOARD_H
#define LEDBOARD_H

#include "Led.h"
#include <vector>


class Ledboard{
    public: 
        Ledboard(unsigned char ucColumn);
        void Off(void);
        void On(unsigned char ucLed);
    
    private:
        std::vector<Led*> Leds;
};

#endif
