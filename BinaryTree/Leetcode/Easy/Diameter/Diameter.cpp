// https://leetcode.com/problems/diameter-of-binary-tree/

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
int calc(TreeNode *root, int &d)
{
    if (root == nullptr)
        return 0;

    int l = calc(root->left, d), r = calc(root->right, d);
    d = max(d, r + l); // this is diameter

    return 1 + max(l, r); // this is height
}

int diameterOfBinaryTree(TreeNode *root)
{
    int d = 0;
    calc(root, d);
    return d;
}