// https://leetcode.com/problems/string-to-integer-atoi/description/
public class Atoi {
    static long parser(String s, int i, long num, boolean isNeg) {
        if (i == s.length() || s.charAt(i) < '0' || s.charAt(i) > '9') {
            return isNeg ? -num : num;
        } else if (isNeg && -(num * 10 + (s.charAt(i) - '0')) <= Integer.MIN_VALUE) {
            return Integer.MIN_VALUE;
        } else if (!isNeg && (num * 10 + (s.charAt(i) - '0')) >= Integer.MAX_VALUE) {
            return Integer.MAX_VALUE;
        }
        num = num * 10 + (s.charAt(i) - '0');
        return parser(s, i + 1, num, isNeg);
    }

    static int myAtoi(String s) {
        boolean isNeg = false;
        int index = 0;
        if (s.equals("")) {
            return 0;
        }
        while (index < s.length() && s.charAt(index) == ' ') {
            index++;
        }
        if (index < s.length() && s.charAt(index) == '-') {
            isNeg = true;
            index++;
        } else if (index < s.length() && s.charAt(index) == '+') {
            index++;
        }
        while (index < s.length() && s.charAt(index) == '0') {
            index++;
        }
        if (index < s.length() && s.charAt(index) >= '0' && s.charAt(index) <= '9') {
            return (int) parser(s, index, 0, isNeg);
        }
        return 0;
    }
    public static void main(String[] args) {
        System.out.println(myAtoi("128712846928374"));
    }
}
