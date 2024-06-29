#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int *arr;
    int top;
    int size;
};

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow :\n");
        printf("Can't PUSH %d in the stack : ", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("%d PUSHED into the stack \n", val);
    }
}


int peek(struct stack *ptr, int i)
{
    int arrPos=(ptr->top - i + 1);
    if (arrPos < 0)
    {
        printf("Invalid position : ");
        return -1;
    }
    else{
        return ptr->arr[arrPos];
    }
}

int stackTop(struct stack *ptr){ // return element which at the top 
    return ptr->arr[ptr->top];
} 
int stackBottom(struct stack *ptr){  // return element which at the first element of the stack 
    return ptr->arr[0];
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 20;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully \n");

    push(sp, 52); 
    push(sp, 14); 
    push(sp, 20); 
    push(sp, 10);  
    push(sp, 1); 
    push(sp, 2); 
    push(sp, 9); 
    push(sp, 5); 
    // for (int i = 1; i <= sp->top+1; i++)
    // {
    //     printf("The value at position %d is %d \n",i,peek(sp,i));
    // }
    // printf("%d",peek(sp,sp->top));

    printf("Element at the top %d \n",stackTop(sp));
    printf("First Element of the stack %d ",stackBottom(sp));

    return 0;
}