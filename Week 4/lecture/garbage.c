#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Nothing in the array
    int scores[1024];

    // We will get garbage (stuff we didn't store!!)
    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }
}