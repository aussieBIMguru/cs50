#include <stdio.h>

// machine code
// globals
// heap - malloc etc (free space)
// VVV
// goes further down
//
// if we run out here, segmentation fault
//
// goes further up
// ^^^
// stack - used for functions, temps etc

// prototype use addresses
void swap(int *a, int *b);

int main(void)
{
    int x = 0;
    int y = 1;

    printf("x is %i, y is %i\n", x, y);

    // pass in the address vs the variable
    swap(&x, &y);

    printf("x is %i, y is %i\n", x, y);
}

// if we refer to addresses, we don't just pass values
// we must use * to imply the addresses of the variables instead
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}