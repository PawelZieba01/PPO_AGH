#ifndef STEPPER_H
#define STEPPER_H

#include "ledinv.h"

class Stepper{
	public:
		void StepRight(void);
		void StepLeft(void);
		void SetMode(unsigned char ucMode);
	
	private:
		void Step(enum Step eStep);
		unsigned char ucLedCtr;
		Led MyLed;
		LedInv MyLedInv;
		unsigned char ucInversion;
};
#endif
