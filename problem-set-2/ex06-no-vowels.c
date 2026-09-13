// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <stdio.h>
#include <stdlib.h>

int vowels(int c);

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error.\nUsage: ./no-vowels word\n");
		exit(EXIT_FAILURE);
	}
	for (; *argv[1] != '\0'; argv[1]++)
	{
		putchar((unsigned char)vowels(*argv[1]));
	}
	putchar('\n');
}

int vowels(int c)
{
	if (c == 'a' || c == 'A')
		return '4';
	if (c == 'e' || c == 'E')
		return '3';
	if (c == 'i' || c == 'I')
		return '1';
	if (c == 'o' || c == 'O')
		return '0';
	return c;
}
