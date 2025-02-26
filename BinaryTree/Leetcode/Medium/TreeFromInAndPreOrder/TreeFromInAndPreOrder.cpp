// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include <bits/stdc++.h>
using namespace std;
int preInd = 0;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *construct(vector<int> &preorder, unordered_map<int, int> &inorder, int inStart, int inEnd)
{
    if (preInd >= preorder.size() || inStart > inEnd)
    {
        return nullptr;
    }

    TreeNode *node = new TreeNode(preorder[preInd]);

    int searchInd = inorder[preorder[preInd]];

    preInd++;

    node->left = construct(preorder, inorder, inStart, searchInd - 1);
    node->right = construct(preorder, inorder, searchInd + 1, inEnd);

    return node;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int preInd = 0;
    unordered_map<int, int> in;
    for (int i = 0; i < inorder.size(); i++)
    {
        in[inorder[i]] = i;
    }

    return construct(preorder, in, 0, preorder.size() - 1);
}