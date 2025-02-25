// https://leetcode.com/problems/reorder-list/

#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return;
    stack<ListNode *> st;
    ListNode *slow = head, *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow = slow->next;

    while (slow)
    {
        st.push(slow);
        slow = slow->next;
    }

    ListNode *curr = head, *prev = nullptr;

    while (!st.empty() && curr)
    {
        ListNode *next = curr->next;
        curr->next = st.top();
        st.pop();
        curr = curr->next;
        curr->next = next;
        prev = curr;
        curr = next;
    }
    if (!fast)
    {
        curr->next = nullptr;
    }
    else
    {
        prev->next = nullptr;
    }
}
