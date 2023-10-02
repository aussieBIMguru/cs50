#include <stdio.h>
#include <cs50.h>

int main(void)
{
    FILE* file = fopen("file.txt", "r");

    if (file == NULL)
    {
        printf("Error reading file");
        return 1;
    }

    char ch;

    while ((ch = fgetc(file)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(file);
    printf("\n");
    return 0;
}