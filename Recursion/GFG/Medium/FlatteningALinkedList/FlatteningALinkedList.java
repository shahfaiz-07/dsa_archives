// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
class Node {

    int data;
    Node next;
    Node bottom;

    Node(int x) {
        data = x;
        next = null;
        bottom = null;
    }
}

public class FlatteningALinkedList {
    Node flatten(Node root) {
        if (root == null) {
            return null;
        }
        Node flatLeft = flatten(root.next);
        root.next = null;
        Node head = null, tail = null;
        // just a simple case of merging two sorted lists
        while (root != null && flatLeft != null) {
            if (root.data < flatLeft.data) {
                if (head == null) {
                    head = tail = root;
                } else {
                    tail.bottom = root;
                    tail = root;
                }
                root = root.bottom;
            } else {
                if (head == null) {
                    head = tail = flatLeft;
                } else {
                    tail.bottom = flatLeft;
                    tail = flatLeft;
                }
                flatLeft = flatLeft.bottom;
            }
        }
        if (root != null) {
            if (head == null) {
                head = tail = root;
            } else {
                tail.bottom = root;
            }
        }
        if (flatLeft != null) {
            if (head == null) { // not required but just for safety
                head = tail = flatLeft;
            } else {
                tail.bottom = flatLeft;
            }
        }
        return head;
    }
}
