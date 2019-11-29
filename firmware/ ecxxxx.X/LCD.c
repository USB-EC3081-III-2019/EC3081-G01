#include "LCD.h"

extern unsigned int c, H, V, z, tecla;

void LCD_Comando(char dato) {
    LCD_RS = 0;
    LCD_DATO = dato;
    LCD_E = 1;
    LCD_E = 0;

    if (dato <= 3) {
        __delay_ms(2);
    } else {
        __delay_us(40);
    }

}

void LCD_Timer() {
    for (z = 0; z < 100; z++) {
        if (tecla == 0) {
            __delay_ms(20);
        }
    }
}

void LCD_Escribir_C1(char H, char V, char linea1[]) {

    LCD_Comando(0x01); //Clear Display
    LCD_Cursor(H, V); // (Horizontal, Vertical)
    LCD_Escribir_Cadena(linea1);


}

void LCD_Escribir_C2(char H, char H1, char linea1[], char linea2 []) {

    c = LCD_Contador(linea1) + H; //Se cuenta el numero de caracteres que tiene a primera linea para que la siguiente linea quede en el lugar que se desea
    LCD_Cursor(H1, 2); // (Horizontal, Vertical)
    LCD_Escribir_Cadena(linea2);

}

void LCD_Escribir_Cadena(char str[]) {
    int i = 0;
    while (str[i] != '\0' && i < 1000) {
        LCD_Escribir(str[i]);
        i++;
    }

}

void LCD_Escribir(char dato) {
    LCD_RS = 1;
    LCD_DATO = dato;
    LCD_E = 1;
    LCD_E = 0;
    __delay_us(40);


}

void LCD_Configuracion_Inicial() {
    LCD_E = 0;
    __delay_ms(15);
    LCD_Comando(0x38);
    __delay_ms(5);
    LCD_Comando(0x38);
    __delay_ms(1);
    LCD_Comando(0x38); //Function Set
    LCD_Comando(0x38); //1. Manda o recibe info en 8 o en 4Bits  

    LCD_Comando(0x01); //Clear Display
    LCD_Comando(0x06); //Entry mode set
    //1.Hace que el cursor se mueva hacia la derecha cuando escribe algo
    //2.Si se mueve o no se mueve la pantalla
    LCD_Comando(0x0C); //Display ON/OFF Cntrl
    LCD_Comando(0x0C); //1.Enciende lapantalla 2. apaga el cursor 3. no hace que titilee el cursor
}

void PIC_Configuracion_Inicial() {

    TRISD = 0;
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 0;
    TRISCbits.TRISC6 = 0;
    PORTCbits.RC6 = 0;
    TRISB = 0b11110000;
    
    TRISAbits.TRISA5 = 0;
    ADCON1bits.PCFG = 0b111110; //A0 será la entrada analógica
    //Perifericos (Iniciar configuraciones analogicas)
    ADCON0bits.ADCS = 0b00;     //ADCS1:ADCS0: A/D Conversion Clock Select bits 00 = FOSC/2    
    ADCON0bits.ADON = 1;        //Encendemos el modulo analogico
    ADCON1bits.ADFM = 1;        //Justificación a la derecha(De esta manera, los bits más significativos se almacenan en ADRESH)
    //ADCON0 = 0b00000000; //Configuracion del registro ADCON0
    /*INICIALIZACIÓN DE INTERRUPCIONES*/
    INTCON = 0; //limpiar registro INTCON
    
    /////////////////////////////////

    INTCONbits.GIE = 1; //Hab interrupciones Globales
    PORTB = 0;
    RBIF = 0;
    INTCONbits.RBIE = 1; //Port b

    OPTION_REGbits.nRBPU = 0;

}

int LCD_Contador(char c[]) {
    int i = 0;
    while (c[i] != '\0' && i < 1000) {
        i++;
    }

    return i;
}

void LCD_Cursor(char h, char v) {
    int i;

    if (v == 1) {
        for (i = 0; i < h; i++) {
            __delay_us(40);
            LCD_Comando(0x14);
        }
    }

    if (v == 2) {
        h = -c + h + 64 ;
        for (i = 0; i < h; i++) {
            __delay_us(40);
            LCD_Comando(0x14);
        }
    }
}

void LCD_Display(int T, int H) {
    int aux1, i;
    __delay_ms(2);
    LCD_Comando(0x02);

    __delay_ms(2000);
    if (T > 16 && T < 40) {
        aux1 = T - 16;
        for (i = -1; i < aux1; i++) {
            __delay_ms(500);
            LCD_Comando(0x1B);
        }
    }

}
