// https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1

import java.util.ArrayDeque;
import java.util.Deque;

public class PostfixtoPrefix {
    static String postToPre(String post_exp) {
        // code here
        Deque<StringBuilder> st = new ArrayDeque<>();
        for(int i=0; i<post_exp.length(); i++) {
            char ch = post_exp.charAt(i);
            if(Character.isLetterOrDigit(ch)) {
                st.push(new StringBuilder().append(ch));
            } else {
                StringBuilder right = st.pop();
                StringBuilder left = st.pop();
                StringBuilder exp = new StringBuilder();
                exp.append(ch).append(left).append(right);
                st.push(exp);
            }
        }
        return st.peek().toString();
    }
}
