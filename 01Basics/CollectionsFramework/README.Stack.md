The best method to implement a stack in Java using collections is to use the `Deque` interface with an `ArrayDeque` implementation. The `Deque` interface provides the necessary operations for a stack, such as push, pop, and peek, and the `ArrayDeque` implementation offers efficient and flexible performance.

### Why `ArrayDeque`?

1. **Performance**: `ArrayDeque` provides amortized constant time for the stack operations `push`, `pop`, and `peek`.
2. **Flexibility**: `ArrayDeque` does not have the synchronization overhead of `Stack`, making it faster in single-threaded contexts.
3. **Standard Practices**: Using `Deque` is recommended over the legacy `Stack` class, which is synchronized and part of the older `Vector` class hierarchy.

### Example Code

Here’s how you can implement a stack using `Deque` and `ArrayDeque`:

```java
import java.util.Deque;
import java.util.ArrayDeque;

public class StackExample {
    public static void main(String[] args) {
        Deque<Integer> stack = new ArrayDeque<>();

        // Pushing elements onto the stack
        stack.push(1);
        stack.push(2);
        stack.push(3);

        System.out.println("Stack after pushes: " + stack);

        // Peeking at the top element
        Integer top = stack.peek();
        System.out.println("Top element: " + top);

        // Popping elements from the stack
        Integer poppedElement = stack.pop();
        System.out.println("Popped element: " + poppedElement);

        System.out.println("Stack after pop: " + stack);
    }
}
```

### Summary

- **Preferred Implementation**: `Deque<Integer> stack = new ArrayDeque<>();`
  - **Push**: `stack.push(element);`
  - **Pop**: `stack.pop();`
  - **Peek**: `stack.peek();`
  
### Benefits of Using `Deque` and `ArrayDeque`

- **Performance**: Efficient stack operations.
- **Thread-Safety**: If you need a thread-safe stack, you can wrap `ArrayDeque` using `Collections.synchronizedDeque`.
- **Modern Practices**: Aligns with modern Java best practices, avoiding legacy classes like `Stack`.

By using `Deque` with `ArrayDeque`, you ensure that your stack implementation is both efficient and aligned with contemporary Java standards.