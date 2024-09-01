// CONSIDERING TRAVERSAL FOR NON CONNECTED COMPONENTS ALSO
import java.util.ArrayDeque;
import java.util.Deque;

public class EdgeListBFS {
    static void traverse(int start, int edges[][], int visited[]) {
        Deque<Integer> q = new ArrayDeque<>();
        visited[start] = 1;
        q.offer(start);
        System.out.print(start+ " ");
        while(!q.isEmpty()) {
            int curr = q.poll();
            for(int[] edge: edges) {
                if(edge[0] == curr && visited[edge[1]] == 0) {
                    System.out.print(edge[1]+" ");
                    visited[edge[1]] = 1;
                    q.offer(edge[1]);
                } else if(edge[1] == curr && visited[edge[0]] == 0) {
                    System.out.print(edge[0]+" ");
                    visited[edge[0]] = 1;
                    q.offer(edge[0]);
                }
            }
        }
        System.out.println();
    }
    static void traversal(int V, int edges[][]) {
        int visited[] = new int[V+1];
        for(int i=1; i<V; i++) {
            if(visited[i] == 0) {
                traverse(i, edges, visited);
            }
        }
    }
    public static void main(String[] args) {
        int[][] edges = {{2, 1}, {2, 4}, {4, 3}, {1, 3}, {5, 6}, {6, 7}, {5, 7}, {8, 9}};
        traversal(11, edges);
    }
}
