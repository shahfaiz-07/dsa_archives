import java.util.Arrays;

public class HeapSort {
    static int leftChild(int parent) {
        return 2*parent + 1;
    }
    static int rightChild(int parent) {
        return 2*(parent + 1);
    }
    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    static void minHeapify(int[] arr, int n, int index) {
        int smallest = index;
        int lc = leftChild(index);
        int rc = rightChild(index);
        if(lc < n && arr[lc] < arr[smallest]) {
            smallest = lc;
        }
        if(rc < n && arr[rc] < arr[smallest]) {
            smallest = rc;
        }
        if(index != smallest) {
            swap(arr, index, smallest);
            minHeapify(arr, n, smallest);
        }
    }
    static void arrayToHeap(int[] arr, int n) {
        // NOT O(n log n) but O(n)
        for(int i=arr.length/2 -1; i>=0; i--) {
            minHeapify(arr, n, i);
        }
    }
    static void heapSort(int[] arr, int n) {
        arrayToHeap(arr, n);
        for(int i=0; i<arr.length; i++) {
            int root = arr[0];

            arr[0] = arr[n-1];

            arr[n-1] = root;

            n--;

            minHeapify(arr, n, 0);
        }
    }
    public static void main(String[] args) {
        int[] arr = {4,2,5,3,7,8};

        heapSort(arr, arr.length);

        System.out.println(Arrays.toString(arr));
    }
}
