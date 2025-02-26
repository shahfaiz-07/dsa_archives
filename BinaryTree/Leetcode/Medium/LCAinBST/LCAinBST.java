// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

public class LCAinBST {
    public class TreeNode {

        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || p == null || q == null) {
            return null;
        }

        if (root.val == p.val || root.val == q.val
                || (p.val < root.val && q.val > root.val)
                || (q.val < root.val && p.val > root.val)) {
            return root;
        }

        if (Math.max(p.val, q.val) < root.val) {
            return lowestCommonAncestor(root.left, p, q);
        }
        return lowestCommonAncestor(root.right, p, q);
    }
}
