// https://leetcode.com/problems/combination-sum-iii/

import java.util.ArrayList;
import java.util.List;

public class Combination_Sum_III {
    static void generate(int k, int n, int curr, List<Integer> seq, List<List<Integer>> combo) {
        if(n <= 0 || curr >= 10 || k <= 0) {
            if(n == 0 && k == 0) {
                combo.add(new ArrayList<>(seq));
            }
            return;
        }
        if(n >= curr) {
            seq.add(curr);
            generate(k-1, n-curr, curr+1, seq, combo);
            seq.remove(seq.size() - 1);
            generate(k, n, curr+1, seq, combo);
        }
    }
    public static List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> list = new ArrayList<>();
        List<Integer> seq = new ArrayList<>();
        generate(k, n, 1, seq, list);
        return list;
    }

    public static void main(String[] args) {
        System.out.println(combinationSum3(3, 7));
    }
}
