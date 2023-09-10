#include <stdio.h>
#include <cs50.h>

// Global arrays (constant)
const int N = 3;

// Hints to compiler
int get_score(int counter);
float average(int array[], int size);

// Main function
int main(void)
{
    // Make array
    int scores[N];
    // Specify array contents
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_score(i);
    }
    // Print
    printf("Average: %f\n", average(scores, N));
}

// Function - ask for score
int get_score(int counter)
{
    int showCount = counter + 1;
    int score;
    do
    {
        score = get_int("Score %i: ", showCount);
    }
    // Has to be 0 to 100
    while (score < 0 || score > 100);
    return score;
}

// Function - get average
float average(int array[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum / (float) size;
}