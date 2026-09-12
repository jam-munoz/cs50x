// Become familiar wih C syntax
// Learn to debug buggy code

#include "../cs50.h"

void get_string(char *dest, int size, char *msg);

int main(void)
{
	// Ask for your name and where live
	char name[256];
	char location[256];
	int len;

	get_string(name, sizeof(name), "What is your name? ");
	get_string(location, sizeof(location), "Where do you live? ");
	// Say hello
	printf("Hello, %s, from %s!\n", name, location);
}
