void interrupt high_priority Teclado (void)
{
if (RBIF)
{
    if (PORTBbits.RB7 == 0)
    {
        if ((PORTBbits.RB7==0)&&(PORTBbits.RB1==0))
        {
            LCD_Comando(0X01);
            __delay_ms(2);
            LCD_Escribir('#');
        }
        if ((PORTBbits.RB7==0)&&(PORTBbits.RB2==0))
        {
            LCD_Comando(0X01);
            __delay_ms(2);
            LCD_Escribir('0');
        }
        if ((PORTBbits.RB7==0)&&(PORTBbits.RB3==0))
        {
            LCD_Comando(0X01);
            __delay_ms(2);
            LCD_Escribir('*');
        }
    }
    
    if (PORTBbits.RB6 == 0)
    {
        if ((PORTBbits.RB6==0)&&(PORTBbits.RB1==0))
        {
            LCD_Comando(0X01);
            __delay_ms(2);
            LCD_Escribir('9');
        }
        if ((PORTBbits.RB6==0)&&(PORTBbits.RB2==0))
        {
            LCD_Comando(0X01);
            __delay_ms(2);
            LCD_Escribir('8');
        }
        if ((PORTBbits.RB6==0)&&(PORTBbits.RB3==0))
        {
            LCD_Comando(0X01);
            __delay_ms(2);
            LCD_Escribir('7');
        }
    }
    
    if (PORTBbits.RB5 == 0)
    {
        if ((PORTBbits.RB5==0)&&(PORTBbits.RB1==0))
        {
            LCD_Comando(0X01);
            __delay_ms(2);
            LCD_Escribir('6');
        }
        if ((PORTBbits.RB5==0)&&(PORTBbits.RB2==0))
        {
            LCD_Comando(0X01);
            __delay_ms(2);
            LCD_Escribir('5');
        }
        if ((PORTBbits.RB5==0)&&(PORTBbits.RB3==0))
        {
            LCD_Comando(0X01);
            __delay_ms(2);
            LCD_Escribir('4');
        }
    }
    
    if (PORTBbits.RB4 == 0)
    {
        if ((PORTBbits.RB4==0)&&(PORTBbits.RB1==0))
        {
            LCD_Comando(0X01);
            __delay_ms(2);
            LCD_Escribir('3');
        }
        if ((PORTBbits.RB4==0)&&(PORTBbits.RB2==0))
        {
            LCD_Comando(0X01);
            __delay_ms(2);
            LCD_Escribir('2');
        }
        if ((PORTBbits.RB4==0)&&(PORTBbits.RB3==0))
        {
            LCD_Comando(0X01);
            __delay_ms(2);
            LCD_Escribir('1');
        }
    }
}
    RBIF=0;
    
}
