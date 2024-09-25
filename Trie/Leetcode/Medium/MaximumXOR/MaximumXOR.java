// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
class Trie {

    static class Node {

        Node links[];

        Node() {
            links = new Node[2];
        }

        boolean containsKey(boolean val) {
            return links[val ? 1 : 0] != null;
        }

        void add(boolean val, Node node) {
            links[val ? 1 : 0] = node;
        }

        Node get(boolean val) {
            return links[val ? 1 : 0];
        }
    }

    Node root;

    Trie() {
        root = new Node();
    }

    void insert(int value) {
        Node node = root;
        for (int i = 31; i >= 0; i--) {
            boolean bit = ((value & (1 << i)) != 0);
            if (!node.containsKey(bit)) {
                node.add(bit, new Node());
            }
            node = node.get(bit);
        }
    }

    int maxXOR(int value) {
        Node node = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            boolean bit = ((value & (1 << i)) != 0);
            if ((!bit && node.containsKey(!bit)) || !node.containsKey(false)) {
                ans = (ans | (1 << i));
                node = node.get(true);
            } else {
                node = node.get(false);
            }
        }
        return (ans ^ value);
    }
}

public class MaximumXOR {

    public int findMaximumXOR(int[] nums) {
        Trie store = new Trie();
        for (int i = 0; i < nums.length; i++) {
            store.insert(nums[i]);
        }
        int XOR = 0;
        for (int i = 0; i < nums.length; i++) {
            int XORVal = store.maxXOR(nums[i]);
            if (XORVal > XOR) {
                XOR = XORVal;
            }
        }
        return XOR;
    }
}
