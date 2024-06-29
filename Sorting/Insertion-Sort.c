#include <stdio.h>

void printarray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%2d", a[i]);
    }
}

void insertionSort(int *a, int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++) // loop for passes
    {
        key = a[i];
        j = i - 1;
        // loop for each pass
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int A[] = {10, 8, 4, 6, 3, 2, 1};
    int n = 7;
    printf("Array before Sorting : ");
    printarray(A, n);
    insertionSort(A,n);
    printf("\nArray after Sorting : ");
    printarray(A, n);
    return 0;
}