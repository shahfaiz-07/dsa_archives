// https://www.naukri.com/code360/problems/complete-string_2687860

class Trie {

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

        Node get(char ch) {
            return links[ch - 'a'];
        }

        void put(char ch, Node node) {
            links[ch - 'a'] = node;
        }

        void setEnd() {
            flag = true;
        }

        boolean getEnd() {
            return flag;
        }
    }

    Node root;

    Trie() {
        root = new Node();
    }

    void insert(String word) {
        Node node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node.containsKey(word.charAt(i))) {
                node.put(word.charAt(i), new Node());
            }
            node = node.get(word.charAt(i));
        }
        node.setEnd();
    }

    boolean containsPrefixes(String word) {
        Node node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node.containsKey(word.charAt(i))) {
                return false;
            }
            node = node.get(word.charAt(i));
            if (!node.getEnd()) {
                return false;
            }
        }
        return node.getEnd();
    }
}

class Solution {

    public static String completeString(int n, String[] a) {
        // Write your code here.
        Trie store = new Trie();
        for (String word : a) {
            store.insert(word);
        }

        String longest = "";
        for (String word : a) {
            if (word.length() >= longest.length()) {
                if (store.containsPrefixes(word)) {
                    if (word.length() > longest.length() || word.compareTo(longest) < 0) {
                        longest = word;
                    }
                }
            }
        }
        return longest == "" ? "None" : longest;
    }
}
