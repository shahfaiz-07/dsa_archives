
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

// https://leetcode.com/problems/shortest-path-in-binary-matrix/
class Tuple {

    int distance, x, y;

    Tuple(int distance, int x, int y) {
        this.distance = distance;
        this.x = x;
        this.y = y;
    }
}
public class ShortestPathInBinaryMatrix {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        int minDist[][] = new int[n][n];

        for (int i = 0; i < n; i++) {
            Arrays.fill(minDist[i], Integer.MAX_VALUE);
        }

        minDist[0][0] = 1;

        Deque<Tuple> pq = new ArrayDeque<>();

        pq.offer(new Tuple(1, 0, 0));

        while (!pq.isEmpty()) {
            Tuple curr = pq.poll();
            int x = curr.x, y = curr.y, dist = curr.distance;
            if (x == n - 1 && y == n - 1) {
                return dist;
            }
            // neighbors will be all of the eight adjacent nodes
            int newDist = dist + 1;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }

                    int nx = x + i, ny = y + j;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != 1 && minDist[nx][ny] > newDist) {
                        minDist[nx][ny] = newDist;
                        pq.offer(new Tuple(newDist, nx, ny));
                    }
                }
            }
        }

        return -1;
    }
}