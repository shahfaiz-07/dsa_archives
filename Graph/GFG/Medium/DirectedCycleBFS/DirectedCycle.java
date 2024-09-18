// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;

public class DirectedCycle {
    public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
        // code here
        Deque<Integer> q = new ArrayDeque<>();
        int []inDegree = new int[V];
        for(int i=0; i<V; i++) {
            for(int ele: adj.get(i)) {
                inDegree[ele]++;
            }
        }
        for(int i=0; i<V; i++) {
            if(inDegree[i] == 0) {
                q.offer(i);
            }
        }
        int count = 0;
        while(!q.isEmpty()) {
            int curr = q.poll();
            count++;
            for(int neighbor: adj.get(curr)) {
                inDegree[neighbor]--;
                if(inDegree[neighbor] == 0) {
                    q.offer(neighbor);
                }
            }
        }
        return count != V;
    }
    public static void main(String[] args) {
        
    }
}