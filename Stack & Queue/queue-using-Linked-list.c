#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *f = NULL; // front pointer initially NULL
struct node *r = NULL; // rear pointer initially NULL

void LinkedListTraversal(struct node *f)
{
    while (f != NULL)
    {
        printf("Queue Element is %d \n", f->data);
        f = f->next;
    }
}
void enqueue(int value)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Queue is full : ");
    }
    else
    {
        ptr->data = value;
        ptr->next = NULL;
        if (f == NULL) // it is special case
        {
            f = r = ptr;
        }
        else
        {
            r->next = ptr;
            r = ptr;
        }
    }
}

int dequeue()
{
    int value=-1;
    struct node *ptr = f;
    if (f == NULL)
    {
        printf("Queue is empty : \n");
    }
    else
    {
        f=f->next;
        value=ptr->data;
        free(ptr);
    }
    return value;
}
int main()
{
    // printf("Dequeing element %d : \n",dequeue(f));
    enqueue(12);
    enqueue(41);
    LinkedListTraversal(f);
    printf("Dequeing element %d : \n",dequeue());
    // LinkedListTraversal(f);
    printf("Dequeing element %d : \n",dequeue());

    return 0;
}