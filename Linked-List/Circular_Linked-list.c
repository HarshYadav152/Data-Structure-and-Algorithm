#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void LinkedListTraversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);

    // printf("Element is %d\n", ptr->data);
    // ptr = ptr->next;
    // while (ptr != head)
    // {
    //     printf("Element is %d\n", ptr->data);
    //     ptr = ptr->next;
    // }
}

struct node *InsertAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head->next;
    while (p->next!=head)
    {
        p=p->next;
    }
    // At this point p points to the last node of this circular linked list
    p->next=ptr;
    ptr->next=head;
    head=ptr;
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
    fourth->next = head;

    printf("Linked list before insertion \n");
    LinkedListTraversal(head);
    head=InsertAtFirst(head,11);
    printf("After insertion \n");
    LinkedListTraversal(head);
    return 0;
}