#include <stdio.h>

int main(void)
{
    // not using get str
    char *s = NULL;

    // ask user for value
    printf("s: ");

    // c function to get user input
    // storing it to address of s
    scanf("%s", s);

    // print the value, stored now in memory
    // doesnt work!
    printf("s: %s\n", s);
}