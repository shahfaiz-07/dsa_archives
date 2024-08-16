// https://leetcode.com/problems/combination-sum-ii/
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CombinationSum_II {
    void generate(int[] candidates, int target, int start, List<Integer> seq, List<List<Integer>> combo) {
        if (start == candidates.length || target <= 0) {
            if (target == 0) {
                combo.add(new ArrayList<>(seq));
            }
            return;
        }
        for (int i = start; i < candidates.length; i++) {
            if (i != start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (target < candidates[i]) {
                break;
            }
            seq.add(candidates[i]);
            generate(candidates, target - candidates[i], i + 1, seq, combo);
            seq.remove(seq.size() - 1);
        }
    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> list = new ArrayList<>();
        List<Integer> seq = new ArrayList<>();
        generate(candidates, target, 0, seq, list);
        return list;
    }
    public static void main(String[] args) {
        
    }
}
