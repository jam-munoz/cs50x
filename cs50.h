#ifndef CS50_H
#define CS50_H

#include <stdio.h>
#include <string.h>

void get_string(char *dest, int size, char *msg)
{
	int len;

	printf("%s", msg);
	fgets(dest, size, stdin);
	len = strlen(dest);
	if (len > 0 && dest[len - 1] == '\n')
		dest[len - 1] = '\0';
}

float get_float(char *str)
{
	float input;

	printf("%s", str);
	scanf("%f", &input);

	return input;
}

int get_int(char *str)
{
	int input;

	printf("%s", str);
	scanf("%d", &input);

	return input;
}

char get_char(char *str)
{
	int c;
	//clean stdout
	while ((c = getchar()) != '\n' && c != EOF)
		;
	printf("%s", str);

	return (char)getchar();
}

#endif
