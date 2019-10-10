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
    PIC_Configuracion_Inicial();
    LCD_Configuracion_Inicial();
    
    
    int Horizontal, Vertical, C, C1, k=1,i;
    
    char aux[]="NUMERO:";
    char aux1[]="(#PARA BORRAR)";
      
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
    
    for(i=0;i<(40-LCD_Contador(aux1)+ LCD_Contador(aux));i++)//Escribe al final de la palabra NUMERO
        {
             __delay_us(40);
            LCD_Comando(0x14);
        }

        //LCD_Display(C,0);
        //LCD_Display(C1,0);


    //LCD_Escribir_Cadena("Hola")   
    while(1)
    {
        __delay_ms(500);
        PORTAbits.RA0 = 1;
        __delay_ms(500);
        PORTAbits.RA0 = 0;
        
    }

}


