// https://leetcode.com/problems/group-anagrams/
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class GroupAnagrams {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();

        for(String str: strs) {
            int hashMap[] = new int[26];
            for(int i=0; i<str.length(); i++) {
                hashMap[str.charAt(i) - 'a']++;
            }
            String key = Arrays.toString(hashMap);
            map.computeIfAbsent(key, k -> new ArrayList<>()).add(str);
        }

        return new ArrayList<>(map.values());
    }
}
