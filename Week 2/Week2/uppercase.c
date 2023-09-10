#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Main function
int main(void)
{
    // Enter a string
    string s = get_string("Before: ");

    // For each character...
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // if (s[i] >= 'a' && s[i] <= 'z') (long way)
        // Not actually necessary, can just run it on upper...
        // I could also just upper the string as well...
        if (islower(s[i]))
        {
            // s[i] = (char) ((int) s[i] - 32) (long way, ASCII)
            s[i] = toupper(s[i]);
        }
    }

    // Print the final string
    printf("After: %s\n", s);

}