// https://leetcode.com/problems/combination-sum/description/
import java.util.ArrayList;
import java.util.List;

public class CombinationSum {
    static void generate(int[] candidates, int target, int index, List<Integer> seq, List<List<Integer>> combo) {
        if (target <= 0 || index == candidates.length) {
            if (target == 0) {
                combo.add(new ArrayList<>(seq));
            }
            return;
        }
        if (candidates[index] <= target) {
            seq.add(candidates[index]);
            generate(candidates, target - candidates[index], index, seq, combo);
            seq.remove(seq.size() - 1);
        }
        generate(candidates, target, index + 1, seq, combo);
    }

    public static List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> list = new ArrayList<>();
        List<Integer> seq = new ArrayList<>();
        generate(candidates, target, 0, seq, list);
        return list;
    }
    public static void main(String[] args) {
        int candidates[] = {2, 3, 6, 7};
        int target = 7;
        System.out.println(combinationSum(candidates, target));
    }
}
