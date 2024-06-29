#include <stdio.h>

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%2d", arr[i]);
    }
}

void mergeSort(int a[], int b[], int c[], int m, int n)
{
    int i, k, j;
    i = j = k = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k] = b[j];
            j++;
            k++;
        }
    }
    // copy all remaining element
    while (i < m)// from a to c
    { 
        c[k] = a[i];
        i++;
        k++;
    }
    while (j < n) // from b to c
    {
        c[k] = b[j];
        j++;
        k++;
    }
}
int main()
{
    int a[4] = {1, 3, 5, 7};
    int b[3] = {0, 2, 4};
    int c[7];
    mergeSort(a, b, c, 4, 3); // this will merge a and b (it will only applicable for sorting array a and b)
    printarray(c, 7);
    return 0;
}