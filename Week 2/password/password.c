// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool hasUp = false;
    bool hasLow = false;
    bool hasNum = false;
    bool hasSymb = false;
    for (int i = 0, n = strlen(password); i < n; i++)
    {
        if (islower(password[i]))
        {
            hasLow = true;
        }
        else if (isupper(password[i]))
        {
            hasUp = true;
        }
        else if (isdigit(password[i]))
        {
            hasNum = true;
        }
        else if (!isblank(password[i]))
        {
            hasSymb = true;
        }
    }
    return hasUp && hasLow && hasNum && hasSymb;
}
