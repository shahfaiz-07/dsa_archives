// https://www.naukri.com/code360/problems/implement-trie_1387095
#include <bits/stdc++.h>
using namespace std;

class Node
{
    Node *links[26];
    int pref, ew;

public:
    Node()
    {
        pref = ew = 0;
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'];
    }

    void createReference(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setPref()
    {
        pref++;
    }

    void setEnd()
    {
        ew++;
    }

    int getPrefixes()
    {
        return pref;
    }

    int getEnd()
    {
        return ew;
    }

    void erasePref()
    {
        pref--;
    }

    void eraseEnd()
    {
        ew--;
    }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        // Write your code here.
        root = new Node();
    }

    void insert(string &word)
    {
        // Write your code here.
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->createReference(word[i], new Node());
            }
            node = node->get(word[i]);
            node->setPref();
        }
        node->setEnd();
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getPrefixes();
    }

    void erase(string &word)
    {
        // Write your code here.
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return;
            }
            node = node->get(word[i]);
            node->erasePref();
        }
        return node->eraseEnd();
    }
};
