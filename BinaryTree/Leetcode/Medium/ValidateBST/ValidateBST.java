// https://leetcode.com/problems/validate-binary-search-tree/

public class ValidateBST {
    public class TreeNode {

        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    boolean validate(TreeNode root, long minVal, long maxVal) {
        if (root == null) {
            return true;
        }

        return root.val > minVal && root.val < maxVal
                && validate(root.left, minVal, root.val)
                && validate(root.right, root.val, maxVal);
    }

    public boolean isValidBST(TreeNode root) {
        return validate(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}
