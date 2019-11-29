/*
 * File:   
 * Author: Orazio Portillo
 *
 * Created on September 27, 2019, 8:59 PM
 */


#include <xc.h>
#include "Config.h"
#include "LCD.h"
#include "Interfaz.h"
#include "Teclado.h"
#include "DHT11.h"
#include "LDR.h"
#include "PWM.h"


#define _XTAL_FREQ 4000000

unsigned int tecla, bloque, c, j, j1, H, V, z;
unsigned int x;
unsigned char temp1, temp2;
unsigned int Temp_Hum, Hum_Suelo, Lluvia, Luz;

unsigned char T_Byte1, T_Byte2, RH_Byte1, RH_Byte2, CheckSum;

int i;

void main() {

    PIC_Configuracion_Inicial();
    LCD_Configuracion_Inicial();

    tecla = 0;
    bloque = 0;

    while (1) {

        LCD_Escribir_C1(3, 1, "BIENVENIDOS");
        LCD_Escribir_C2(3, 0, "BIENVENIDOS", "Sistema de riego");

        LCD_Timer();
        
        //OSCC1 = 0b01110011;
        
       // ADCON1 = 0xff;
        
        x = 1;
        
        //myPWM ( 10 , 500 );
        while (x == 1) {
            
            //myPWM ( 50 , 50 );
            INTERFACE_Principal();
        }      
    }
}
