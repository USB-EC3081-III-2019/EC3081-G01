#include "S_Hum_Suelo.h"
    
unsigned char Tierra_Humeda;

void S_Hum_Suelo(){ 
    
    if (PORTEbits.RE0 == 1) {
        Tierra_Humeda = 1;
    }
    if (PORTEbits.RE0 == 0) {
        Tierra_Humeda = 0;
    }
}
