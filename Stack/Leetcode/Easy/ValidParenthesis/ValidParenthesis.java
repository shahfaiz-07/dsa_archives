// https://leetcode.com/problems/valid-parentheses/

import java.util.Stack;

public class ValidParenthesis {
    public boolean isValid(String s) {
        if(s.length()%2 != 0) return false;
        Stack<Integer> st = new Stack<>();
        for(int i=0; i<s.length(); i++) {
            char ch = s.charAt(i);
            if(ch == '(' || ch == '{' || ch == '[') {
                int x = ch;
                st.push(x);
            } else {
                if(st.isEmpty()) return false;
                int top = st.pop();
                if(top < ch - 2 || top > ch) {
                    return false;
                }
            }
        }
        return st.isEmpty();
    }
}
