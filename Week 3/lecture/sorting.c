#include <stdio.h>
#include <cs50.h>

void swap_int(int* a, int* b);

int main(void)
{
    int myValues[] = {7,2,5,4,1,6,0,3};
    int size = 8;

    for (int i = 0; i < size; i++)
    {
        int temp = i;
        for (int j = i; j < size; j++)
        {
            if (myValues[j] < myValues[i])
            {
                temp = j;
            }
        }
        swap_int(&myValues[temp], &myValues[i]);
    }
    for (int k = 0; k < size; k++)
     {
         printf("%i, ", myValues[k]);
     }
    printf("\n");

}

void swap_int(int* a, int* b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}