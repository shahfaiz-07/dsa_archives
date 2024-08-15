// https://leetcode.com/problems/generate-parentheses/
import java.util.ArrayList;
import java.util.List;

public class GenerateParenthesis {
    static void generate(int n, String str, int left, int right, List<String> combo) {
        if (str.length() == 2 * n) {
            combo.add(str);
            return;
        }
        if (left < n) {
            generate(n, str + "(", left + 1, right, combo);
        }
        if (right < left) {
            generate(n, str + ")", left, right + 1, combo);
        }
    }

    static List<String> generateParenthesis(int n) {
        List<String> v = new ArrayList<>();
        generate(n, "", 0, 0, v);
        return v;
    }
    public static void main(String[] args) {
        List<String> v = generateParenthesis(3);
        System.out.println(v);
    }
}
