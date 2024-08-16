// https://www.geeksforgeeks.org/problems/find-length-of-loop/1
class Node {

    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}
public class NodesInLoop {
    public int countNodesinLoop(Node head) {
        // Add your code here.
        if (head == null) {
            return 0;
        }
        Node slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow.next;
                    fast = fast.next;
                }
                int count = 0;
                do {
                    fast = fast.next;
                    count++;
                } while (fast != slow);
                return count;
            }
        }
        return 0;
    }
}
