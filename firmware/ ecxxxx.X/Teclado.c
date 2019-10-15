#include "Teclado.h"

void interrupt Teclado(void) {
    char a = 0, b = 1, c = 1, i = 0;

    if (RBIF) {

        a = 0;
        b = 1;
        c = 1;
        i = 0;
        while (i < 3) {
            PORTBbits.RB3 = a;
            PORTBbits.RB2 = b;
            PORTBbits.RB1 = c;

            if ((PORTBbits.RB7 == 0)&&(PORTBbits.RB1 == 0)) {       

                LCD_Comando(0X01);
                i = 10;
            }

            if ((PORTBbits.RB7 == 0)&&(PORTBbits.RB2 == 0)) {

                tecla = 0;
                i = 10;
            }

            if ((PORTBbits.RB7 == 0)&&(PORTBbits.RB3 == 0)) {

                tecla = 10;
                i = 10;
            }

            if ((PORTBbits.RB6 == 0)&&(PORTBbits.RB1 == 0)) {

                tecla = 9;
                i = 10;
            }

            if ((PORTBbits.RB6 == 0)&&(PORTBbits.RB2 == 0)) {

                tecla = 8;
                i = 10;
            }

            if ((PORTBbits.RB6 == 0)&&(PORTBbits.RB3 == 0)) {

                tecla = 7;
                i = 10;
            }

            if ((PORTBbits.RB5 == 0)&&(PORTBbits.RB1 == 0)) {

                tecla = 6;
                i = 10;
            }

            if ((PORTBbits.RB5 == 0)&&(PORTBbits.RB2 == 0)) {

                tecla = 5;
                i = 10;
            }

            if ((PORTBbits.RB5 == 0)&&(PORTBbits.RB3 == 0)) {

                tecla = 4;
                i = 10;
            }

            if ((PORTBbits.RB4 == 0)&&(PORTBbits.RB1 == 0)) {

                tecla = 3;
                i = 10;
            }

            if ((PORTBbits.RB4 == 0)&&(PORTBbits.RB2 == 0)) {
                tecla = 2;
                i = 10;
            }

            if ((PORTBbits.RB4 == 0)&&(PORTBbits.RB3 == 0)) {

                tecla = 1;
                i = 10;
            }
            i++;

            if (i == 1) {
                a = 1;
                b = 0;
                c = 1;
            }

            if (i == 2) {
                a = 1;
                b = 1;
                c = 0;
            }
            
            PORTB = 0;
            RBIF = 0;
        }
    }
}
