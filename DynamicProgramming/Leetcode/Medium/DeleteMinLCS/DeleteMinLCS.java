// https://leetcode.com/problems/delete-operation-for-two-strings/

import java.util.Arrays;


public class DeleteMinLCS {
    // MEMOIZATION
    int maximize(String text1, String text2, int i, int j, int dp[][]) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (text1.charAt(i) == text2.charAt(j)) {
            dp[i][j] = 1 + maximize(text1, text2, i - 1, j - 1, dp);
            return dp[i][j];
        }
        dp[i][j] = Math.max(maximize(text1, text2, i - 1, j, dp), 
                maximize(text1, text2, i, j - 1, dp));
        return dp[i][j];
    }

    public int minDistance1(String word1, String word2) {
        int n = word1.length(), m = word2.length();
        int dp[][] = new int[n][m];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return n + m - 2 * maximize(word1, word2, n - 1, m - 1, dp);
    }

    // TABULATION
    public int minDistance(String word1, String word2) {
        int n = word1.length(), m = word2.length();
        int dp[][] = new int[n + 1][m + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1.charAt(i - 1) == word2
                        .charAt(j - 1)) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }

            }
        }
        return n + m - 2 * dp[n][m];
    }
}
