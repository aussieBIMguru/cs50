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

    // We can use realloc to copy the data and make more space
    // More efficient than malloc
    // Still use tmp pointer so we can free list if realloc fails
    int *tmp = realloc(list, 4 * sizeof(int));

    // Make sure we have the memory, and free list if not
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    // Set new pointer for list so we can keep using old variable
    list = tmp;

    // Extra value
    list[3] = 4;

    // Print values
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // test with valgrind ./code name
    free(list);

}