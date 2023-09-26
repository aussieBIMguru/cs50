#include <stdio.h>
#include <cs50.h>

// hex is always 0x##
// & operator gets address
// * operator goes to an address
// %p is address printer
// pointers are addresses in memory, 8 bytes as a type

int main(void)
{
    // store a variable
    int n = 50;
    // this variable is a pointer in hex
    int *p = &n;
    // print an address
    printf("%p\n", p);
    // print at address
    printf("%i\n", *p);
}