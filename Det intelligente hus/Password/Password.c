/*
 * Password.c
 *
 * Created: 07-12-2020 12:40:47
 *  Author: Niels
 */ 
#include <string.h>
#include <stdbool.h>
#define PASSWORD_SIZE 4
char password[PASSWORD_SIZE];
int index = 0;
char myPassword[] = "1234";
int invalidEntry = 0;
int isValid = false;

bool ValidatePassword(char password[])
{
	if (strncmp(password, myPassword, PASSWORD_SIZE) == 0)
	{
		invalidEntry = 0;
		return true;
	}
	else
	{
		invalidEntry++;
		return false;
	}
	index = 0;
}

int PasswordChecker(char a)
{
	if(a != '#' && a != '*')
	{
		Appender(a);
	}
	else if(a == '*')
	{
		memset(password, 0, sizeof(password));
	}
	else if(a == '#')
	{
		if (invalidEntry >= 3)
		{
			return isValid;
		}
		else
		{
			isValid = ValidatePassword(password);
			memset(password, 0, sizeof(password));
			if (isValid)
			{
				invalidEntry = 0;
				return isValid;
			}
		}
	}
}

void Appender(char a)
{
	password[index] = a;
	index++;
}
