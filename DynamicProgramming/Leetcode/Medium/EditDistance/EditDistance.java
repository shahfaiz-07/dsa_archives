// https://leetcode.com/problems/edit-distance/
import java.util.Arrays;

public class EditDistance {

    // MEMOIZATION
    int minimize(String word1, String word2, int i, int j, int[][] dp) {
        if(i < 0 && j < 0) return 0;
        if(j < 0) {
            return i+1;
        }
        if(i < 0) {
            return j+1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(word1.charAt(i) == word2.charAt(j)) {
            dp[i][j] = minimize(word1, word2, i-1, j-1, dp);
            return dp[i][j];
        }

        // insert
        int m1 = minimize(word1, word2, i, j-1, dp);

        // replace
        int m2 = minimize(word1, word2, i-1, j-1, dp);

        // delete
        int m3 = minimize(word1, word2, i-1, j, dp);
        dp[i][j] = Math.min(m1, Math.min(m2, m3)) + 1;
        return dp[i][j];
    }
    public int minDistance1(String word1, String word2) {
        int [][] dp = new int[word1.length()][word2.length()];
        for(int i=0; i<dp.length; i++) {
            Arrays.fill(dp[i], -1);
        }
        return minimize(word1, word2, word1.length()-1, word2.length()-1, dp);
    }

    // TABULATION
    public int minDistance2(String word1, String word2) {
        int[][] dp = new int[word1.length() + 1][word2.length() + 1];
        for (int i = 1; i < dp[0].length; i++) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= word1.length(); i++) {
            dp[i][0] = i;
            for (int j = 1; j <= word2.length(); j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // insert
                    int m1 = dp[i][j - 1];

                    // replace
                    int m2 = dp[i - 1][j - 1];

                    // delete
                    int m3 = dp[i - 1][j];
                    dp[i][j] = Math.min(m1, Math.min(m2, m3)) + 1;
                }
            }
        }
        return dp[word1.length()][word2.length()];
    }

    // SPACE OPTIMIZED
    public int minDistance(String word1, String word2) {
        int[] dp = new int[word2.length() + 1];
        for (int i = 1; i < dp.length; i++) {
            dp[i] = i;
        }

        for (int i = 1; i <= word1.length(); i++) {
            int[] temp = new int[word2.length() + 1];
            temp[0] = i;
            for (int j = 1; j <= word2.length(); j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    temp[j] = dp[j - 1];
                } else {
                    // insert
                    int m1 = temp[j - 1];

                    // replace
                    int m2 = dp[j - 1];

                    // delete
                    int m3 = dp[j];
                    temp[j] = Math.min(m1, Math.min(m2, m3)) + 1;
                }
            }
            dp = temp;
        }
        return dp[word2.length()];
    }
}