// https://leetcode.com/problems/longest-substring-without-repeating-characters/

public class LongestSubstrWithoutRepChar {
    public int lengthOfLongestSubstring(String s) {
        boolean[] hashSet = new boolean[256];
        int l = 0, r = 0;
        int maxLen = 0;
        while (r < s.length()) {
            if (hashSet[s.charAt(r)]) {
                hashSet[s.charAt(l)] = false;
                l++;
            } else {
                hashSet[s.charAt(r)] = true;
                if (r - l + 1 > maxLen) {
                    maxLen = Math.max(r - l + 1, maxLen);
                }
                r++;
            }
        }
        return maxLen;
    }
}
