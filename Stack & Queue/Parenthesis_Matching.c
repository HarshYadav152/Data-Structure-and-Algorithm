#include <stdio.h>
#include <stdlib.h>

struct stack
{
    char *arr;
    int top;
    int size;
};

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
void push(struct stack *ptr, char val)
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
        // printf("%d PUSHED into the stack \n", val);
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow :\n");
        printf("Can't POP from stack : ");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int i)
{
    int arrPos = ptr->top - i + 1;
    if (arrPos < 0)
    {
        printf("Invalid position : ");
        return -1;
    }
    else
    {
        return ptr->arr[arrPos];
    }
}
int parenthesis_Matching(char *exp)
{
    struct stack* sp;
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    else{

        return 0;
    }
}
int main()
{
    char *exp="(8)*(7)";
    // check if stack is empty 
    if (parenthesis_Matching(exp))
    {
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    
    return 0;
}