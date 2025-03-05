// https://leetcode.com/problems/missing-number/

public class MissingNumber {

    public int missingNumber(int[] nums) {
        int XOR = 0;
        for (int i = 0; i < nums.length; i++) {
            XOR = XOR ^ nums[i];
        }
        for (int i = 0; i <= nums.length; i++) {
            XOR = XOR ^ i;
        }
        return XOR;
    }
}