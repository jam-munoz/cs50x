#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
	char	*name;
	int		votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int	candidate_count;

// Function prototypes
bool	vote(const char *name);
void	print_winner(void);

int main(int argc, char *argv[])
{
	// Check for invalid usage
	if (argc < 2)
	{
		printf("Usage: plurality [candidate ...]\n");
		return 1;
	}
	char name[512];
	int voter_count;
	// Populate array of candidates
	candidate_count = argc - 1;
	if (candidate_count > MAX)
	{
		printf("Maximum number of candidates is %i\n", MAX);
		return 2;
	}
	for (int i = 0; i < candidate_count; i++)
	{
		candidates[i].name = argv[i + 1];
		candidates[i].votes = 0;
	}
	printf("Number of voters: ");
	scanf("%d", &voter_count);

	// Loop over all voters
	for (int i = 0; i < voter_count; i++)
	{
		printf("Vote: ");
		scanf("%511s", name);

		// Check for invalid vote
		if (vote(name) == false)
		{
			printf("Invalid vote.\n");
		}
	}

	// Display winner of election
	print_winner();
}

// Update vote totals given a new vote
bool vote(const char *name)
{
	for (int i = 0; i < candidate_count; i++)
	{
		if (strcmp(name, candidates[i].name) == 0)
		{
			candidates[i].votes++;
			return true;
		}
	}
	return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
	int i;
	int winner_count = 1;
	int current = candidates[0].votes;
	char *winner[MAX];

	winner[0] = candidates[0].name;
	for (i = 1; i < candidate_count; i++)
	{
		if (candidates[i].votes == current)
		{
			winner[winner_count] = candidates[i].name;
			winner_count++;
		}
		else if (candidates[i].votes > current)
		{
			winner_count = 1;
			current = candidates[i].votes;
			winner[0] = candidates[i].name;
		}
	}
	for (i = 0; i < winner_count; i++)
		printf("Winner: %s\n", winner[i]);
	return;
}

