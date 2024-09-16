// https://www.geeksforgeeks.org/problems/topological-sort/1

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;

public class KahnAlgorithm {
    static int[] topoSort(int V, ArrayList<ArrayList<Integer>> adj) 
    {
        // add your code here
        int[] inDegree = new int[V];
        for(int i=0; i<V; i++) {
            for(int neighbor: adj.get(i)) {
                inDegree[neighbor]++;
            }
        }
        Deque<Integer> q = new ArrayDeque<>();
        for(int i=0; i<V; i++) {
            if(inDegree[i] == 0) {
                q.offer(i);
            }
        }
        int ans[] = new int[V];
        int index = 0;
        while(!q.isEmpty()) {
            int curr = q.poll();
            ans[index++] = curr;
            for(int neighbor: adj.get(curr)) {
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0) {
                    q.offer(neighbor);
                }
            }
        }
        return ans;
    }
}
