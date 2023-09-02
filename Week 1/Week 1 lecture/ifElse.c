#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get user input
    char c = get_char("Do you agree? ");

    // Check for agree
    if (c == 'y' || c == 'Y')
    {
        printf("Agreed\n");
    }
    // Check for not agreed
    else if (c == 'n' || c == 'N')
    {
        printf("Not agreed\n");
    }
    // Tell user expected input
    else
    {
        printf("Enter y or n/n");
    }
}