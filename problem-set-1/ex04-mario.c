#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int height;
	int i, j;

	printf("Enter height: ");
	scanf("%d", &height);
	if (height < 0 || height > 1024)
	{
		printf("Error. Invalid height.\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < height; i++)
	{
		for (j = i; j < height - 1; j++)
			putchar(' ');
		for (j = 0; j < i + 1; j++)
			putchar('#');
		printf("  ");
		for (j = 0; j < i + 1; j++)
			putchar('#');
		putchar('\n');
	}
}
