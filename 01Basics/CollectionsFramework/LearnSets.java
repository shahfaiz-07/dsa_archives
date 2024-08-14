import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

public class LearnSets {
    public static void main(String[] args) {
        // HashSet, LinkedHashSet, TreeSet
        
        Set<Integer> set1 = new HashSet<>(); // Random order based on hash function
        // Performance: It offers constant-time performance for basic operations (add, remove, contains, and size), assuming the hash function disperses elements properly among the buckets.
        // Memory: Typically, it uses less memory compared to LinkedHashSet as it does not need to maintain any additional order information.

        // # add(ele), #addAll(Collection)
        set1.add(32);
        set1.add(4);
        set1.add(54);
        set1.add(21);
        set1.add(65);

        System.out.println(set1);

        // # clear(), # contains(ele), # containsAll(Collection), # size()

        // # isEmpty()

        // # remove(ele) - returns 'true' or 'false'

        // # removeAll(Collection)

        Set<Integer> set2 = new LinkedHashSet<>(); // Order is preserved
        // Performance: It also offers constant-time performance for basic operations, but with a slightly higher overhead compared to HashSet due to the maintenance of the linked list.
        // Memory: Uses more memory than HashSet because of the additional linked list used to maintain the order.

        set2.add(32);
        set2.add(4);
        set2.add(54);
        set2.add(21);
        set2.add(65);

        System.out.println(set2);

        SortedSet<Integer> set3 = new TreeSet<>(); // Elements in sorted order
        // Performance: The basic operations (add, remove, contains) have a time complexity of O(log n) due to the underlying tree structure (Red-Black Tree).
        // Functions exclusive to TreeSet are in 'README.TreeSet.md'

        set3.add(32);
        set3.add(4);
        set3.add(54);
        set3.add(21);
        set3.add(65);

        System.out.println(set3);
    }
}
