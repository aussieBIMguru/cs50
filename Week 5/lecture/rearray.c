#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
    // Make list of 3 ints
    int *list = malloc(3 * sizeof(int));

    // Make sure we have the memory
    if (list == NULL)
    {
        return 1;
    }

    // Store items
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Make list of 4 ints
    // We just use this to redefine list
    int *tmp = malloc(4 * sizeof(int));

    // Make sure we have the memory, and free list if not
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    // Set new values in tmp
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    // Extra value
    tmp[3] = 4;

    // Free original list, change pointers
    free(list);
    // Set new pointer for list so we can keep using old variable
    list = tmp;

    // Print values
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // test with valgrind ./code name
    free(list);

}