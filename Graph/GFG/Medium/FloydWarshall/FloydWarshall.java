// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

public class FloydWarshall {
    public void shortest_distance(int[][] matrix) {
        // Code here
        for (int via = 0; via < matrix.length; via++) {
            for (int i = 0; i < matrix.length; i++) {
                for (int j = 0; j < matrix.length; j++) {
                    if (i == via || j == via || matrix[i][via] == -1 || matrix[via][j] == -1) {
                        continue;
                    }
                    int viaDist = matrix[i][via] + matrix[via][j];
                    if (matrix[i][j] == -1 || matrix[i][j] > viaDist) {
                        matrix[i][j] = viaDist;
                    }
                }
            }
        }
    }
}
