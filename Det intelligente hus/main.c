/*
 * Det intelligente hus.c
 *
 * Created: 04-12-2020 08:25:15
 * Author : Niels
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Keypad.h"




int main(void)
{
    KeyPadInit();
	
    while(1)
    {
	    ColumnScan();
	    DisplayKey(ReadRows());
    }
}

