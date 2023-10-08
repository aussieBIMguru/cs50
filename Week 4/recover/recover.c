#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Make type def for byte
typedef uint8_t BYTE;

// Main function
int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover IMAGE\n");
        return 1;
    }

    // remember filename from input
    char *infile = argv[1];

    // Open input file
    FILE *inptr = fopen(infile, "r");
    // Make sure file was opened
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // Out file pointer, image name and image number
    FILE *outptr = NULL;
    char image[8];
    int images = 0;

    // Buffer for reading (512 byte blocks)
    const int BLOCK_SIZE = 512;
    BYTE buffer[BLOCK_SIZE];

    // Read the memory card in blocks
    while (fread(buffer, BLOCK_SIZE, 1, inptr) == 1)
    {
        // Check for jpeg header (1110)
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            // If we have an image already, close it (stops writing to it)
            if (images > 0)
            {
                fclose(outptr);
            }

            // Create name for next image, 3 places
            sprintf(image, "%03d.jpg", images);

            // Open next image file, it will be written to until we get another header
            outptr = fopen(image, "w");
            // Make sure it was opened successfully
            if (outptr == NULL)
            {
                fprintf(stderr, "Could not create %s.\n", image);
                return 3;
            }

            // Uptick images
            images++;
        }

        // If out image exists, write a block to it
        if (outptr != NULL)
        {
            fwrite(buffer, BLOCK_SIZE, 1, outptr);
        }
    }

    // Close last image if it exists
    if (outptr != NULL)
    {
        fclose(outptr);
    }

    // Close read file, finished
    fclose(inptr);
    return 0;
}