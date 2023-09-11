// Include libraries
#include <stdio.h>
#include <cs50.h>

// Tease compiler for functions below main
int get_size(string msg);
void print_grid(int row, int col);


// Main function
int main(void)
{
    // Use functions
    int row = get_size("Row: ");
    int col = get_size("Col: ");
    print_grid(row, col);

    // Final new line for terminal
    printf("\n");
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

// Function to print grid for user
void print_grid(int row, int col)
{
    // For each row...
    for (int i = 0; i < row; i++)
    {
        // For each column, print a hash
        for (int j = 0; j < col; j++)
        {
            printf("#");
        }
        // Go to next row
        printf("\n");
    }
}