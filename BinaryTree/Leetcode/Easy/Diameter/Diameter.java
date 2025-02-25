// https://leetcode.com/problems/diameter-of-binary-tree/

public class Diameter {
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
    public int diameterOfBinaryTree(TreeNode root) {
        int[] d = {0};
        calc(root, d);
        return d[0];
    }

    private int calc(TreeNode root, int[] d) {
        if (root == null) {
            return 0;
        }

        int l = calc(root.left, d), r = calc(root.right, d);
        d[0] = Math.max(d[0], r + l); // this is diameter

        return 1 + Math.max(l, r); // this is height
    }
}
