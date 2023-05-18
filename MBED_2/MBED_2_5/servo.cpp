#include "servo.h"
#include "led.h"
#include "mbed.h"


#define DETECTOR_PIN PB_0

enum DetectorState {ACTIVE, INACTIVE};
enum ServoState {CALLIB, IDLE, IN_PROGRESS};

struct Servo
{
	enum ServoState eState; 
	unsigned int uiCurrentPosition;
	unsigned int uiDesiredPosition;
}; 

struct Servo sServo;

DigitalIn Detector(DETECTOR_PIN);
Ticker Trigger;

void DetectorInit(void);
enum DetectorState eReadDetector(void);
void Automat(void);


void Automat(void)
{
	switch(sServo.eState)
	{
		case IDLE:
			if(sServo.uiCurrentPosition != sServo.uiDesiredPosition)
			{
				sServo.eState = IN_PROGRESS;
			}
			else
			{
				sServo.eState = IDLE;
			}
			break;
		
		case IN_PROGRESS:
			if(sServo.uiCurrentPosition < sServo.uiDesiredPosition)
			{
				LedStepRight();
				sServo.uiCurrentPosition++;
				sServo.eState = IN_PROGRESS;
			}
			else if(sServo.uiCurrentPosition > sServo.uiDesiredPosition)
			{
				LedStepLeft();
				sServo.uiCurrentPosition--;
				sServo.eState = IN_PROGRESS;
			}
			else
			{
				sServo.eState = IDLE;
			}
			break;
		
		case CALLIB:
			if(ACTIVE == eReadDetector())
			{
				sServo.uiCurrentPosition = 0;
				sServo.uiDesiredPosition = 0;
				sServo.eState = IDLE;
			}
			else
			{
				LedStepLeft();
				sServo.eState = CALLIB;
			}
			break;
		
		default:
			break;
	}
}


void ServoStep(int uiSteps)
{
    sServo.uiDesiredPosition = sServo.uiDesiredPosition + uiSteps;
}


enum DetectorState eReadDetector(void)
{
	if(Detector.read())
	{
		return INACTIVE;
	}
	else
	{
		return ACTIVE;
	}
}


void ServoInit(unsigned int uiServoFrequency)
{
	LedInit();
	Trigger.attach(&Automat, (1.0/uiServoFrequency));
	sServo.eState = CALLIB;
}


void ServoCallib(void)
{
	sServo.eState = CALLIB;
}


void ServoGoTo(unsigned int uiPosition)
{
	sServo.uiDesiredPosition = uiPosition;
}
