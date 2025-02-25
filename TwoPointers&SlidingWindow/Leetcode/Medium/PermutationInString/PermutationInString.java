// https://leetcode.com/problems/permutation-in-string/

public class PermutationInString {
    public boolean checkInclusion(String s1, String s2) {
        if (s2.length() < s1.length()) {
            return false;
        }
        int[] hashMap = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            hashMap[s1.charAt(i) - 'a']++;
        }
        int l = 0, r = 0;
        // fix window size
        int s2Map[] = new int[26];
        while (r < s2.length()) {
            s2Map[s2.charAt(r) - 'a']++;
            if ((r - l + 1) < s1.length()) {
                r++;
            } else {
                if (Arrays.equals(hashMap, s2Map)) {
                    return true;
                }
                s2Map[s2.charAt(l) - 'a']--;
                l++;
                r++;
            }
        }

        return false;
    }
}
