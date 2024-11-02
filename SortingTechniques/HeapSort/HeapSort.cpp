#include<bits/stdc++.h>
using namespace std;

int parent(int index) { return (index - 1) / 2; }
int leftChild(int index) { return 2 * index + 1; }
int rightChild(int index) { return 2 * index + 2; }

void minHeapInsert(vector<int> &arr, int val) {
    arr.emplace_back(val);

    int index = arr.size() - 1;
    while(index > 0 && arr[parent(index)] > arr[index]) {
        swap(arr[index], arr[parent(index)]);
        index = parent(index);
    }
}

void minHeapify(vector<int> &arr, int n, int index) {
    int smallest = index;
    int lc = leftChild(index);
    int rc = rightChild(index);

    if(lc < n && arr[lc] < arr[smallest]) {
        smallest = lc;
    }
    if(rc < n && arr[rc] < arr[smallest]) {
        smallest = rc;
    }

    if(smallest != index) {
        swap(arr[smallest], arr[index]);
        minHeapify(arr, n, smallest);
    }
}

void arrayToHeap(vector<int> &arr)
{
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
    {
        minHeapify(arr, arr.size(), i);
    }
}

void heapSort(vector<int> &arr) {
    int size = arr.size();
    for(int i=0; i<arr.size() - 1; i++) {
        // delete first element
        int root = arr[0];
        arr[0] = arr[size - 1];
        // place it in the last
        arr[size - 1] = root;
        // reduce the size
        size--;
        // heapify the remaining array
        minHeapify(arr, size, 0);
    }
}

int main(void) {
    vector<int> arr = {4,2,5,3,7,8};
    // minHeapInsert(arr, 4);
    // minHeapInsert(arr, 2);
    // minHeapInsert(arr, 5);
    // minHeapInsert(arr, 3);
    // minHeapInsert(arr, 7);
    // minHeapInsert(arr, 8);
    arrayToHeap(arr);
    for(int &ele: arr) {
        cout << ele << " ";
    }
    cout << "\n";
    heapSort(arr);
    for(int &ele: arr) {
        cout << ele << " ";
    }
    cout << "\n";

    return 0;
}