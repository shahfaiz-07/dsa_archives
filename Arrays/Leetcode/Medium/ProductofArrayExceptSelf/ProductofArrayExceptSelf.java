// https://leetcode.com/problems/product-of-array-except-self/

public class ProductofArrayExceptSelf {
    public int[] productExceptSelf(int[] nums) {
        int l = nums.length;
        int prefixProd[] = new int[l];
        int suffixProd[] = new int[l];
        prefixProd[0] = nums[0];
        suffixProd[l - 1] = nums[l - 1];
        for (int i = 1; i < l - 1; i++) {
            prefixProd[i] = nums[i] * prefixProd[i - 1];
            suffixProd[l - i - 1] = nums[l - i - 1] * suffixProd[l - i];
        }
        int ans[] = new int[l];

        ans[0] = suffixProd[1];
        ans[l - 1] = prefixProd[l - 2];

        for (int i = 1; i < l - 1; i++) {
            ans[i] = prefixProd[i - 1] * suffixProd[i + 1];
        }
        return ans;
    }
}
