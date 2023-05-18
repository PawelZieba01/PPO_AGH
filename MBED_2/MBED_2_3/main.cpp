#include "mbed.h"
#include <cstring>


#define TERMINATOR '\r'
#define RX_BUFF_SIZE 16
#define TX_BUFF_SIZE 16


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





DigitalOut MyLed(LED3);
DigitalOut MyLedOverflow(LED2);

char RxBuff[RX_BUFF_SIZE];

int main() {

    while(1)
    {
        if(gets(RxBuff, RX_BUFF_SIZE) == 0)
        {
            MyLedOverflow = 0;

            if(!strcmp(RxBuff, "on"))
            {
                MyLed = 1;
            }
            else if(!strcmp(RxBuff, "off"))
            {
                MyLed = 0;
            }
            else if(!strcmp(RxBuff, "toggle"))
            {
                MyLed = !MyLed;
            }
        }
        else
        {
            MyLedOverflow = 1;
        }
    }
}
