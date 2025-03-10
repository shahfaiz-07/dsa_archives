// https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

import java.util.ArrayDeque;
import java.util.Deque;

public class InfixtoPostfix {
    public static String infixToPostfix(String s) {
        // Your code here
        Deque<Character> st = new ArrayDeque<>();
        StringBuilder post = new StringBuilder("");
        for(int i=0; i<s.length(); i++) {
            char ch = s.charAt(i);
            if(Character.isLetterOrDigit(ch)) {
                post.append(ch);
            } else if(ch == '(') {
                st.push(ch);
            } else if(ch == ')') {
                while(st.peek() != '(') {
                    post.append(st.pop());
                }
                st.pop();
            } else {
                while(!st.isEmpty() && priority(ch) <= priority(st.peek())) {
                    post.append(st.pop());
                }
                st.push(ch);
            }
        }
        while(!st.isEmpty()) {
            post.append(st.pop());
        }
        return post.toString();
    }
    static int priority(char ch) {
        switch(ch) {
            case '^': return 2;
            case '*': case '/': return 1;
            case '+': case '-': return 0;
        }
        return -1;
    }
}
