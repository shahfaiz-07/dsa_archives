import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class LearnMap {
    public static void main(String[] args) {
        // HashMap and TreeMap(keys are sorted)
        Map<String, Integer> hashMap = new HashMap<>();

        // # put(K, V) - if absent, it inserts else it overrides
        // # putAll(Map)

        hashMap.put("A", 1);
        hashMap.put("B", 2);
        hashMap.put("A", 4);
        hashMap.put("D", 2);
        hashMap.put("C", 1);

        System.out.println(hashMap);
        
        // # putIfAbsent(K, V)
        hashMap.putIfAbsent("A", 9);
        hashMap.putIfAbsent("F", 7);
        System.out.println(hashMap);

        // # getOrDefault(K, default) - returns 'default' if key is not present
        
        // # get(K) - returns NULL if the key is not present
        // Iterating using # entrySet()

        for(Map.Entry<String, Integer> e : hashMap.entrySet()) {
            System.out.println(e);
            // # getKey(), # getValue()
            System.out.println(e.getKey());
            System.out.println(e.getValue());
        }

        // # keySet()
        System.out.println(hashMap.keySet());

        // # values()
        System.out.println(hashMap.values());

        // # containsKey(K), # containsValue(V)

        // # remove(K)

        // # isEmpty(), # clear(), # size()

        Map<String, Integer> treeMap = new TreeMap<>();
        treeMap.put("A", 1);
        treeMap.put("B", 2);
        treeMap.put("A", 4);
        treeMap.put("D", 2);
        treeMap.put("C", 1);

        System.out.println(treeMap);

        // exclusive Functions
        // # firstKey(), #lastKey()

        // # headMap(K) - The method returns a view of the portion of the map strictly less than the parameter key_value.

        // # subMap(start K, end K)
    }
}
