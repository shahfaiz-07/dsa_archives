// https://leetcode.com/problems/lru-cache/
#include<bits/stdc++.h>
using namespace std;
class LRUCache {
private:
    class Node {
        public:
            int key, val;
            Node *next, *prev;
            Node(int k, int v): key(k), val(v) {
                next = prev = nullptr;
            }
    };

    Node *head, *tail;
    int cap, size;
    unordered_map<int, Node*> mp;

    void insert(Node *node) {
        Node *headNext = head->next;
        head->next = node;
        node->prev = head;
        node->next = headNext;
        headNext->prev = node;
        size++;
    }

    void remove(Node *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        size--;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        Node *node = mp[key];
        if(!node) return -1;
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        Node *node = mp[key];
        if(node) {
            remove(node);
        } else if(size == cap) {
            mp[tail->prev->key] = nullptr;
            remove(tail->prev);
        }
        Node *newNode = new Node(key, value);
        mp[key] = newNode;
        insert(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */