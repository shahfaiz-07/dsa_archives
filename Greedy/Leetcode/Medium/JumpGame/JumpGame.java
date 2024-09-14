// https://leetcode.com/problems/jump-game/
public class JumpGame {
    public boolean canJump(int[] nums) {
        int maxJump = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i > maxJump) {
                return false;
            }
            if (nums[i] + i > maxJump) {
                maxJump = nums[i] + i;
            }
            if (maxJump >= nums.length - 1) {
                return true;
            }
        }
        return false;
    }
}
