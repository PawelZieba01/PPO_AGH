#ifndef STEPPER_H
#define STEPPER_H

#include "led.h"

class Stepper
{
	private:
		void Step(enum Step eStep);
		Led * pMyLed;
		unsigned char ucLedCtr;
		unsigned char ucInversion;
	
	public:
		void StepRight(void);
		void StepLeft(void);
		void SetLed(Led * pLed);
};


#endif
