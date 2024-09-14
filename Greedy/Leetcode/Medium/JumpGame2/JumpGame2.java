// https://leetcode.com/problems/jump-game-ii/

public class JumpGame2 {
    public int jump(int[] nums) {
        int l = 0, r = 0, jumps = 0;
        while (r < nums.length - 1) {
            int maxJ = 0;
            for (int i = l; i <= r; i++) {
                if (i + nums[i] > maxJ) {
                    maxJ = i + nums[i];
                }
            }
            jumps++;
            l = r + 1;
            r = maxJ;
        }
        return jumps;
    }
}
