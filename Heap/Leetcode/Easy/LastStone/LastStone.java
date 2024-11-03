// https://leetcode.com/problems/last-stone-weight/

import java.util.PriorityQueue;

public class LastStone {
    // IN PLACE HEAP CONVERSION
    int parent(int index) {
        return (index - 1) / 2;
    }

    int leftChild(int index) {
        return 2 * index + 1;
    }

    int rightChild(int index) {
        return 2 * index + 2;
    }

    void swap(int[] arr, int i, int j) {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }

    void maxHeapify(int[] arr, int index, int size) {
        int largest = index;
        int lc = leftChild(index), rc = rightChild(index);

        if (lc < size && arr[lc] > arr[largest]) {
            largest = lc;
        }
        if (rc < size && arr[rc] > arr[largest]) {
            largest = rc;
        }
        if (index != largest) {
            swap(arr, index, largest);
            maxHeapify(arr, largest, size);
        }

    }

    int remove(int[] heap, int size) {
        if (size == 0) {
            return -1;
        }
        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        if (size > 0) {
            maxHeapify(heap, 0, size);
        }
        return root;
    }

    void insert(int[] heap, int size, int val) {
        heap[size] = val;
        int index = size;

        while (index > 0 && heap[parent(index)] < heap[index]) {
            swap(heap, index, parent(index));
            index = parent(index);
        }
    }

    public int lastStoneWeight(int[] stones) {
        int n = stones.length;
        for (int i = n / 2 - 1; i >= 0; i--) {
            maxHeapify(stones, i, n);
        }

        while (n > 1) {
            int y = remove(stones, n);
            n--;
            int x = remove(stones, n);
            n--;
            if (x != y) {
                insert(stones, n, y - x);
                n++;
            }
        }

        return n > 0 ? stones[0] : 0;
    }


    // CREATING NEW HEAP
    public int lastStoneWeight1(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);

        for(int ele: stones) {
            pq.offer(ele);
        }

        while(pq.size() > 1) {
            int y = pq.poll();
            int x = pq.poll();
            if(y != x) {
                pq.offer(y - x);
            }
        }

        return pq.isEmpty() ? 0 : pq.peek();
    }
}