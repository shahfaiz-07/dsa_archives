// https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1
public class ArrayIsMaxHeap {
    int parent(int index) {
        return (index - 1) / 2;
    }

    int leftChild(int index) {
        return 2 * index + 1;
    }

    int rightChild(int index) {
        return 2 * index + 2;
    }

    public boolean countSub(long arr[], long n) {
        // Your code goes here
        for (int i = 0; leftChild(i) < n; i++) {
            int lc = leftChild(i), rc = rightChild(i);
            if (arr[lc] > arr[i] || rc < n && arr[rc] > arr[i]) {
                return false;
            }
        }
        return true;
    }
}
