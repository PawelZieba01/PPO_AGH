#ifndef LED_LCD_H
#define LED_LCD_H

#include "LCD_DISCO_F429ZI.h"

class LedLcd{
    private: 
        LCD_DISCO_F429ZI LCD;
        void DrawLed(uint8_t RectIndex, uint32_t Color);

        uint8_t ColumnNum;
    
    public:
        LedLcd(uint8_t Column = 0);
        void On(uint8_t LedIndex);
};

#endif
