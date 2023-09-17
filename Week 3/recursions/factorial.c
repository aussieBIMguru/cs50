#include <stdio.h>
#include <cs50.h>

int factorial(int f);

int main(void)
{
    int factor = 4;
    printf("%i\n", factorial(factor));
}

int factorial(int number)
{
    // ... until the base case, stops recursion
    if (number == 1)
    {
        return 1;
    }

    // Multiply the number by itself minus one, by itself...
    return number * factorial(number - 1);
}