#include "led.h"
#include "mbed.h"

#define LED_NUM 4;

DigitalOut Led0(PF_13);
DigitalOut Led1(PF_15);
DigitalOut Led2(PG_1);
DigitalOut Led3(PE_8);

void LedInit(void)
{
	Led0 = 1;
}


void LedOn(unsigned char ucLedIndeks)
{
	Led0 = 0;
    Led1 = 0;
    Led2 = 0;
    Led3 = 0;
	
	switch(ucLedIndeks)
	{
		case 0:
            Led0 = 1;
            break;
		case 1:
            Led1 = 1;
            break;
		case 2:
            Led2 = 1;
            break;
		case 3:
            Led3 = 1;
            break;
	}
}


enum StepLedDirection {LEFT, RIGHT};

void LedStep(enum StepLedDirection eDirection)
{
	static unsigned int LedModuloCounter = 0;
	
	if(eDirection == LEFT)
	{
		LedModuloCounter++;
	}
	else if(eDirection == RIGHT)
	{
		LedModuloCounter--;
	}
	
	LedOn(LedModuloCounter % 4);
}


void LedStepRight(void)
{
	LedStep(RIGHT);
}


void LedStepLeft(void)
{
	LedStep(LEFT);
}
