// https://leetcode.com/problems/last-stone-weight/
#include<bits/stdc++.h>
using namespace std;

// IN PLACE HEAP CONVERSION
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
    int largest = index;
    int lc = leftChild(index), rc = rightChild(index);

    if (lc < arr.size() && arr[lc] > arr[largest])
    {
        largest = lc;
    }
    if (rc < arr.size() && arr[rc] > arr[largest])
    {
        largest = rc;
    }
    if (index != largest)
    {
        swap(arr[index], arr[largest]);
        maxHeapify(arr, largest);
    }
}
int remove(vector<int> &heap)
{
    if (heap.size() == 0)
        return -1;
    int root = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if (heap.size() > 0)
        maxHeapify(heap, 0);
    return root;
}
void insert(vector<int> &heap, int val)
{
    heap.push_back(val);
    int index = heap.size() - 1;

    while (index > 0 && heap[parent(index)] < heap[index])
    {
        swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}

int lastStoneWeight(vector<int> &stones)
{
    for (int i = stones.size() / 2 - 1; i >= 0; i--)
    {
        maxHeapify(stones, i);
    }

    while (stones.size() > 1)
    {
        int y = remove(stones);
        int x = remove(stones);
        if (x != y)
        {
            insert(stones, y - x);
        }
    }

    return stones.size() > 0 ? stones[0] : 0;
}


// CREATING NEW HEAP
int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> pq;
    for (int &ele : stones)
    {
        pq.push(ele);
    }

    while (pq.size() > 1)
    {
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();
        if (x != y)
        {
            pq.push(y - x);
        }
    }
    return pq.empty() ? 0 : pq.top();
}
int main(void) {
    
    return 0;
}