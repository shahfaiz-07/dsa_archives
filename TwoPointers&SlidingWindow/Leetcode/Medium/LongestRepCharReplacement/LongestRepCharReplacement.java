// https://leetcode.com/problems/longest-repeating-character-replacement/

public class LongestRepCharReplacement {

    public int characterReplacement(String s, int k) {
        int hashMap[] = new int[26];

        int l = 0, r = 0, maxLen = 0, maxFreq = 0;
        while (r < s.length()) {
            hashMap[s.charAt(r) - 'A']++;
            maxFreq = Math.max(maxFreq, hashMap[s.charAt(r) - 'A']);
            // window_size - maxFreq character gives length of changed character
            if ((r - l + 1) - maxFreq > k) {
                // more than k letters are to be flipped
                hashMap[s.charAt(l) - 'A']--;
                l++;
            } else {
                maxLen = Math.max(r - l + 1, maxLen);
            }
            r++;
        }
        return maxLen;
    }
}