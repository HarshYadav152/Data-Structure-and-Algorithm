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
        printf("\nElement is %d", ptr->data);
        ptr = ptr->next;
    }
}
int isEmpty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
        return 0;
}
int isFull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    else
        return 0;
}
struct node *push(struct node *top, int value) // inserting a node at index 0 / beginning
{
    if (isFull(top))
    {
        printf("Stack Overflow : \n");
    }
    else
    {
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->data = value;
        p->next = top;
        top = p;
        return top;
    }
}
int pop(struct node **top) // deleting a node at index 0 / beginning
{
    if (isEmpty(*(top)))
    {
        printf("Stack Underflow : ");
    }
    else
    {
        struct node *ptr = *(top);
        *(top) = (*top)->next;
        int value = ptr->data;
        free(ptr);
        return value;
    }
}

int main()
{
    struct node *top = NULL;
    top = push(top, 20);
    top = push(top, 56);
    top = push(top, 13);
    top = push(top, 74);
    printf("Before pop :\n");
    LinkedListTraversal(top);

    int element = pop(&top);
    printf("\nElement %d poped : ", element);
    LinkedListTraversal(top);

    return 0;
}