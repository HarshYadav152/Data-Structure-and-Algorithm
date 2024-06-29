#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue *ptr)
{
    if (ptr->r == ptr->size - 1)
    {
        return 1;
    }
    else
        return 0;
}

int isEmpty(struct Queue *ptr)
{
    if (ptr->r == ptr->f)
    {
        return 1;
    }
    else
        return 0;
}
void enqueue(struct Queue *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("This queue is full : ");
    }
    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = value;
    }
}
int dequeue(struct Queue *ptr)
{
    int a = -1;
    if (isEmpty(ptr))
    {
        printf("This queue is Empty : ");
    }
    else
    {
        ptr->f++;
        a = ptr->arr[ptr->f];
    }
    return a;
}
int main()
{
    struct Queue q;
    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * (sizeof(int)));

    // if (isEmpty(&q))
    // {
    //     printf("Queue is empty : ");
    // }

    // Enqueue few element
    enqueue(&q, 10);
    enqueue(&q, 23);
    enqueue(&q, 25);
    enqueue(&q, 12);
    // enqueue(&q,23);

    // Dequeue element
    printf("\nDEqueue element is %d :", dequeue(&q));
    printf("\nDEqueue element is %d :", dequeue(&q));
    printf("\nDEqueue element is %d :", dequeue(&q));
    printf("\nDEqueue element is %d :", dequeue(&q));
    if (isFull(&q))
    {
        printf("\nQueue is full : ");
    }
    if (isEmpty(&q))
    {
        printf("\nQueue is empty : ");
    }

    // at same time queue is empty and also full
    // to avoid this use circular queue
    return 0;
}