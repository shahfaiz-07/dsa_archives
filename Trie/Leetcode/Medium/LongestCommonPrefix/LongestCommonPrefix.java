// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
class Trie {

    static class Node {

        Node links[];

        Node() {
            links = new Node[10];
        }

        boolean containsKey(char ch) {
            return links[ch - '0'] != null;
        }

        void add(char ch, Node node) {
            links[ch - '0'] = node;
        }

        Node get(char ch) {
            return links[ch - '0'];
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
                node.add(word.charAt(i), new Node());
            }
            node = node.get(word.charAt(i));
        }
    }

    int checkPref(String word) {
        Node node = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word.charAt(i);
            if (!node.containsKey(ch)) {
                return i;
            }
            node = node.get(ch);
        }
        return word.length();
    }
}

public class LongestCommonPrefix {

    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        Trie store = new Trie();
        for (int ele : arr1) {
            store.insert(Integer.toString(ele));
        }
        int prefLength = 0;
        for (int ele : arr2) {
            int thisPrefLength = store.checkPref(Integer.toString(ele));
            if (thisPrefLength > prefLength) {
                prefLength = thisPrefLength;
            }
        }
        return prefLength;
    }
}
