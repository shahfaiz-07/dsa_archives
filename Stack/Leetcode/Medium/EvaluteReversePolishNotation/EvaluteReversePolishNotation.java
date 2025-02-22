// https://leetcode.com/problems/evaluate-reverse-polish-notation/

import java.util.ArrayDeque;
import java.util.Deque;

public class EvaluteReversePolishNotation {
    public int evalRPN(String[] tokens) {
        Deque<Integer> nums = new ArrayDeque<>();
        for(int i=0; i<tokens.length; i++) {
            int ch = tokens[i].charAt(0);
            if(tokens[i].length() == 1 && (ch == '+' || ch == '*' || ch == '/' || ch == '-')) {
                int ch2 = nums.poll();
                int ch1 = nums.poll();
                int res = 0;
                switch(ch) {
                    case '+': res = ch1 + ch2;
                    break;
                    case '-': res = ch1 - ch2;
                    break;
                    case '*': res = ch1 * ch2;
                    break;
                    case '/': res = ch1 / ch2;
                    break;
                }
                nums.push(res);
            } else {
                nums.push(Integer.parseInt(tokens[i]));
            }
        }
        return nums.poll();
    }
}
