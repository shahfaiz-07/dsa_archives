// https://leetcode.com/problems/single-number/
public class SingleNumber1 {
    public int singleNumber(int[] nums) {
        int xor = 0;
        for (int i : nums) {
            xor = xor ^ i;
        }
        return xor;
    }
}
