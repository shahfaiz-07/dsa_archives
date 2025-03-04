// 

import java.util.Arrays;

public class DecodeWays {
    // MEMOIZATION
    int backtrack(String s, int i, int[] dp) {
        if(i < 0) return 1;
        if(dp[i] != -1) {
            return dp[i];
        }

        if(s.charAt(i) == '0') {
            if(i == 0 || s.charAt(i-1) > '2' || s.charAt(i - 1) == '0') {
                dp[i] = 0;
                return 0;
            }
            dp[i] = backtrack(s, i-2, dp);
            return dp[i];    
        }

        // as a single unit
        int x = backtrack(s, i-1, dp);
        int y = 0;
        // as a pair only if
        if(i != 0 && s.charAt(i - 1) != '0') {
            int num = (s.charAt(i-1) - '0') * 10 + (s.charAt(i) - '0');
            if(num <= 26) {
                y = backtrack(s, i-2, dp);
            }
        }
        dp[i] = x + y;
        return dp[i];
    }
    public int numDecodings(String s) {
        int[] dp = new int[s.length()];
        Arrays.fill(dp, -1);
        return backtrack(s, s.length() - 1, dp);
    }
    // TABULATION
    public int numDecodings(String s) {
        if (s.charAt(0) == '0') {
            return 0;
        }
        if (s.length() == 1) {
            return 1;
        }
        int[] dp = new int[s.length()];
        dp[0] = 1;
        if (s.charAt(1) == '0') {
            if (s.charAt(0) <= '2') {
                dp[1] = 1; 
            }else {
                return 0;
            }
        } else {
            int initial = (s.charAt(0) - '0') * 10 + (s.charAt(1) - '0');
            if (initial <= 26) {
                dp[1] = 2;
            } else {
                dp[1] = 1;
            }
        }
        for (int i = 2; i < s.length(); i++) {
            if (s.charAt(i) == '0') {
                if (i == 0 || s.charAt(i - 1) > '2' || s.charAt(i - 1) == '0') {
                    return 0;
                }
                dp[i] = dp[i - 2];
            } else {
                // as a single unit
                int x = dp[i - 1];
                int y = 0;
                // as a pair only if
                if (i != 0 && s.charAt(i - 1) != '0') {
                    int num = (s.charAt(i - 1) - '0') * 10 + (s.charAt(i) - '0');
                    if (num <= 26) {
                        y = dp[i - 2];
                    }
                }
                dp[i] = x + y;
            }
        }
        return dp[s.length() - 1];
    }
    // SPACE-OPTIMIZED
    public int numDecodings(String s) {
        if (s.charAt(0) == '0') {
            return 0;
        }
        if (s.length() == 1) {
            return 1;
        }
        int prev2 = 1, prev1 = 0;
        if (s.charAt(1) == '0') {
            if (s.charAt(0) <= '2') {
                prev1 = 1; 
            }else {
                return 0;
            }
        } else {
            int initial = (s.charAt(0) - '0') * 10 + (s.charAt(1) - '0');
            if (initial <= 26) {
                prev1 = 2;
            } else {
                prev1 = 1;
            }
        }
        for (int i = 2; i < s.length(); i++) {
            int curr = 0;
            if (s.charAt(i) == '0') {
                if (i == 0 || s.charAt(i - 1) > '2' || s.charAt(i - 1) == '0') {
                    return 0;
                }
                curr = prev2;
            } else {
                // as a single unit
                int x = prev1;
                int y = 0;
                // as a pair only if
                if (i != 0 && s.charAt(i - 1) != '0') {
                    int num = (s.charAt(i - 1) - '0') * 10 + (s.charAt(i) - '0');
                    if (num <= 26) {
                        y = prev2;
                    }
                }
                curr = x + y;
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
}
