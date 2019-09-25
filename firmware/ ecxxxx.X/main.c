/*
 * File:   main.c
 * Author: user
 *
 * Created on 24 de septiembre de 2019, 01:43 PM
 */

#include <xc.h>

#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // FLASH Program Memory Code Protection bits (Code protection off)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low Voltage In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection (Code Protection off)
#pragma config WRT = ON          // FLASH Program Memory Write Enable (Unprotected program memory may be written to by EECON control)

#define _XTAL_FREQ 4000000

#define LCD_DATO PORTD
#define LCD_E PORTCbits.RC0 
#define LCD_RS PORTCbits.RC1

void LCD_Comando(char dato);
void LCD_Escribir(char dato);
void LCD_Configuracion_Inicial();
void PIC_Configuracion_Inicial();

void main ()
{
    
    PIC_Configuracion_Inicial();
    LCD_Configuracion_Inicial();
    LCD_Escribir('a');
    
    while(1){
        PORTAbits.RA0 = 1;
        __delay_ms(500);
        PORTAbits.RA0 = 0;
        __delay_ms(500);
    }
};

void LCD_Comando ( char dato )
{
    LCD_RS = 1;
    LCD_DATO = dato;
    LCD_E = 1;
    LCD_E = 0;
    
    if(dato <= 3)
    {
        __delay_ms(2);
    }
    else
    {
        __delay_us(40);
    }
    
};

void LCD_Escribir ( char dato )
{
    LCD_RS = 0;
    LCD_DATO = dato;
    LCD_E = 1;
    LCD_E = 0;
    __delay_us(40);

    
};

void LCD_Configuracion_Inicial ()
{
    LCD_E = 0;
    __delay_ms(15);
    LCD_Comando(0x38);
    __delay_ms(5);
    LCD_Comando(0x38);
    __delay_ms(1);
    LCD_Comando(0x38);
    LCD_Comando(0x38);    
    LCD_Comando(0x0C);
    LCD_Comando(0x01);/*Display Clear*/
    LCD_Comando(0x06);/*Incrementa el cursor*/
    LCD_Comando(0x0C);
};

void PIC_Configuracion_Inicial ()
{
    TRISD = 0;
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 0;
    TRISAbits.TRISA0 = 0;
    ADCON0 = 0;
    
    INTCON = 0;
};
