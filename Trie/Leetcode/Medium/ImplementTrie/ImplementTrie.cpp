// https://leetcode.com/problems/implement-trie-prefix-tree/
#include<bits/stdc++.h>
using namespace std;
class Node
{
private:
    Node *links[26];
    bool flag = false;

public:
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

    void setEnd()
    {
        flag = true;
    }

    bool getEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    // TC = O(word length)
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            // if it is a new character
            if (!node->containsKey(word[i]))
            {
                // create a reference node(or a new node)
                node->put(word[i], new Node());
            }
            // move to the reference Trie if it exists or after it is created
            node = node->get(word[i]);
        }
        // if your word ends then you must be starting at the last reference Trie
        node->setEnd();
    }
    // TC = O(word length)
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->getEnd();
    }
    // TC = O(word length)
    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
int main(void) {
    
    return 0;
}