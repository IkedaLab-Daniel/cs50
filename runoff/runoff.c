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
// voter = which voter (0, 1, 2, ...)
// rank  = which rank they're filling in (0 = 1st choice, 1 = 2nd choice, ...)
// name  = the candidate name they typed
bool vote(int voter, int rank, string name)
{
    // Loop through every candidate to find one whose name matches what was typed
    for (int i = 0; i < candidate_count; i++)
    {
        // strcmp compares two strings; it returns 0 when they are equal
        if (strcmp(candidates[i].name, name) == 0)
        {
            // We found the candidate!
            // Store their index (i) as this voter's choice at this rank.
            // Example: preferences[2][0] = 1  means voter #2's 1st choice is candidate #1.
            preferences[voter][rank] = i;

            // Return true to signal the vote was recorded successfully
            return true;
        }
    }

    // If we get here, no candidate matched the typed name (the vote is invalid)
    return false;
}

// Tabulate votes for non-eliminated candidates
// Called once per round. Counts each voter's CURRENT top choice (their
// highest-ranked candidate who has NOT been eliminated yet).
void tabulate(void)
{
    // Go through every voter
    for (int i = 0; i < voter_count; i++)
    {
        // Go through this voter's ranked preferences from best (0) to worst
        for (int j = 0; j < candidate_count; j++)
        {
            // preferences[i][j] is the index of this voter's j-th choice candidate
            int choice = preferences[i][j];

            // Is this candidate still in the race?
            if (!candidates[choice].eliminated)
            {
                candidates[choice].votes++;
                break; // stop looking through this voter's ranked list
            }
            // If the candidate is eliminated, the inner loop continues to
            // the next preference automatically
        }
    }
}

// Print the winner of the election, if there is one
// A winner exists when a candidate holds MORE THAN 50% of all votes cast.
bool print_winner(void)
{
    // A majority means strictly more than half the voters
    // Example: 9 voters → majority requires at least 5 votes
    int majority = voter_count / 2 + 1;

    // Check every candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Only non-eliminated candidates can win
        if (!candidates[i].eliminated)
        {
            if (candidates[i].votes >= majority)
            {
                // This candidate has a majority (winner)
                printf("%s\n", candidates[i].name);
                return true;
            }
        }
    }

    // Nobody has a majority yet; the runoff must continue
    return false;
}

// Return the minimum number of votes any remaining (non-eliminated) candidate has
int find_min(void)
{
    // Start with a very large number so any real vote count will be smaller
    int min = MAX_VOTERS + 1;

    for (int i = 0; i < candidate_count; i++)
    {
        // Skip candidates who are already out of the race
        if (!candidates[i].eliminated)
        {
            // If this candidate has fewer votes than our current minimum, update it
            if (candidates[i].votes < min)
            {
                min = candidates[i].votes;
            }
        }
    }

    return min;
}

// Return true if the election is tied between ALL remaining candidates, false otherwise
// A tie means every non eliminated candidate has exactly the minimum vote count
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Skip eliminated candidates, no need tie check
        if (!candidates[i].eliminated)
        {
            // If any active candidate has MORE votes than the minimum,
            // the race is NOT a tie
            if (candidates[i].votes != min)
            {
                return false;
            }
        }
    }

    // Every active candidate has exactly "min" votes --> it is a tie
    return true;
}

// Eliminate the candidate (or candidates) in last place
// Any non-eliminated candidate whose vote count equals 'min' is knocked out.
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Only act on candidates still in the race
        if (!candidates[i].eliminated)
        {
            // If this candidate is tied for last place, eliminate them
            if (candidates[i].votes == min)
            {
                candidates[i].eliminated = true;
            }
        }
    }
}
