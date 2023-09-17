#include <stdio.h>
#include <cs50.h>

// Hint the compiler
int collatz(int number, int counter);

// Main
int main(void)
{
    // Ask for integer
    int start = get_int("Start at: ");
    int steps = 0;
    // Return the collatz steps
    printf("Steps: %i\n", collatz(start, steps));
}

// Collatz step calculator
int collatz(int number, int counter)
{
    // Base case, we reached zero
    if (number == 1)
    {
        return counter;
    }
    // Otherwise we will take a step
    else
    {
        counter += 1;
    }
    // If we have an even number...
    if (number % 2 == 0)
    {
        // Next collatz
        number = number/2;
    }
    // Otherwise...
    else
    {
        // Next collatz
        number = (number * 3) + 1;
    }
    // Recursive stage
    return collatz(number, counter);
}