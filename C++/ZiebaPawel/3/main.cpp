#include "led.h"
#include "stepper.h"

void Delay(int iTimeInMs){
	int iCycle;
	int iNumberOfCycles = 2400 * iTimeInMs;
	
	for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}
}

Led MyLed;
Stepper MyStepper;

int main(void)
{
	MyLed.Init();

	while(1){
		Delay(100);
		MyStepper.StepLeft();
	}
}
