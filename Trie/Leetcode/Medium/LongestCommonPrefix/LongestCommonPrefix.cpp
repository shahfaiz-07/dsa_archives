// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
#include<bits/stdc++.h>
using namespace std;
class Node
{
    Node *links[10] = {nullptr};

public:
    Node()
    {
    }

    bool containsKey(char ch) { return links[ch - '0'] != nullptr; }

    void add(char ch, Node *node) { links[ch - '0'] = node; }

    Node *get(char ch) { return links[ch - '0']; }
};
class Trie
{
public:
    Node *root;
    Trie() { root = new Node(); }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->add(word[i], new Node());
            }
            node = node->get(word[i]);
        }
    }

    int checkPref(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            if (!node->containsKey(ch))
            {
                return i;
            }
            node = node->get(ch);
        }
        return word.length();
    }
};
class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        Trie store;
        for (int &ele : arr1)
        {
            store.insert(to_string(ele));
        }
        int prefLength = 0;
        for (int &ele : arr2)
        {
            int thisPrefLength = store.checkPref(to_string(ele));
            if (thisPrefLength > prefLength)
            {
                prefLength = thisPrefLength;
            }
        }
        return prefLength;
    }
};
int main(void) {
    
    return 0;
}