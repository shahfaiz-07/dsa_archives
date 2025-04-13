// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

public class LongestKSubstr {
    public int longestkSubstr(String s, int k) {
        // code here
        int l = 0, r = 0, ans = -1;
        int[] hash = new int[26];
        while (r < s.length()) {
            hash[s.charAt(r) - 'a']++;
            if (hash[s.charAt(r) - 'a'] == 1) {
                k--;
            }
            while (k == -1) {
                hash[s.charAt(l) - 'a']--;
                if (hash[s.charAt(l) - 'a'] == 0) {
                    k++;
                }
                l++;
            }
            if (k == 0) {
                ans = Math.max(ans, r - l + 1);
            }
            r++;
        }
        return ans;
    }
}
