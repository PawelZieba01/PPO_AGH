#include "mbed.h"


#define TERMINATOR '\r'
#define BUFF_SIZE 8


Serial MySerial(USBTX, USBRX);

uint8_t puts(char String[], uint8_t Size)
{   
    for(uint8_t CharIndex = 0; CharIndex < Size; CharIndex++)
    {
        if(String[CharIndex] == NULL)
        {
            break;
        }
        else if(CharIndex == Size)
        {
          return 1;  
        }
    }

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
}

DigitalOut MyLed(LED3);

int main() {
    uint8_t Result = puts((char *)"Tekst zbyt dlugi, zeby wyslac NULLa", BUFF_SIZE);
    MyLed = Result;
}
