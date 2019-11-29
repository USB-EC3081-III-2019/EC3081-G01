#include <xc.h>
#include "LCD.h" 

#define _XTAL_FREQ 4000000

extern unsigned int tecla, bloque, j;

void interrupt Teclado (void);
