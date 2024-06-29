#include <iostream>
using namespace std;

int Binary_Search(int arr[], int size, int element)
{
    int mid, low, high;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    // only valid for sorted list 
    int arr[] = {1, 2, 5, 6, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    int element;
    printf("Enter the element to be search : ");
    scanf("%d", &element);
    int Search_index = Binary_Search(arr, size, element);
    printf("Element %d found at the index %d ", element, Search_index);
    return 0;
}