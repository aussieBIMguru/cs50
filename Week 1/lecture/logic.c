// Header code
#include <cs50.h>
#include <stdio.h>

// Green flag
int main(void)
{
    // Get inputs from user
    int x = get_int("x: ");
    int y = get_int("y: ");

    // Check if greater
    if (x > y)
    {
        printf("x greater than y\n");
    }
    // Else check if less
    else if (x < y)
    {
    // Greater than
    printf("x less than y\n");
    }
    else
    {
        printf("x equals to y\n");
    }
}