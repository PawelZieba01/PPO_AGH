#include "Ledboard.h"

#define LED_NUMBER 4

Ledboard::Ledboard(unsigned char ucColumn)
{
    for( uint8_t LedNum = 0; LedNum < LED_NUMBER; LedNum++)
    {
        Leds.push_back(new Led(ucColumn, LedNum));
        Leds.at(LedNum)->Off();
    }
}

void Ledboard::On(unsigned char ucLed)
{
    Off();
    Leds.at(ucLed)->On();
}

void Ledboard::Off(void)
{
    // for(std::vector<Led*>::iterator ItLed = Leds.begin(); ItLed != Leds.end(); ItLed++)
    // {
    //     (*ItLed)->Off();
    // }

    

    for(auto ItLed : Leds)
    {
        ItLed->Off();
    }
}