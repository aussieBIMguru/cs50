#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Main
int main(void)
{
    string names[]   = {"Carter", "David"};
    string numbers[] = {"1234", "2345"};

    string name = get_string("Name: ");

    for (int i =0; i<2; i++)
    {
        if(strcmp(names[i], name) == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    printf("Not found\n");
    return 1;
    }
}