// Practice working with structs
// Practice applying sorting algorithms

#include <stdio.h>
#include <stdlib.h>

#define NUM_CITIES 10

typedef struct
{
	char *city;
	int temp;
}	avg_temp;

avg_temp temps[NUM_CITIES];

int comp(const void *a, const void *b);
void sort_cities(void);

int main(void)
{
	temps[0].city = "Austin";
	temps[0].temp = 97;

	temps[1].city = "Boston";
	temps[1].temp = 82;

	temps[2].city = "Chicago";
	temps[2].temp = 85;

	temps[3].city = "Denver";
	temps[3].temp = 90;

	temps[4].city = "Las Vegas";
	temps[4].temp = 105;

	temps[5].city = "Los Angeles";
	temps[5].temp = 82;

	temps[6].city = "Miami";
	temps[6].temp = 97;

	temps[7].city = "New York";
	temps[7].temp = 85;

	temps[8].city = "Phoenix";
	temps[8].temp = 107;

	temps[9].city = "San Francisco";
	temps[9].temp = 66;

	sort_cities();

	printf("\nAverage July Temperatures by City\n\n");

	for (int i = 0; i < NUM_CITIES; i++)
	{
		printf("%s: %d\n", temps[i].city, temps[i].temp);
	}
}

// Sort cities by temperature in descending order
void sort_cities(void)
{
	qsort(temps, NUM_CITIES, sizeof(avg_temp), comp);
}

int comp(const void *a, const void *b)
{
	const avg_temp *x = a;
	const avg_temp *y = b;

	return y->temp - x->temp;
}
