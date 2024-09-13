// https://leetcode.com/problems/counting-bits/
public class CountingBits {
    // TC = O(N)
    public int[] countBits(int n) {
        int[] ans = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i / 2] + (i & 1);
        }
        return ans;
    }
    // TC = O(NlogN)
    public int[] countBits2(int n) {
        int[] ans = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            int temp = i, count = 0;
            // Integer.bitCount(i)
            while (temp != 0) {
                temp = temp & (temp - 1);
                count++;
            }
            ans[i] = count;
        }
        return ans;
    }
}
