#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // Get length of string
    int count  = strlen(input);

    // Recursion - base case, empty string
    // If our string is empty, we've reached the end
    if (count == 0)
    {
        return 0;
    }

    // Get the last character to integer
    char c = input[count - 1];
    // Convert to ASCII number from equivalent char
    int number = c - '0';
    // Remove the last character from string
    input[count - 1] = '\0';

    // Recursive component
    // We multiply by 10 to shift the places
    // We then run the same until we run out of digits
    return number + 10 * convert(input);
}