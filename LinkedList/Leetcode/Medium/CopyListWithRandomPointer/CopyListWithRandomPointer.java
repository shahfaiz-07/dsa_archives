// https://leetcode.com/problems/copy-list-with-random-pointer/

import java.util.HashMap;
import java.util.Map;

public class CopyListWithRandomPointer {
    class Node {

        int val;
        Node next;
        Node random;

        public Node(int val) {
            this.val = val;
            this.next = null;
            this.random = null;
        }
    }
    public Node copyRandomList(Node head) {
        if(head == null) return null;
        Node newHead = new Node(head.val);
        Map<Node, Node> mp = new HashMap<>();

        Node newPtr = newHead, ptr = head;

        while(ptr != null && ptr.next != null) {
            newPtr.next = new Node(ptr.next.val);
            mp.put(ptr, newPtr);
            newPtr = newPtr.next;
            ptr = ptr.next;
        }
        mp.put(ptr, newPtr);

        newPtr = newHead; ptr = head;

        while(newPtr != null && ptr != null) {
            newPtr.random = mp.get(ptr.random);
            newPtr = newPtr.next;
            ptr = ptr.next;
        }

        return newHead;
    }
}
