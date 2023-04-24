#ifndef STEPPER_H
#define STEPPER_H

#include "led.h"

class Stepper{
	public:
		void StepRight(void);
		void StepLeft(void);
		void SetLed(Led * pLed);
	
	private:
		Led * pMyLed;
	
		unsigned char ucLedCtr;
		unsigned char ucInversion;
	
		void Step(enum Step eStep);
};
 
#endif
