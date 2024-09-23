// https://www.naukri.com/code360/problems/count-distinct-substrings_985292
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    Node() {}

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    int insertAndCount(string word)
    {
        Node *node = root;
        int count = 0;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                count++;
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        return count;
    }
};
int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    Trie *store = new Trie();
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        count += store->insertAndCount(s.substr(i));
    }
    return count + 1;
}