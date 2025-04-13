// https://leetcode.com/problems/lfu-cache/
import java.util.Map;
import java.util.HashMap;
class LFUCache {

    // freq, list
    Map<Integer, DLL> mp1;
    // key, node
    Map<Integer, Node> mp2;
    int size, capacity, leastFreq;

    public LFUCache(int capacity) {
        mp1 = new HashMap<>();
        mp2 = new HashMap<>();
        size = 0;
        leastFreq = 0;
        this.capacity = capacity;
    }

    public int get(int key) {
        Node node = mp2.getOrDefault(key, null);
        if (node == null) {
            return -1;
        }
        remove(node);
        node.freq += 1;
        mp1.compute(node.freq, (k, v) -> v == null ? new DLL() : v).insert(node);
        return node.val;
    }

    public void put(int key, int value) {
        Node node = mp2.getOrDefault(key, null);
        if (node == null) {
            if (size == capacity) {
                DLL lfu = mp1.get(leastFreq);
                mp2.remove(lfu.tail.prev.key);
                remove(lfu.tail.prev);
            }
            Node newNode = new Node(key, value);
            mp1.compute(1, (k, v) -> v == null ? new DLL() : v).insert(newNode);
            mp2.put(key, newNode);
            leastFreq = 1;
        } else {
            remove(node);
            node.val = value;
            node.freq += 1;
            mp1.compute(node.freq, (k, v) -> v == null ? new DLL() : v).insert(node);
        }
    }

    class Node {

        int key, val, freq;
        Node next, prev;

        Node(int key, int val) {
            this.key = key;
            this.val = val;
            freq = 1;
            next = prev = null;
        }
    }

    void remove(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
        if (node.freq == leastFreq && mp1.get(leastFreq).isEmpty()) {
            leastFreq++;
        }
        size--;
    }

    class DLL {

        Node head, tail;

        DLL() {
            head = tail = new Node(-1, -1);
            tail.prev = head;
            head.next = tail;
        }

        void insert(Node node) {
            Node headNext = head.next;
            head.next = node;
            node.prev = head;
            headNext.prev = node;
            node.next = headNext;
            size++;
        }

        boolean isEmpty() {
            return head.next == tail;
        }
    }
}

/** * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
