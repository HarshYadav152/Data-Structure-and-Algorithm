#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element is %d \n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocation of the memory in the linked list from the Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second node
    head->data = 10;
    head->next = second;

    // Link second and third node
    second->data = 20;
    second->next = third;

    // Terminate the list at the third node
    third->data = 30;
    third->next = NULL; // it is the last element of the linked list

    LinkedListTraversal(head);
    return 0;
}