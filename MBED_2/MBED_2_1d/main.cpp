#include "mbed.h"


Serial MySerial(USBTX, USBRX);
DigitalOut MyLed(LED1);

int main() {
    
    while(1) { 
        switch(MySerial.getc())
        {
            case 's':
                MyLed = 1;
                break;
                
            case 'c':
                MyLed = 0;
                break;

            case 't':
                MyLed = !MyLed;
                break;

            default: 
                break;
        }
    } 
}
