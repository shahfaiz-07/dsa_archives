// https://leetcode.com/problems/lru-cache/
import java.util.HashMap;
import java.util.Map;


class LRUCache {
    Node head, tail;
    int cap, size;
    Map<Integer, Node> mp;

    public LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        mp = new HashMap<>();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        Node node = mp.getOrDefault(key, null);
        if(node == null) {
            return -1;
        }
        remove(node);
        insert(node);
        return node.val;
    }
    
    public void put(int key, int value) {
        Node node = mp.getOrDefault(key, null);
        if(node != null) {
            remove(node);
        } else if(size == cap) {
            mp.remove(tail.prev.key);
            remove(tail.prev);
        }
        Node newNode = new Node(key, value);
        mp.put(key, newNode);
        insert(newNode);
    }

    class Node {
        int key, val;
        Node next, prev;
        Node(int key, int val) {
            this.key = key;
            this.val = val;
            next = prev = null;
        }
    }

    void insert(Node node) {
        Node headNext = head.next;
        head.next = node;
        node.prev = head;
        headNext.prev = node;
        node.next = headNext;
        size++;
    }
    void remove(Node node) {
        if(head.next == tail || node == null) return;
        Node nodeNext = node.next, nodePrev = node.prev;
        nodeNext.prev = nodePrev;
        nodePrev.next = nodeNext;
        size--;
    }
}