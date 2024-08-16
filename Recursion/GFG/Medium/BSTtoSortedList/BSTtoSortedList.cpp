// https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
// Main code
Node *flattenBST(Node *root)
{
    if (root)
    {
        Node *left = flattenBST(root->left); // trust that this code gives you the head of left sub tree which is flattened
        root->left = nullptr;
        Node *head = root;
        if (left)
        {
            head = left;
            while (left->right != nullptr)
            {
                left = left->right;
            }
            left->right = root;
        }
        Node *right = flattenBST(root->right);
        root->right = right;
        return head;
    }
    return nullptr;
}
int main(void)
{

    return 0;
}