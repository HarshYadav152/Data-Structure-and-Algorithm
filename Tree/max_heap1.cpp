#include <iostream>
#include <queue>
using namespace std;


int main()
{
    priority_queue<int> maxHeap;
    
    int arr[6] = {4,2,5,1,2,10};

    for (int i = 0; i < 6; i++)
    {
        maxHeap.push(arr[i]);
    }

    // priority queue

    while (!maxHeap.empty())
    {
        cout<<maxHeap.top()<<" ";
        maxHeap.pop();
    }
    
    return 0;
}