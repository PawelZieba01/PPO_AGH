#include "mbed.h"


Serial MySerial(USBTX, USBRX);

int main() {
    
    while(1) { 
        MySerial.putc( MySerial.getc() );
    } 
}
