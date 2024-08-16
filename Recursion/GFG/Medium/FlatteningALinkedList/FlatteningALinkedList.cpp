// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
// Main code
Node *flatten(Node *root)
{
    if (!root)
    {
        return nullptr;
    }
    Node *flattenedNext = flatten(root->next);
    Node *head = nullptr, *tail = nullptr;
    while (root && flattenedNext)
    {
        if (root->data < flattenedNext->data)
        {
            if (!head)
            {
                head = tail = root;
                head->next = nullptr;
            }
            else
            {
                tail->bottom = root;
                tail = tail->bottom;
            }
            root = root->bottom;
        }
        else
        {
            if (!head)
            {
                head = tail = flattenedNext;
                head->next = nullptr;
            }
            else
            {
                tail->bottom = flattenedNext;
                tail = tail->bottom;
            }
            flattenedNext = flattenedNext->bottom;
        }
    }
    if (root)
    {
        if (!head)
        {
            head = tail = root;
            head->next = nullptr;
        }
        else
        {
            tail->bottom = root;
        }
    }
    if (flattenedNext)
    {
        if (!head)
        {
            head = tail = flattenedNext;
            head->next = nullptr;
        }
        else
        {
            tail->bottom = flattenedNext;
        }
    }
    return head;
}
int main(void) {
    
    return 0;
}