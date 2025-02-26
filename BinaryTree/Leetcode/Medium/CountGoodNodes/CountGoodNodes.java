// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

public class CountGoodNodes {
    public class TreeNode {

        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }
    void myGoodNodes(TreeNode root, int[] c, int currMax) {
        if (root == null) {
            return;
        }
        if (root.val >= currMax) {
            c[0]++;
        }

        currMax = Math.max(currMax, root.val);

        myGoodNodes(root.left, c, currMax);
        myGoodNodes(root.right, c, currMax);
    }

    public int goodNodes(TreeNode root) {
        int c[] = {0};
        myGoodNodes(root, c, Integer.MIN_VALUE);
        return c[0];
    }
}
