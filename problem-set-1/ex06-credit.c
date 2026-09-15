#include <stdio.h>
#include <stdlib.h>

int		digit_count(long nb);
char	check_card(long card, int digit_number);
bool	luhn_valid(long card);

int main(void)
{
	long card;
	char card_type;

	printf("Card number: ");
	scanf("%ld", &card);

	card_type = check_card(card, digit_count(card));

	if (luhn_valid(card) == false)
	{
		printf("INVALID\n");
		exit(EXIT_FAILURE);
	}
	if (card_type == 'V')
		printf("VISA\n");
	else if (card_type == 'M')
		printf("MASTERCARD\n");
	else if (card_type == 'A')
		printf("AMEX\n");
}

char check_card(long card, int digit_number)
{
	if (digit_number == 15)
	{
		card /= 10000000000000L;
		if (card != 34 && card != 37)
		{
			printf("INVALID\n");
			exit(EXIT_FAILURE);
		}
		return 'A';
	}
	else if (digit_number == 13)
	{
		card /= 1000000000000L;
		if (card != 4)
		{
			printf("INVALID\n");
			exit(EXIT_FAILURE);
		}
		return 'V';
	}
	else if (digit_number == 16)
	{
		card /= 100000000000000L;
		if (51 <= card && card <= 55)
		{
			return 'M';
		}
		else
		{
			card /= 10;
			if (card != 4)
			{
				printf("INVALID\n");
				exit(EXIT_FAILURE);
			}
			return 'V';
		}
	}
	printf("INVALID\n");
	exit(EXIT_FAILURE);
}

bool luhn_valid(long card)
{
	long copy, digit;
	long sum = 0;

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
	if (sum % 10 == 0)
		return true;
	else
		return false;
}

int	digit_count(long n)
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

