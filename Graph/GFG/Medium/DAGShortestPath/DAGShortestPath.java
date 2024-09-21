// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

class Pair {

    int first, second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

public class DAGShortestPath {
    // DFS
    void topoSort(List<List<Pair>> adj, int curr, boolean[] visited, Deque<Integer> stack) {
        visited[curr] = true;
        for (Pair neighbor : adj.get(curr)) {
            if (!visited[neighbor.first]) {
                topoSort(adj, neighbor.first, visited, stack);
            }
        }
        stack.push(curr);
    }

    public int[] shortestPath(int N, int M, int[][] edges) {
        //Code here
        List<List<Pair>> adj = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < M; i++) {
            adj.get(edges[i][0]).add(new Pair(edges[i][1], edges[i][2]));
        }
        boolean visited[] = new boolean[N];
        Deque<Integer> stack = new ArrayDeque<>();
        topoSort(adj, 0, visited, stack);
        int distance[] = new int[N];
        for (int i = 1; i < N; i++) {
            distance[i] = Integer.MAX_VALUE;
        }
        while (!stack.isEmpty()) {
            int curr = stack.pop();
            for (Pair neighbor : adj.get(curr)) {
                if (neighbor.second + distance[curr] < distance[neighbor.first]) {
                    distance[neighbor.first] = neighbor.second + distance[curr];
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (distance[i] == Integer.MAX_VALUE) {
                distance[i] = -1;
            }
        }
        return distance;
    }
}
