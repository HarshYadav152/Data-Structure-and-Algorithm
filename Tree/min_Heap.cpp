#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void showPQ(priority_queue<int ,vector<int> ,greater<int>> minHeap){
    while (!minHeap.empty())
    {
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }
    
}
int main(){
    int arr[6] = {5,2,1,4,3,9};
    // priority_queue<int ,vector<int> ,greater<int>> minHeap(arr,arr+6); // directly passed the address of base and last element address
    priority_queue<int ,vector<int> ,greater<int>> minHeap;

    for (int i = 0; i < 6; i++)
    {
        minHeap.push(arr[i]); // one bhy one element pushed into the priority _queue
    }    

    showPQ(minHeap);

    return 0;
}