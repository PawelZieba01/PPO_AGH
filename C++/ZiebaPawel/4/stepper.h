#ifndef STEPPER_H
#define STEPPER_H

class Stepper{
	public:
		void StepRight(void);
		void StepLeft(void);
	
	private:
		void Step(enum Step eStep);
		unsigned char ucLedCtr;
};
#endif
