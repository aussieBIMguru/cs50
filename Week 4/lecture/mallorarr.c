#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Declare array with malloc
    // Size of gets data type size
    int *x = malloc(3 * sizeof(int));

    // Memory limit check
    if (x == NULL)
    {
        return 1;
    }

    // Store array values
    // use valgrind mallorarr
    // will report the issue with index 3 in 3 array
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;

    // Free x to stop leaks
    free(x);
}