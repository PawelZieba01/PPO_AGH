#include "stepper.h"
#include "led.h"

void Delay(int iTimeInMs){
	int iCycle;
	int iNumberOfCycles = 2400 * iTimeInMs;
	
	for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}
}

Led MyLed;
Stepper MyStepper;

int main(void)
{

	while(1){
		Delay(100);
		MyStepper.StepLeft();
	}
}
