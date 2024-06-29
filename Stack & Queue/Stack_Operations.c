#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int *arr;
    int top;
    int size;
};

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

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow :\n");
        printf("Can't POP from stack : ");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int i)
{
    int arrPos=ptr->top - i + 1;
    if (arrPos < 0)
    {
        printf("Invalid position : ");
        return -1;
    }
    else{
        return ptr->arr[arrPos];
    }
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

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
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully \n");

    // printf("%d\n",isFull(sp)); // return 0 means stack is not full
    // printf("%d\n",isEmpty(sp)); // return 1 means stack is empty

    push(sp, 25); // first element pushed into the stack
    push(sp, 52); // second element pushed into the stack
    push(sp, 20); 
    push(sp, 10); 
    // printf("Element %d POP from the stack ", pop(sp));
    // printf("\nElement %d POP from the stack ", pop(sp));

    // printf("%d\n",isFull(sp)); // return 0 means stack is not full
    // printf("%d\n",isEmpty(sp)); // return 1 means stack is empty

    // if (isEmpty(sp))
    // {
    //     printf("The stack is Empty : ");
    // }
    // else
    // {
    //     printf("This stack is not Empty : ");
    // }

    // peek value form stack
    for (int i = 1; i < sp->top+1; i++)
    {
        printf("The value at position %d is %d \n",i,peek(sp,i));
    }

    return 0;
}