// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
public class CheckRotatedSortedArray {
    static boolean check(int[] nums) {
        int breakPoint = 0;
        for(int i=0; i<nums.length-1 && breakPoint <= 1; i++) {
            if(nums[i] > nums[i+1]) {
                breakPoint++;
            }
        }
        if(breakPoint == 1) {
            return nums[0] >= nums[nums.length - 1]; 
        }
        return breakPoint == 0;
    }
    public static void main(String[] args) {
        int arr[] = {2,1,3,4};
        System.out.println(check(arr));
    }
}