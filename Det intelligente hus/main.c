/*
 * Det intelligente hus.c
 *
 * Created: 04-12-2020 08:25:15
 * Author : Niels
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Keypad/Keypad.h"
#include "LED/LED.h"
#include <util/delay.h>


void ReceiveChar(char a)
{
	int returncode;
	returncode = PasswordChecker(a); // Checks char and returns a code dependant on the character
	SetLED(returncode); // Sets LED according to the return code
}


void Init()
{
	KeyPadInit();
	LEDInit();
}

int main(void)
{
    Init();
	
    while(1)
    {
		OCR1C = red;		// Red
		OCR1B = green;			// Green
		OCR1A = blue;		// Blue
		//Key
	    ColumnScan();
	    DisplayKey(ReadRows());
    }
}

