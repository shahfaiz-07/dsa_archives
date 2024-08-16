// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
import java.util.ArrayList;
import java.util.List;

public class LetterCombinationsOfPhone {
    static void getCombos(String digits, List<String> combos, String seq, int index, String[] charMap) {
        if(seq.length() == digits.length()) {
            combos.add(seq);
            return;
        }
        for(int i=0; i<charMap[digits.charAt(index) - '0'].length(); i++) {
            getCombos(digits, combos, seq+charMap[digits.charAt(index) - '0'].charAt(i), index+1, charMap);
        }
    }
    public static List<String> letterCombinations(String digits) {
        List<String> list = new ArrayList<>();
        if(digits.length() == 0) {
            return list;
        }
        String[] charMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        getCombos(digits, list, "", 0, charMap);
        return list;
    }
    public static void main(String[] args) {
        System.out.println(letterCombinations("234"));
    }
}
