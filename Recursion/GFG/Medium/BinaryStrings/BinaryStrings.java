// https://www.geeksforgeeks.org/problems/generate-all-binary-strings/
import java.util.ArrayList;
import java.util.List;

public class BinaryStrings {
    static void generate(int n, String s, List<String> combo) {
        if (s.length() == n) {
            combo.add(s);
            return;
        }
        generate(n, s + "0", combo);
        if (s.equals("") || s.charAt(s.length() - 1) != '1') {
            generate(n, s + "1", combo);
        }
    }

    public static List<String> generateBinaryStrings(int n) {
        List<String> ans = new ArrayList<>();
        generate(n, "", ans);
        return ans;
    }

    public static void main(String[] args) {
        List<String> str = generateBinaryStrings(5);
        System.out.println(str.toString());
    }
}
