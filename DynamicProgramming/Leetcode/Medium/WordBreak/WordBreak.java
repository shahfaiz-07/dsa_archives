// https://leetcode.com/problems/word-break/
import java.util.Arrays;
import java.util.List;

public class WordBreak {
    boolean partition(String s, int index, List<String> wordDict, int[] dp) {
        if(index == -1) {
            return true;
        }
        if(dp[index] != -1) {
            return dp[index] == 1;
        }
        String str = "";
        for(int i=index; i>=0; i--) {
            str = s.charAt(i) + str;
            if(wordDict.contains(str) && partition(s, i-1, wordDict, dp)) {
                dp[index] = 1;
                return true;
            }
        }
        dp[index] = 0;
        return false;
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        int []dp = new int[s.length()];
        Arrays.fill(dp, -1);
        return partition(s, s.length() - 1, wordDict, dp);
    }
}
