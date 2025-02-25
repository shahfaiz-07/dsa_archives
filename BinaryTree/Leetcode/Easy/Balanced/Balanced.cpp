// https://leetcode.com/problems/balanced-binary-tree/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    if (!root->right && !root->left)
        return 1;
    int x = maxDepth(root->left);
    if (x == -1)
        return -1;
    int y = maxDepth(root->right);
    if (y == -1)
        return -1;
    if (abs(x - y) > 1)
        return -1;
    return 1 + max(x, y);
}

bool isBalanced(TreeNode *root)
{
    return maxDepth(root) != -1;
}