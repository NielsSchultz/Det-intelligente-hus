/*
 * Password.c
 *
 * Created: 07-12-2020 12:40:47
 *  Author: Niels
 */ 
#include <string.h>
#define PASSWORD_SIZE 4
char password[PASSWORD_SIZE]
char myPassword[PASSWORD_SIZE]



void ValidatePassword(char password[])
{
	strcpy(myPassword, "1234");
	volatile int test = 0;
	if (strncmp(password, myPassword, PASSWORD_SIZE) == 0)
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