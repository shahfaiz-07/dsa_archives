// https://leetcode.com/problems/kth-missing-positive-number/

public class KthMissingNumber {

    public int findKthPositive(int[] arr, int k) {
        int left = 0, right = arr.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int missingCount = arr[mid] - (mid + 1);

            if (missingCount < k) {
                left = mid + 1; 
            }else {
                right = mid - 1;
            }
        }

        return left + k;
    }
}