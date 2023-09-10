// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string before);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Error: No word provided.\n");
        return 1;
    }
    else
    {
        printf("%s\n", replace(argv[1]));
    }
}

string replace(string before)
{
    string after = before;

    for (int i = 0, n = strlen(before); i < n; i++)
    {
        if (before[i] == 'a')
        {
            after[i] = '6';
        }
        else if (before[i] == 'e')
        {
            after[i] = '3';
        }
        else if (before[i] == 'o')
        {
            after[i] = '0';
        }
        else if (before[i] == 'i')
        {
            after[i] = '1';
        }
        else
        {
            after[i] = before[i];
        }
    }

    return after;
}