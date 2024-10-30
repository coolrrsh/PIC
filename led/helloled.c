#include "pic14/pic16f690.h"
#include "stdio.h"
#pragma preproc_asm-
typedef unsigned int config;
config __at 0x2007 __CONFIG =
 _INTRC_OSC_NOCLKOUT &
 _WDT_OFF &
 _PWRTE_OFF &
 _MCLRE_OFF &
 _CP_OFF &
 _BOR_OFF &
 _IESO_OFF &
 _FCMEN_OFF;

// ------------------------------------------------
// a simple delay function

void delay_ms(long ms)
{
    long i;

    while (ms--)
        for (i=0; i < 330; i++)
            ;
}
void main()
{
    short display;
    TRISC = 0x0;
    display = 0xf; // Turn all 4 lights on
    PORTC = display;
}
