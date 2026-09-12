#include <stdio.h>

long	digit_count(long nb);

int main(void)
{
	long sum = 0;
	long card;
	long copy;
	long digit;
	long digit_number;
	char card_type;

	printf("Card number: ");
	scanf("%ld", &card);

	digit_number = digit_count(card);
	if (digit_number != 16 && digit_number != 13 && digit_number != 15)
	{
		printf("INVALID\n");
		return 0;
	}
	copy = card;
	if (digit_number == 15)
	{
		copy /= 10000000000000L;
		if (copy != 34 && copy != 37)
		{
			printf("INVALID\n");
			return 0;
		}
		card_type = 'A';
	}
	else if (digit_number == 13)
	{
		copy /= 1000000000000L;
		if (copy != 4)
		{
			printf("INVALID\n");
			return 0;
		}
		card_type = 'V';
	}
	else
	{
		copy /= 100000000000000L;
		if (51 <= copy && copy <= 55)
		{
			card_type = 'M';
		}
		else
		{
			card_type = 'V';
			copy /= 10;
			if (copy != 4)
			{
				printf("INVALID\n");
				return 0;
			}
		}
	}

	copy = card / 10;
	while (copy > 0)
	{
		digit = (copy % 10) * 2;
		if (digit > 9)
		{
			digit = digit - 10 + 1;
		}
		sum += digit;
		copy /= 100;
	}
	copy = card;
	while (copy > 0)
	{
		sum += copy % 10;
		copy /= 100;
	}
	if (sum % 10 != 0)
	{
		printf("INVALID\n");
		return 0;
	}
	if (card_type == 'V')
		printf("VISA\n");
	else if (card_type == 'M')
		printf("MASTERCARD\n");
	else if (card_type == 'A')
		printf("AMEX\n");
}

long	digit_count(long n)
{
	if (n < 10)
		return (1);
	if (n < 100)
		return (2);
	if (n < 1000)
		return (3);
	if (n < 10000)
		return (4);
	if (n < 100000)
		return (5);
	if (n < 1000000)
		return (6);
	if (n < 10000000)
		return (7);
	if (n < 100000000)
		return (8);
	if (n < 1000000000)
		return (9);
	if (n < 10000000000L)
		return (10);
	if (n < 100000000000L)
		return (11);
	if (n < 1000000000000L)
		return (12);
	if (n < 10000000000000L)
		return (13);
	if (n < 100000000000000L)
		return (14);
	if (n < 1000000000000000L)
		return (15);
	if (n < 10000000000000000L)
		return (16);
	if (n < 100000000000000000L)
		return (17);
	if (n < 1000000000000000000L)
		return (18);
	return (19);
}

