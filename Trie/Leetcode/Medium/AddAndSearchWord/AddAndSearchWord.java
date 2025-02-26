// https://leetcode.com/problems/design-add-and-search-words-data-structure/

public class AddAndSearchWord {
    class WordDictionary {

        class Node {

            Node links[];
            boolean flag;

            Node() {
                links = new Node[26];
                flag = false;
            }

            boolean contains(char ch) {
                return links[ch - 'a'] != null;
            }

            Node get(char ch) {
                return links[ch - 'a'];
            }

            void put(char ch) {
                links[ch - 'a'] = new Node();
            }

            void setEnd() {
                flag = true;
            }

            boolean getEnd() {
                return flag;
            }
        }

        Node root;

        public WordDictionary() {
            root = new Node();
        }

        public void addWord(String word) {
            Node node = root;
            for (int i = 0; i < word.length(); i++) {
                if (!node.contains(word.charAt(i))) {
                    node.put(word.charAt(i));
                }
                node = node.get(word.charAt(i));
            }

            node.setEnd();
        }

        boolean search(String word, int index, Node node) {
            if (index == word.length()) {
                return node.getEnd();
            }
            // match '.' with all characters possible
            if (word.charAt(index) == '.') {
                for (Node curr : node.links) {
                    if (curr != null && search(word, index + 1, curr)) {
                        return true;
                    }
                }
                return false;
            }

            if (!node.contains(word.charAt(index))) {
                return false;
            }

            return search(word, index + 1, node.get(word.charAt(index)));
        }

        public boolean search(String word) {
            return search(word, 0, root);
        }
    }
}
