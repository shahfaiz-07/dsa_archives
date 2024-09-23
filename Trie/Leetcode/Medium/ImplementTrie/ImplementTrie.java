// https://leetcode.com/problems/implement-trie-prefix-tree/

public class ImplementTrie {

    static class Node {

        Node links[];
        boolean flag;

        Node() {
            links = new Node[26];
            flag = false;
        }

        boolean containsKey(char ch) {
            return links[ch - 'a'] != null;
        }

        void createReference(char ch, Node node) {
            links[ch - 'a'] = node;
        }

        Node getReference(char ch) {
            return links[ch - 'a'];
        }

        void setEnd() {
            flag = true;
        }

        boolean getEnd() {
            return flag;
        }
    }
    Node root;

    public ImplementTrie() {
        root = new Node();
    }

    public void insert(String word) {
        Node node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node.containsKey(word.charAt(i))) {
                node.createReference(word.charAt(i), new Node());
            }
            node = node.getReference(word.charAt(i));
        }
        node.setEnd();
    }

    public boolean search(String word) {
        Node node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node == null || !node.containsKey(word.charAt(i))) {
                return false;
            }
            node = node.getReference(word.charAt(i));
        }
        return node != null && node.getEnd();
    }

    public boolean startsWith(String prefix) {
        Node node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (node == null || !node.containsKey(prefix.charAt(i))) {
                return false;
            }
            node = node.getReference(prefix.charAt(i));
        }
        return true;
    }

    /**
     * Your Trie object will be instantiated and called as such: Trie obj = new
     * Trie(); obj.insert(word); boolean param_2 = obj.search(word); boolean
     * param_3 = obj.startsWith(prefix);
     */
}
