// https://leetcode.com/problems/subsets-ii/
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Subsets_II {
    static void generate(int []nums, int index, List<Integer> seq, List<List<Integer>> combo) {
        if(index <= nums.length) {
            combo.add(new ArrayList<>(seq));
        }
        for(int i=index; i<nums.length; i++) {
            if(i != index && nums[i] == nums[i-1]) continue;
            seq.add(nums[i]);
            generate(nums, i+1, seq, combo);
            seq.remove(seq.size() - 1);
        }
    }
    public static List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> list = new ArrayList<>();
        List<Integer> seq = new ArrayList<>();
        generate(nums, 0, seq, list);
        return list;
    }
    public static void main(String[] args) {
        int arr[] = {1, 2, 2};
        List<List<Integer>> list = subsetsWithDup(arr);
        System.out.println(list);
    }
}
