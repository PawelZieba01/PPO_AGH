#ifndef LED_H
#define LED_H

class Led
{
	private:
		void On(unsigned char ucLedIndex);
		void Step(enum Step eStep);
	
		unsigned char ucLedCtr;
	
	public:
		void StepRight(void);
		void StepLeft(void);
		void Init(void);
};

#endif
