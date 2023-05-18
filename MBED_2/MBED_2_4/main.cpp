#include "mbed.h"
#include <cctype>

#define TERMINATOR '\r'
#define RX_BUFF_SIZE 64
#define TX_BUFF_SIZE 64

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


void ToLowerStr(char DestinationString[], char SourceString[])
{
    for(int CharIndex = 0; SourceString[CharIndex] != NULL; CharIndex++)
    {
        DestinationString[CharIndex] = tolower(SourceString[CharIndex]);
    }
}



char RxBuff[RX_BUFF_SIZE];
char TxBuff[TX_BUFF_SIZE];

int main() {

    while(1)
    {   
        uint8_t Fail = gets(RxBuff, RX_BUFF_SIZE);
        if(Fail == 0)
        {
            strcpy(TxBuff, RxBuff);
            strcat(TxBuff, RxBuff);
            ToLowerStr(TxBuff, TxBuff);
            puts(TxBuff, TX_BUFF_SIZE);  
        }
        else 
        {
            puts((char *)"Bad Input", TX_BUFF_SIZE);
        }
        
    }
}
