#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL; //use TOP as GLOBAL variable 
void LinkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("\nElement is %d", ptr->data);
        ptr = ptr->next;
    }
}
int isEmpty(struct node *tp)
{
    if (tp == NULL)
    {
        return 1;
    }
    else
        return 0;
}
int isFull(struct node *tp)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    else
        return 0;
}
struct node *push(struct node *tp, int value) // inserting a node at index 0 / beginning
{
    if (isFull(tp))
    {
        printf("Stack Overflow : \n");
    }
    else
    {
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->data = value;
        p->next = tp;
        top = p;
        return top;
    }
}
int pop(struct node *tp) // deleting a node at index 0 / beginning
{
    if (isEmpty(top))
    {
        printf("Stack Underflow : ");
    }
    else
    {
        struct node *ptr = top;
        top = top->next;
        int value = ptr->data;
        free(ptr);
        return value;
    }
}

int main()
{
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