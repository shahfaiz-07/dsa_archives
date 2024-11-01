
public class MaxHeap {

    private int[] heap;
    private int size;
    private int capacity;

    public MaxHeap(int capacity) {
        this.capacity = capacity;
        this.size = 0;
        heap = new int[capacity];
    }

    // Helper methods for getting parent and child indices
    private int parent(int index) {
        return (index - 1) / 2;
    }

    private int leftChild(int index) {
        return 2 * index + 1;
    }

    private int rightChild(int index) {
        return 2 * index + 2;
    }

    // Helper method to swap elements
    private void swap(int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    // Insert a new element into the heap
    public void insert(int value) {
        if (size >= capacity) {
            throw new IllegalStateException("Heap is full");
        }

        // First insert the new value at the end
        heap[size] = value;
        int current = size;
        size++;

        // Bubble up until heap property is restored
        while (current > 0 && heap[current] > heap[parent(current)]) {
            swap(current, parent(current));
            current = parent(current);
        }
    }

    // Remove and return the maximum element
    public int extractMax() {
        if (size <= 0) {
            throw new IllegalStateException("Heap is empty");
        }

        if (size == 1) {
            size--;
            return heap[0];
        }

        // Store the max value to return
        int max = heap[0];

        // Move last element to root and remove last element
        heap[0] = heap[size - 1];
        size--;

        // Restore heap property
        heapify(0);

        return max;
    }

    // Heapify (bubble down) from given index
    private void heapify(int index) {
        int largest = index;
        int left = leftChild(index);
        int right = rightChild(index);

        // Compare with left child
        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }

        // Compare with right child
        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }

        // If largest is not root
        if (largest != index) {
            swap(index, largest);
            heapify(largest);
        }
    }

    // Get maximum element without removing it
    public int peekMax() {
        if (size <= 0) {
            throw new IllegalStateException("Heap is empty");
        }
        return heap[0];
    }

    // Check if heap is empty
    public boolean isEmpty() {
        return size == 0;
    }

    // Get current size of heap
    public int getSize() {
        return size;
    }

    // Print the heap
    public void print() {
        for (int i = 0; i < size; i++) {
            System.out.print(heap[i] + " ");
        }
        System.out.println();
    }
}
