// https://leetcode.com/problems/rotate-image/
public class RotateImage {

    public void rotate(int[][] matrix) {
        int u = 0, l = matrix.length - 1;
        while (u < l) {
            int temp[] = matrix[u];
            matrix[u] = matrix[l];
            matrix[l] = temp;
            u++;
            l--;
        }
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < i; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
    }
}