// https://leetcode.com/problems/merge-two-sorted-lists/description/
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
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    ListNode *list3;
    if (list1->val < list2->val)
    {
        list3 = list1;
        list1 = list1->next;
    }
    else
    {
        list3 = list2;
        list2 = list2->next;
    }
    ListNode *end = list3;

    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            end->next = list1;
            end = list1;
            list1 = list1->next;
        }
        else
        {
            end->next = list2;
            end = list2;
            list2 = list2->next;
        }
    }

    while (list1)
    {
        end->next = list1;
        end = list1;
        list1 = list1->next;
    }
    while (list2)
    {
        end->next = list2;
        end = list2;
        list2 = list2->next;
    }

    return list3;
}