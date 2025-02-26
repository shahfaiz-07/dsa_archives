// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

import java.util.HashMap;
import java.util.Map;

public class TreeFromInAndPreOrder {
    int preInd = 0;
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
    TreeNode construct(int[] preorder, Map<Integer, Integer> inorder, int inStart, int inEnd) {
        if(preInd >= preorder.length || inStart > inEnd) {
            return null;
        }

        TreeNode node = new TreeNode(preorder[preInd]);

        int searchInd = inorder.get(preorder[preInd]);

        preInd++;

        if(searchInd != -1) {
            node.left = construct(preorder, inorder, inStart, searchInd-1);
            node.right = construct(preorder, inorder, searchInd+1, inEnd);
        }

        return node;
    }
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        Map<Integer, Integer> in = new HashMap<>();
        for(int i=0; i<inorder.length; i++) {
            in.put(inorder[i], i);
        }
        return construct(preorder, in, 0, inorder.length - 1);
    }
}
