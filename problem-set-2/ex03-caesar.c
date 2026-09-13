#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error.\nUsage: ./caesar key\n");
		exit(EXIT_FAILURE);
	}
	errno = 0;
	int key = strtol(argv[1], &argv[1], 10) % 26;
	if (errno != 0 || *argv[1] != '\0')
	{
		printf("Error.\nUsage: ./caesar key\n");
		exit(EXIT_FAILURE);
	}
	char str[BUFSIZ];
	printf("plaintext: ");
	fgets(str, sizeof(str), stdin);

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (islower((unsigned char)str[i]))
		{
			str[i] += key;
			if (str[i] < 'a')
				str[i] += 26;
			else if (str[i] > 'z')
				str[i] -= 26;
		}
		else if (isupper((unsigned char)str[i]))
		{
			str[i] += key;
			if (str[i] < 'A')
				str[i] += 26;
			else if (str[i] > 'Z')
				str[i] -= 26;
		}
	}
	printf("ciphertext: %s", str);
}
