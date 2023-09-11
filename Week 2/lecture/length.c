#include <stdio.h>
#include <cs50.h>
// This has string length
#include <string.h>

// Main function
int main(void)
{
    // Ask for name
    string name = get_string("What is your name? ");

    // Begin at 0
    int n = 0;

    // Index the name until we reach the end
    // NB: Arrays do not usually end with this, just strings
    while (name[n] != '\0')
    {
        n++;
    }

    // Print length of string
    printf("%i\n", n);

    // I can also just use this from string.h
    int n2 = strlen(name);

}