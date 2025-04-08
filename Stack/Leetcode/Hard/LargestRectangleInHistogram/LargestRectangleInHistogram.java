// https://leetcode.com/problems/largest-rectangle-in-histogram/
import java.util.ArrayDeque;
import java.util.Deque;

public class LargestRectangleInHistogram {

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
}