#include "Stepper.h"


void Delay(int iTimeInMs){
	int iCycle;
	int iNumberOfCycles = 2400 * iTimeInMs;
	
	for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}
}

Stepper MyStepper(2);

int main(void)
{
	
	while(1){
		Delay(500);
		MyStepper.StepLeft();
	}
}
