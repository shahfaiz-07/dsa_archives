// https://leetcode.com/problems/maximal-rectangle/

import java.util.ArrayDeque;
import java.util.Deque;

public class MaximalRectangle {
    public int largestRectangleArea(int[] heights) {
        // find nse, pse
        // for each index to rectangle will be height[i] * (nse[i] - pse[i] - 1)
        Deque<Integer> st = new ArrayDeque<>();
        int maxR = 0;
        for(int i=0; i<heights.length; i++) {
            while(!st.isEmpty() && heights[st.peek()] >= heights[i]) {
                int ind = st.pop();
                int left = st.isEmpty() ? -1 : st.peek();
                maxR = Math.max(maxR, heights[ind] * (i - left - 1));
            }
            st.push(i);
        }
        while(!st.isEmpty()) {
            int ind = st.pop();
            int left = st.isEmpty() ? -1 : st.peek();
            maxR = Math.max(maxR, heights[ind] * (heights.length - left - 1));
        }
        return maxR;
    }
    public int maximalRectangle(char[][] matrix) {
        int[] pref = new int[matrix[0].length];
        for(int i=0; i<matrix[0].length; i++) {
            pref[i] = matrix[0][i] - '0';
        }
        int maxR = largestRectangleArea(pref);

        for(int i=1; i<matrix.length; i++) {
            for(int j=0; j<matrix[0].length; j++) {
                pref[j] = matrix[i][j] == '0' ? 0 : pref[j] + 1; 
            }
            maxR = Math.max(maxR, largestRectangleArea(pref));
        }
        return maxR;
    }
}
