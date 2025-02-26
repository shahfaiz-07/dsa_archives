// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void myGoodNodes(TreeNode *root, int &c, int currMax)
{
    if (!root)
        return;
    if (root->val >= currMax)
    {
        c++;
    }
    currMax = max(root->val, currMax);
    myGoodNodes(root->left, c, currMax);
    myGoodNodes(root->right, c, currMax);
}
int goodNodes(TreeNode *root)
{
    int c = 0;
    myGoodNodes(root, c, INT_MIN);
    return c;
}