
import java.util.ArrayList;
import java.util.List;

public class WeightedAdjList {
    static List<List<List<Integer>>> printGraph(int V, int [][]edges) {
        List<List<List<Integer>>> graph = new ArrayList<>(V);
        for(int i=0; i<V; i++) {
            graph.add(new ArrayList<>());
        }
        for(int[] edge: edges) {
            List<Integer> node1 = new ArrayList<>();
            node1.add(edge[1]);
            node1.add(edge[2]);
            graph.get(edge[0]).add(node1);
            List<Integer> node2 = new ArrayList<>();
            node2.add(edge[0]);
            node2.add(edge[2]);
            graph.get(edge[1]).add(node2);
        }
        return graph;
    }
    public static void main(String[] args) {
        int[][] edges = {{0, 1, 2}, {0, 4, 3}, {4, 1, 5}, {4, 3, 2}, {1, 3, 6}, {1, 2, 1}, {3, 2, 4}};
        List<List<List<Integer>>> list = printGraph(5, edges);
        for(List<List<Integer>> arr: list) {
            System.out.println(arr);
        }
    }
}
