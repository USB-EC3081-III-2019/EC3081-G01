#include <xc.h>

#define LCD_RS PORTCbits.RC1
#define LCD_E PORTCbits.RC0 
#define LCD_DATO PORTD

#define _XTAL_FREQ 4000000

void LCD_Comando(char dato);
void LCD_Escribir(char dato);
void LCD_Configuracion_Inicial();
void PIC_Configuracion_Inicial();
void LCD_Escribir_Cadena(char str[]);
void LCD_Cursor (int Horizontal , int Vertical);
void LCD_Display (int T, int H);
int LCD_Contador(char c[]);
