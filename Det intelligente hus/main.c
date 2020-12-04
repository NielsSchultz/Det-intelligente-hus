/*
 * Det intelligente hus.c
 *
 * Created: 04-12-2020 08:25:15
 * Author : Niels
 */ 

#include <avr/io.h>
#include "Keypad.h"

int main(void)
{
    Init();

    while(1)
    {
	    ColumnScan();
	    DisplayKey(ReadRows());
    }
}

