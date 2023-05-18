#include "mbed.h"


Serial MySerial(USBTX, USBRX);
DigitalOut MyLed(LED1);

int main() {
    
    
    while(1) { 
        if(MySerial.getc())
        {
            MyLed = !MyLed;
        }
    } 
}
