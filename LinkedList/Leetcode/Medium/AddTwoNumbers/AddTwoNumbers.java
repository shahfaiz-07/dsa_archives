// https://leetcode.com/problems/add-two-numbers/

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

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode ptr1 = l1, ptrTail = null, ptr2 = l2;

        while (ptr1 != null && ptr2 != null) {
            int val = ptr1.val + ptr2.val + carry;
            ptr1.val = val % 10;
            carry = val / 10;
            ptrTail = ptr1;
            ptr1 = ptr1.next;
            ptr2 = ptr2.next;
        }

        while (ptr1 != null) {
            int val = carry + ptr1.val;
            ptr1.val = val % 10;
            carry = val / 10;
            ptrTail = ptr1;
            ptr1 = ptr1.next;
        }

        if (ptr2 != null) {
            ptrTail.next = ptr2;
        }

        while (ptr2 != null) {
            int val = carry + ptr2.val;
            ptr2.val = val % 10;
            carry = val / 10;
            ptrTail = ptr2;
            ptr2 = ptr2.next;
        }

        if (carry != 0) {
            ptrTail.next = new ListNode(carry);
        }

        return l1;
    }
}
