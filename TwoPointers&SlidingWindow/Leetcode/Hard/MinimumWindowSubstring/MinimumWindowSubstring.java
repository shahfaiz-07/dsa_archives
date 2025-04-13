import java.util.HashMap;
import java.util.Map;
// https://leetcode.com/problems/minimum-window-substring/
public class MinimumWindowSubstring {

    public String minWindow(String s, String t) {
        Map<Character, Integer> mp = new HashMap<>();
        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            mp.compute(c, (k, v) -> v == null ? 1 : v + 1);
        }
        int l = 0, r = 0, start = -1, len = Integer.MAX_VALUE, c = 0;
        while (r < s.length()) {
            if (mp.compute(s.charAt(r), (k, v) -> v == null ? -1 : v - 1) >= 0) {
                c++;
            }
            while (c == t.length()) {
                if (r - l + 1 <= len) {
                    start = l;
                    len = r - l + 1;
                }
                if (mp.compute(s.charAt(l), (k, v) -> v + 1) == 1) {
                    c--;
                }
                l++;
            }
            r++;
        }
        return start == -1 ? "" : s.substring(start, start + len);
    }
}