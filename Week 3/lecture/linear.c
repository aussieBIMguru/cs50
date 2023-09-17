#include <stdio.h>
#include <cs50.h>

// Hint the compiler
int search_linear(int array[], int size, int find);

// Main
int main(void)
{
    // Get doors
    int find = 0;
    do
    {
        find = get_int("Number: ");
    }
    while (find <= 0);
    // Search terms
    int doors = 5;
    int lockers[] = {20, 500, 10, 5, 100};
    // Check for item
    int doorCheck = search_linear(lockers, doors, find);
    // See what we found
    if (doorCheck == -1)
    {
        printf("Did not find it.\n");
    }
    else
    {
        printf("Found it behind door number %i\n", doorCheck);
    }

}

// Search function
int search_linear(int array[], int size, int find)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == find)
        {
            return i;
        }
    }
    int notFound = -1;
    return notFound;
}