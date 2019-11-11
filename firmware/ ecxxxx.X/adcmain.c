// CONFIG
#define _XTAL_FREQ 4000000

#define RS RD2
#define EN RD3
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7


#pragma config FOSC = XT        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include <pic16f877.h>
#include "lcd.h"
#include <math.h>



void ADC_Init()
{
   ADCON0 = 0x81;
   ADCON1 = 0x80;
}

unsigned int ADC_Read(unsigned char channel)
{
   if(channel > 7)
     return 0;

   ADCON0 &= 0xC5;
   ADCON0 |= channel<<3;
   __delay_ms(2);
   GO_nDONE = 1;
   while(GO_nDONE);
   return ((ADRESH<<8)+ADRESL);
}

void main()
{ 
   unsigned int a;
   float b,c,d,e,f,b1,b2,b3,b4,x;
   
   TRISA = 0xFF;
   TRISB = 0xFF;
   TRISD = 0x00;
   
   ADC_Init();
   
   Lcd_Init();
   Lcd_Clear();
   
   
   
   while(1){
       
     a = ADC_Read(0);
     
     //b = 18.463;
     //c = 85.66;
     //d = 921.72;
     //e = 67295.5;
     //f = 11399;
         
     x = (a/204.6);
     
         
     b4 = (18.46*pow(x,4));
     b3 = (85.66*pow(x,3));
     b2 = (921.72*pow(x,2));
     b1 = (6729.5*x);
     b  = -b4 + b3 + b2 - b1 + 11399; 
     
     
     
     //Lcd_Set_Cursor(1,1);
     //Lcd_Write_String("MedicionADC");
     
     Lcd_Set_Cursor(1,4);
     Lcd_Write_float(a);
     
      Lcd_Set_Cursor(1,9);
     Lcd_Write_float(x);
     //Lcd_Write_float(b3);
     
     
     Lcd_Set_Cursor(2,1);
     Lcd_Write_String("LUX");
     
     Lcd_Set_Cursor(2,7);     
     Lcd_Write_Int(b);
     Lcd_Write_String("    ");
     
     Lcd_Write_float(x);
     Lcd_Write_String("    ");
   }
}
