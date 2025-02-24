// https://leetcode.com/problems/search-a-2d-matrix-ii/

public class BinarySearchIn2DII {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length, n = matrix[0].length;

        int ri = 0, ci = n - 1;
        while (ri < m && ci >= 0) {
            if (matrix[ri][ci] == target) {
                return true;
            }
            if (target > matrix[ri][ci]) {
                ri++;
            } else {
                ci--;
            }
        }
        return false;
    }
}
