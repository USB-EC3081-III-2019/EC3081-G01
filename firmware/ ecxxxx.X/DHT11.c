#include "DHT11.h"
#include "LCD.h"

// DHT11 sensor connection (here data pin is connected to RB0)

#define DHT11_PIN      PORTAbits.RA2
#define DHT11_PIN_DIR  TRISAbits.TRISA2

#define _XTAL_FREQ 4000000

char Temperature[] = "Temp = 00.0 C  "; // DHT11 Variables
char Humidity[] = "RH   = 00.0 %  ";
char CheckSum1[] = "CS   = 00.0 %  ";
unsigned char T_Byte1, T_Byte2, RH_Byte1, RH_Byte2, CheckSum;
extern unsigned int tecla, z ,x ,j;

// send start signal to the sensor

void Start_Signal(void) {
    DHT11_PIN_DIR = 0; // configure DHT11_PIN as output
    DHT11_PIN = 0; // clear DHT11_PIN output (logic 0)

    __delay_ms(25); // wait 25 ms
    DHT11_PIN = 1; // set DHT11_PIN output (logic 1)

    __delay_us(40); // wait 30 us
    DHT11_PIN_DIR = 1; // configure DHT11_PIN as input
}

// Check sensor response

__bit Check_Response() {
    TMR1H = 0; // reset Timer1
    TMR1L = 0;
    TMR1ON = 1; // enable Timer1 module

    while (!DHT11_PIN && TMR1L < 100); // wait until DHT11_PIN becomes high (checking of 80µs low time response)

    if (TMR1L > 99) // if response time > 99µS  ==> Response error
        return 0; // return 0 (Device has a problem with response)

    else {
        TMR1H = 0; // reset Timer1
        TMR1L = 0;

        while (DHT11_PIN && TMR1L < 100); // wait until DHT11_PIN becomes low (checking of 80µs high time response)

        if (TMR1L > 99) // if response time > 99µS  ==> Response error
            return 0; // return 0 (Device has a problem with response)

        else
            return 1; // return 1 (response OK)
    }
}

// Data read function

__bit Read_Data(unsigned char* dht_data) {
    *dht_data = 0;

    for (char i = 0; i < 8; i++) {
        TMR1H = 0; // reset Timer1
        TMR1L = 0;

        while (!DHT11_PIN) // wait until DHT11_PIN becomes high
            if (TMR1L > 100) { // if low time > 100  ==>  Time out error (Normally it takes 50µs)
                return 1;
            }

        TMR1H = 0; // reset Timer1
        TMR1L = 0;

        while (DHT11_PIN) // wait until DHT11_PIN becomes low
            if (TMR1L > 100) { // if high time > 100  ==>  Time out error (Normally it takes 26-28µs for 0 and 70µs for 1)
                return 1; // return 1 (timeout error)
            }

        if (TMR1L > 50) // if high time > 50  ==>  Sensor sent 1
            *dht_data |= (1 << (7 - i)); // set bit (7 - i)
    }


    return 0; // return 0 (data read OK)
}

void DHT11() {
    
    
    T1CON = 0x00; // set Timer1 clock source to internal with 1:1 prescaler (Timer1 clock = 1MHz)
    TMR1H = 0; // reset Timer1
    TMR1L = 0;

    while (tecla == 0){

        LCD_Comando(0x01); //Clear Display

        Start_Signal(); // send start signal to the sensor
        
        if (Check_Response() && !Read_Data(&RH_Byte1) && !Read_Data(&RH_Byte2) && !Read_Data(&T_Byte1) && !Read_Data(&T_Byte2) && Read_Data(&CheckSum)) {// read (and save) data from the DHT11 sensor and check time out errors
            
            //char var = (RH_Byte1 + RH_Byte2 + T_Byte1 + T_Byte2);
            
            //if (CheckSum == var) { // if there is no checksum error
                Temperature[7] = T_Byte1 / 10 + '0';
                Temperature[8] = T_Byte1 % 10 + '0';
                Temperature[10] = T_Byte2 / 10 + '0';
                Humidity[7] = RH_Byte1 / 10 + '0';
                Humidity[8] = RH_Byte1 % 10 + '0';
                Humidity[10] = RH_Byte2 / 10 + '0';
                Temperature[11] = 223; // put degree symbol (°)

                LCD_Escribir_C1(0, 1, Temperature);
                LCD_Escribir_C2(0, 0, Temperature, Humidity);
                ;
            //}else {
              //  LCD_Comando(0x01); // clear LCD
                //LCD_Escribir_Cadena("Time Out!"); // display "Time out!"
            //}
        } else {
            LCD_Comando(0x01); // clear LCD
            LCD_Escribir_Cadena("No Responde S");
        }
        TMR1ON = 0; // disable Timer1 module
        for (z = 0; z < 100; z++) {
            if (tecla == 0) {
                __delay_ms(10);
            }
        }
    }
}
