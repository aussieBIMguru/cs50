#include "helpers.h"
#include "math.h"

// Function to calculate sobel value
int sobel(int gx, int gy)
{
    int n = round((float) sqrt((gx * gx) + (gy * gy)));
    if (n > 255)
    {
        return 255;
    }
    else
    {
        return n;
    }
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Temporary integer to store to
    int temp_rgb;
    // For each row
    for (int i = 0; i < height; i++)
    {
        // For each pixel in that row
        for (int j = 0; j < width; j++)
        {
            // Get the grayscale value of the pixel
            temp_rgb = round((float) (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3);
            // Change its RGB to that grayscale value
            image[i][j].rgbtRed = temp_rgb;
            image[i][j].rgbtGreen = temp_rgb;
            image[i][j].rgbtBlue = temp_rgb;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Half the array, temp variable
    RGBTRIPLE tmp;
    int halfLength = floor((float) width / 2);
    // For each row
    for (int i = 0; i < height; i++)
    {
        // For each pixel to halfway
        for (int j = 0; j < halfLength; j++)
        {
            // Swap the pixels
            tmp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = tmp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Make a copy of image to process whilst changing new one
    RGBTRIPLE temp_image[height][width];
    // For each row...
    for (int i = 0; i < height; i++)
    {
        // For each pixel
        for (int j = 0; j < width; j++)
        {
            // Write it's RGB values across
            temp_image[i][j].rgbtRed = image[i][j].rgbtRed;
            temp_image[i][j].rgbtGreen = image[i][j].rgbtGreen;
            temp_image[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    // For each row...
    for (int row = 0; row < height; row++)
    {
        // For each pixel in that row...
        for (int col = 0; col < width; col++)
        {
            // Variables
            int count = 0;
            int reds = 0;
            int blues = 0;
            int greens = 0;
            // From relative pixel above to below
            for (int y = -1; y < 2; y++)
            {
                // From relative pixel left to right
                for (int x = -1; x < 2; x++)
                {
                    // If the row and column exist
                    if ((row + y >= 0 && row + y < height) && (col + x >= 0 && col + x < width))
                    {
                        // Add to the total RGB to average
                        reds += temp_image[row + y][col + x].rgbtRed;
                        greens += temp_image[row + y][col + x].rgbtGreen;
                        blues += temp_image[row + y][col + x].rgbtBlue;
                        // Uptick cells found
                        count++;
                    }
                }
            }
            // Set the average pixel rgb
            image[row][col].rgbtRed = (int) round(reds / (float) count);
            image[row][col].rgbtBlue = (int) round(blues / (float) count);
            image[row][col].rgbtGreen = (int) round(greens / (float) count);
        }
    }
    // Void return
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Sobel Gx and Gy arrays
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    // Make a copy of image to process whilst changing new one
    RGBTRIPLE temp_image[height][width];
    // For each row...
    for (int i = 0; i < height; i++)
    {
        // For each pixel
        for (int j = 0; j < width; j++)
        {
            // Write it's RGB values across
            temp_image[i][j].rgbtRed = image[i][j].rgbtRed;
            temp_image[i][j].rgbtGreen = image[i][j].rgbtGreen;
            temp_image[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }
    // For each row...
    for (int row = 0; row < height; row++)
    {
        // For each pixel in that row...
        for (int col = 0; col < width; col++)
        {
            // Variables
            int Xreds, Xblues, Xgreens, Yreds, Ygreens, Yblues;
            Xreds = Xblues = Xgreens = Yreds = Ygreens = Yblues = 0;
            // From relative pixel above to below
            for (int y = -1; y < 2; y++)
            {
                // From relative pixel left to right
                for (int x = -1; x < 2; x++)
                {
                    // If the row and column exist
                    if ((row + y >= 0 && row + y < height) && (col + x >= 0 && col + x < width))
                    {
                        // Add to the total RGB times its aligned Sobel values
                        Xreds += Gx[x + 1][y + 1] * temp_image[row + y][col + x].rgbtRed;
                        Xgreens += Gx[x + 1][y + 1] * temp_image[row + y][col + x].rgbtGreen;
                        Xblues += Gx[x + 1][y + 1] * temp_image[row + y][col + x].rgbtBlue;
                        Yreds += Gy[x + 1][y + 1] * temp_image[row + y][col + x].rgbtRed;
                        Ygreens += Gy[x + 1][y + 1] * temp_image[row + y][col + x].rgbtGreen;
                        Yblues += Gy[x + 1][y + 1] * temp_image[row + y][col + x].rgbtBlue;
                    }
                }
            }
            // Set the average pixel rgb
            image[row][col].rgbtRed = sobel(Xreds, Yreds);
            image[row][col].rgbtBlue = sobel(Xblues, Yblues);
            image[row][col].rgbtGreen = sobel(Xgreens, Ygreens);
        }
    }
    // Void return
    return;
}