#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // For each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if it is a matching name
        if (strcmp(candidates[i].name, name) == 0)
        {
            // If it is, set the voters preference to it
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // For each voter i
    for (int i = 0; i < voter_count; i++)
    {
        // Check their preference j in order
        for (int j = 0; j < candidate_count; j++)
        {
            // Check if candidate at index is not eliminated
            if (!candidates[preferences[i][j]].eliminated)
            {
                // If not, add a vote to candidate j and break
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Required vote percentage
    float needed = (float) voter_count * (float) 0.50;
    // For each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // If they have over 50% of the vote
        if ((float) candidates[i].votes > needed)
        {
            // Print their name and return true
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    // Return false if no winner
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Minimum storage
    int min = voter_count;
    // Go through each candidate and get the minimum
    for (int i = 0; i < candidate_count; i++)
    {
        // If a candidate has less votes and is not eliminated
        if (candidates[i].votes < min && !(candidates[i].eliminated))
        {
            // Update minimum
            min = candidates[i].votes;
        }
    }
    // Return the minimum
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // Go through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // If a candidate has more than min and is not eliminated
        if (candidates[i].votes > min && !(candidates[i].eliminated))
        {
            // It is not a tie
            return false;
        }
    }
    // Otherwise, it is
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Go through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // If a candidate has min and is not eliminated
        if (candidates[i].votes == min && !(candidates[i].eliminated))
        {
            // Eliminate them
            candidates[i].eliminated = true;
        }
    }
    // Return empty
    return;
}