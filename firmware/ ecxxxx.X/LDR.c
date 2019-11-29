#include "LDR.h"
#include "LCD.h"

extern unsigned int tecla, c;


void Fotocelda() {

    tecla = 0;
    int valor;
    long lux1;
    int uni, dec, cen, mil;

    while (tecla == 0) {
        valor = ADC_Read(0); //Se coloca 0 porque es el canal analogico RA0

        if (valor > 725) {
            lux1 = (-6 * valor + 5010) / 10;

            if (valor > 835)
                lux1 = 0;
        } else {
            lux1 = ((8 * valor / 1000 - 11600 / 1000) * valor) + 4271;
        }

        if (lux1 < 0) {
            lux1 = -lux1;
        }

        LCD_Comando(0x01); //Clear Display
        LCD_Escribir_Cadena("Flujo Luminoso:");

        c = 0;
        LCD_Comando(0x02); // reiniciar el cursor
        LCD_Cursor(0, 2);

        mil = (lux1) / 1000;
        LCD_Escribir('0' + mil);
        cen = (lux1 - mil * 1000) / 100;
        LCD_Escribir('0' + cen);
        dec = (lux1 - mil * 1000 - cen * 100) / 10; // a partir de aqui es el error
        LCD_Escribir('0' + dec);
        uni = lux1 % 10;
        LCD_Escribir('0' + uni);


        __delay_ms(500);
        LCD_Comando(0x02);

    }
}


unsigned int ADC_Read(unsigned char canal) {
    ADCON0 &= 0xC5;                     //Valor para reiniciar los canales a 0
    ADCON0bits.CHS = canal;             //Se elige el canal
    __delay_ms(2);                      //Espera para el cambio
    GO_nDONE = 1;                       //Se activa la
    while (GO_nDONE);                   //Esperamos hasta que terminen
    int X = ADRESH << 8;
    X = X + ADRESL;                     //Los valores se guardarán en el registro ADRES H(2 mas significativos) L(6 menos significativos)
    return (X);

}
