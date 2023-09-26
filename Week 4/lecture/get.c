#include <stdio.h>

int main(void)
{
    // not using get int
    int x;

    // ask user for value
    printf("x: ");

    // c function to get user input
    // storing it to address of x
    scanf("%i", &x);

    // print the value, stored now in memory
    printf("x: %i\n", x);
}