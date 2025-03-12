// https://leetcode.com/problems/trapping-rain-water/
// APROACH 1 is to use the concept of prefix and suffix sum
public class TrappingRainwater {
    public int trap(int[] height) {
        int l = 0, r = height.length - 1, lMax = 0, rMax = 0, ans = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] < lMax) {
                    ans += lMax - height[l];
                } else {
                    lMax = height[l];
                }
                l++;
            } else {
                if (rMax > height[r]) {
                    ans += rMax - height[r];
                } else {
                    rMax = height[r];
                }
                r--;
            }
        }
        return ans;
    }
}
