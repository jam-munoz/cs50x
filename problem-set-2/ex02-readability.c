#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char str[BUFSIZ];
	int i;
	double letters = 0.0, words = 0.0, sentences = 0.0;
	double index;
	// Prompt the user for some text
	printf("Text: ");
	fgets(str, sizeof(str), stdin);
	// Count the number of letters, words, and sentences in the text
	for (i = 0; str[i] != '\n' && str[i] != '\0'; i++)
	{
		if (isalnum((unsigned char)str[i]))
			letters++;
		if ((str[i] == '.' || str[i] == '!' || str[i] == '?') && (isspace((unsigned char)str[i + 1]) || str[i + 1] == '\0'))
			sentences++;
	}
	for (i = 0; str[i] != '\n' && str[i] != '\0';)
	{
		if (!isspace((unsigned char)str[i]))
		{
			words++;
			while(!isspace((unsigned char)str[i]) && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	words /= 100;
	// Compute the Coleman-Liau index
	index = 0.0588 * (letters / words) - 0.296 * (sentences / words) - 15.8;
	// Print the grade level
	if (index >= 16.0)
		printf("Grade 16+\n");
	else if (index < 1.0)
		printf("Before Grade 1\n");
	else
		printf("Grade %0.lf\n", index);
}
