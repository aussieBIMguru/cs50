#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Main
int main(void)
{
    // String array
    string strings[] = {"ship","boot","cannon","iron","thimble","hat"};
    // Get user string
    string s = "";
    do
    {
        s = get_string("Piece: ");
    }
    while (strlen(s) == 0);
    // Get piece
    for (int i = 0; i < 6; i++)
    {
        // Cannot use == for strings
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found it!\n");
            return 0;
        }
    }
    printf("Did not find it...\n");
    return 0;
}