// Libraries
#include <cs50.h>
#include <stdio.h>

// Tease compiler for functions below main
int get_size(string msg);
int pyramid_make(int pyramid_size, int pyramid_gap);

// Main program to make a pyramid
int main(void)
{
    // Get size and gap from user
    int size = get_size("Enter size of pyramid: ");
    int gap  = get_size("Enter size of gap: ");
    // Print the pyramid structure
    int pyramid = pyramid_make(size, gap);
}

// Function to get size from user
int get_size(string msg)
{
    // Get a positive integer
    int n;
    do
    {
        n = get_int("%s", msg);
    }
    while(n < 1);
    // Return the value
    return n;
}

// Function to print the pyramid
int pyramid_make(int pyramid_size, int pyramid_gap)
{
    // For each row of the pyramid
    for (int i = 1; i <= pyramid_size; i++)
    {
        // Calculate the dots
        int dots = pyramid_size - i;

        // Print the left dots
        for (int d = 0; d < dots; d++)
        {
            printf(".");
        }
        // Print the left hashes
        for (int lh = 1; lh <= i; lh++)
        {
            printf("#");
        }
        // Print the gap dots
        for (int g = 0; g < pyramid_gap; g++)
        {
            printf(".");
        }
        // Print the right hashes
        for (int rh = 0; rh < i; rh++)
        {
            printf("#");
        }
        // Print the new line
        printf("\n");
    }
    return 0;
}