// Practice writing a function to find a max value

#include "../cs50.h"
#include <stdlib.h>

int comp(const void *a, const void *b);
int max(int array[], int n);

int main(void)
{
	int n;
	do
	{
		n = get_int("Number of elements: ");
	}
	while (n < 1);

	int arr[n];

	for (int i = 0; i < n; i++)
	{
		printf("Element %d: ", i);
		arr[i] = get_int("");
	}

	printf("The max value is %d.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
	qsort(array, n, sizeof(int), comp);
	return array[0];
}

int comp(const void *a, const void *b)
{
	const int *x = a;
	const int *y = b;

	return *y - *x;
}
