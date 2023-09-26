#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // string s = "HI!"
    char *s = "HI!";
    printf("%p\n", s);
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+250));
}