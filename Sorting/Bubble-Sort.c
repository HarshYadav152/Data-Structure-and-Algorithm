#include <stdio.h>

void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%2d", a[i]);
    }
}
void bubbleSort(int *a, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // for number of passes
    {
        for (int j = 0; j < n-1-i; j++) // number of comparision in each pass
        {
            if (a[j]>a[j+1]) // if condition satisfy swap these two elements
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        
    }
}
void bubbleSortAdaptive(int *a, int n)
{
    int temp;
    int isSorted=0;
    for (int i = 0; i < n - 1; i++) // for number of passes
    {
        printf("\nWorking on pass no. %d\n",i+1); // if our array is already sorted ( toh hamara kaam ek hi pass main ho gaya ) 
        // ( nahi toh n-1 pass lagenge )
        isSorted=1; // har pass pe isSorted ki value ko 1 kar denge jisse ye pass ke agle iteration pe nahi jayega
        for (int j = 0; j < n-1-i; j++) // number of comparision in each pass
        {
            if (a[j]>a[j+1]) // if condition satisfy swap these two elements
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                isSorted=0;
            }
            // agar hamara array kisi pass mai sorted ho gaya toh hamein aage sort karne ki jarurat nahi padegi
        }
        if (isSorted)
        {
            return;
        }
        
    }
}
int main()
{
    int a[]={5,2,1,9,7,2,1};
    // int a[] = {1,2,3,4,5,6,7};
    int n = 7;
    printf("Array before sorting : ");
    printarray(a, n); // printing the array before sorting
    bubbleSort(a, n);
    // bubbleSortAdaptive(a, n);
    printf("\nArray after sorting : ");
    printarray(a, n); // array after sorting
    return 0;
}