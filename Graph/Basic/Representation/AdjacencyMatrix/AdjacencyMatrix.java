
import java.util.Arrays;

public class AdjacencyMatrix {

    static int[][] printGraph(int V, int[][] edges) {
        int[][] graph = new int[V][V];
        for (int[] edge : edges) {
            graph[edge[0]][edge[1]] = 1;
            graph[edge[1]][edge[0]] = 1;
        }
        return graph;
    }

    public static void main(String[] args) {
        int[][] edges = {{0, 1}, {0, 4}, {4, 1}, {4, 3}, {1, 3}, {1, 2}, {3, 2}};
        int[][] graph = printGraph(5, edges);
        for (int[] row : graph) {
            System.out.println(Arrays.toString(row));
        }
    }
}
