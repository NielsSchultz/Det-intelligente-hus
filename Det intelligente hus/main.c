/*
 * Det intelligente hus.c
 *
 * Created: 04-12-2020 08:25:15
 * Author : Niels
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Keypad/Keypad.h"
int returncode = 0;

void ReceiveChar(char a)
{
	returncode = PasswordChecker(a);
	//SetLED(returncode);
}


void Init()
{
	KeyPadInit();
}

int main(void)
{
    Init();
	
    while(1)
    {
	    ColumnScan();
	    DisplayKey(ReadRows());
    }
}

