
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
