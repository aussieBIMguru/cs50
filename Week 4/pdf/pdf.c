#include <cs50.h>
#include <stdio.h>
#include <string.h>
// for uint8_t
#include <stdint.h>

int main(int argc, string argv[])
{
    // Check for CLI
    if (argc != 2)
    {
        printf("Improper usage.\n");
        return 1;
    }

    // Read file at filename
    string filename = argv[1];
    FILE *file = fopen(filename, "r");

    // Check if file exists
    if (file == NULL)
    {
        printf("No such file found.\n");
        return 1;
    }

    // Make a buffer, pdfs store uint8_t's
    // unsigned integer, 8 bit, its own type
    uint8_t buffer[4];

    // Read our buffer using the array
    // fread works on its own
    fread(buffer, 1, 4, file);

    // Compartive array
    int compare[4] = {37,80,68,70};
    bool isPdf = true;

    // Iterate over buffer
    // PDF's begin with 37 80 68 70
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != compare[i])
        {
            isPdf = false;
            break;
        }
    }

    // Return result
    if (isPdf)
    {
        printf("Likely a pdf");
    }
    else
    {
        printf("Likely not a pdf");
    }

    // Close the file
    printf("\n");
    fclose(file);
    return 0;
}