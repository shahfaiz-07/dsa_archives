// https://leetcode.com/problems/distinct-subsequences/

import java.util.Arrays;


public class DistinctSubsequence {
    // MEMOIZATION
    int count(String s, String t, int i, int j, int[][] dp) {
        if (j < 0) {
            return 1;
        }
        if (i < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int p = 0;
        if (s.charAt(i) == t.charAt(j)) {
            p = count(s, t, i - 1, j - 1, dp);
        }
        int n = count(s, t, i - 1, j, dp);
        dp[i][j] = p + n;
        return dp[i][j];
    }

    public int numDistinct1(String s, String t) {
        int dp[][] = new int[s.length()][t.length()];
        for (int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        return count(s, t, s.length() - 1, t.length() - 1, dp);
    }

    // TABULATION
    public int numDistinct(String s, String t) {
        int dp[][] = new int[s.length() + 1][t.length() + 1];
        for (int i = 0; i < dp.length; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= t.length(); j++) {
                int p = 0;
                if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    p = dp[i - 1][j - 1];
                }
                int n = dp[i - 1][j];
                dp[i][j] = (p + n);
            }
        }

        return dp[s.length()][t.length()];
    }

    // SPACE OPTIMIZED
    public int numDistinct2(String s, String t) {
        int dp[] = new int[t.length() + 1];
        dp[0] = 1;
        for (int i = 1; i <= s.length(); i++) {
            int temp[] = new int[t.length() + 1];
            temp[0] = 1;
            for (int j = 1; j <= t.length(); j++) {
                int p = 0;
                if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    p = dp[j - 1];
                }
                int n = dp[j];
                temp[j] = (p + n);
            }
            dp = temp;
        }

        return dp[t.length()];
    }
}
