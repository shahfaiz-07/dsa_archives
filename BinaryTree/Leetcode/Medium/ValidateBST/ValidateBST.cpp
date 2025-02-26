// https://leetcode.com/problems/validate-binary-search-tree/

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
bool validate(TreeNode *root, long minVal, long maxVal)
{
    if (!root)
        return true;
    return root->val < maxVal && root->val > minVal && validate(root->left, minVal, root->val) && validate(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode *root)
{
    return validate(root, LONG_MIN, LONG_MAX);
}