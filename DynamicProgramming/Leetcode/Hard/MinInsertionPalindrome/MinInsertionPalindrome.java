
import java.util.Arrays;

// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

public class MinInsertionPalindrome {
    // MEMOIZATION
    int maximize(String s, int i, int j, int[][] dp) {
        if (i >= s.length() || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s.charAt(i) == s.charAt(j)) {
            dp[i][j] = maximize(s, i + 1, j - 1, dp) + 1;
        } else {
            dp[i][j] = Math.max(maximize(s, i + 1, j, dp), maximize(s, i, j - 1, dp));
        }
        return dp[i][j];
    }

    public int minInsertions1(String s) {
        int dp[][] = new int[s.length()][s.length()];
        for (int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        return s.length() - maximize(s, 0, s.length() - 1, dp);
    }
    // TABULATION
    public int minInsertions(String s) {
        int dp[][] = new int[s.length() + 1][s.length() + 1];
        String s2 = "";
        for (int i = 0; i < s.length(); i++) {
            s2 = s.charAt(i) + s2;
        }
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= s.length(); j++) {
                if (s.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return s.length() - dp[s.length()][s.length()];
    }
}
