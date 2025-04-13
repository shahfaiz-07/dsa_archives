// https://leetcode.com/problems/lfu-cache/
#include<bits/stdc++.h>
using namespace std;
class LFUCache
{
private:
    int size, leastFreq;

    class Node
    {
    public:
        int key, val, freq;
        Node *next, *prev;
        Node(int k, int v) : key(k), val(v)
        {
            freq = 1;
            next = prev = nullptr;
        }
    };

    void remove(Node *node)
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        if (node->freq == leastFreq && mp1[leastFreq]->empty())
        {
            leastFreq++;
        }
        size--;
    }

    class DLL
    {
    public:
        Node *head, *tail;
        DLL()
        {
            head = tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }
        void insert(Node *node)
        {
            Node *headNext = head->next;
            node->prev = head;
            head->next = node;
            node->next = headNext;
            headNext->prev = node;
        }
        bool empty()
        {
            return head->next == tail;
        }
    };

    unordered_map<int, DLL *> mp1;
    unordered_map<int, Node *> mp2;
    int cap;

public:
    LFUCache(int capacity) : cap(capacity)
    {
        size = 0;
        leastFreq = 0;
    }

    int get(int key)
    {
        Node *node = mp2[key];
        if (!node)
        {
            return -1;
        }
        remove(node);
        node->freq += 1;
        auto &list = mp1[node->freq];
        if (!list)
        {
            list = new DLL();
        }
        list->insert(node);
        size++;
        return node->val;
    }

    void put(int key, int value)
    {
        Node *node = mp2[key];
        if (!node)
        {
            if (size == cap)
            {
                mp2[mp1[leastFreq]->tail->prev->key] = nullptr;
                remove(mp1[leastFreq]->tail->prev);
            }
            Node *newNode = new Node(key, value);
            mp2[key] = newNode;
            auto &list = mp1[1];
            if (!list)
            {
                list = new DLL();
            }
            list->insert(newNode);
            size++;
            leastFreq = 1;
        }
        else
        {
            node->val = value;
            remove(node);
            node->freq += 1;
            auto &list = mp1[node->freq];
            if (!list)
            {
                list = new DLL();
            }
            list->insert(node);
            size++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */