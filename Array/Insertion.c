#include <stdio.h>

void display(int arr[], int n)
{
    // traversal
    for (int i = 0; i < n; i++)
    {
        printf("%4d", arr[i]);
    }
}

// code for insertion
int Indexinsertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        printf("Insertion Failed \n");
        return -1;
    }
    else
    {
        for (int i = size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        printf("Insertion Successfull \n");
        return 1;
    }
}
int main()
{
    int arr[10] = {1, 4, 5, 6};
    printf("Given array is : ");
    display(arr, 4);
    printf("\n");
    int element, index;
    int size = 4;
    printf("Enter the element for Insertion : ");
    scanf("%d",&element);
    printf("Enter the index for Insertion : ");
    scanf("%d",&index);
    printf("\n");
    Indexinsertion(arr, size, element, 10, index);
    size++;
    display(arr, size);

    return 0;
}