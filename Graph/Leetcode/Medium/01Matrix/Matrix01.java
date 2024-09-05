// https://leetcode.com/problems/01-matrix/
import java.util.ArrayDeque;
import java.util.Deque;


class Triplet {

    int first;
    int second;
    int third;

    Triplet(int first, int second, int third) {
        this.first = first;
        this.second = second;
        this.third = third;
    }
}

public class Matrix01 {

    public int[][] updateMatrix(int[][] mat) {
        Deque<Triplet> que = new ArrayDeque<>();
        int visited[][] = new int[mat.length][mat[0].length];
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                if (mat[i][j] == 0) {
                    que.offer(new Triplet(i, j, 0));
                    visited[i][j] = 1;
                }
            }
        }
        int dels[][] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while (!que.isEmpty()) {
            Triplet curr = que.poll();
            int x = curr.first, y = curr.second, distance = curr.third;
            visited[x][y] = 1;
            for (int[] del : dels) {
                int i = x + del[0], j = y + del[1];
                if (i >= 0 && i < mat.length && j >= 0 && j < mat[0].length && visited[i][j] == 0) {
                    mat[i][j] = distance + 1;
                    visited[i][j] = 1;
                    que.offer(new Triplet(i, j, mat[i][j]));
                }
            }
        }
        return mat;
    }
}
