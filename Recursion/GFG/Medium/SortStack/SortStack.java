// https://www.geeksforgeeks.org/problems/sort-a-stack/
import java.util.Stack;

public class SortStack {
    static void insert(Stack<Integer> s, int x) {
        if (s.isEmpty() || s.peek() <= x) {
            s.push(x);
            return;
        }
        int y = s.pop();
        insert(s, x);
        s.push(y);
    }
    // for GFG you need to return the stack
    static void sortStack(Stack<Integer> s) {
        if (s.isEmpty()) {
            return;
        }
        int x = s.pop();
        sortStack(s);
        insert(s, x);
    }

    public static void main(String[] args) {
        Stack<Integer> st = new Stack<>();
        st.push(6);
        st.push(2);
        st.push(33);
        st.push(42);
        st.push(15);
        st.push(6);
        st.push(70);
        System.out.println(st.toString());
        sortStack(st);
        System.out.println(st.toString());
    }
}
