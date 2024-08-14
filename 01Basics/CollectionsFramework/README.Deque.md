In Java, the `Deque` (double-ended queue) interface represents a linear collection that supports element insertion and removal at both ends. The best way to implement a `Deque` using Java collections is by using one of the classes that implement the `Deque` interface. The most commonly used implementations are `ArrayDeque` and `LinkedList`.

### ArrayDeque

`ArrayDeque` is generally preferred over `LinkedList` for implementing a `Deque` because it offers better performance for most use cases. It provides amortized constant time for both insertion and removal operations at both ends.

```java
import java.util.ArrayDeque;
import java.util.Deque;

public class DequeExample {
    public static void main(String[] args) {
        Deque<String> deque = new ArrayDeque<>();

        // Adding elements to the deque
        deque.addFirst("Element 1 (Head)");
        deque.addLast("Element 2 (Tail)");
        deque.addFirst("Element 3 (Head)");

        System.out.println("Deque after adding elements: " + deque);

        // Removing elements from the deque
        String headElement = deque.removeFirst();
        System.out.println("Removed from head: " + headElement);
        String tailElement = deque.removeLast();
        System.out.println("Removed from tail: " + tailElement);

        System.out.println("Deque after removing elements: " + deque);
    }
}
```

### LinkedList

`LinkedList` can also be used to implement a `Deque`. While it offers similar functionality to `ArrayDeque`, it may have different performance characteristics. For example, `LinkedList` provides constant time for insertions and removals at both ends but may have higher memory overhead due to the need to store pointers to the next and previous nodes.

```java
import java.util.Deque;
import java.util.LinkedList;

public class DequeExample {
    public static void main(String[] args) {
        Deque<String> deque = new LinkedList<>();

        // Adding elements to the deque
        deque.addFirst("Element 1 (Head)");
        deque.addLast("Element 2 (Tail)");
        deque.addFirst("Element 3 (Head)");

        System.out.println("Deque after adding elements: " + deque);

        // Removing elements from the deque
        String headElement = deque.removeFirst();
        System.out.println("Removed from head: " + headElement);
        String tailElement = deque.removeLast();
        System.out.println("Removed from tail: " + tailElement);

        System.out.println("Deque after removing elements: " + deque);
    }
}
```

### Summary

- **ArrayDeque**:
  - Offers better performance for most use cases.
  - Provides amortized constant time for insertion and removal operations at both ends.
  - Does not support null elements.

- **LinkedList**:
  - Offers similar functionality to `ArrayDeque`.
  - Provides constant time for insertion and removal operations at both ends.
  - May have higher memory overhead due to node pointers.
  - Supports null elements.

In general, `ArrayDeque` is preferred unless you have a specific reason to use `LinkedList`.