// https://leetcode.com/problems/find-a-peak-element-ii/
public class PeakIn2D {
    int maxInColumn(int[][] mat, int j) {
        int max = 0;
        for(int i=1; i<mat.length; i++) {
            if(mat[i][j] > mat[max][j]) {
                max = i;
            }
        }
        return max;
    }
    public int[] findPeakGrid(int[][] mat) {
        int n = mat[0].length;
        int l = 0, u = n - 1;
        while(l <= u) {
            int mid = u - (u - l)/2;
            int maxRowInd = maxInColumn(mat, mid);
            int left = mid == 0 ? -1 : mat[maxRowInd][mid - 1];
            int right = mid == n-1 ? -1 : mat[maxRowInd][mid + 1];
            if(mat[maxRowInd][mid] > left && mat[maxRowInd][mid] > right) {
                return new int[]{maxRowInd, mid};
            } else if(mat[maxRowInd][mid] > left) {
                l = mid + 1;
            } else {
                u = mid - 1;
            }
        }
        return new int[]{-1, -1};
    }
}