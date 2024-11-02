// https://leetcode.com/problems/merge-k-sorted-lists/

import java.util.PriorityQueue;

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

public class MergeKLists {

    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<>((a, b) -> a.val - b.val);

        for (int i = 0; i < lists.length; i++) {
            if (lists[i] != null) {
                pq.offer(lists[i]);
            }
        }
        if (pq.isEmpty()) {
            return null;
        }
        ListNode head = pq.poll(), ptr = head;
        if (ptr.next != null) {
            pq.offer(ptr.next);
        }
        while (!pq.isEmpty()) {
            ptr.next = pq.poll();
            ptr = ptr.next;
            if (ptr.next != null) {
                pq.offer(ptr.next);
            }
        }

        return head;
    }
}
