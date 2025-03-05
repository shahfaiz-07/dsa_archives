// https://leetcode.com/problems/spiral-matrix/

import java.util.ArrayList;
import java.util.List;

public class SpiralMatrix {

    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        int m = matrix.length, n = matrix[0].length;
        int top = 0, bottom = matrix.length - 1, left = 0, right = matrix[0].length - 1;
        boolean toRight = true, toDown = true, goHorizontal = true;
        while(ans.size() < m*n) {
            if(goHorizontal) {
                if(toRight) {
                    // from left to right at top
                    for(int i=left; i<=right; i++) {
                        ans.add(matrix[top][i]);
                    }
                    top++;
                    toRight = false;
                } else {
                    // from right to left at bottom
                    for(int i=right; i>=left; i--) {
                        ans.add(matrix[bottom][i]);
                    }
                    bottom--;
                    toRight = true;
                }
                goHorizontal = false;
            } else {
                if(toDown) {
                    // from top to bottom at right
                    for(int i=top; i<=bottom; i++) {
                        ans.add(matrix[i][right]);
                    }
                    right--;
                    toDown = false;
                } else {
                    // from bottom to top at left
                    for(int i=bottom; i>=top; i--) {
                        ans.add(matrix[i][left]);
                    }
                    left++;
                    toDown = true;
                }
                goHorizontal = true;
            }
        }
        return ans;
    }
}