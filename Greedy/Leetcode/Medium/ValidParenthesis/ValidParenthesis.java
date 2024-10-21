// https://leetcode.com/problems/valid-parenthesis-string/
public class ValidParenthesis {
    public boolean checkValidString(String s) {
        int min = 0, max = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch == '(') {
                min++;
                max++;
            } else if (ch == ')') {
                min--;
                max--;
            } else {
                min--;
                max++;
            }
            min = min < 0 ? 0 : min;
            if (max < 0) {
                return false;
            }
        }
        return min == 0;
    }
}
