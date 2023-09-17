#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Make a struct for people
typedef struct
{
    string name;
    int votes;
}
candidate;

// Main
int main(void)
{
    candidate candidates[2];

    candidates[0].name  = get_string("Candidate name: ");
    candidates[0].votes = get_int("Candidate votes: ");

    candidates[1].name  = get_string("Candidate name: ");
    candidates[1].votes = get_int("Candidate votes: ");

    if (candidates[0].votes > candidates[1].votes)
    {
        printf("%s wins!\n", candidates[0].name);
    }
    else
    {
        printf("%s wins!\n", candidates[1].name);
    }
}