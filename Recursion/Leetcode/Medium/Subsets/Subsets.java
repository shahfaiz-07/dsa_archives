// https://leetcode.com/problems/subsets/description/
import java.util.ArrayList;
import java.util.List;

public class Subsets {
    static void generate(int[] nums, int index, List<Integer> seq, List<List<Integer>> combo) {
        if (index == nums.length) {
            combo.add(new ArrayList<>(seq));
            return;
        }
        generate(nums, index + 1, seq, combo);
        seq.add(nums[index]);
        generate(nums, index + 1, seq, combo);
        seq.remove((int) (seq.size() - 1));
    }

    static List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> seq = new ArrayList<>();
        generate(nums, 0, seq, ans);
        return ans;
    }

    public static void main(String[] args) {
        List<List<Integer>> lists = subsets(new int[]{1,2,3});
        System.out.println(lists);
    }
}
