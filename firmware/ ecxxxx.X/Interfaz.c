#include <xc.h>
#include "LCD.h"
#include "DHT11.h"
#include "S_Hum_Suelo.h"
#include "LDR.h"


#define _XTAL_FREQ 4000000

extern unsigned int H, V, c, z, tecla, x, j,j1;
extern unsigned int Temp_Hum, Hum_Suelo, Lluvia, Luz;
extern unsigned char T_Byte1, T_Byte2, RH_Byte1, RH_Byte2, CheckSum, Tierra_Humeda;

void INTERFACE_Configuracion_1_Temp_Hum() {
    tecla = 0;
    j = 0;
    Temp_Hum = 0; // Lo sefine el sensor

    while (j == 0) {
        switch (tecla) {
            case (0):

                LCD_Escribir_C1(2, 1, "S. Temp./Hum.");
                LCD_Escribir_C2(2, 0, "S. Temp./Hum.", "1. SI      2. NO");

                LCD_Timer();

                break;
            case (1):
                tecla = 0;

                LCD_Escribir_C1(2, 1, "S. Temp./Hum.");
                LCD_Escribir_C2(2, 3, "S. Temp./Hum.", "(ENCENDIDOS)");

                LCD_Timer();

                Temp_Hum = 1;
                x = 0;
                j = 1;
                break;
            case (2):
                tecla = 0;

                LCD_Escribir_C1(2, 1, "S. Temp./Hum.");
                LCD_Escribir_C2(2, 3, "S. Temp./Hum.", "(APAGADOS)");

                LCD_Timer();

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
    Hum_Suelo = 0; // Lo define el sensor

    while (j == 0) {
        switch (tecla) {
            case (0):

                LCD_Escribir_C1(2, 1, "S. Hum. Suelo");
                LCD_Escribir_C2(2, 0, "S. Hum. Suelo", "1. SI      2. NO");

                LCD_Timer();

                break;
            case (1):
                tecla = 0;

                LCD_Escribir_C1(2, 1, "S. Hum. Suelo");
                LCD_Escribir_C2(2, 3, "S. Hum. Suelo", "(ENCENDIDO)");

                LCD_Timer();

                Hum_Suelo = 1;
                x = 0;
                j = 1;
                break;
            case (2):
                tecla = 0;

                LCD_Escribir_C1(2, 1, "S. Hum. Suelo");
                LCD_Escribir_C2(2, 3, "S. Hum. Suelo", "(APAGADO)");

                LCD_Timer();

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

                LCD_Escribir_C1(3, 1, "S. Lluvia");
                LCD_Escribir_C2(3, 0, "S. Lluvia", "1. SI      2. NO");

                LCD_Timer();

                break;
            case (1):
                tecla = 0;

                LCD_Escribir_C1(3, 1, "S. Lluvia");
                LCD_Escribir_C2(3, 3, "S. Lluvia", "(ENCENDIDO)");

                LCD_Timer();

                Lluvia = 1;
                x = 0;
                j = 1;
                break;
            case (2):
                tecla = 0;

                LCD_Escribir_C1(3, 1, "S. Lluvia");
                LCD_Escribir_C2(3, 3, "S. Lluvia", "(APAGADO)");

                LCD_Timer();

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

                LCD_Escribir_C1(5, 1, "S. Luz");
                LCD_Escribir_C2(5, 0, "S. Luz", "1. SI      2. NO");

                LCD_Timer();

                break;
            case (1):
                tecla = 0;

                LCD_Escribir_C1(5, 1, "S. Luz");
                LCD_Escribir_C2(5, 3, "S. Luz", "(ENCENDIDO)");

                LCD_Timer();

                Luz = 1;
                x = 0;
                j = 1;
                break;
            case (2):
                tecla = 0;

                LCD_Escribir_C1(5, 1, "S. Luz");
                LCD_Escribir_C2(5, 4, "S. Luz", "(APAGADO)");

                LCD_Timer();

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

                LCD_Escribir_C1(0, 1, "¿Que sensores");
                LCD_Escribir_C2(0, 0, "¿Que sensores", "desea utilizar?");

                LCD_Timer();

                if (tecla == 1) {
                    break;
                }

                LCD_Escribir_C1(0, 1, "1. S. Temp./Hum.");
                LCD_Escribir_C2(0, 0, "1. S. Temp./Hum.", "2. S. Hum. Suelo");

                LCD_Timer();

                if (tecla == 1) {
                    break;
                }

                LCD_Escribir_C1(0, 1, "3. S. Lluvia");
                LCD_Escribir_C2(0, 0, "3. S. Lluvia", "4. S. Luz");

                LCD_Timer();

                if (tecla == 1) {
                    break;
                }

                LCD_Escribir_C1(0, 1, "*. Regresar");

                LCD_Timer();

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
    char Temperature[] = "Temp. Max: 20 C ";
    tecla = 0;
    j = 0;
    temp1 = '0';
    temp2 = '2';

    LCD_Comando(0x01);
    while (j == 0) {
        switch (tecla) {
            case(0):
                ///////////CONFIGURACIONES////////////
                LCD_Comando(0x01);

                Temperature[15] = 223; // put degree symbol (°)
                LCD_Escribir_Cadena(Temperature);

                c = LCD_Contador("Temp. Max: 20 C ") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

                H = 0;
                V = 2;

                LCD_Cursor(H, V); // (Horizontal, Vertical)
                LCD_Escribir_Cadena("2(+) 5 (OK) 8(-)");
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

                c = LCD_Contador("Temp. Max: 20 C ") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

                H = 0;
                V = 2;

                LCD_Cursor(H, V); // (Horizontal, Vertical)
                LCD_Escribir_Cadena("2(+) 5 (OK) 8(-)");

                tecla = 0;
                j = 0;
                break;

            case(8):

                if (temp1 >= '0' && temp2 > '1') {
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

                    c = LCD_Contador("Temp. Max: 20 C ") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

                    H = 0;
                    V = 2;

                    LCD_Cursor(H, V); // (Horizontal, Vertical)
                    LCD_Escribir_Cadena("2(+) 5 (OK) 8(-)");
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

    extern unsigned char temp1, temp2;
    char Temperature[] = "Temp. Max: 20 C ";
    tecla = 0;
    j = 0;
    temp1 = '0';
    temp2 = '2';

    LCD_Comando(0x01);
    while (j == 0) {
        switch (tecla) {
            case(0):
                ///////////CONFIGURACIONES////////////
                LCD_Comando(0x01);

                Temperature[15] = 223; // put degree symbol (°)
                LCD_Escribir_Cadena(Temperature);

                c = LCD_Contador("Temp. Min: 20 C ") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

                H = 0;
                V = 2;

                LCD_Cursor(H, V); // (Horizontal, Vertical)
                LCD_Escribir_Cadena("2(+) 5 (OK) 8(-)");
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

                c = LCD_Contador("Temp. Min: 20 C ") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

                H = 0;
                V = 2;

                LCD_Cursor(H, V); // (Horizontal, Vertical)
                LCD_Escribir_Cadena("2(+) 5 (OK) 8(-)");

                tecla = 0;
                j = 0;
                break;

            case(8):

                if (temp1 >= '0' && temp2 > '1') {
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

                    c = LCD_Contador("Temp. Min: 20 C ") + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea

                    H = 0;
                    V = 2;

                    LCD_Cursor(H, V); // (Horizontal, Vertical)
                    LCD_Escribir_Cadena("2(+) 5 (OK) 8(-)");
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

                LCD_Escribir_C1(0, 1, "1. C. Sensores");
                LCD_Escribir_C2(0, 0, "1. C. Sensores", "2. C. Humbral");

                LCD_Timer();

                if (tecla == 1) {
                    break;
                }

                LCD_Escribir_C1(0, 1, "*. Regresar");

                LCD_Timer();

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
                    DHT11();
                    if (tecla == 10) {
                        x = 0;
                        j = 1;
                    }
                    tecla = 1;
                    break;
                }
                if (Temp_Hum == 0) {
                    tecla = 0;
                    LCD_Escribir_Cadena("Temp_Hum = Off");
                    
                    LCD_Timer();
                    
                    if (tecla == 10) {
                        x = 0;
                        j = 1;
                    }
                    tecla = 1;
                    break;
                }
            case(1):
                LCD_Comando(0x01); //Clear Display
                if (Hum_Suelo == 1) {
                    tecla = 0;
                    LCD_Escribir_Cadena("Hum_Suelo = On");

                    LCD_Timer();
                    
                    if (tecla == 10) {
                        x = 0;
                        j = 1;
                    }
                    tecla = 2;
                    break;
                }
                if (Hum_Suelo == 0) {
                    tecla = 0;
                    LCD_Escribir_Cadena("Hum_Suelo = Off");

                    LCD_Timer();
                    
                    if (tecla == 10) {
                        x = 0;
                        j = 1;
                    }
                    tecla = 2;
                    break;
                }
            case (2):
                LCD_Comando(0x01); //Clear Display
                if (Lluvia == 1) {
                    tecla = 0;
                    LCD_Escribir_Cadena("Lluvia = On");

                    LCD_Timer();
                    
                    if (tecla == 10) {
                        x = 0;
                        j = 1;
                    }
                    tecla = 3;
                    break;
                }
                if (Lluvia == 0) {
                    tecla = 0;
                    LCD_Escribir_Cadena("Lluvia = Off");

                    LCD_Timer();
                    
                    if (tecla == 10) {
                        x = 0;
                        j = 1;
                    }
                    tecla = 3;
                    break;
                }
            case (3):
                LCD_Comando(0x01); //Clear Display
                if (Luz == 1) {
                    tecla = 0;
                    Fotocelda();

                    LCD_Timer();
                    
                    if (tecla == 10) {
                        x = 0;
                        j = 1;
                    }
                    tecla = 4;
                    break;
                }
                if (Luz == 0) {
                    tecla = 0;
                    LCD_Escribir_Cadena("Luz = Off");

                    LCD_Timer();
                    
                    if (tecla == 10) {
                        x = 0;
                        j = 1;
                    }
                    tecla = 4;
                    break;
                }
            case (4):
                tecla = 0;
                LCD_Escribir_C1(1, 1, "Si desea salir");
                LCD_Escribir_C2(1, 2, "Si desea salir", "PRESIONE (*)");

                LCD_Timer();
                
                if (tecla == 10) {
                    x = 0;
                    j = 1;
                }
                break;
        }
    }
}

void INTERFACE_Sistema_Automatico_Llueve() {
    tecla = 0;
    j1 = 0;
    int lluvia = 1; //Esto lo define el sensor

    while (j1 == 0) {
        switch (tecla) {
            case (0):

                LCD_Escribir_C1(4, 1, "¿Llueve?");
                LCD_Escribir_C2(4, 0, "¿Llueve?", "Si(?)      No(?)");

                LCD_Timer();

                if (tecla == 10) {
                    j1 = 1;
                    break;
                }
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

                LCD_Escribir_C1(4, 1, "Ventanas");
                LCD_Escribir_C2(4, 3, "Ventanas", "(ABIERTAS)");

                LCD_Timer();

                j1 = 1;
                
                if (tecla == 10) {
                    x = 0;
                    j = 1;
                    j1 = 1;
                }
                break;
            case (2):
                tecla = 0;

                LCD_Escribir_C1(4, 1, "Ventanas");
                LCD_Escribir_C2(4, 3, "Ventanas", "(CERRADAS)");

                LCD_Timer();

                j1 = 1;

                if (tecla == 10) {
                    x = 0;
                    j = 1;
                    j1 = 1;
                }
                break;
        }
    }
}

void INTERFACE_Sistema_Automatico_Tierra_Humeda() {
    tecla = 0;
    j1 = 0;
    
    while (j1 == 0) {
        switch (tecla) {
            case (0):

                LCD_Escribir_C1(1, 1, "¿Tierra Humeda?");
                LCD_Escribir_C2(1, 0, "¿Tierra Humeda?", "Si(?)      No(?)");

                LCD_Timer();
                
                S_Hum_Suelo();
                
                if (tecla == 10) {
                    j1 = 1;
                    break;
                }
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

                PORTAbits.RA5 = 1;
                
                LCD_Escribir_C1(3, 1, "Aspersores");
                LCD_Escribir_C2(3, 2, "Aspersores", "(ENCENDIDOS)");

                LCD_Timer();

                tecla = 2;

                j1 = 1;

                if (tecla == 10) {
                    x = 0;
                    j = 1;
                    j1 = 1;
                }
                break;
            case (2):
                tecla = 0;

                PORTAbits.RA5 = 0;
                
                LCD_Escribir_C1(3, 1, "Aspersores");
                LCD_Escribir_C2(3, 3, "Aspersores", "(APAGADOS)");

                LCD_Timer();

                j1 = 1;
                
                if (tecla == 10) {
                    x = 0;
                    j = 1;
                    j1 = 1;
                }
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
                if (tecla == 10) {
                    x = 0;
                    j = 1;
                }
                tecla = 1;
                break;
            case (1):
                INTERFACE_Sistema_Automatico_Tierra_Humeda();
                if (tecla == 10) {
                    x = 0;
                    j = 1;
                }
                tecla = 2;
                break;
            case (2):
                
                tecla = 0;
                LCD_Escribir_C1(1, 1, "Si desea salir");
                LCD_Escribir_C2(1, 2, "Si desea salir", "PRESIONE (*)");

                LCD_Timer();
                
                if (tecla == 10) {
                    j = 1;
                }
                
                tecla = 0;

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

                LCD_Escribir_C1(3, 1, "Aspersores");
                LCD_Escribir_C2(3, 0, "Aspersores", "1.On       2.Off");

                LCD_Timer();

                break;
            case (1):
                tecla = 0;

                PORTAbits.RA5 = 1;
                
                LCD_Escribir_C1(3, 1, "Aspersores");
                LCD_Escribir_C2(3, 2, "Aspersores", "(ENCENDIDOS)");

                LCD_Timer();

                j = 1;
                break;
            case (2):
                tecla = 0;

                PORTAbits.RA5 = 0;
                
                LCD_Escribir_C1(3, 1, "Aspersores");
                LCD_Escribir_C2(3, 3, "Aspersores", "(APAGADOS)");

                LCD_Timer();

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

                LCD_Escribir_C1(4, 1, "Ventanas");
                LCD_Escribir_C2(4, 0, "Ventanas", "1.On       2.Off");

                LCD_Timer();

                break;
            case (1):
                tecla = 0;

                LCD_Escribir_C1(4, 1, "Ventanas");
                LCD_Escribir_C2(4, 3, "Ventanas", "(ABIERTAS)");

                LCD_Timer();

                //PORTAbits.RA2 = 1;
                x = 0;
                j = 1;
                break;
            case (2):
                tecla = 0;

                LCD_Escribir_C1(4, 1, "Ventanas");
                LCD_Escribir_C2(4, 3, "Ventanas", "(CERRADAS)");

                LCD_Timer();

                //PORTAbits.RA0 = 0;
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
                LCD_Escribir_C1(0, 1, "1. Configuracion");
                LCD_Escribir_C2(0, 0, "1. Configuracion", "2. Consulta Sens.");

                LCD_Timer();

                if (tecla == 1) {
                    break;
                }

                LCD_Escribir_C1(0, 1, "3. Sist. Autom.");
                LCD_Escribir_C2(0, 0, "3. Sist. Autom.", "4. Sist. Manual");

                LCD_Timer();

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
