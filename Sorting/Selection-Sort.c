#include<stdio.h>

void printArray(int *a,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%2d",a[i]);
    }    
}

void selectionSort(int *a,int n){
    int indexOfMin,temp;
    for (int i = 0; i < n-1; i++)
    {
        indexOfMin=i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j]<a[indexOfMin])
            {
                indexOfMin=j;
            }
        }
        // swap a[i] and a[indexOfMin]
        temp=a[i];
        a[i]=a[indexOfMin];
        a[indexOfMin]=temp;        
    }
}
int main()
{

    // input array (There will be total n-1 passes in this case it is 4)
    // 0  1  2  3  4
    // 3  2  8  1  7

    // After first pass
    // 0  1  2  3  4
    // 1| 2  8  3  7

    // After second pass
    // 0  1  2  3  4
    // 1  2| 8  3  7

    // After third pass
    // 0  1  2  3  4
    // 1  2  3| 8  7

    // After fourth pass
    // 0  1  2  3  4
    // 1  2  3  7| 8  // after this we have no need to one more pass 
    // array is sorted

    int a[]={3,2,8,1,7};
    printArray(a,5);
    selectionSort(a,5);
    printf("\nArray after sorting : ");
    printArray(a,5); 
    return 0;
}