import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Stack;
public class LearnStack {
    public static void main(String[] args) {
        // NOTE : It is more efficient to implement the stack using 'Deque' interface and 'ArrayDeque' class - 'README.Stack.md' file
        Stack<String> st = new Stack<>();

        // # push
        st.push("Hello");
        st.push("World");
        st.push("How");
        st.push("This");
        System.out.println(st);

        // # pop
        st.pop();
        System.out.println(st);

        // # peek - top element
        System.out.println(st.peek());
        

        Deque<String> stack = new ArrayDeque<>();
        stack.push("1");
        stack.push("2");
        stack.push("3");
        stack.push("4");
        stack.push("5");
        System.out.println(stack);

        stack.pop();
        System.out.println(stack);

        System.out.println(stack.peek());
    }
}
