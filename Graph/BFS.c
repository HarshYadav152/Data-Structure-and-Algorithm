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
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * (sizeof(int)));

    // BFS implementation
    int u;
    int i = 4;
    int visited[7] = {0,0,0,0,0,0,0};
/*
    0-----1
    | \   |
    |  \  |
    |   \ |
    2-----3
     \   /
      \ /
       4
      / \
     /   \
    5     6
*/
    // adjacency matrx representation of the above graph
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,0,0,1,1,0,0},
        {1,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };

    printf("%d",i);
    visited[i] = 1;
    enqueue(&q,i);  // ENqueue i  for exploration 
    while (!isEmpty(&q))
    { 
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                printf("%d",j);
                 visited[j] = 1;
                 enqueue(&q,j);
            }
        }
    }
    return 0;
}