#include <xc.h>

#define LCD_RS PORTCbits.RC1
#define LCD_E PORTCbits.RC0 
#define LCD_DATO PORTD

#define _XTAL_FREQ 4000000

void LCD_Comando(char dato);
void LCD_Escribir(char dato);
void LCD_Configuracion_Inicial();
void PIC_Configuracion_Inicial();

void LCD_Timer();

void LCD_Escribir_Cadena(char str[]);
void LCD_Escribir_C1(char H, char V, char linea1[]);
void LCD_Escribir_C2(char H, char H1, char linea1[] , char linea2 []);

void LCD_Cursor (char Horizontal , char Vertical);
void LCD_Display (int T, int H);
int LCD_Contador(char c[]);
