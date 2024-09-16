// https://www.geeksforgeeks.org/problems/topological-sort/1

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;

public class TopologicalSort {
    static void dfsTopo(ArrayList<ArrayList<Integer>> adj, int curr, Deque<Integer> stack, boolean[] visited) {
        visited[curr] = true;
        for(int neighbor: adj.get(curr)) {
            if(!visited[neighbor]) {
                dfsTopo(adj, neighbor, stack, visited);
            }
        }
        stack.push(curr);
    }
    //Function to return list containing vertices in Topological order. 
    static int[] topoSort(int V, ArrayList<ArrayList<Integer>> adj) 
    {
        // add your code here
        Deque<Integer> stack = new ArrayDeque<>();
        boolean visited[] = new boolean[V];
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                dfsTopo(adj, i, stack, visited);
            }
        }
        int[] arr = new int[V];
        for(int i=0; i<V; i++) {
            arr[i] = stack.pop();
        }
        return arr;
    }
}