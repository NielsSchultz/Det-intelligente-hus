/*
 * Password.c
 *
 * Created: 07-12-2020 12:40:47
 *  Author: Niels
 */ 
#include <string.h>
#define PASSWORD_SIZE 4
char password[PASSWORD_SIZE];

void ValidatePassword(char password[])
{
	volatile int test = 0;
	if (password[0] == '1' && password[1] == '2' && password[2] == '3' && password[3] == '4')
	{
		test = 1;
	}
	else
	{
		test = 2;
	}
	test = test;
}

void PasswordChecker(volatile char a)
{
	if(a != '#')
	{
		strcat(password, a);
	}
	else
	{
		ValidatePassword(password);
		memset(password, 0, sizeof(password));
	}
	int test = 0;
}