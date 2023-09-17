#include <stdio.h>

// Hint the compiler
int binarySearch(int array[], int find, int low, int high);

// Main
int main(void)
{
    // Array and size of array
    int array[] = {0,1,2,3,4,5,6,7,8,9};
    int n = sizeof(array) / sizeof(array[0]);
    // Find this value
    int f = 4;
    // Binary search
    int result = binarySearch(array, f, 0, n-1);
    // Outcome
    if (result == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index %i\n", result);
    }
}

int binarySearch(int array[], int find, int low, int high)
{
    // Keep searching low or high half
    while (low <= high)
    {
        // Get the middle index
        int mid = low + (high - low) / 2;
        // If the value matches, return index
        if (array[mid] == find)
        {
            return mid;
        }
        // If the value is lower, make low value after mid
        if (array[mid] < find)
        {
            low = mid + 1;
        }
        // Otherwise it must be higher, so make high 1 below mid
        else
        {
            high = mid - 1;
        }
    }
    // No match, return -1
    return -1;
}