// https://www.naukri.com/code360/problems/count-distinct-substrings_985292
class Trie {

    static class Node {

        Node links[];

        Node() {
            links = new Node[26];
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
    }

    Node root;

    Trie() {
        root = new Node();
    }

    int insertAndCount(String word) {
        Node node = root;
        int count = 0;
        for (int i = 0; i < word.length(); i++) {
            if (!node.containsKey(word.charAt(i))) {
                count++;
                node.put(word.charAt(i), new Node());
            }
            node = node.get(word.charAt(i));
        }
        return count;
    }
}

public class CountDistinctSubstrings {

    public static int countDistinctSubstrings(String s) {
        //	  Write your code here.
        Trie store = new Trie();
        int count = 1;
        for (int i = 0; i < s.length(); i++) {
            count += store.insertAndCount(s.substring(i));
        }
        return count;
    }
}
