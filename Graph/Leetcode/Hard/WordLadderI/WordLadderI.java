// https://leetcode.com/problems/word-ladder/

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Pair {

    String first;
    int second;

    Pair(String first, int second) {
        this.first = first;
        this.second = second;
    }
}

public class WordLadderI {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> st = new HashSet<>(wordList);  // Simplified set initialization
        
        if (!st.contains(endWord)) return 0;
        st.remove(beginWord);
        
        Deque<Pair> dq = new ArrayDeque<>();
        dq.offer(new Pair(beginWord, 1));
        
        while (!dq.isEmpty()) {
            Pair curr = dq.poll();
            String word = curr.first;
            int level = curr.second;
            
            for (int i = 0; i < word.length(); i++) {
                char[] wordChars = word.toCharArray();
                
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    wordChars[i] = ch;
                    String newWord = new String(wordChars);
                    
                    if (newWord.equals(endWord)) {
                        return level + 1;
                    }
                    
                    if (st.remove(newWord)) {
                        dq.offer(new Pair(newWord, level + 1));
                    }
                }
            }
        }
        return 0;
    }
}
