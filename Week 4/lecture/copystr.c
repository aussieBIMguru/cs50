#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// malloc - memory allocate
// free - free memory

int main(void)
{
    char *s = get_string("s: ");

    // Guard if we ran out of memory
    // NULL means we didn't have enough
    if (s == NULL)
    {
        return 1;
    }

    // t and s are the same address / pointer
    //char *t = s

    // get enough bytes for chars + null
    char *t = malloc(strlen(s+1));

    // Guard if we ran out of memory
    if (t == NULL)
    {
        return 1;
    }

    // copy string characters (+ null)
    //for (int i = 0; i < strlen(s) + 1; i++)
    //{
    //    t[i] = s[i]
    //}

    // Declare strlen once only as a variable
    //for (int i = 0, n = strlen(s) + 1; i < n; i++)
    //{
    //    t[i] = s[i]
    //}

    // A function can do this
    strcpy(t, s);

    // memory address
    printf("%p\n", &s);
    printf("%p\n", &t);

    // cap first letter (bad syntax, might be empty)
    // t[0] = toupper(t[0])

    // better, safer
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // s is protected from address copy
    printf("%s\n", s);
    printf("%s\n", t);

    // you must return the memory if we use malloc
    free(t);

    return 0;

}