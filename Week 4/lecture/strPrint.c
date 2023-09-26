#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // string s = "HELLO!"
    char *s = "HI!";
    printf("%s\n", s);
    printf("%s\n", s+1);
    printf("%s\n", s+2);
}