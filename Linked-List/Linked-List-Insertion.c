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

// Case 1
struct Node *InsertionAtHead(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// Case 2
struct Node *InsertionAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case 3
struct Node *InsertionAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next=NULL;
    return head;
}

// Case 4
struct Node *InsertionAtfteNode(struct Node *head,struct Node *PreviousNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next=PreviousNode->next;
    PreviousNode->next=ptr;

    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocation of the memory in the linked list from the Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second node
    head->data = 10;
    head->next = second;

    // Link second and third node
    second->data = 20;
    second->next = third;

    // Link third node to fourth node
    third->data = 30;
    third->next = fourth;

    // Terminate the list at the end 
    fourth->data = 50;
    fourth->next = NULL; // it is the last element of the linked list

    printf("Element before insertion\n");
    LinkedListTraversal(head);
    // head = InsertionAtHead(head, 40); // now head been updated  by ptr
    // printf("Element after insertion at the beginning\n");
    // head = InsertionAtIndex(head, 40, 3); // it is not work for index 0
    // printf("Element after insertion at index or between\n");
    // InsertionAtEnd(head,11);
    // printf("Element after insertion at End\n");
    InsertionAtfteNode(head,second,100);
    printf("Element after insertion after the given Node\n");

    LinkedListTraversal(head);
    return 0;
}
