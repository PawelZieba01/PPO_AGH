#ifndef STEPPER_H
#define STEPPER_H

#include "led.h"

class Stepper{
	public:
		void StepRight(void);
		void StepLeft(void);
		void SetLed(Led * pLed);
	
	private:
		void Step(enum Step eStep);
		unsigned char ucLedCtr;
		Led * pMyLed;
};
#endif
