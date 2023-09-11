#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int compute_letter(char letter);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Function to compute a word's value
int compute_score(string word)
{
    // Score begins at 0
    int score = 0;
    // For each character
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Score its value, add to score
        score += compute_letter(word[i]);
    }
    // Return word score
    return score;
}

// Function to comute a character's value
int compute_letter(char letter)
{
    // Make char uppercase, get its ascii
    char test = toupper(letter);
    int check = (int) test;
    // If it's an upper case letter, score it
    if (check > 64 && check < 91)
    {
        // Score the letter
        int ind = check - 65;
        return POINTS[ind];
    }
    else
    {
        // Otherwise, it's 0
        int points = 0;
        return points;
    }
}