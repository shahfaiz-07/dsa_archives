// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root || !p || !q)
    {
        return nullptr;
    }

    if (root->val == p->val || root->val == q->val ||
        (p->val < root->val && q->val > root->val) ||
        (q->val < root->val && p->val > root->val))
    {
        return root;
    }

    if (max(p->val, q->val) < root->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    return lowestCommonAncestor(root->right, p, q);
}