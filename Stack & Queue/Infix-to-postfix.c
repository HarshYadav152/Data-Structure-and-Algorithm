#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
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

int precedence(char ch) // only for ( + - * / )
{
    if (ch == '/' || ch == '*')
    {
        return 3;
    }
    else if (ch=='-'||ch=='+')
    {
        return 2;
    }
    else{
        return 0;
    }
    
}
int isOperator(char ch)
{
    if (ch=='+'||ch=='/'||ch=='-'||ch=='*')
    {
        return 1;
    }
    else{
        return 0;
    }
    
}

char* infix_to_postfix(char *infix)
{
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0; // track infix traversal
    int j = 0; // track postfix

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "x-y/z-k*a";
    printf("Postfix is %s ",infix_to_postfix(infix));
    return 0;
}