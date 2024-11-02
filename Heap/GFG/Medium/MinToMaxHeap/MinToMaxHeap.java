// https://www.geeksforgeeks.org/problems/convert-min-heap-to-max-heap-1666385109/1

public class MinToMaxHeap {
    static int parent(int index) {
        return (index - 1) / 2;
    }

    static int leftChild(int index) {
        return 2 * index + 1;
    }

    static int rightChild(int index) {
        return 2 * index + 2;
    }

    static void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static void maxHeapify(int arr[], int index) {
        int n = arr.length;
        int lc = leftChild(index);
        int rc = rightChild(index);
        int largest = index;

        if (lc < n && arr[lc] > arr[largest]) {
            largest = lc;
        }
        if (rc < n && arr[rc] > arr[largest]) {
            largest = rc;
        }

        if (index != largest) {
            swap(arr, index, largest);
            maxHeapify(arr, largest);
        }
    }

    static void convertMinToMaxHeap(int N, int arr[]) {
        // code here
        for (int i = arr.length/2 - 1; i >= 0; i--) {
            maxHeapify(arr, i);
        }
    }
}
