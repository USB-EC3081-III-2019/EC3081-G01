#include "LCD.h"
#include "PWM.h"

#define _XTAL_FREQ 4000000

void myPWM(unsigned int duty, unsigned int fpwm){

    TRISCbits.TRISC2=0;
    unsigned int prescalador = 1;
    unsigned long PR2cal = _XTAL_FREQ;
    PR2cal = PR2cal/fpwm;
    PR2cal = PR2cal/4;     
    T2CON = 0b00000000;
    while(PR2cal>254){
        prescalador = prescalador*4;
        T2CON++;
        PR2cal = PR2cal/4;
    }
    PR2cal--;
    PR2 = PR2cal/4;
    
    unsigned long AuxCCPR1L = PR2cal;
    AuxCCPR1L++;
    AuxCCPR1L = AuxCCPR1L*duty;
    AuxCCPR1L = AuxCCPR1L*4;
    AuxCCPR1L = AuxCCPR1L/100;
    
    unsigned int AuxCCPR1CON = AuxCCPR1L;
    
    AuxCCPR1CON = AuxCCPR1CON & 0b00000011;
    AuxCCPR1CON = AuxCCPR1CON*16;
    CCP1CON = 0b00001100;
    CCP1CON = CCP1CON|AuxCCPR1CON;
    
    AuxCCPR1L = AuxCCPR1L/4;
    CCPR1L = AuxCCPR1L;
    T2CONbits.TMR2ON = 1;
    TMR2=0;
    
}
