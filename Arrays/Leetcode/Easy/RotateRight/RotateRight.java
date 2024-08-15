package Arrays.Leetcode.Easy.RotateRight;
// https://leetcode.com/problems/rotate-array/description/

import java.util.Arrays;

public class RotateRight {
    // with O(1) extra space
    // Observation:
    // Reverse the array
    // Reverse first k elements
    // Reverse next k elements
    static void rotate2(int[] nums, int k) {
        k = k % nums.length;
        for (int i = 0;
                i < nums.length
                / 2; i++) {
            int t = nums[i];
            nums[i] = nums[nums.length - 1 - i];
            nums[nums.length - 1 - i] = t;
        }
        for (int l = 0, r = k - 1;
                l < r;
                l++, r--) {
            int t = nums[l];
            nums[l] = nums[r];
            nums[r] = t;
        }
        for (int l = k, r = nums.length - 1;
                l < r;
                l++, r--) {
            int t = nums[l];
            nums[l] = nums[r];
            nums[r] = t;
        }
    }
    // With O(n - k) extra space
    static void rotate(int[] nums, int k) {
        k = k % nums.length;
        int temp[] = new int[nums.length - k];
        for (int i = 0; i < nums.length - k; i++) {
            temp[i] = nums[i];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = nums[nums.length - k + i];
        }
        for (int i = k, j = 0; i < nums.length; i++, j++) {
            nums[i] = temp[j];
        }
    }

    public static void main(String[] args) {
        int arr[] = {1, 2, 3, 4, 5, 6, 7};
        System.out.println(Arrays.toString(arr));
        rotate2(arr, 3);
        System.out.println(Arrays.toString(arr));
    }
}
