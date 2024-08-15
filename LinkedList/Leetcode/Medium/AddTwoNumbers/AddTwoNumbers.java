
import java.util.ArrayDeque;
import java.util.Deque;

class ListNode {

    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val,
            ListNode next) {
        this.val = val;
        this.next = next;
    }
}

public class AddTwoNumbers {

    // without reversing the lists - using stacks
    static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Deque<ListNode> st1 = new ArrayDeque<>();
        Deque<ListNode> st2 = new ArrayDeque<>();
        while (l1 != null) {
            st1.push(l1);
            l1 = l1.next;
        }
        while (l2 != null) {
            st2.push(l2);
            l2 = l2.next;
        }
        int carry = 0;
        ListNode node = st1.peek();
        while (!st1.isEmpty() && !st2.isEmpty()) {
            node = st1.peek();
            node.val += st2.peek().val + carry;
            carry = (node.val) > 9 ? 1 : 0;
            node.val = node.val % 10;
            st1.pop();
            st2.pop();
        }
        if (!st1.isEmpty()) {
            while (!st1.isEmpty()) {
                node = st1.peek();
                node.val += carry;
                carry = (node.val) > 9 ? 1 : 0;
                node.val = node.val % 10;
                st1.pop();
            }
        } else {
            while (!st2.isEmpty()) {
                st2.peek().next = node;
                node = st2.peek();
                node.val += carry;
                carry = (node.val) > 9 ? 1 : 0;
                node.val = node.val % 10;
                st2.pop();
            }
        }
        ListNode headNode = node;
        if (carry == 1) {
            headNode = new ListNode(1);
            headNode.next = node;
        }
        return headNode;
    }
}
