#include "mbed.h"

Serial MySerial(USBTX, USBRX);

int main() {
    
    int Character = 'a';
    
    while(1) { 
        MySerial.putc(Character);
        Character++;
        wait(0.5); 
    } 
}
