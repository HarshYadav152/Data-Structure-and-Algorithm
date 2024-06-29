#include <stdio.h>

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%2d", arr[i]);
    }
    printf("\n");
}

void elementDeletion(int arr[],int size,int element){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==element)
        {
            for (int j = i; j < size-1; j++)
            {
                arr[j] = arr[j+1];
            }
        }
        
    }
    
}
int main()
{
    int arr[10] = {1, 4, 5, 2, 3, 5};
    int size = 6,element;
    display(arr, size);
    printf("Enter the element to be deleted in the array : ");
    scanf("%d",&element);
    elementDeletion(arr, size, element);
    display(arr, size - 1);
    return 0;
}