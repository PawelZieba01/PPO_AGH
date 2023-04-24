#ifndef STEPPER_H
#define STEPPER_H

#include "led.h"
#include "ledInv.h"


class Stepper
{
	private:
		void Step(enum Step eStep);
		Led MyLed;
		LedInv MyLedInv;
		unsigned char ucLedCtr;
	
	public:
		void StepRight(void);
		void StepLeft(void);
};


#endif
