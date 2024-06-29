#include<stdio.h>

void display(int arr[],int size){
    printf("Given array is \n ");
    for (int i = 0; i < size; i++)
    {
        printf("%2d",arr[i]);
    }
    printf("\n");
}

void positionDeletion(int *arr,int position,int size){
    for (int i= position-1; i < size-1; i++)
    {
        arr[i] = arr[i+1];
    }    
}
int main()
{
    int arr[10] = {2,3,1,4,5,6};
    int size = 6;
    display(arr,size);
    positionDeletion(arr,3,size);
    size = size-1;
    display(arr,size);
    
    return 0;
}