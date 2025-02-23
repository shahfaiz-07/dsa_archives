// https://leetcode.com/problems/daily-temperatures/description/

import java.util.ArrayDeque;
import java.util.Deque;

class DailyTemperatures {

    class Pair {
        int val, index;
        Pair(int val, int index) {
            this.val = val;
            this.index = index;
        }
    }
    public int[] dailyTemperatures(int[] temperatures) {
        Deque<Pair> stack = new ArrayDeque<>();
        for(int i=temperatures.length - 1; i>=0; i--) {
            while(!stack.isEmpty() && temperatures[i] >= stack.peek().val) {
                stack.pop();
            }

            int days = stack.isEmpty() ? 0 : stack.peek().index - i;
            stack.push(new Pair(temperatures[i], i));
            temperatures[i] = days;
        }
        return temperatures;
    }
}