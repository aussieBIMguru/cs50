#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Make a struct for people
typedef struct
{
    string name;
    string number;
    string address;
}
person;

// Main
int main(void)
{
    person people[2];

    people[0].name = "Carter";
    people[0].number = "1234";

    people[1].name = "Tom";
    people[1].number = "5678";

    string name = get_string("Name: ");

    for (int i = 0; i<2; i++)
    {
        if(strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}