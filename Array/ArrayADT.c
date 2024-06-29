#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr
};

void createArray(struct myArray *a, int t_size, int u_size)
{
    // (*a).total_size = t_size;
    // (*a).used_size = u_size;
    // (*a).ptr = (int *)malloc(t_size * sizeof(int));

    a->total_size = t_size;
    a->used_size = u_size;
    a->ptr = (int *)malloc(t_size * sizeof(int));
}

void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n",(a->ptr)[i]);
    }
    
}

void setValue(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the element %d ",i+1);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    
    }
}
int main()
{
    struct myArray marks;
    createArray(&marks, 10, 2);
    printf("We are running setvalue now : \n");
    setValue(&marks); // we passing the address of the marks
    printf("We are running show now : \n");
    show(&marks);

    return 0;
}