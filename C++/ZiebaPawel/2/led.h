#ifndef LED_H
#define LED_H

class Led{
	public:
		void StepRight(void);
		void StepLeft(void);
		void Init(void);
	
	private:
		void On(unsigned char ucLedIndex);
		void Step(enum Step eStep);
		unsigned char ucLedCtr;
};
#endif
