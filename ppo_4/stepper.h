#ifndef STEPPER_H
#define STEPPER_H


class Stepper
{
	private:
		void Step(enum Step eStep);
	
		unsigned char ucLedCtr;
	
	public:
		void StepRight(void);
		void StepLeft(void);
};


#endif
