// https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1

import java.util.ArrayDeque;
import java.util.Deque;

public class PrefixtoInfix {
    static String preToInfix(String pre_exp) {
        // code here
        Deque<StringBuilder> st = new ArrayDeque<>();
        for(int i=pre_exp.length() - 1; i>=0; i--) {
            char ch = pre_exp.charAt(i);
            if(Character.isLetterOrDigit(ch)) {
                st.push(new StringBuilder().append(ch));
            } else {
                StringBuilder first = st.pop();
                StringBuilder second = st.pop();
                StringBuilder exp = new StringBuilder();
                exp.append("(").append(first).append(ch).append(second).append(")");
                st.push(exp);
            }
        }
        StringBuilder ans = st.peek();
        return ans.toString();
    }
}
