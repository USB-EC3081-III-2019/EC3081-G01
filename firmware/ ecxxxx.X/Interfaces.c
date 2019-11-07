#include <xc.h>
#include "LCD.h"

#define _XTAL_FREQ 4000000

extern unsigned int H, V, c;

void Bienvenida() {
    ///////////BIENVENIDOS////////////

    H = 3;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("BIENVENIDOS");


    ///////////////////////

    c = LCD_Contador("BIENVENIDOS") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 0;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("Sistema de Riego");

    __delay_ms(2000);

}

void C1() {
    ///////////CONFIGURACIONES 1////////////

    LCD_Comando(0x01); //Clear Display

    H = 0;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("1. Configuracion");


    ///////////////////////

    c = LCD_Contador("1. Configuracion") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 0;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("2. Consulta Sens.");

    __delay_ms(3000);
}

void C2() {
    ///////////////////////

    LCD_Comando(0x01); //Clear Display

    H = 0;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("3. Sist. Autom.");


    ///////////////////////

    c = LCD_Contador("3. Sist. Autom.") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 0;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("4. Sist. Manual");

    __delay_ms(3000);
}

void C3() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 0;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("1. C. Sensores");


    ///////////////////////

    c = LCD_Contador("1. C. Sensores") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 0;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("2. C. Humbral");

    __delay_ms(2000);
}

void C4() {
    ///////////////////////

    LCD_Comando(0x01); //Clear Display

    H = 0;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("*. Regresar");

    __delay_ms(2000);
}

void C5() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 0;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("¿Que sensores");


    ///////////////////////

    c = LCD_Contador("¿Que sensores") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 0;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("desea utilizar?");

    __delay_ms(2000);
}

void C6() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 0;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("1. S. Temp./Hum.");


    ///////////////////////

    c = LCD_Contador("1. S. Temp./Hum.") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 0;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("2. S. Hum. Suelo");

    __delay_ms(2000);
}

void C7() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 0;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("3. S. Lluvia");


    ///////////////////////

    c = LCD_Contador("3. S. Lluvia") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 0;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("4. S. Luz");

    __delay_ms(2000);
}

void C8() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 0;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("*. Regresar");

    __delay_ms(2000);
}

void C9() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 0;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("S. Temp./Hum.");


    ///////////////////////

    c = LCD_Contador("S. Temp./Hum.") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 0;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("1. SI      2. NO");
        __delay_ms(2000);
}
