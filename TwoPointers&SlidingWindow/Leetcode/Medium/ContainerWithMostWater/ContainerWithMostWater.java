// https://leetcode.com/problems/container-with-most-water/

public class ContainerWithMostWater {
    public int maxArea(int[] height) {
        int l = 0, r = height.length - 1;
        int maxArea = 0;
        while (l < r) {
            int area = (r - l) * ((height[l] < height[r]) ? height[l] : height[r]);
            maxArea = Math.max(area, maxArea);

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxArea;
    }
}
