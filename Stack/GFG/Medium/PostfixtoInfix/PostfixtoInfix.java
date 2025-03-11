// https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1

import java.util.ArrayDeque;
import java.util.Deque;

public class PostfixtoInfix {
    static String postToInfix(String exp) {
        // code here
        String str = "";
        Deque<String> st = new ArrayDeque<>();
        
        for(int i=0; i<exp.length(); i++) {
            char ch = exp.charAt(i);
            if(Character.isLetterOrDigit(ch)) {
                st.push(""+ch);
            } else {
                String first = st.pop();
                String second = st.pop();
                String brac = "("+second+ch+first+")";
                st.push(brac);
            }
        }
        return st.pop();
    }
}
