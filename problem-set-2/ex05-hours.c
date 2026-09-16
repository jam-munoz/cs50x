#include "../cs50.h"
#include <ctype.h>
#include <stdlib.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
	int weeks = get_int("Number of weeks taking CS50: ");
	int *hours = malloc(weeks * sizeof(int));

	for (int i = 0; i < weeks; i++)
	{
		printf("Week %d HW Hours: ", i);
		scanf("%d", &hours[i]);
	}

	char output;
	do
	{
		output = toupper((unsigned char)get_char("Enter T for total hours, A for average hours per week: "));
	}	while (output != 'T' && output != 'A');

	printf("%.1f hours\n", calc_hours(hours, weeks, output));
	free(hours);
}

// complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
	float sum;

	for (int i = 0; i < weeks; i++)
	{
		sum += (float)hours[i];
	}
	if (output == 'T')
		return sum;
	return sum / (float)weeks;
}
