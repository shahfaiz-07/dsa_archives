// https://leetcode.com/problems/balanced-binary-tree/

public class Balanced {
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
    int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (root.right == null && root.left == null) {
            return 1;
        }
        int x = maxDepth(root.left);
        if (x == -1) {
            return -1;
        }
        int y = maxDepth(root.right);
        if (y == -1) {
            return -1;
        }
        if (Math.abs(x - y) > 1) {
            return -1;
        }
        return 1 + Math.max(x, y);
    }

    public boolean isBalanced(TreeNode root) {
        return maxDepth(root) != -1;
    }
}
