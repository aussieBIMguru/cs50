#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Open a file in memory as its pointer
    FILE *file = fopen("phonebook.csv", "a");

    // Ask user for name and number
    string name = get_string("Name: ");
    string number = get_string("Number: ");

    // Print the data to file using fprintf
    fprintf(file, "%s,%s\n", name, number);

    // Close the file
    fclose(file);
}