// https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
void sumNodes(TreeNode *root, int num, int &s)
{
    if (root)
    {
        num = num * 10 + root->val;
        if (!root->left && !root->right)
        {
            s += num;
            return;
        }
        sumNodes(root->left, num, s);
        sumNodes(root->right, num, s);
    }
}

int sumNumbers(TreeNode *root)
{
    int ans = 0;
    sumNodes(root, 0, ans);
    return ans;
}