
import java.util.ArrayList;
import java.util.List;

public class EdgeListDFS {
    static void DFS(int start, int[][] edges, boolean[] visited, List<Integer> dfs) {
        if(!visited[start]) {
            visited[start] = true;
            dfs.add(start);
            for(int[] edge: edges) {
                if(edge[0] == start && !visited[edge[1]]) {
                    DFS(edge[1], edges, visited, dfs);
                } else if(edge[1] == start && !visited[edge[0]]) {
                    DFS(edge[0], edges, visited, dfs);
                }
            }
        }
    }
    static List<Integer> traverse(int V, int[][] edges) {
        List<Integer> dfs = new ArrayList<>();
        boolean[] visited = new boolean[V];
        for(int i=1; i<V; i++) {
            DFS(i, edges, visited, dfs);
        }
        return dfs;
    }
    public static void main(String[] args) {
        int[][] edges = {{2, 1}, {2, 4}, {4, 3}, {1, 3}, {5, 6}, {6, 7}, {5, 7}, {8, 9}};
        List<Integer> list = traverse(11, edges);
        System.out.println(list);
    }
}
