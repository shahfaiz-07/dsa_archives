// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
#include<bits/stdc++.h>
using namespace std;
class Node
{
private:
    Node *links[2] = {nullptr};

public:
    Node() {}
    bool containsKey(bool val) { return links[val] != nullptr; }
    void add(bool val, Node *node) { links[val] = node; }
    Node *get(bool val) { return links[val]; }
};

class Trie
{
private:
    Node *root;

public:
    Trie() { root = new Node(); }
    void insert(int value)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            bool bit = (value & (1 << i));
            if (!node->containsKey(bit))
            {
                node->add(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int maxXOR(int value)
    {
        Node *node = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            bool bit = (value & (1 << i));
            if ((!bit && node->containsKey(!bit)) || !node->containsKey(0))
            {
                ans |= (1 << i);
                node = node->get(1);
            }
            else
            {
                node = node->get(0);
            }
        }
        return ans ^ value;
    }
};
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        Trie store;
        for (int &ele : nums)
        {
            store.insert(ele);
        }
        int XOR = 0;
        for (int &ele : nums)
        {
            int XORVal = store.maxXOR(ele);
            if (XORVal > XOR)
            {
                XOR = XORVal;
            }
        }
        return XOR;
    }
};
int main(void) {
    
    return 0;
}