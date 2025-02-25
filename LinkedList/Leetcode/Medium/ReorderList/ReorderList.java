// https://leetcode.com/problems/reorder-list/

import java.util.Stack;

public class ReorderList {

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

    public void reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }
        Stack<ListNode> stack = new Stack<>();
        ListNode slow = head, fast = head.next;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        slow = slow.next;

        while (slow != null) {
            stack.push(slow);
            slow = slow.next;
        }

        ListNode curr = head, prev = null;

        while (!stack.isEmpty() && curr != null) {
            ListNode next = curr.next;
            curr.next = stack.pop();
            curr = curr.next;
            curr.next = next;
            prev = curr;
            curr = next;
        }
        if (fast == null) {
            curr.next = null;
        } else {
            prev.next = null;
        }
    }
}
