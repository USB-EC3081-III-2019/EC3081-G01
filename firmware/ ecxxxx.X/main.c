/*
 * File:   newmain.c
 * Author: Alejandro Portillo
 *
 * Created on September 27, 2019, 8:59 PM
 */


#include <xc.h>
#include "Config.h"
#include "LCD.h" 

#define _XTAL_FREQ 4000000

void main ()
{
    int Horizontal, Vertical, C;
    
    char aux[]="GRUPO 01";
    char aux1[]="ORAZIO PORTILLO";
    
    PIC_Configuracion_Inicial();
    LCD_Configuracion_Inicial();
   
    C = LCD_Contador(aux); 
    
    Horizontal = 4;
    Vertical = 1; // 1 Arriba, 2 Abajo
    
    LCD_Cursor(Horizontal, Vertical);
    
    LCD_Escribir_Cadena(aux);
    
    ///////////////////////
    
    
    Horizontal = -C-Horizontal;
    Vertical = 2; // 1 Arriba, 2 Abajo
    
    LCD_Cursor(Horizontal, Vertical);
    
    LCD_Escribir_Cadena(aux1);
            
    /*char ora[] = "HOLAComo estas";
    PIC_Configuracion_Inicial();
    LCD_Configuracion_Inicial();
    
    LCD_Escribir_Cadena(ora);
    
    LCD_Escribir('A');
    LCD_Escribir('a');
    LCD_Escribir('A');
    LCD_Escribir('a');
    LCD_Escribir('A');*/
   
	
    while(1)
    {
        __delay_ms(500);
        PORTAbits.RA0 = 1;
        __delay_ms(500);
        PORTAbits.RA0 = 0;
        
    }
}
