// https://leetcode.com/problems/number-of-1-bits

public class NumberOf1Bits {
    public int hammingWeight(int n) {
        int c = 0;
        while (n != 0) {
            n = n & (n - 1);
            c++;
        }
        return c;
    }
}
