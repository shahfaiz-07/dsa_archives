// https://www.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1

#include<bits/stdc++.h>
using namespace std;
int parent(int index)
{
    return (index - 1) / 2;
}

int leftChild(int index)
{
    return 2 * index + 1;
}

int rightChild(int index)
{
    return 2 * index + 2;
}
void maxHeapify(vector<int> &arr, int index)
{
    int n = arr.size();
    int lc = leftChild(index);
    int rc = rightChild(index);
    int largest = index;

    if (lc < n && arr[lc] > arr[largest])
    {
        largest = lc;
    }
    if (rc < n && arr[rc] > arr[largest])
    {
        largest = rc;
    }

    if (index != largest)
    {
        swap(arr[index], arr[largest]);
        maxHeapify(arr, largest);
    }
}

void convertMinToMaxHeap(vector<int> &arr, int N)
{
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        maxHeapify(arr, i);
    }
}
int main(void) {
    
    return 0;
}