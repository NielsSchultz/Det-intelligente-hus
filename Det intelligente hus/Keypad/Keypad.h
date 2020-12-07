/*
 * Keypad.h
 *
 * Created: 04-12-2020 09:43:01
 *  Author: Niels
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

void KeyPadInit();
void ColumnScan();
char DecodeKey(char data);
char ReadRows();
void DisplayKey(char data);

#endif /* KEYPAD_H_ */