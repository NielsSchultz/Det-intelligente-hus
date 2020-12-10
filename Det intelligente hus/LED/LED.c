/*
 * LED.c
 *
 * Created: 08-12-2020 13:23:42
 *  Author: Niels
 */ 
#include <avr/io.h>
int red = 120;
int green = 80;
int blue = 0;
void SetLED(int code)
{
	
	if (code == 1)
	{
		//Unlocked, set LED to green
		red = 0;
		green = 155;
		blue = 0;
	}
	else if(code == 2)
	{
		//Locked, set LED to yellow
		red = 120;
		green = 80;
		blue = 0;
		
	}
	else if(code == 3)
	{
		//Alarm, set LED to red
		red = 155;
		green = 0;
		blue = 0;
		
	}
	
}

void LEDInit()
{
	// Compare Output Mode: Fast PWM Mode: Clear OC0A on Compare Match, set OC0A at BOTTOM, non-inverting mode (Table 16-3)
	TCCR1A |= (1<<COM1A1) | (1<<COM1B1)| (1<<COM1C1);
	
	//Waveform Generation Mode: Mode 5 Fast PWM 8 bit: WGM0 = 1, WGM1 = 1 (Table 16-8)
	TCCR1A |= (1<<WGM10) | (1<<WGM12);
	
	// Clock Select Bit: clk/64 prescaling: CS = 011 : CS01 = 1, CS00 = 1 (Table 16-9), frekv. = 980Hz
	TCCR1B |= (1<<CS11) | (1<<CS10);		// datasheet 16.9.2
	
	// Set output to OC0A = PB7, see datasheet 16.9.4 and Arduino MEGA pin configuration: (pin 13), same as LED
	DDRB |= (1<<PB7) | (1<<PB6) | (1<<PB5);
	
}