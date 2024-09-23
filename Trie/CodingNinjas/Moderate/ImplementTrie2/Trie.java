// https://www.naukri.com/code360/problems/implement-trie_1387095

public class Trie {

    static class Node {

        Node links[];
        int pref, ew;

        Node() {
            links = new Node[26];
            pref = ew = 0;
        }

        boolean containsKey(char ch) {
            return links[ch - 'a'] != null;
        }

        void createRef(char ch, Node node) {
            links[ch - 'a'] = node;
        }

        Node getRef(char ch) {
            return links[ch - 'a'];
        }

        void addPrefix() {
            pref++;
        }

        int getPrefix() {
            return pref;
        }

        void erasePrefix() {
            pref--;
        }

        void setEnd() {
            ew++;
        }

        void eraseEnd() {
            ew--;
        }

        int getEnd() {
            return ew;
        }
    }

    Node root;

    public Trie() {
        // Write your code here.
        root = new Node();
    }

    public void insert(String word) {
        // Write your code here.
        Node node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node.containsKey(word.charAt(i))) {
                node.createRef(word.charAt(i), new Node());
            }
            node = node.getRef(word.charAt(i));
            node.addPrefix();
        }
        node.setEnd();
    }

    public int countWordsEqualTo(String word) {
        // Write your code here.
        Node node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node.containsKey(word.charAt(i))) {
                return 0;
            }
            node = node.getRef(word.charAt(i));
        }
        return node.getEnd();
    }

    public int countWordsStartingWith(String word) {
        // Write your code here.
        Node node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node.containsKey(word.charAt(i))) {
                return 0;
            }
            node = node.getRef(word.charAt(i));
        }
        return node.getPrefix();
    }

    public void erase(String word) {
        // Write your code here.
        Node node = root;
        for (int i = 0; i < word.length(); i++) {
            node = node.getRef(word.charAt(i));
            node.erasePrefix();
        }
        node.eraseEnd();
    }

}
