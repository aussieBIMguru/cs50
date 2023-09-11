#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Declare variables
    int counter = 0;
    string msg = "Meow\n";
    // Keep saying message
    while (counter < 3)
    {
        printf("%s", msg);
        // Same as += syntax in C
        // -- or -= for downticks
        counter ++;
    }
}