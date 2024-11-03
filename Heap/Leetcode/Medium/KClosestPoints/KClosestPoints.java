// https://leetcode.com/problems/k-closest-points-to-origin/

import java.util.PriorityQueue;

public class KClosestPoints {
    // Through Manual Heap Creation -> O(k) extra space
    double magnitude(int[] point) {
        return Math.sqrt(point[0] * point[0] + point[1] * point[1]);
    }

    int parent(int index) {
        return (index - 1) / 2;
    }

    int leftChild(int index) {
        return 2 * index + 1;
    }

    int rightChild(int index) {
        return 2 * index + 2;
    }

    void swap(int arr[][], int i, int j) {
        int temp[] = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    void insert(int[][] heap, int size, int[] val) {
        heap[size] = val;
        int index = size;

        while (index > 0 && magnitude(heap[parent(index)]) < magnitude(heap[index])) {
            swap(heap, index, parent(index));
            index = parent(index);
        }
    }

    void minHeapify(int[][] heap, int size, int index) {
        int largest = index;
        int lc = leftChild(index), rc = rightChild(index);
        if (lc < size && magnitude(heap[lc]) > magnitude(heap[largest])) {
            largest = lc;
        }
        if (rc < size && magnitude(heap[rc]) > magnitude(heap[largest])) {
            largest = rc;
        }
        if (index != largest) {
            swap(heap, index, largest);
            minHeapify(heap, size, largest);
        }
    }

    void remove(int[][] heap, int size) {
        if (size == 0) {
            return;
        }
        heap[0] = heap[size - 1];
        size--;
        if (size > 0) {
            minHeapify(heap, size, 0);
        }
    }

    public int[][] kClosest(int[][] points, int k) {
        int ans[][] = new int[k][2];
        int size = 0;
        for (int i = 0; i < k; i++) {
            insert(ans, size, points[i]);
            size++;
        }

        for (int i = k; i < points.length; i++) {
            if (magnitude(points[i]) < magnitude(ans[0])) {
                remove(ans, size);
                size--;
                insert(ans, size, points[i]);
                size++;
            }
        }

        return ans;
    }

    // USING JAVA COLLECTIONS FRAMEWORK - O(2*k) extra space and also O(klog(k)) extra time for removing all elements from heap
    class Pair {

        int x, y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
    double magnitude(int x, int y) {
        return Math.sqrt(x*x + y*y);
    }
    public int[][] kClosest1(int[][] points, int k) {
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> Double.compare(magnitude(b.x, b.y), magnitude(a.x, a.y)));

        for(int i=0; i<k; i++) {
            pq.offer(new Pair(points[i][0], points[i][1]));
        }

        for(int i=k; i<points.length; i++) {
            int x = points[i][0], y = points[i][1];
            if(magnitude(x, y) < magnitude(pq.peek().x, pq.peek().y)) {
                pq.poll();
                pq.offer(new Pair(x, y));
            }
        }

        int ans[][] = new int[k][2];
        for(int i=0; i<k; i++) {
            Pair root = pq.poll();
            ans[i][0] = root.x;
            ans[i][1] = root.y;
        }

        return ans;
    }
}
