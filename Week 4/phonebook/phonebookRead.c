#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get file pointer, read it
    FILE *file = fopen("phonebook.csv", "r");

    // Print the file pointer
    printf("%p\n", file);

    // Read using a buffer
    // fread(where to store, size to read in bytes, how many to read, input file)
    // fread(buffer, 1, 3, input)

    // Close the file
    fclose(file);
}