#ifndef STEPPER_H
#define STEPPER_H

#include "ledInv.h"

class Stepper{
	public:
		void StepRight(void);
		void StepLeft(void);
		void SetMode(unsigned char ucMode);
	
	private:
		Led MyLed;
		LedInv MyLedInv;
	
		unsigned char ucLedCtr;
		unsigned char ucInversion;
	
		void Step(enum Step eStep);
};
 
#endif
