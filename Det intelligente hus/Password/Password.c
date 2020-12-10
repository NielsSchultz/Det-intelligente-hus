/*
 * Password.c
 *
 * Created: 07-12-2020 12:40:47
 *  Author: Niels
 */ 
#define PASSWORD_SIZE 4
#define UNLOCKED 1
#define LOCKED 2
#define ALARM 3
#define PASSWORD "1234"
char password[PASSWORD_SIZE];
char myPassword[] = PASSWORD;
int index = 0; //int used to indicate the index of the password array, gets reset after each attempt
int invalidEntry = 0; // Starts at 0 goes up by 1 for every invalid entry


int ValidatePassword(char password[])
{
	index = 0;
	if (strncmp(password, myPassword, PASSWORD_SIZE) == 0) // Compares the actual password with the input password array
	{
		invalidEntry = 0;
		return 1;
	}
	else
	{
		invalidEntry++;
		return 0;
	}
}

int PasswordChecker(char a)
{
	if(a != '#' && a != '*') //Appends if not a function key(# or *)
	{
		Appender(a); // Appends char 'a' to the password array
	}
	else if(a == '*') // * Function resets your password array
	{
		memset(password, 0, sizeof(password)); // Function to set all bits to 0
		index = 0;
	}
	else if(a == '#') // # Function submits your current password array, use else if so it's easier to add another function key later
	{
		if (invalidEntry >= 3) // Trigger alarm after x amount of invalid entries
		{
			return ALARM;
		}
		else
		{
			int isValid = ValidatePassword(password); // Sends password for validation
			memset(password, 0, sizeof(password));
			index = 0;
			if (isValid == 1)
			{
				return UNLOCKED;
			}
			else
			{
				return LOCKED;
			}
		}
	}
}

void Appender(char a)
{
	password[index] = a;
	index++;
}

