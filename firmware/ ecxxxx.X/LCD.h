
// PIC16F877 Configuration Bit Settings

// 'C' source line config statements

// CONFIG

#define LCD_RS PORTCbits.RC1
#define LCD_E PORTCbits.RC0 
#define LCD_DATO PORTD

#define _XTAL_FREQ 4000000

void LCD_Comando(char dato);
void LCD_Escribir(char dato);
void LCD_Configuracion_Inicial();
void PIC_Configuracion_Inicial();
void LCD_Escribir_Cadena(char str[]);
void LCD_Cursor (int Horizontal , int Vertical);
void LCD_Display (int T, int H);
int LCD_Contador(char c[]);

void LCD_Comando ( char dato )
{
    LCD_RS = 0;
    LCD_DATO = dato;
    LCD_E = 1;
    LCD_E = 0;
    
    if(dato <= 3)
    {
        __delay_ms(2);
    }
    else
    {
        __delay_us(40);
    }
    
}

void LCD_Escribir_Cadena(char str[])
{
    int i=0;
    while (str[i]!= '\0'&& i<1000)
    {
        LCD_Escribir(str[i]);
        i++;
    }
    
}

int LCD_Contador(char c[])
{
    int i=0;
    while (c[i]!= '\0'&& i<1000)
    {
        i++;
    }
    
    return i;
}

void LCD_Escribir ( char dato )
{
    LCD_RS = 1;
    LCD_DATO = dato;
    LCD_E = 1;
    LCD_E = 0;
    __delay_us(40);

    
}

void LCD_Configuracion_Inicial ()
{
    LCD_E = 0;
    __delay_ms(15);
    LCD_Comando(0x38);
    __delay_ms(5);
    LCD_Comando(0x38);
    __delay_ms(1);
    LCD_Comando(0x38);  //Function Set
    LCD_Comando(0x38);  //1. Manda o recibe info en 8 o en 4Bits  
    
    LCD_Comando(0x01);  //Clear Display
    LCD_Comando(0x06);  //Entry mode set
                        //1.Hace que el cursor se mueva hacia la derecha cuando escribe algo
                        //2.Si se mueve o no se mueve la pantalla
    LCD_Comando(0x0C);  //Display ON/OFF Cntrl
    LCD_Comando(0x0C);  //1.Enciende lapantalla 2. apaga el cursor 3. no hace que titilee el cursor

}

void PIC_Configuracion_Inicial ()
{
    
    TRISD = 0;
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 0;
    TRISA = 0;
    ADCON0 = 0b00000000;
    INTCON = 0;
    
    TRISB = 0B11110000;
        
    INTCON = 0;
    INTCONbits.RBIE = 1;
    INTCONbits.GIE = 1;
    
    OPTION_REGbits.nRBPU = 0;
    
    
}; 

void LCD_Cursor (int h , int v)
{
    int i;
    
    if (v==1)
    {
        for(i=0 ; i<h ; i++)
        {
            __delay_us(40);
            LCD_Comando(0x14);
        }
    }
    
    if (v==2)
    {
        h = h+40;
        for (i = 0; i<h ; i++)
        {
            __delay_us(40);
            LCD_Comando(0x14);
        }
    }
}

void LCD_Display (int T, int H)
{
    int aux1, i;
    __delay_ms(2);
    LCD_Comando(0x02);
    
    __delay_ms(2000);
    if(T>16 && T<40)
    {
        aux1 = T-16;
        for(i=-1;i<aux1;i++)
        {
            __delay_ms(500);
            LCD_Comando(0x1B);
        }
    }

}

void interrupt high_priority Interrupcion_Teclado (void)
{

if (RBIF)
{
    if (PORTBbits.RB7 == 0)
    {
        LCD_Comando(0X01);
        __delay_ms(2);
       // LCD_Escribir_Cadena("* 0 #");
        
        if (PORTBbits.RB3 == 0 && PORTBbits.RB2 == 1 && PORTBbits.RB1 == 0)
        {
            LCD_Escribir('0');
        }
        //if (PORTBbits.RB2 == 0)
        //if (PORTBbits.RB1 == 0)
    }
    
    if (PORTBbits.RB6 == 0)
    {
        LCD_Comando(0X01);
        __delay_ms(2);
        LCD_Escribir_Cadena("7 8 9 ");
    }
    
    if (PORTBbits.RB5 == 0)
    {
        LCD_Comando(0X01);
        __delay_ms(2);
        LCD_Escribir_Cadena("4 5 6");
    }
    
        if (PORTBbits.RB4 == 0)
    {
        LCD_Comando(0X01);
        __delay_ms(2);
        LCD_Escribir_Cadena("1 2 3");
    }
}
    RBIF=0;
    
}


