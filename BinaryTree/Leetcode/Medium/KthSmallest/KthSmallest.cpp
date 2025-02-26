// https://leetcode.com/problems/kth-smallest-element-in-a-bst

#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int kthSmallest(TreeNode *root, int k)
{
    stack<TreeNode *> st;
    TreeNode *curr = root, *lastCurr = nullptr;
    int i = 0;
    while (i < k)
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        lastCurr = curr;
        curr = curr->right;
        i++;
    }

    return lastCurr->val;
}