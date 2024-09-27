// https://leetcode.com/problems/palindrome-partitioning/
import java.util.ArrayList;
import java.util.List;

public class PalindromePartition {
    boolean isPalindrome(String str) {
        int i = 0, j = str.length() - 1;
        System.out.println(str);
        while(i < j) {
            if(str.charAt(i) != str.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void partition(String s, int index, List<List<String>> seqs, List<String> seq) {
        if(index == s.length()) {
            seqs.add(new ArrayList<>(seq));
            return;
        }
        String str = "";
        for(int i=index; i<s.length(); i++) {
            str += s.charAt(i);
            if(isPalindrome(str)) {
                seq.add(str);
                partition(s, i+1, seqs, seq);
                seq.remove(seq.size() - 1);
            }
        }
    }
    public List<List<String>> partition(String s) {
        List<List<String>> seqs = new ArrayList<>();
        List<String> seq = new ArrayList<>();
        partition(s, 0, seqs, seq);
        return seqs;
    }
}
