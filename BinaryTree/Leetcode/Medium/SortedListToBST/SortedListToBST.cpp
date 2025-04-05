// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *listToBST(ListNode *head, ListNode *end)
{
    if (!head || head == end)
        return nullptr;
    ListNode *slow = head, *fast = head;
    while (fast != end && fast->next != end)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode *root = new TreeNode(slow->val);
    root->left = listToBST(head, slow);
    root->right = listToBST(slow->next, end);
    return root;
}

TreeNode *sortedListToBST(ListNode *head)
{
    return listToBST(head, nullptr);
}