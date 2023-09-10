#include <cs50.h>
#include <stdio.h>

// Tease compiler for functions below main
int get_size(int start, string msg);

int main(void)
{
    // TODO: Prompt for start size
    int initial = 9;
    int population = get_size(initial, "Start size: ");

    // TODO: Prompt for end size
    int size_end = get_size(population, "End size: ");

    // TODO: Calculate number of years until we reach threshold
    int years = 0;

    while (population < size_end)
    {
        years++;
        int born = population / 3;
        int dead = population / 4;
        population += born - dead;
    }

    // TODO: Print number of years
    printf("Years: %i/n", years);
}

// Function to get size from user
int get_size(int start, string msg)
{
    // Get a positive integer
    int n;
    do
    {
        n = get_int("%s", msg);
    }
    while (n < start);
    // Return the value
    return n;
}