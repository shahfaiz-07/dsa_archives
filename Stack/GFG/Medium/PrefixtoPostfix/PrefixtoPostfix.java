// https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1

import java.util.ArrayDeque;
import java.util.Deque;

public class PrefixtoPostfix {
    static String preToPost(String pre_exp) {
        // code here
        Deque<StringBuilder> st = new ArrayDeque<>();
        for(int i=pre_exp.length()-1; i>=0; i--) {
            char ch = pre_exp.charAt(i);
            if(Character.isLetterOrDigit(ch)) {
                st.push(new StringBuilder().append(ch));
            } else {
                StringBuilder left = st.pop();
                StringBuilder right = st.pop();
                StringBuilder exp = new StringBuilder();
                exp.append(left).append(right).append(ch);
                st.push(exp);
            }
        }
        return st.pop().toString();
    }
}
