#include <stdio.h>

int main(void)
{
	char str[256];

	printf("Enter your name: ");
    fgets(str, sizeof(str), stdin);
	printf("hello, %s", str);
}
