// https://leetcode.com/problems/kth-smallest-element-in-a-bst

import java.util.ArrayDeque;
import java.util.Deque;

public class KthSmallest {
    public class TreeNode {

        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public int kthSmallest(TreeNode root, int k) {
        Deque<TreeNode> stack = new ArrayDeque<>();
        TreeNode curr = root, lastCurr = root;
        int i = 0;
        while(i < k) {
            while(curr != null) {
                stack.push(curr);
                curr = curr.left;
            }

            curr = stack.pop();
            lastCurr = curr;
            curr = curr.right;
            i++;
        }
        return lastCurr.val;
    }
}
