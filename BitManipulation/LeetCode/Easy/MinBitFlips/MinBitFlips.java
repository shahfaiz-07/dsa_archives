// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
public class MinBitFlips {
    public static int minBitFlips(int start, int goal) {
        int count = 0;
        while (start != 0 && goal != 0) {
            if (((start & 1) ^ (goal & 1)) == 1) {
                count++;
            }
            start = start >> 1;
            goal = goal >> 1;
        }
        while (start != 0) {
            start = start & (start - 1);
            count++;
        }
        while (goal != 0) {
            goal = goal & (goal - 1);
            count++;
        }
        return count;
    }
    public static void main(String[] args) {
        System.out.println(minBitFlips(10, 7));
    }
}
