#include "Stepper.h"
#include "Keyboard.h"


void Delay(int iTimeInMs){
	int iCycle;
	int iNumberOfCycles = 2400 * iTimeInMs;
	
	for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}
}



int main(void)
{
	Stepper MyStepper;
	Keyboard MyKeyboard;
	MyKeyboard.Init();
	
	while(1){
		Delay(500);
		
		switch(MyKeyboard.eRead())
		{
			case BUTTON_1:
				MyStepper.StepRight();
				break;
			case BUTTON_2:
				MyStepper.StepLeft();
				break;
			default: break;
		}
		
	}
}
