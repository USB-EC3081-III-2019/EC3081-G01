#include <xc.h>
#include "LCD.h"
#include "DHT11.h"

#define _XTAL_FREQ 4000000

extern unsigned int H, V, c, z, tecla, x, j;
extern unsigned int Temp_Hum, Hum_Suelo, Lluvia, Luz;
extern unsigned char T_Byte1, T_Byte2, RH_Byte1, RH_Byte2, CheckSum;

void C1_0() {
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

    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }


}

void C2_0() {

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
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }

}

void C1_1() {
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

    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C1_2() {
    ///////////////////////

    LCD_Comando(0x01); //Clear Display

    H = 0;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("*. Regresar");

    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C1_1_1() {
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

    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C1_1_2() {
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

    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C1_1_3() {
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

    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C1_1_4() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 0;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("*. Regresar");

    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C1_1_1_1() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 2;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("S. Temp./Hum.");


    ///////////////////////

    c = LCD_Contador("S. Temp./Hum.") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 0;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("1. SI      2. NO");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C1_1_1_2() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 2;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("S. Temp./Hum.");


    ///////////////////////

    c = LCD_Contador("S. Temp./Hum.") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 3;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("(ENCENDIDOS)");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C1_1_1_3() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 2;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("S. Temp./Hum.");


    ///////////////////////

    c = LCD_Contador("S. Temp./Hum.") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 3;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("(APAGADOS)");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C1_1_2_1() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 2;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("S. Hum. Suelo");


    ///////////////////////

    c = LCD_Contador("S. Hum. Suelo") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 0;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("1. SI      2. NO");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C1_1_2_2() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 2;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("S. Hum. Suelo");


    ///////////////////////

    c = LCD_Contador("S. Hum. Suelo") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 3;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("(ENCENDIDO)");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C1_1_2_3() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 2;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("S. Hum. Suelo");


    ///////////////////////

    c = LCD_Contador("S. Hum. Suelo") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 3;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("(APAGADO)");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C1_1_3_1() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 3;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("S. Lluvia");


    ///////////////////////

    c = LCD_Contador("S. Lluvia") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 0;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("1. SI      2. NO");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C1_1_3_2() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 3;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("S. Lluvia");


    ///////////////////////

    c = LCD_Contador("S. Lluvia") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 3;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("(ENCENDIDO)");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C1_1_3_3() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 3;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("S. Lluvia");


    ///////////////////////

    c = LCD_Contador("S. Lluvia") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 3;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("(APAGADO)");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C1_1_4_1() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 5;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("S. Luz");


    ///////////////////////

    c = LCD_Contador("S. Luz") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 0;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("1. SI      2. NO");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C1_1_4_2() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 5;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("S. Luz");


    ///////////////////////

    c = LCD_Contador("S. Luz") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 3;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("(ENCENDIDO)");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C1_1_4_3() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 5;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("S. Luz");


    ///////////////////////

    c = LCD_Contador("S. Luz") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 3;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("(APAGADO)");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void INTERFACE_Bienvenida() {
    ///////////BIENVENIDOS////////////
    LCD_Comando(0x01); //Clear Display

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

    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C3_0(){
    LCD_Comando(0x01); //Clear Display

    H = 4;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("¿Llueve?");


    ///////////////////////

    c = LCD_Contador("¿Llueve?") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 0;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("Si(?)      No(?)");

    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C3_1(){
    LCD_Comando(0x01); //Clear Display
    
    H = 4;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("Ventanas");


    ///////////////////////

    c = LCD_Contador("Ventanas") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 3;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("(ABIERTAS)");

    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C3_2(){
    LCD_Comando(0x01); //Clear Display
        
    H = 4;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("Ventanas");


    ///////////////////////

    c = LCD_Contador("Ventanas") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 3;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("(CERRADAS)");

    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C3_3(){
    LCD_Comando(0x01); //Clear Display

    H = 1;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("¿Tierra Humeda?");


    ///////////////////////

    c = LCD_Contador("¿Tierra Humeda?") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 0;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("Si(?)      No(?)");

    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C3_4(){
    LCD_Comando(0x01); //Clear Display
    
    H = 3;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("Aspersores");


    ///////////////////////

    c = LCD_Contador("Aspersores") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 2;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("(ENCENDIDOS)");

    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C3_5(){
    LCD_Comando(0x01); //Clear Display
        
    H = 3;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("Aspersores");


    ///////////////////////

    c = LCD_Contador("Aspersores") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 3;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("(APAGADOS)");

    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C4_0() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 3;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("Aspersores");


    ///////////////////////

    c = LCD_Contador("Aspersores") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 0;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("1.On       2.Off");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C4_1() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 3;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("Aspersores");


    ///////////////////////

    c = LCD_Contador("Aspersores") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 3;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("(ENCENDIDOS)");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C4_2() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 3;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("Aspersores");


    ///////////////////////

    c = LCD_Contador("Aspersores") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 3;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("(APAGADOS)");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C4_3() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 4;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("Ventanas");


    ///////////////////////

    c = LCD_Contador("Ventanas") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 0;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("1.On       2.Off");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C4_4() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 4;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("Ventanas");


    ///////////////////////

    c = LCD_Contador("Ventanas") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 3;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("(ABIERTAS)");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void C4_5() {
    ///////////CONFIGURACIONES////////////

    LCD_Comando(0x01); //Clear Display

    H = 3;
    V = 1;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("Ventanas");


    ///////////////////////

    c = LCD_Contador("Ventanas") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

    H = 3;
    V = 2;

    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena("(CERRADAS)");
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void INTERFACE_Configuracion_1_Temp_Hum() {
    tecla = 0;
    j = 0;
    Temp_Hum = 0;// Lo sefine el sensor

    while (j == 0) {
        switch (tecla) {
            case (0):
                C1_1_1_1();
                break;
            case (1):
                tecla = 0;
                C1_1_1_2();
                Temp_Hum = 1;
                x = 0;
                j = 1;
                break;
            case (2):
                tecla = 0;
                C1_1_1_3();
                Temp_Hum = 0;
                x = 0;
                j = 1;
                break;
            case (10):
                x = 0;
                j = 1;
                break;

        }
    }
}

void INTERFACE_Configuracion_1_Hum_Suelo() {
    tecla = 0;
    j = 0;
    Hum_Suelo = 0;// Lo define el sensor

    while (j == 0) {
        switch (tecla) {
            case (0):
                C1_1_2_1();
                break;
            case (1):
                tecla = 0;
                C1_1_2_2();
                Hum_Suelo = 1;
                x = 0;
                j = 1;
                break;
            case (2):
                tecla = 0;
                C1_1_2_3();
                Hum_Suelo = 0;
                x = 0;
                j = 1;
                break;
            case (10):
                x = 0;
                j = 1;
                break;

        }
    }
}

void INTERFACE_Configuracion_1_Lluvia() {
    tecla = 0;
    j = 0;
    Lluvia = 0; // Lo define el sensor

    while (j == 0) {
        switch (tecla) {
            case (0):
                C1_1_3_1();
                break;
            case (1):
                tecla = 0;
                C1_1_3_2();
                Lluvia = 1; 
                x = 0;
                j = 1;
                break;
            case (2):
                tecla = 0;
                C1_1_3_3();
                Lluvia = 0;
                x = 0;
                j = 1;
                break;
            case (10):
                x = 0;
                j = 1;
                break;

        }
    }
}

void INTERFACE_Configuracion_1_Luz() {
    tecla = 0;
    j = 0;
    Luz = 0; // Lo define el sensor

    while (j == 0) {
        switch (tecla) {
            case (0):
                C1_1_4_1();
                break;
            case (1):
                tecla = 0;
                C1_1_4_2();
                Luz = 1;
                x = 0;
                j = 1;
                break;
            case (2):
                tecla = 0;
                C1_1_4_3();
                Luz = 0;
                x = 0;
                j = 1;
                break;
            case (10):
                x = 0;
                j = 1;
                break;

        }
    }
}

void INTERFACE_Configuracion_1() {
    tecla = 0;
    j = 0;

    while (j == 0) {
        switch (tecla) {
            case (0):
                C1_1_1();
                if (tecla == 1) {
                    break;
                }
                C1_1_2();
                if (tecla == 1) {
                    break;
                }
                C1_1_3();
                if (tecla == 1) {
                    break;
                }
                C1_1_4();
                if (tecla == 1) {
                    break;
                }
                break;
            case (1):
                INTERFACE_Configuracion_1_Temp_Hum();
                break;
            case (2):
                INTERFACE_Configuracion_1_Hum_Suelo();
                break;
            case (3):
                INTERFACE_Configuracion_1_Lluvia();
                break;
            case (4):
                INTERFACE_Configuracion_1_Luz();
                break;
            case (10):
                x = 0;
                j = 1;
                break;

        }
    }

}

void Suma() {


}

void Resta() {

}

Neutro() {

}

void C2_1() {

    extern unsigned char temp1, temp2;
    char Temperature[] = "Temp. Max: 00 C ";
    tecla = 0;
    j = 0;
    temp1 = '0';
    temp2 = '0';

    LCD_Comando(0x01);
    while (j == 0) {
        switch (tecla) {
            case(0):
                ///////////CONFIGURACIONES////////////
                LCD_Comando(0x01);

                Temperature[15] = 223; // put degree symbol (°)
                LCD_Escribir_Cadena(Temperature);

                c = LCD_Contador("Temp. Max: 00 C ") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

                H = 0;
                V = 2;

                LCD_Cursor(H, V); // (Horizontal, Vertical)
                LCD_Escribir_Cadena("2.+   5.OK   8.-");
                break;

            case(2):
                LCD_Comando(0x01);

                Temperature[12] = temp1 + 1;
                temp1 = Temperature[12];

                if (temp1 == ':') {

                    Temperature[11] = temp2 + 1;
                    temp2 = Temperature[11];
                    temp1 = '0';
                    Temperature[12] = temp1;
                }

                LCD_Escribir_Cadena(Temperature);

                c = LCD_Contador("Temp. Max: 00 C ") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

                H = 0;
                V = 2;

                LCD_Cursor(H, V); // (Horizontal, Vertical)
                LCD_Escribir_Cadena("2.+   5.OK   8.-");

                tecla = 0;
                j = 0;
                break;

            case(8):

                if (temp1 >= '0' && temp2 > '/') {
                    LCD_Comando(0x01);

                    Temperature[12] = temp1 - 1;
                    temp1 = Temperature[12];


                    if (temp1 == '/') {

                        Temperature[11] = temp2 - 1;
                        temp2 = Temperature[11];
                        temp1 = '9';
                        Temperature[12] = temp1;

                    }

                    LCD_Escribir_Cadena(Temperature);

                    c = LCD_Contador("Temp. Max: 00 C ") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

                    H = 0;
                    V = 2;

                    LCD_Cursor(H, V); // (Horizontal, Vertical)
                    LCD_Escribir_Cadena("2.+   5.OK   8.-");
                }



                tecla = 0;
                j = 0;
                break;

            case(5):
                j = 1;
                break;
        }

        for (z = 0; z < 100; z++) {
            if (tecla == 0) {
                __delay_ms(20);
            }
        }
    }
}

void C2_2() {

}

void C2_3() {

}

void C2_4() {

}

void C2_5() {

}

void C2_6() {

}

void C2_7() {

}

void INTERFACE_Configuracion_2() {
    tecla = 0;
    j = 0;

    while (j == 0) {
        switch (tecla) {
            case (0):
                C2_1();
                tecla = 1;
                break;
            case (1):
                C2_2();
                tecla = 2;
                break;
            case (2):
                C2_3();
                tecla = 3;
                break;
            case (3):
                C2_4();
                tecla = 4;
                break;
            case (4):
                C2_5();
                tecla = 5;
                break;
            case (5):
                C2_6();
                tecla = 6;
                break;
            case (6):
                C2_7();
                break;
            case (10):
                x = 0;
                j = 1;
                break;

        }
    }

}

void INTERFACE_Configuracion() {
    tecla = 0;
    j = 0;

    while (j == 0) {
        switch (tecla) {
            case (0):
                C1_1();
                if (tecla == 1) {
                    break;
                }
                C1_2();
                break;
            case (1):
                INTERFACE_Configuracion_1();
                break;
            case (2):
                INTERFACE_Configuracion_2();
                break;
            case (10):
                x = 0;
                j = 1;
                break;

        }
    }
}

void INTERFACE_Consulta_Sensores() {


    tecla = 0;
    j = 0;

    while (j == 0) {
        switch (tecla) {
            case(0):
                LCD_Comando(0x01); //Clear Display
                if (Temp_Hum == 1) {
                    tecla = 0;
                    LCD_Escribir_Cadena("Temp_Hum = 1");
                    for (z = 0; z < 100; z++) {
                        if (tecla == 0) {
                            __delay_ms(20);
                        }
                    }
                    tecla = 1;
                }
                if (Temp_Hum == 0) {
                    tecla = 0;
                    LCD_Escribir_Cadena("Temp_Hum = 0");
                    for (z = 0; z < 100; z++) {
                        if (tecla == 0) {
                            __delay_ms(20);
                        }
                    }
                    tecla = 1;
                }
            case(1):
                LCD_Comando(0x01); //Clear Display
                if (Hum_Suelo == 1) {
                    tecla = 0;
                    LCD_Escribir_Cadena("Hum_Suelo = 1");
                    for (z = 0; z < 100; z++) {
                        if (tecla == 0) {
                            __delay_ms(20);
                        }
                    }
                    tecla = 2;                   
                }
                if (Hum_Suelo == 0) {
                    tecla = 0;
                    LCD_Escribir_Cadena("Hum_Suelo = 0");
                    for (z = 0; z < 100; z++) {
                        if (tecla == 0) {
                            __delay_ms(20);
                        }
                    }
                    tecla = 2;      
                }
            case (2):
                LCD_Comando(0x01); //Clear Display
                if (Lluvia == 1) {
                    tecla = 0;
                    LCD_Escribir_Cadena("Lluvia = 1");
                    for (z = 0; z < 100; z++) {
                        if (tecla == 0) {
                            __delay_ms(20);
                        }
                    }
                    tecla = 3; 
                }
                if (Lluvia == 0) {
                    tecla = 0;
                    LCD_Escribir_Cadena("Lluvia = 0");
                    for (z = 0; z < 100; z++) {
                        if (tecla == 0) {
                            __delay_ms(20);
                        }
                    }
                    tecla = 3;
                }
            case (3):
                LCD_Comando(0x01); //Clear Display
                if (Luz == 1) {
                    tecla = 0;
                    LCD_Escribir_Cadena("Luz = 1");
                    for (z = 0; z < 100; z++) {
                        if (tecla == 0) {
                            __delay_ms(20);
                        }
                    }
                    x = 0;
                    j = 1;
                }
                if (Luz == 0) {
                    tecla = 0;
                    LCD_Escribir_Cadena("Luz = 0");
                    for (z = 0; z < 100; z++) {
                        if (tecla == 0) {
                            __delay_ms(20);
                        }
                    }
                    x = 0;
                    j = 1;
                }
            case(10):
                x = 0;
                j = 1;
                break;
        }
    }
}

void INTERFACE_Sistema_Automatico_Llueve() {
    tecla = 0;
    j = 0;
    int lluvia = 1;//Esto lo define el sensor

    while (j == 0) {
        switch (tecla) {
            case (0):
                C3_0();
                
                if (lluvia == 1) {
                    tecla = 1;
                    break;
                }
                if (lluvia == 0) {
                    tecla = 2;
                    break;
                }
            case (1):
                tecla = 0;
                C3_1();
                tecla = 2;
            case (2):
                tecla = 0;
                C3_2();
                x = 0;
                j = 1;
                break;
            case(10):
                x = 0;
                j = 1;
                break;
        }
    }
}

void INTERFACE_Sistema_Automatico_Tierra_Humeda(){
    tecla = 0;
    j = 0;
    int Tierra_Humeda = 1;// Esto lo define el censor

    while (j == 0) {
        switch (tecla) {
            case (0):
                C3_3();
                
                if (Tierra_Humeda == 1) {
                    tecla = 1;
                    break;
                }
                if (Tierra_Humeda == 0) {
                    tecla = 2;
                    break;
                }
            case (1):
                tecla = 0;
                C3_4();
                tecla = 2;
            case (2):
                tecla = 0;
                C3_5();
                x = 0;
                j = 1;
                break;
            case(10):
                x = 0;
                j = 1;
                break;
        }
    }  
}

void INTERFACE_Sistema_Automatico() {
    tecla = 0;
    j = 0;
    
    while (j == 0) {
        switch (tecla) {
            case (0):
                INTERFACE_Sistema_Automatico_Llueve();
                tecla = 1;
            case (1):
                INTERFACE_Sistema_Automatico_Tierra_Humeda();
                break;
            case(10):
                x = 0;
                j = 1;
                break;

        }
    }

}

void INTERFACE_Sistema_Manual_Aspersores() {
    tecla = 0;
    j = 0;

    while (j == 0) {
        switch (tecla) {
            case (0):
                C4_0();
                break;
            case (1):
                tecla = 0;
                C4_1();
                j = 1;
                break;
            case (2):
                tecla = 0;
                C4_2();
                j = 1;
                break;
            case(10):
                x = 0;
                j = 1;
                break;

        }
    }
}

void INTERFACE_Sistema_Manual_Ventanas() {
    tecla = 0;
    j = 0;

    while (j == 0) {
        switch (tecla) {
            case (0):
                C4_3();
                break;
            case (1):
                tecla = 0;
                C4_4();
                x = 0;
                j = 1;
                break;
            case (2):
                tecla = 0;
                C4_5();
                x = 0;
                j = 1;
                break;
            case(10):
                x = 0;
                j = 1;
                break;

        }
    }
}

void INTERFACE_Sistema_Manual() {
    tecla = 0;
    j = 0;

    while (j == 0) {
        switch (tecla) {
            case (0):
                INTERFACE_Sistema_Manual_Aspersores();
                tecla = 1;
            case (1):
                INTERFACE_Sistema_Manual_Ventanas();
                break;
            case(10):
                x = 0;
                j = 1;
                break;

        }
    }
}

void INTERFACE_Principal() {
    tecla = 0;
    j = 0;

    while (j == 0) {
        switch (tecla) {
            case (0):
                C1_0();
                if (tecla == 1) {
                    break;
                }
                C2_0();
                break;
            case (1):
                INTERFACE_Configuracion();
                break;
            case (2):
                INTERFACE_Consulta_Sensores();
                break;
            case (3):
                INTERFACE_Sistema_Automatico();
                break;
            case (4):
                INTERFACE_Sistema_Manual();
                break;
            case(10):
                x = 0;
                j = 1;
                break;

        }
    }
}
