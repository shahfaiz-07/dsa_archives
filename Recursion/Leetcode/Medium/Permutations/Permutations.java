// https://leetcode.com/problems/permutations/

import java.util.ArrayList;
import java.util.List;

public class Permutations {
void add(List<List<Integer>> list, int arr[]) {
        List<Integer> temp = new ArrayList<>();
        for(int i=0; i<arr.length; i++) {
            temp.add(arr[i]);
        }
        list.add(temp);
    }
    void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    void recurse(int[] nums, int ind, List<List<Integer>> ans) {
        if(ind == nums.length) {
            add(ans, nums);
            return;
        }
        for(int i=ind; i<nums.length; i++) {
            swap(nums, ind, i);
            recurse(nums, ind + 1, ans);
            swap(nums, ind, i);
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        recurse(nums, 0, ans);
        return ans;
    }
    
}