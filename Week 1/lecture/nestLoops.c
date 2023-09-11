#include <stdio.h>

int main(void)
{
    int row = 3;
    int col = 4;

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