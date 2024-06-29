#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%2d", a[i]);
    }
    printf("\n");
}
int maximum(int *a, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

void countSort(int *a, int n)
{
    int i, j;
    // find the maximum element in a
    int max = maximum(a, n);

    // create the count array
    int *count = (int *)malloc((max + 1) * sizeof(int));

    // initialize the count array's element to 0
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // Increment of the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }

    i = 0; // counter for count array
    j = 0; // counter for given array

    while (i < max + 1) // this will copy element from the count array to given array in a sorted fashion
    {
        if (count[i] > 0)
        {
            a[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}
int main()
{
    int a[7] = {4, 1, 3, 2, 3, 7, 0};
    printarray(a, 7);
    countSort(a, 7);
    printarray(a, 7);
    return 0;
}