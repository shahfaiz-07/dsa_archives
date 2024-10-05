// https://leetcode.com/problems/path-with-minimum-effort/

import java.util.Arrays;
import java.util.PriorityQueue;

class Tuple {

    int distance, x, y;

    Tuple(int distance, int x, int y) {
        this.distance = distance;
        this.x = x;
        this.y = y;
    }
}
public class MinEffortPath {
    public int minimumEffortPath(int[][] heights) {
        int m = heights.length, n = heights[0].length;
        int maxHeight[][] = new int[m][n];
        for (int i = 0; i < m; i++) {
            Arrays.fill(maxHeight[i], Integer.MAX_VALUE);
        }
        maxHeight[0][0] = heights[0][0];
        PriorityQueue<Tuple> pq = new PriorityQueue<>((a, b) -> {
            return a.distance - b.distance;
        });
        pq.offer(new Tuple(0, 0, 0));
        int dels[][] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!pq.isEmpty()) {
            Tuple curr = pq.poll();
            int x = curr.x, y = curr.y, dist = curr.distance;
            if (x == m - 1 && y == n - 1) {
                return dist;
            }
            // up, down, left and right
            for (int[] del : dels) {
                int nx = x + del[0], ny = y + del[1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newDist = Math.max(dist, Math.abs(heights[nx][ny] - heights[x][y]));
                    if (maxHeight[nx][ny] > newDist) {
                        maxHeight[nx][ny] = newDist;
                        pq.offer(new Tuple(newDist, nx, ny));
                    }
                }
            }
        }

        return 0;
    }
}
