// https://leetcode.com/problems/sum-root-to-leaf-numbers/
public class SumRootToLeafNumber {
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
    private void sumNodes(TreeNode root, int num, int[] sum) {
        if (root != null) {
            num = num * 10 + root.val;
            if (root.left == null && root.right == null) {
                sum[0] += num;
            }
            sumNodes(root.left, num, sum);
            sumNodes(root.right, num, sum);
        }
    }

    public int sumNumbers(TreeNode root) {
        int[] ans = new int[1];
        sumNodes(root, 0, ans);
        return ans[0];
    }
}
