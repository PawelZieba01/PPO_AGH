#include "mbed.h"
#include <stdio.h>

#define TERMINATOR '\r'
#define BUFF_SIZE 64


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

int main() {
    uint8_t BeatCounter = 0;
    char StringToSend[BUFF_SIZE];

    while(1) { 
        sprintf(StringToSend, "hardbeat number: %d\n", BeatCounter);
        puts(StringToSend, BUFF_SIZE);

        BeatCounter++;
        wait(1);
    } 
}
