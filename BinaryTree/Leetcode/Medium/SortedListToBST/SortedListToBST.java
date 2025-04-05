// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
class ListNode {

    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }

}

class TreeNode {

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

public class SortedListToBST {
    TreeNode convertToBST(ListNode head, ListNode end) {
        if (head == null || head == end) {
            return null;
        }
        ListNode slow = head, fast = head;
        while (fast != end && fast.next != end) {
            slow = slow.next;
            fast = fast.next.next;
        }
        TreeNode root = new TreeNode(slow.val);
        root.left = convertToBST(head, slow);
        root.right = convertToBST(slow.next, end);
        return root;
    }

    public TreeNode sortedListToBST(ListNode head) {
        return convertToBST(head, null);
    }
}
