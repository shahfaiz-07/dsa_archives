// https://leetcode.com/problems/remove-k-digits/

import java.util.ArrayDeque;
import java.util.Deque;


public class RemoveKDigits {

    public String removeKdigits(String num, int k) {
        Deque<Character> st = new ArrayDeque<>();
        for (int i = 0; i < num.length(); i++) {
            char ch = num.charAt(i);
            while (!st.isEmpty() && k > 0 && st.peek() > ch) {
                st.pop();
                k--;
            }
            if (!st.isEmpty() || ch != '0') {
                st.push(ch);
            }
        }
        while (!st.isEmpty() && k > 0) {
            st.pop();
            k--;
        }
        StringBuilder ans = new StringBuilder();
        for (char c : st) {
            ans.append(c);
        }

        return ans.length() == 0 ? "0" : ans.reverse().toString();
    }
}