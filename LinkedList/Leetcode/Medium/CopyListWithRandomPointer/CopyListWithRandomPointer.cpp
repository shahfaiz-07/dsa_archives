// https://leetcode.com/problems/copy-list-with-random-pointer/

#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (head == nullptr)
        return nullptr;
    Node *newHead = new Node(head->val);
    unordered_map<Node *, Node *> mp;

    Node *newPtr = newHead, *ptr = head;

    while (ptr != nullptr && ptr->next != nullptr)
    {
        newPtr->next = new Node(ptr->next->val);
        mp[ptr] = newPtr;
        newPtr = newPtr->next;
        ptr = ptr->next;
    }
    mp[ptr] = newPtr;

    newPtr = newHead;
    ptr = head;

    while (newPtr != nullptr && ptr != nullptr)
    {
        newPtr->random = mp[ptr->random];
        newPtr = newPtr->next;
        ptr = ptr->next;
    }

    return newHead;
}