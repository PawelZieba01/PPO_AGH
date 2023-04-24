#ifndef STEPPER_H
#define STEPPER_H

#include "led.h"


class Stepper : private Led
{
	private:
		void Step(enum Step eStep);
	
		unsigned char ucLedCtr;
	
	public:
		void StepRight(void);
		void StepLeft(void);
};


#endif
