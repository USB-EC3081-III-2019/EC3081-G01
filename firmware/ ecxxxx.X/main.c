/*
 * File:   newmain.c
 * Author: Alejandro Portillo
 *
 * Created on September 27, 2019, 8:59 PM
 */


#include <xc.h>
#include "Config.h"
#include "LCD.h" 
#include "Teclado.h"

#define _XTAL_FREQ 4000000

void main ()
{
    
while(1)
{
    PIC_Configuracion_Inicial();
    LCD_Configuracion_Inicial();
    
    
    int Horizontal, Vertical, C, C1;
    
    char aux[]="1#ORAZIO PORTILLO";
    char aux1[]="1#BENSEDI ACOSTA";
      
    PIC_Configuracion_Inicial();
    LCD_Configuracion_Inicial();
   
    C = LCD_Contador(aux); 
    
    Horizontal = 0;
    Vertical = 1; // 1 Arriba, 2 Abajo
    
    LCD_Cursor(Horizontal, Vertical);
    
    LCD_Escribir_Cadena(aux);
    
    
    ///////////////////////
    
    C1 = LCD_Contador(aux) + LCD_Contador(aux1);
    
    Horizontal = -C-Horizontal;
    Vertical = 2; // 1 Arriba, 2 Abajo
    
    LCD_Cursor(Horizontal, Vertical);
    
    LCD_Escribir_Cadena(aux1);


        //LCD_Display(C,0);
        //LCD_Display(C1,0);

    while (1)
    {
        int c;
        
        for(c=1 ; c<4 ; c++)
        {
            PORTB&=~(1<<c);//011 101 110
            PORTB|=(1<<c);
        }
    }
    
        
    /*while(1)
    {
        __delay_ms(500);
        PORTAbits.RA0 = 1;
        __delay_ms(500);
        PORTAbits.RA0 = 0;
        
    }¨*/
}
}


