#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int row;
    int col;

    do
    {
        row = get_int("Size X: ");
    }
    while(row<1);

    do
    {
        col = get_int("Size Y: ");
    }
    while(col<1);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");
}