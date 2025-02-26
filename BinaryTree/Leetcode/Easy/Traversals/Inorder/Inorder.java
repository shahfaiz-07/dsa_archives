// https://leetcode.com/problems/binary-tree-inorder-traversal/description/

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class Inorder {
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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if(root == null) return ans;

        Deque<TreeNode> st = new ArrayDeque<>();
        TreeNode curr = root;
        
        while(curr != null || !st.isEmpty()) {
            while(curr != null) {
                st.push(curr);
                curr = curr.left;
            }

            curr = st.pop();
            ans.add(curr.val);
            curr = curr.right;
        }

        return ans;
    }
}
