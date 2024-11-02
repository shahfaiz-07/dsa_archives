#include<bits/stdc++.h>
using namespace std;

class MaxHeap
{
private:
    vector<int> heap;

    // Helper methods for getting parent and child indices
    int parent(int index) { return (index - 1) / 2; }
    int leftChild(int index) { return 2 * index + 1; }
    int rightChild(int index) { return 2 * index + 2; }

    // Helper method to swap elements
    void swap(int i, int j)
    {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    // Heapify (bubble down) from given index
    void heapify(int index)
    {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        // Compare with left child
        if (left < heap.size() && heap[left] > heap[largest])
        {
            largest = left;
        }

        // Compare with right child
        if (right < heap.size() && heap[right] > heap[largest])
        {
            largest = right;
        }

        // If largest is not root
        if (largest != index)
        {
            swap(index, largest);
            heapify(largest);
        }
    }

public:
    MaxHeap() {} // Default constructor

    // Insert a new element into the heap
    void insert(int value)
    {
        // Add the new value at the end
        heap.push_back(value);
        int current = heap.size() - 1;

        // Bubble up until heap property is restored
        while (current > 0 && heap[current] > heap[parent(current)])
        {
            swap(current, parent(current));
            current = parent(current);
        }
    }

    // Remove and return the maximum element
    int extractMax()
    {
        if (heap.empty())
        {
            throw runtime_error("Heap is empty");
        }

        int max = heap[0];

        // If this is the last element
        if (heap.size() == 1)
        {
            heap.pop_back();
            return max;
        }

        // Move last element to root and remove last element
        heap[0] = heap.back();
        heap.pop_back();

        // Restore heap property
        heapify(0);

        return max;
    }

    // Get maximum element without removing it
    int peekMax()
    {
        if (heap.empty())
        {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }

    // Check if heap is empty
    bool isEmpty()
    {
        return heap.empty();
    }

    // Get current size of heap
    size_t size()
    {
        return heap.size();
    }

    // Print the heap
    void print()
    {
        for (int value : heap)
        {
            cout << value << " ";
        }
        cout << endl;
    }
};