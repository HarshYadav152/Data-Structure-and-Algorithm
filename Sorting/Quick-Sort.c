#include <stdio.h>

void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%2d", a[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {   
            //swap a[i] and a[j]
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    } while (i < j);
    // swap a[low] ant a[j]
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}
void QuickSort(int *a, int low, int high)
{
    int partitionIndex; // index of pivot after partition 

    if (low < high)
    {
        partitionIndex = partition(a, low, high); 
        // printArray(a,6);
        QuickSort(a, low, partitionIndex - 1);  // quicksort for the left sub array
        QuickSort(a, partitionIndex + 1, high); // quicksort for the right sub array
    }
}
int main()
{
    int a[] = {3, 2, 6, 8, 4, 5};

    //3, 2, 6, 8, 4, 5
    //3, 2i, 6, 8, 4, 5j
    //3, 2i, 6, 8, 4, 5j
    //3, 2i, 6, 8, 4, 5j
    //3, 2i, 6, 8, 4, 5j 

    int n = 6;
    printArray(a, n);
    QuickSort(a, 0, n - 1);
    printf("\n");
    printArray(a, n);
    return 0;
}