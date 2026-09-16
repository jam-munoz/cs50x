// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include "../cs50.h"
#include <ctype.h>

bool valid(char *password);

int main(void)
{
	char password[256];
	get_string(password, sizeof(password), "Enter your password: ");

	if (valid(password))
	{
		printf("Your password is valid!\n");
	}
	else
	{
		printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
	}
}

// Complete the Boolean function below
bool valid(char *password)
{
	typedef struct
	{
		bool upper;
		bool lower;
		bool digit;
		bool symbol;
	}	check;

	check p = { 0 };

	for(; *password != '\0'; password++)
	{
		if (!isprint((unsigned char)*password))
			return false;
		else if (isupper((unsigned char)*password))
			p.upper = true;
		else if (islower((unsigned char)*password))
			p.lower = true;
		else if (isdigit((unsigned char)*password))
			p.digit = true
		else
			p.symbol = true;

		if (p.upper == true && p.lower == true && p.digit == true && p.symbol == true)
			return true;
	}
	return false;
}
