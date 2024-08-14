When deciding between `Queue<Integer> que = new LinkedList<>();` and `LinkedList<Integer> que = new LinkedList<>();` for defining a queue, it is generally better to use the interface type (`Queue`) rather than the implementation type (`LinkedList`). Here's why:

### Using the Interface Type (`Queue<Integer> que = new LinkedList<>();`)

1. **Abstraction**: By using the `Queue` interface, you are programming to an interface, not an implementation. This promotes better abstraction and decoupling, making your code more flexible and easier to maintain.

2. **Flexibility**: If you later decide to change the implementation of your queue to another class that implements `Queue`, such as `PriorityQueue` or `ArrayDeque`, you can do so with minimal changes to your code. You only need to change the instantiation part, not the usage part.

3. **Clarity**: Using the `Queue` interface makes it clear that you are working with a queue and intend to use it as such, which can improve code readability.

### Using the Implementation Type (`LinkedList<Integer> que = new LinkedList<>();`)

1. **Tight Coupling**: Directly using `LinkedList` ties your code to a specific implementation. This makes it harder to switch to a different implementation in the future without modifying the code significantly.

2. **Reduced Flexibility**: If you want to change the queue implementation later, you would need to change not only the instantiation but also potentially other parts of your code that depend on `LinkedList` specific methods that are not part of the `Queue` interface.

### Recommendation

It's generally better to use the interface type when defining your queue:

```java
Queue<Integer> que = new LinkedList<>();
```

### Example Code

Here’s a simple example demonstrating the usage:

```java
import java.util.LinkedList;
import java.util.Queue;

public class QueueExample {
    public static void main(String[] args) {
        Queue<Integer> que = new LinkedList<>();

        // Adding elements to the queue
        que.add(1);
        que.add(2);
        que.add(3);

        System.out.println("Queue: " + que);

        // Removing elements from the queue
        Integer head = que.poll();
        System.out.println("Removed head: " + head);

        System.out.println("Queue after removal: " + que);
    }
}
```

By using `Queue<Integer> que = new LinkedList<>();`, you ensure that your code adheres to good design principles, making it more modular, maintainable, and flexible.