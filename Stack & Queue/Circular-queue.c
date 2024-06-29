#include <stdio.h>
#include <stdlib.h>

struct Circular_Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Circular_Queue *ptr)
{
    if (((ptr->r + 1) % ptr->size) == ptr->f)
    {
        return 1;
    }
    else
        return 0;
}

int isEmpty(struct Circular_Queue *ptr)
{
    if (ptr->r == ptr->f)
    {
        return 1;
    }
    else
        return 0;
}
void enqueue(struct Circular_Queue *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Queue overflow : ");
    }
    else
    {
        printf("\nEnqueued element is : %d",value);
        ptr->r = (ptr->r + 1) % ptr->size;
        ptr->arr[ptr->r] = value;
    }
}
int dequeue(struct Circular_Queue *ptr)
{
    int a = -1;
    if (isEmpty(ptr))
    {
        printf("Queue underflow : ");
    }
    else
    {
        ptr->f = (ptr->f + 1) % ptr->size;
        a = ptr->arr[ptr->f];
    }
    return a;
}

int main()
{
    struct Circular_Queue q;
    q.size = 4;
    // front and rear is 0 means that we left one element black // we can't use all element of the circular queue // because f=-1 there is no position in the queue to satisfy the condition isFull() because rear never be -1 that's why we initilize the front and rear is 0 
    q.f = q.r = 0; // 0 in circular queue if we use f = -1 then the isEmpty() and isFull() is disturb 
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 10);
    enqueue(&q, 23);
    enqueue(&q, 25);

    printf("\nDEqueue element is %d :", dequeue(&q));
    printf("\nDEqueue element is %d :", dequeue(&q));
    printf("\nDEqueue element is %d :", dequeue(&q));

    enqueue(&q, 25); // we enqueue element after the dequeue element in circular queue after DEqueueing element because the using the circular increament i goes to 0 after reaching the last index 
    enqueue(&q, 34);
     
    // here the problem occur in previous program is shortout 
    if (isEmpty(&q))
    {
        printf("Queue is empty : \n");
    }
    if (isFull(&q))
    {
        printf("Queue is full : \n"); 
    }
    

    return 0;
}