// https://leetcode.com/problems/add-two-numbers/
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
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // adding to the first list

    int carry = 0;
    ListNode *ptr1 = l1, *ptrTail = nullptr, *ptr2 = l2;

    while (ptr1 && ptr2)
    {
        int val = ptr1->val + ptr2->val + carry;
        ptr1->val = val % 10;
        carry = val / 10;
        ptrTail = ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    while (ptr1)
    {
        int val = carry + ptr1->val;
        ptr1->val = val % 10;
        carry = val / 10;
        ptrTail = ptr1;
        ptr1 = ptr1->next;
    }

    if (ptr2)
        ptrTail->next = ptr2;

    while (ptr2)
    {
        int val = carry + ptr2->val;
        ptr2->val = val % 10;
        carry = val / 10;
        ptrTail = ptr2;
        ptr2 = ptr2->next;
    }

    if (carry)
    {
        ptrTail->next = new ListNode(carry);
    }

    return l1;
}