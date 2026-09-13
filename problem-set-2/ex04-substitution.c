#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void error_msg(void);

int main(int argc, char *argv[])
{
	if (argc != 2)
		error_msg();
	bool repeat[128] = { 0 };
	char *key;
	int i;

	for (key = argv[1]; *key != '\0'; key++)
	{
		*key = tolower((unsigned char)*key);
		if (!islower((unsigned char)*key) || repeat[((unsigned char)*key)] == true)
			error_msg();
		repeat[((unsigned char)*key)] = true;
	}
	if (key - argv[1] != 26)
		error_msg();

	char str[BUFSIZ];
	printf("plaintext: ");
	fgets(str, sizeof(str), stdin);
	for (key = argv[1], i = 0; str[i] != '\0'; i++)
	{
		if (islower((unsigned char)str[i]))
		{
			str[i] = key[str[i] - 'a'];
		}
		else if (isupper((unsigned char)str[i]))
		{
			str[i] = toupper(key[str[i] - 'A']);
		}
	}
	printf("ciphertext: %s", str);
}
void error_msg(void)
{
	printf("Error.\nUsage: ./substitution key\n");
	exit(EXIT_FAILURE);
}
