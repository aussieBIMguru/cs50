#include <stdio.h>
#include <cs50.h>

const int CAPACITY = 50;

typedef struct
{
    int age;
}
person;

typedef struct
{
    person people[CAPACITY];
    int size;
}
stack;

int main(void)
{
    return 0;
}