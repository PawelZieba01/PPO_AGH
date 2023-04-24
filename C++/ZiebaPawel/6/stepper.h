#ifndef STEPPER_H
#define STEPPER_H

#include "led.h"

class Stepper : private Led{
	public:
		Stepper(unsigned char ucLedPos = 0);
		void StepRight(void);
		void StepLeft(void);
	
	private:
		unsigned char ucLedCtr;
		void Step(enum Step eStep);
};

#endif
