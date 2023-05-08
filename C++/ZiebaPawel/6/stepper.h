#ifndef STEPPER_H
#define STEPPER_H

#include "led.h"

class Stepper : private Led{
	public:
		Stepper(unsigned char ucLedPos = 0);
		void StepRight(void);
		void StepLeft(void);
	
	private:
		void Step(enum Step eStep);
		unsigned char ucLedCtr;
};
#endif
