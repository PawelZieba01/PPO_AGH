#include "Stepper.h"
#include "Keyboard.h"
#include "Led.h"
#include "LedInv.h"


void Delay(int iTimeInMs){
	int iCycle;
	int iNumberOfCycles = 2400 * iTimeInMs;
	
	for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}
}




int main(void)
{
	Stepper MyStepper;
	Keyboard MyKeyboard;
	Led MyLed;
	LedInv MyLedInv;
	
	MyKeyboard.Init();
	
	if(MyKeyboard.eRead() == BUTTON_4){
		MyStepper.SetLed(&MyLedInv);
	}
	else{
		MyStepper.SetLed(&MyLed);
	}
	
	
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
