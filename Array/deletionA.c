#include<stdio.h>

void display(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        printf("%2d",arr[i]);
    }
    printf("\n");
}

void indexDeletion(int arr[],int index,int size){
    if (size==0)
    {
        printf("Deletion is not possible : ");
    }
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i+1];
    }
}

int main()
{
    int arr[10] = {1,4,5,2,1,3,5};
    int size = 7;
    display(arr,size);
    indexDeletion(arr,3,size);
    display(arr,size-1);
    return 0;
}