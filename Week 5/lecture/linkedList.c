#include <stdio.h>
#include <stdlib.h>

// New operator
// . = get property
// * = store or get at address
// -> = go to address as property

// Disadvantages
// More memory
// Indexing not possible []
// Can't binary search, linear time

// typedef for linked list object (node)
// struct itself to reference it
typedef struct node
{
    int number;
    // Address of next node
    // Need to struct it internally to reference it
    struct node *next;
}
node;

// Main function
int main(int argc, char *argv[])
{
    // Initialize the list with a node at garbage value
    // This will become the first address
    node *list = NULL;

    // Iterate over arguments, make linked list
    for (int i = 1; i < argc; i++)
    {
        // Convert ascii to integer
        int number = atoi(argv[i]);
        // Make new node
        node *n = malloc(sizeof(node));
        // Ensure we have enough memory
        // Note we have some memory we could leak here progressively if we run out of memory
        // We could write a function to do it
        if (n == NULL)
        {
            return 1;
        }
        // Store number in n
        n->number = number;
        n->next = NULL;
        // Next is the list
        n->next = list;
        list = n;
    }

    // Get the first pointer of the list (node 1)
    node *ptr = list;

    // Print the values in linkedlist while we havent got to end
    while (ptr != NULL)
    {
        // Print number at pointer
        printf("%i\n", ptr->number);
        // Pointer is equal to 'next' property at next node
        ptr = ptr->next;
    }

    // Alternative using for loops
    // for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    // {
    //     printf("%i\n", ptr->number)
    // }

    // Reset to address
    // Could do this in one while technically
    ptr = list;
    // Free memory used by list
    while (ptr != NULL)
    {
        // Temporary address for next address
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}