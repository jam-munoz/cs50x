#include <ctype.h>
#include <stdio.h>

int compute_scrabble_value(const char *word);

int main(void)
{
	char p1[16];
	char p2[16];
	int score1, score2;
	printf("Player 1: ");
	fgets(p1, sizeof(p1), stdin);
	printf("Player 2: ");
	fgets(p2, sizeof(p2), stdin);
	score1 = compute_scrabble_value(p1);
	score2 = compute_scrabble_value(p2);
	if (score1 > score2)
	{
		printf("Player 1 wins!\n");
	}
	else if (score1 < score2)
	{
		printf("Player 2 wins!\n");
	}
	else
	{
		printf("Tie!\n");
	}

}

int compute_scrabble_value(const char *word)
{
    int i = 0;
    while (*word)
    {
        switch (toupper(*word))
        {
            case 'A': case 'E': case 'I': case 'L':
            case 'N': case 'O': case 'R': case 'S':
            case 'T': case 'U': i++;
				break;
            case 'D': case 'G': i += 2;
				break;
            case 'B': case 'C': case 'M': case 'P': i += 3;
				break;
            case 'F': case 'H': case 'V': case 'W':
            case 'Y': i += 4;
				break;
            case 'K': i += 5;
				break;
            case 'J': case 'X': i += 8;
				break;
            case 'Q': case 'Z': i += 10;
				break;
            default: 
				break;
        }
        word++;
    }
    return i;
}
