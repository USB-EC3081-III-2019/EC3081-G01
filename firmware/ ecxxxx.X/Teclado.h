void interrupt Teclado (void)
{
    if (RBIF)
    {
        int a=1, b=1, c=1, i=0, k=1;
        
        while(k==1)
        {
            PORTBbits.RB3 = a;
            PORTBbits.RB2 = b;
            PORTBbits.RB1 = c;
            
            if ((PORTBbits.RB7==0)&&(PORTBbits.RB1==0))
            {
                LCD_Comando(0X01);
                //__delay_ms(2);
                //LCD_Escribir('#');
                LCD_Escribir_Cadena("NUMERO:");
                k=0;
            }
            
            if ((PORTBbits.RB7==0)&&(PORTBbits.RB2==0))
            {
                //LCD_Comando(0X01);
                __delay_ms(2);
                LCD_Escribir('0');
                k=0;
            }
            
            if ((PORTBbits.RB7==0)&&(PORTBbits.RB3==0))
            {
                 //LCD_Comando(0X01);
                __delay_ms(2);
                LCD_Escribir('*');
                k=0;
            } 
    
            if ((PORTBbits.RB6==0)&&(PORTBbits.RB1==0))
            {
                //LCD_Comando(0X01);
                __delay_ms(2);
                LCD_Escribir('9');
                k=0;
            }
            
            if ((PORTBbits.RB6==0)&&(PORTBbits.RB2==0))
            {
                //LCD_Comando(0X01);
                __delay_ms(2);
                LCD_Escribir('8');
                k=0;
            }
            
            if ((PORTBbits.RB6==0)&&(PORTBbits.RB3==0))
            {
                //LCD_Comando(0X01);
                __delay_ms(2);
                    LCD_Escribir('7');
                k=0;
            }
           
            if ((PORTBbits.RB5==0)&&(PORTBbits.RB1==0))
            {
                //LCD_Comando(0X01);
                __delay_ms(2);
                LCD_Escribir('6');
                k=0;
            }
            
            if ((PORTBbits.RB5==0)&&(PORTBbits.RB2==0))
            {
                //LCD_Comando(0X01);
                __delay_ms(2);
                LCD_Escribir('5');
                k=0;
            }
            
            if ((PORTBbits.RB5==0)&&(PORTBbits.RB3==0))
            {
                //LCD_Comando(0X01);
                __delay_ms(2);
                LCD_Escribir('4');
                k=0;
            }  
            
            if ((PORTBbits.RB4==0)&&(PORTBbits.RB1==0))
            {
                //LCD_Comando(0X01);
                __delay_ms(2);
                LCD_Escribir('3');
                k=0;
            }
            
            if ((PORTBbits.RB4==0)&&(PORTBbits.RB2==0))
            {
                //LCD_Comando(0X01);
                __delay_ms(2);
                LCD_Escribir('2');
                k=0;
            }
            
            if ((PORTBbits.RB4==0)&&(PORTBbits.RB3==0))
            {
                //LCD_Comando(0X01);
                __delay_ms(2);
                LCD_Escribir('1');
                k=0;
            }
               
        if (i == 0)
        {
            a = 0;
            b = 1;
            c = 1;
        }
        
        if (i == 1)
        {
            a = 1;
            b = 0;
            c = 1;
        }
        
        if (i == 2)
        {
            a = 1;
            b = 1;
            c = 0;
            i = -1;
        }
        i++;
    
//PORTB = 0;    
RBIF=0;
}
}   
}

