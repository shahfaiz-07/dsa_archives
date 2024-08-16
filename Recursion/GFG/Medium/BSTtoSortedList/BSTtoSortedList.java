// https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1

public class BSTtoSortedList {
    // Main Code
    static Node flattenBST(Node root) {
        if (root != null) {
            Node left = flattenBST(root.left); // trust that this code gives you the head of left sub tree which is flattened
            root.left = null;
            Node head = root;
            if (left != null) {
                head = left;
                while (left.right != null) {
                    left = left.right;
                }
                left.right = root;
            }
            root.right = flattenBST(root.right);
            return head;
        }
        return null;
    }

    public static void main(String[] args) {

    }
}

class Node {

    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}
