// https://leetcode.com/problems/subsets/

import java.util.ArrayList;
import java.util.List;

public class PowerSet {
    public static List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> allSubs = new ArrayList<>();
        for(int i=0; i < (1 << nums.length); i++) {
            List<Integer> sub = new ArrayList<>();
            for(int j=0; j<nums.length; j++) {
                if(((1 << j) & i) != 0) {
                    sub.add(nums[j]);
                }
            }
            allSubs.add(sub);
        }
        return allSubs;
    }
    public static void main(String[] args) {
        int[] list = {1,2,3};
        System.out.println(subsets(list));
    }
}
