#include "../cs50.h"

bool prime(int number);

int main(void)
{
	int min;
	do
	{
		min = get_int("Minimum: ");
	}
	while (min < 1);

	int max;
	do
	{
		max = get_int("Maximum: ");
	}
	while (min >= max);

	for (int i = min; i <= max; i++)
	{
		if (prime(i))
		{
			printf("%d\n", i);
		}
	}
}

bool prime(int number)
{
	if (number < 2)
		return false;
	if (number < 4)
		return true;
	if (number % 2 == 0 || number % 3 == 0)
		return false;

	for (int i = 5; i * i < number; i += 6)
	{
		if (number % i == 0 || number % (i + 2) == 0)
			return false;
	}
	return true;
}
