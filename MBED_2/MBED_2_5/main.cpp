#include "mbed.h"
#include "led.h"
#include "servo.h"
#include "command_decoder.h"

#define TERMINATOR '\r'
#define RX_BUFF_SIZE 64
#define TX_BUFF_SIZE 64

#define SERVO_FREQ 20

Serial MySerial(USBTX, USBRX);

uint8_t puts(char String[], uint8_t Size)
{
    for(uint8_t CharIndex = 0; CharIndex < Size; CharIndex++)
    {
        char CurrentChar = String[CharIndex];

        if(CurrentChar == NULL)
        {
            MySerial.putc(TERMINATOR);
            return 0;
        }
        else
        {
           MySerial.putc(CurrentChar); 
        }
    }
    return 1;
}

uint8_t gets(char String[], uint8_t Size)
{
    uint8_t CharCounter = 0;
    char CurrentChar;

    while(CharCounter < Size)
    {
        CurrentChar = MySerial.getc(); 

        if(CurrentChar == TERMINATOR)
        {
            String[CharCounter] = NULL;
            return 0;
        }
        else
        {
            String[CharCounter] = CurrentChar;
        }

        CharCounter++;
    }
    return 1;
}



char RxBuff[RX_BUFF_SIZE];

int main() {

    ServoInit(SERVO_FREQ);

    while(1)
    {
        if(gets(RxBuff, RX_BUFF_SIZE) == 0)
        {
            DecodeMsg(RxBuff);

            switch(asToken[0].uValue.eKeyword)
            {
                case ID:
                    puts((char *)" --> STM32 F429ZI DISCOVERY\n", TX_BUFF_SIZE);
                    break;

                case CALIB:
                    ServoCallib();
                    puts((char *)"OK\n", TX_BUFF_SIZE);
                    break;

                case GOTO:
                    if(ucTokenNr > 1 && asToken[1].eType == NUMBER)
                    {
                        ServoGoTo(asToken[1].uValue.uiNumber);
                        puts((char *)"OK\n", TX_BUFF_SIZE);
                    }
                    else
                    {
                        puts((char *)" --> unknowncommand\n", TX_BUFF_SIZE);
                    }
                    break;

                case STEP:
                    if(ucTokenNr > 1 && asToken[1].eType == NUMBER)
                    {
                        ServoStep(asToken[1].uValue.uiNumber);
                        puts((char *)"OK\n", TX_BUFF_SIZE);
                    }
                    else
                    {
                        puts((char *)" --> unknowncommand\n", TX_BUFF_SIZE);
                    }
                    break;

                default:
                    puts((char *)" --> unknowncommand\n", TX_BUFF_SIZE);
                    break;
            }
        }
    }
}
