// https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1

import java.util.PriorityQueue;
class Pair {

    int ele, ind;

    Pair(int ele, int ind) {
        this.ele = ele;
        this.ind = ind;
    }
}
public class ReplaceElementByRank {
    static int[] replaceWithRank(int arr[], int N) {
     // code here
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> a.ele - b.ele);
        
        for(int i=0; i<arr.length; i++) {
            pq.offer(new Pair(arr[i], i));
        }
        
        int lastPop = 0, rank = 0;
        
        while(!pq.isEmpty()) {
            Pair root = pq.poll();
            if(root.ele != lastPop) {
                rank++;
            }
            lastPop = root.ele;
            arr[root.ind] = rank;
        }
        
        return arr;
    }
}
