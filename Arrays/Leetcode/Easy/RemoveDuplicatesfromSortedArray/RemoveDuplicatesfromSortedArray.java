//https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

public class RemoveDuplicatesfromSortedArray {

    static int removeDuplicates(int[] nums) {
        int l = 0, r = 1;
        while (r < nums.length) {
            if (nums[l] != nums[r]) { // using two pointers only copy the element which is not equal to current element 
                nums[++l] = nums[r];
            }
            r++;
        }
        return l + 1; // l-th element will be the last element
    }

    public static void main(String[] args) {
        int arr[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.err.println("");
        int n = removeDuplicates(arr);
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
