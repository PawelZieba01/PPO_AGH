#include "stepper.h"


enum Step{LEFT,RIGHT};

extern unsigned char ucInversion;

void Stepper::Step(enum Step eStep){
	if(eStep == LEFT){
		ucLedCtr--;
	}
	else if(eStep == RIGHT){
		ucLedCtr++;
	}
	else{}
		
	ucLedCtr = ucLedCtr % 4;
	
	if(1 == ucInversion){
		MyLedInv.On(ucLedCtr);
	}
	else{
		MyLed.On(ucLedCtr);
	}
}

void Stepper::StepLeft(void){
	Step(LEFT);
}

void Stepper::StepRight(void){
	Step(RIGHT);
}
