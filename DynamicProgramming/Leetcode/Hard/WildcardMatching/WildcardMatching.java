// https://leetcode.com/problems/wildcard-matching
import java.util.Arrays;

public class WildcardMatching {
    // MEMOIZATION
    boolean matched(String s, String p, int i, int j, int[][] dp) {
        if (i < 0 && j < 0) {
            return true;
        }
        if (j < 0) {
            return false;
        }
        if (i < 0) {
            while (j >= 0 && p.charAt(j) == '*') {
                j--;
            }
            return j == -1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j] == 1;
        }
        char ch1 = s.charAt(i), ch2 = p.charAt(j);
        if (ch2 != '*') {
            if (ch2 == '?') {
                dp[i][j] = matched(s, p, i - 1, j - 1, dp) ? 1 : 0;
            } else {
                dp[i][j] = (ch1 == ch2 && matched(s, p, i - 1, j - 1, dp)) ? 1 : 0;
            }
        } else {
            dp[i][j] = (matched(s, p, i - 1, j, dp) || matched(s, p, i, j - 1, dp)) ? 1 : 0;
        }
        return dp[i][j] == 1;
    }

    public boolean isMatch1(String s, String p) {
        int[][] dp = new int[s.length()][p.length()];
        for (int i = 0; i < dp.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        return matched(s, p, s.length() - 1, p.length() - 1, dp);
    }
    // TABULATION
    public boolean isMatch(String s, String p) {
        boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
        dp[0][0] = true;
        for (int i = 1; i <= p.length() && p.charAt(i - 1) == '*'; i++) {
            dp[0][i] = true;
        }
        for (int i = 1; i <= s.length(); i++) {
            for (int j = 1; j <= p.length(); j++) {
                char ch1 = s.charAt(i - 1), ch2 = p.charAt(j - 1);
                if (ch2 != '*') {
                    if (ch2 == '?') {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = ch1 == ch2 && dp[i - 1][j - 1];
                    }
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        return dp[s.length()][p.length()];
    }
}