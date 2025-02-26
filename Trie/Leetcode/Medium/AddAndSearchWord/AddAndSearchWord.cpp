// https://leetcode.com/problems/design-add-and-search-words-data-structure/
#include<bits/stdc++.h>
using namespace std;
class WordDictionary
{
private:
    class Node
    {
    public:
        Node *links[26];
        bool flag = false;

        bool contains(char ch)
        {
            return links[ch - 'a'] != nullptr;
        }

        void put(char ch)
        {
            links[ch - 'a'] = new Node();
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

    Node *root;

public:
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->contains(word[i]))
            {
                node->put(word[i]);
            }

            node = node->get(word[i]);
        }

        node->setEnd();
    }

    bool search(string &word, int i, Node *node)
    {
        if (i == word.length())
            return node->getEnd();

        if (word[i] == '.')
        {
            for (Node *curr : node->links)
            {
                if (curr != nullptr && search(word, i + 1, curr))
                {
                    return true;
                }
            }
            return false;
        }

        if (!node->contains(word[i]))
            return false;

        return search(word, i + 1, node->get(word[i]));
    }

    bool search(string word)
    {
        return search(word, 0, root);
    }
};