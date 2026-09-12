#include <stdio.h>

int main(void)
{
	int owed = -1;
	int coins = 0;

	while (owed < 0)
	{
		printf("Change owed: ");
		scanf("%d", &owed);
	}
	while (owed >= 25)
	{
		owed -= 25;
		coins++;
	}
	while (owed >= 10)
	{
		owed -= 10;
		coins++;
	}
	while (owed >= 5)
	{
		owed -= 5;
		coins++;
	}
	coins += owed;
	printf("%d\n", coins);
}
