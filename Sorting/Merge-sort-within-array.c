#include <stdio.h>

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%2d", arr[i]);
    }
    printf("\n");
}

void merge(int a[], int mid, int low, int high)
{
    int i, j, k;
    int b[10];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++) // coping b[] ke element in the a[]
    {
        a[i] = b[i];
    }
}

void mergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);      // mergeSort for the left half
        mergeSort(a, mid + 1, high); // mergeSort for the right half

        merge(a, mid, low, high); // merging the array from [low to mid] and [mid+1 to high]
    }
}
int main()
{
    // int a[7] = {5, 1, 7, 3, 2, 8, 4};
    int a[7] = {5, 1, 0, 3, 2, 2, 4};
    printarray(a, 7);
    mergeSort(a, 0, 7);
    printarray(a, 7);
    return 0;
}