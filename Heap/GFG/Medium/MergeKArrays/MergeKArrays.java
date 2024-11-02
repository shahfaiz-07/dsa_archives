// https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

import java.util.ArrayList;
import java.util.PriorityQueue;

class Tuple {

    int num, arr, ind;

    Tuple(int num, int arr, int ind) {
        this.num = num;
        this.arr = arr;
        this.ind = ind;
    }
}
public class MergeKArrays {
    public static ArrayList<Integer> mergeKArrays(int[][] arr,int K) 
    {
        // Write your code here.
        PriorityQueue<Tuple> pq = new PriorityQueue<>((a, b) -> a.num - b.num);
        ArrayList<Integer> ans = new ArrayList<>();
        
        for(int i=0; i<K; i++) {
            pq.offer(new Tuple(arr[i][0], i, 0));
        }
        
        for(int i=0; i<K*K; i++) {
            Tuple root = pq.poll();
            ans.add(root.num);
            if(root.ind < K - 1) {
                pq.offer(new Tuple(arr[root.arr][root.ind + 1], root.arr, root.ind + 1));
            }
        }
        
        return ans;
    }
}
