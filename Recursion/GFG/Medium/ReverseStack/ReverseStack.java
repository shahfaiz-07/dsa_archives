// https://www.geeksforgeeks.org/problems/sort-a-stack/
import java.util.Stack;

public class ReverseStack {
    static void endInsert(Stack<Integer> s, int x) {
        if(s.isEmpty()) {
            s.push(x);
            return;
        }
        int y = s.pop();
        endInsert(s, x);
        s.push(y);
    }
    static void reverse(Stack<Integer> s) {
        if(s.isEmpty()) {
            return;
        }
        int x = s.pop();
        reverse(s);
        endInsert(s, x);
    }
    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);
        st.push(6);
        System.out.println(st.toString());
        reverse(st);
        System.out.println(st.toString());
    }
}
