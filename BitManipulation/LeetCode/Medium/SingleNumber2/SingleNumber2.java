// https://leetcode.com/problems/single-number-ii/
public class SingleNumber2 {
    // BIT MANIPULATION
    // TC = O(32*N)
    public int singleNumber(int[] nums) {
        int ans = 0;
        for(int i=0; i<=31; i++) {
            int count = 0;
            for(int index=0; index<nums.length; index++) {
                if(((nums[index] >> i) & 1) == 1) {
                    count++;
                }
            }
            if(count%3 != 0) {
                ans = (ans | (1 << i));
            }
        }
        return ans;
    }
    // SORTING
    // TC = O(NlogN) + O(N/3)
    public int singleNumber2(int[] nums) {
        int ans = 0;
        for (int i = 0; i <= 31; i++) {
            int count = 0;
            for (int index = 0; index < nums.length; index++) {
                if (((nums[index] >> i) & 1) == 1) {
                    count++;
                }
            }
            if (count % 3 != 0) {
                ans = (ans | (1 << i));
            }
        }
        return ans;
    }
    // CONCEPT OF BUCKETS
    public int singleNumber1(int[] nums) {
        int ones = 0, twos = 0;
        for (int i = 0; i < nums.length; i++) {
            // if it is not in twos, it should be in ones
            ones = (ones ^ nums[i]) & (~twos);
            // if it is not in ones, it will go to twos
            twos = (twos ^ nums[i]) & (~ones);
        }
        return ones;
    }
}
