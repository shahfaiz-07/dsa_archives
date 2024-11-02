// https://leetcode.com/problems/merge-k-sorted-lists/
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};


ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, compare> pq;

    for (int i = 0; i < lists.size(); i++)
    {
        if (lists[i])
        {
            pq.push(lists[i]);
        }
    }
    if (pq.empty())
        return nullptr;
    ListNode *head = pq.top(), *ptr = head;
    pq.pop();
    if (ptr->next != nullptr)
    {
        pq.push(ptr->next);
    }

    while (!pq.empty())
    {
        ptr->next = pq.top();
        pq.pop();
        ptr = ptr->next;
        if (ptr->next)
        {
            pq.push(ptr->next);
        }
    }

    return head;
}
int main(void)
{

    return 0;
}