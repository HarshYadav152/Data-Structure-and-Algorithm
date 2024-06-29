#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void LinkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element is %d \n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1 Delete the head of the Linked List
struct node *DeletionOFhead(struct node *head)
{
    // struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2 Deleting an node from the given index
struct node *DeletionATIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next=q->next;
    free(q); // free q
    return head;
}
// Case 3 Delete the last node of the Linked List
struct node *DeletionOFEnd(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

// Case 4 Delete the node with specify value
struct node* DeletionOFGivenValue(struct node* head ,int value)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->data!=value && q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data==value)
    {
        p->next=q->next;
        free(q);
    }
    
    return head;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second;
    struct node *third;
    struct node *fourth;

    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = NULL;

    LinkedListTraversal(head);
    // printf("Deletion of the HEAD node \n");
    // head=DeletionOFhead(head); // for deleting the first element of the Linked List

    // printf("Deletion in linked list at the index \n");
    // head = DeletionATIndex(head, 3);

    // printf("Deletion from the End \n");
    // DeletionOFEnd(head);
    printf("Deleting the node with the specify value \n");
    DeletionOFGivenValue(head,2);
    LinkedListTraversal(head);
    return 0;
}