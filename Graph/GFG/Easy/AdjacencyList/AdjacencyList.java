// https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1
import java.util.ArrayList;
import java.util.List;

public class AdjacencyList {

    public static List<List<Integer>> printGraph(int V, int edges[][]) {
        List<List<Integer>> graph = new ArrayList<>(V);
        for (int i = 0; i < V; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        return graph;
    }

    public static void main(String[] args) {
        int[][] edges = {{0, 1}, {0, 4}, {4, 1}, {4, 3}, {1, 3}, {1, 2}, {3, 2}};
        List<List<Integer>> list = printGraph(5, edges);
        System.out.println(list);
    }
}
