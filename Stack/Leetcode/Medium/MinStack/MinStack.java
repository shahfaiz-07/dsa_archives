// https://leetcode.com/problems/min-stack/

import java.util.ArrayDeque;
import java.util.Deque;

public class MinStack {
    class Pair {
        int ele, min;
        Pair(int ele, int min) {
            this.ele = ele;
            this.min = min;
        }
    }
    Deque<Pair> stack;
    public MinStack() {
        stack = new ArrayDeque<>();
    }
    
    public void push(int val) {
        int min = stack.isEmpty() || stack.peek().min > val ? val : stack.peek().min;
        stack.push(new Pair(val, min));
    }
    
    public void pop() {
        stack.pop();
    }
    
    public int top() {
        return stack.peek().ele;
    }
    
    public int getMin() {
        return stack.peek().min;
    }
}
