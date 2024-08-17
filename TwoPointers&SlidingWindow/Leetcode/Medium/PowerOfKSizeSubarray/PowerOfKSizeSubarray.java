
import java.util.Arrays;

public class PowerOfKSizeSubarray {
    public static int[] resultsArray(int[] nums, int k) {
        int result[] = new int[nums.length - k + 1];
        int l = 0, r = 0, last_peak = -1, index = 0;
        while (r < nums.length) {
            if (r > 0) {
                if (nums[r - 1] + 1 != nums[r]) {
                    last_peak = r;
                }
            }
            if ((r - l + 1) < k) {
                r++;
            } else if ((r - l + 1) > k) {
                l++;
            } else {
                if (last_peak > l && last_peak <= r) {
                    result[index++] = -1;
                } else {
                    result[index++] = nums[r];
                }
                l++;
                r++;
            }
        }
        return result;
    }
    public static void main(String[] args) {
        int nums[] = {1,2,3,4,6,7,9};
        System.out.println(Arrays.toString(resultsArray(nums, 3)));
    }
}
