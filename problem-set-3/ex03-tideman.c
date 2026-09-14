#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX] = { 0 };

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
	int winner;
	int loser;
}	pair;

// Array of candidates
char *candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, char *name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool creates_cycle(int winner, int loser);

int main(int argc, char *argv[])
{
	// Check for invalid usage
	if (argc < 2)
	{
		printf("Usage: tideman [candidate ...]\n");
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
		candidates[i] = argv[i + 1];
	}

	// Clear graph of locked in pairs
	for (int i = 0; i < candidate_count; i++)
	{
		for (int j = 0; j < candidate_count; j++)
		{
			locked[i][j] = false;
		}
	}

	pair_count = 0;
	printf("Number of voters: ");
	scanf("%d", &voter_count);
	// Query for votes
	for (int i = 0; i < voter_count; i++)
	{
		// ranks[i] is voter's ith preference
		int ranks[candidate_count];

		// Query for each rank
		for (int j = 0; j < candidate_count; j++)
		{
			printf("Rank %d: ", j + 1);
			scanf("%511s", name);

			if (!vote(j, name, ranks))
			{
				printf("Invalid vote.\n");
				return 3;
			}
		}

		record_preferences(ranks);

		printf("\n");
	}

	add_pairs();
	sort_pairs();
	lock_pairs();
	print_winner();
	return 0;
}

// Update ranks given a new vote
bool vote(int rank, char *name, int ranks[])
{
/* The function takes arguments rank, name, and ranks. If name is a match for the name of a valid candidate,
then you should update the ranks array to indicate that the voter has the candidate as their rank preference
(where 0 is the first preference, 1 is the second preference, etc.)
Recall that ranks[i] here represents the user’s ith preference.
The function should return true if the rank was successfully recorded, and false otherwise (if, for instance,
name is not the name of one of the candidates).
You may assume that no two candidates will have the same name. */
	for (int i = 0; i < candidate_count; i++)
	{
		if (strcmp(name, candidates[i]) == 0)
		{
			ranks[i] = rank;
			return true;
		}
	}

	return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
/* The function is called once for each voter, and takes as argument the ranks array, (recall that
ranks[i] is the voter’s ith preference, where ranks[0] is the first preference).
The function should update the global preferences array to add the current voter’s preferences. Recall
that preferences[i][j] should represent the number of voters who prefer candidate i over candidate j.
You may assume that every voter will rank each of the candidates.*/
	int i, j;

	for (i = 0; i < candidate_count; i++)
	{
		for (j = 0; j < candidate_count; j++)
		{
			if (ranks[i] < ranks [j])
			{
				preferences[i][j]++;
			}
		}
	}
	return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
/* The function should add all pairs of candidates where one candidate is preferred to the pairs array.
A pair of candidates who are tied (one is not preferred over the other) should not be added to the array.
The function should update the global variable pair_count to be the number of pairs of candidates. (The
pairs should thus all be stored between pairs[0] and pairs[pair_count - 1], inclusive).*/
	int i, j;

	pair_count = 0;

	for (i = 0; i < candidate_count; i++)
	{
		for (j = 0; j < candidate_count; j++)
		{
			if (preferences[i][j] > preferences[j][i])
			{
				pairs[pair_count].winner = i;
				pairs[pair_count].loser = j;
				pair_count++;
			}
		}
	}
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
/*The function should sort the pairs array in decreasing order of strength of victory, where strength
of victory is defined to be the number of voters who prefer the preferred candidate. If multiple pairs
have the same strength of victory, you may assume that the order does not matter.*/
	int largest;
	int i, j;
	pair temp;

	for (i = 0; i < pair_count - 1; i++)
	{
		largest = i;

		for (j = i + 1; j < pair_count; j++)
		{
			if (preferences[pairs[j].winner][pairs[j].loser] >
				preferences[pairs[largest].winner][pairs[largest].loser])
			{
				largest = j;
			}
		}

		temp = pairs[i];
		pairs[i] = pairs[largest];
		pairs[largest] = temp;
	}
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
/*The function should create the locked graph, adding all edges in decreasing order of victory strength
so long as the edge would not create a cycle.*/
	int i, winner, loser;

	for (i = 0; i < pair_count; i++)
	{
		winner = pairs[i].winner;
		loser = pairs[i].loser;

		if (creates_cycle(winner, loser) == false)
			locked[winner][loser] = true;
	}
}
bool creates_cycle(int winner, int loser)
{
	bool visited[MAX] = { false };
	int stack[MAX];
	int top = 1;
	int current;

	stack[0] = loser;
	visited[loser] = true;

	while (top > 0)
	{
		top--;
		current = stack[top];

		if (current == winner)
			return true;

		for (int i = 0; i < candidate_count; i++)
		{
			if (locked[current][i] && visited[i] == false)
			{
				visited[i] = true;
				stack[top] = i;
				top++;
			}
		}
	}

	return false;
}

// Print the winner of the election
void print_winner(void)
{
/*The function should print out the name of the candidate who is the source of the graph.
You may assume there will not be more than one source.*/
	int i, j;
	bool is_source;

	for (i = 0; i < candidate_count; i++)
	{
		is_source = false;

		for (j = 0; j < candidate_count; j++)
		{
			if (locked[j][i])
			{
				is_source = true;
				break;
			}
		}

		if (is_source == false)
		{
			printf("Winner: %s\n", candidates[i]);
			return;
		}
	}
}

