#include "../cs50.h"
#include <ctype.h>
#include <math.h>

int convert(char *input);

int main(void)
{
	char input[12];
	get_string(input, sizeof(input), "Enter a positive integer: ");
	int len = strlen(input);

	/*for (int i = 0, n = len; i < n; i++)
	{
		if (!isdigit(input[i]))
		{
			printf("Invalid Input!\n");
			return 1;
		}
	}*/

	// Convert string to int
	printf("%d\n", convert(input));
}

int convert(char *input)
{
	static int sum = 0;
	static int sign = 1;
	static int position = 1;

	while (isspace(*input))
		input++;
	if (*input == '+' || *input == '-')
	{
		if (*input == '-')
			sign = -1;
		input++;
	}
	if (*input == '\0')
		return 0;
	if (isdigit(*input))
	{
		convert(input + 1);
	}
	sum += ((unsigned char)*input - '0') * position;
	position *= 10;

	return sum * sign;
}
