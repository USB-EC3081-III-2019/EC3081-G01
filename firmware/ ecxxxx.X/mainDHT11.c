/*
 * File:   
 * Author: Orazio Portillo
 *
 * Created on September 27, 2019, 8:59 PM
 */


// DHT11 sensor connection (here data pin is connected to RB0)
#define DHT11_PIN      PORTBbits.RB0
#define DHT11_PIN_DIR  TRISBbits.TRISB0

#include <xc.h>
#include "Config.h"
#include "LCD.h" 
#include "Teclado.h"
#include "DHT11_1.h"

#define _XTAL_FREQ 4000000

unsigned int tecla;

// variables declaration
char Temperature[] = "Temp = 00.0 C  ";
char Humidity[] = "RH   = 00.0 %  ";
char CheckSum1[] = "CS   = 00.0 %  ";
unsigned char T_Byte1, T_Byte2, RH_Byte1, RH_Byte2, CheckSum;

void main() {
    PIC_Configuracion_Inicial();
    LCD_Configuracion_Inicial();

    //OSCCONbits.IRCF = 0b110;        // set internal oscillator to 8MHz
    TRISB = 0; // configure all PORTB pins as digital
    T1CON = 0x00; // set Timer1 clock source to internal with 1:1 prescaler (Timer1 clock = 1MHz)
    TMR1H = 0; // reset Timer1
    TMR1L = 0;

    while(1){  
       
        Start_Signal(); // send start signal to the sensor
        if (Check_Response()) // check if there is a response from sensor (If OK start reading humidity and temperature data)
        {
            // read (and save) data from the DHT11 sensor and check time out errors
            if (!Read_Data(&RH_Byte1)) {
                if (!Read_Data(&RH_Byte2)) {
                    if (!Read_Data(&T_Byte1)) {
                        if (!Read_Data(&T_Byte2)) {
                            if (!Read_Data(&CheckSum)) {
                                
                                char var =(RH_Byte1 + RH_Byte2 + T_Byte1 + T_Byte2);                                
                                
                                if (CheckSum == var) { // if there is no checksum error
                                    Temperature[7] = T_Byte1 / 10 + '0';
                                    Temperature[8] = T_Byte1 % 10 + '0';
                                    Temperature[10] = T_Byte2 / 10 + '0';
                                    Humidity[7] = RH_Byte1 / 10 + '0';
                                    Humidity[8] = RH_Byte1 % 10 + '0';
                                    Humidity[10] = RH_Byte2 / 10 + '0';
                                    Temperature[11] = 223; // put degree symbol (°)
                                    
                                    LCD_Cursor(0,1);
                                    LCD_Escribir_Cadena(Temperature);
                                    LCD_Cursor(-12,2);
                                    LCD_Escribir_Cadena(Humidity);
                                }
                                    // if there is a checksum error
                                else {
                                    LCD_Comando(0x01); // clear LCD
                                    
                                    
                                    char var =(RH_Byte1 + RH_Byte2 + T_Byte1 + T_Byte2);
                                    
                                    Temperature[0] = T_Byte1 / 10 + '0';
                                    Temperature[1] = T_Byte1 % 10 + '0';
                                    Temperature[2] = T_Byte2 / 10 + '0';
                                    Temperature[3] = ' ';
                                    Temperature[4] = RH_Byte1 / 10 + '0';
                                    Temperature[5] = RH_Byte1 % 10 + '0';
                                    Temperature[6] = RH_Byte2 / 10 + '0';
                                    Humidity[0] = CheckSum / 100 + '0' ;
                                    Humidity[1] = (CheckSum / 10) % 10 + '0' ;
                                    Humidity[2] = (CheckSum % 10) % 10 + '0' ;
                                    Humidity[4] = var / 100 + '0';
                                    Humidity[5] = (var / 10) % 10 + '0';
                                    Humidity[6] = (var % 10) % 10 + '0';
                                    
                                    
                                    CheckSum1 [9]= CheckSum / 100 + '0' ;
                                    CheckSum1[10]= (CheckSum / 10) % 10 + '0' ;
                                    CheckSum1[11]= (CheckSum % 10) % 10 + '0' ;
                                    
                                    /*Temperature[7] = var / 100 + '0';
                                    Temperature[8] = (var / 10) % 10 + '0';
                                    Temperature[9] = (var % 10) % 10 + '0';*/
                                    
                                    /*LCD_Escribir_Cadena(CheckSum1);*/
                                    
                                    //LCD_Cursor(-12,2);
                                    LCD_Escribir_Cadena(Temperature);
                                    LCD_Cursor(-12,2);
                                    LCD_Escribir_Cadena(Humidity);
                                            
                                            
                                    
                                    //Temperature[7]= T_Byte1 ;
                                                                      
                                    /*Temperature[7] = T_Byte1 / 10 + '0';
                                    Temperature[8] = T_Byte1 % 10 + '0';
                                    Temperature[10] = T_Byte2 / 10 + '0';
                                    Humidity[7] = RH_Byte1 / 10 + '0';
                                    Humidity[8] = RH_Byte1 % 10 + '0';
                                    Humidity[10] = RH_Byte2 / 10 + '0';
                                    Temperature[11] = 223; // put degree symbol (°)
                                    
                                    
                                    LCD_Cursor(0,1);
                                    LCD_Escribir_Cadena(Temperature);
                                    LCD_Cursor(-12,2);
                                    LCD_Escribir_Cadena(Humidity);*/
                                    

                                }
                                
                            } else {
                                LCD_Comando(0x01); // clear LCD
                                LCD_Escribir_Cadena("Time Out 05!"); // display "Time out!"
                            }

                        } else {
                            LCD_Comando(0x01); // clear LCD
                            LCD_Escribir_Cadena("Time Out 04!"); // display "Time out!"
                        }

                    } else {
                        LCD_Comando(0x01); // clear LCD
                        LCD_Escribir_Cadena("Time Out 03!"); // display "Time out!"
                    }

                } else {
                    LCD_Comando(0x01); // clear LCD
                    LCD_Escribir_Cadena("Time Out 02!"); // display "Time out!"
                }
            } else {
                LCD_Comando(0x01); // clear LCD
                LCD_Escribir_Cadena("Time Out 01!"); // display "Time out!"
            }

            /*  
            if(Read_Data(&RH_Byte1) || Read_Data(&RH_Byte2) || Read_Data(&T_Byte1) || Read_Data(&T_Byte2) || Read_Data(&CheckSum))
            {
              LCD_Comando(0x01);    // clear LCD
              LCD_Escribir_Cadena("Time Out!");   // display "Time out!"
            }
 
            else         // if there is no time out error
            {
              if(CheckSum == ((RH_Byte1 + RH_Byte2 + T_Byte1 + T_Byte2) & 0xFF))
              {                                       // if there is no checksum error
                Temperature[7]  = T_Byte1 / 10  + '0';
                Temperature[8]  = T_Byte1 % 10  + '0';
                Temperature[10] = T_Byte2 / 10  + '0';
                Humidity[7]     = RH_Byte1 / 10 + '0';
                Humidity[8]     = RH_Byte1 % 10 + '0';
                Humidity[10]    = RH_Byte2 / 10 + '0';
                Temperature[11] = 223;    // put degree symbol (°)
          

                LCD_Escribir_Cadena(Temperature);

                LCD_Escribir_Cadena(Humidity);
              }
 
              // if there is a checksum error
              else
              {
                  LCD_Comando(0x01);    // clear LCD
                  LCD_Escribir_Cadena("Check Sum");
              }
 
            }*/
        }
            // if there is a response (from the sensor) problem
        else {
            LCD_Comando(0x01); // clear LCD
            LCD_Escribir_Cadena("No Responde S");
        }

        TMR1ON = 0; // disable Timer1 module
        __delay_ms(2000); // wait 1 second
    }

}





