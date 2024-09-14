// https://leetcode.com/problems/single-number-iii/
public class SingleNumber3 {
    public int[] singleNumber(int[] nums) {
        int XOR = 0;
        for (int i = 0; i < nums.length; i++) {
            XOR = XOR ^ nums[i];
        }
        int separator = ((XOR & (XOR - 1)) ^ XOR);
        int b1 = 0;
        int b2 = 0;
        for (int i = 0; i < nums.length; i++) {
            if ((separator & nums[i]) != 0) {
                b1 = b1 ^ nums[i];
            } else {
                b2 = b2 ^ nums[i];
            }
        }
        return new int[]{b1, b2};
    }
}
