#ifndef STEPPER_H
#define STEPPER_H

#include "led.h"


class Stepper
{
	private:
		void Step(enum Step eStep);
		Led MyLed;
		unsigned char ucLedCtr;
	
	public:
		Stepper(unsigned char ucLedPos = 0);
		void StepRight(void);
		void StepLeft(void);
};


#endif
