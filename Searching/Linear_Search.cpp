#include <iostream>
using namespace std;

int Linear_Search(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 5, 6, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    int element;
    printf("Enter the element to be search : ");
    scanf("%d", &element);
    int Search_index = Linear_Search(arr, size, element);
    printf("Element %d found at the index %d ", element, Search_index);
    return 0;
}