// https://leetcode.com/problems/clone-graph/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        Node *newNode = new Node(node->val);
        queue<Node *> que;
        unordered_map<Node *, Node *> mp;
        que.push(node);
        mp[node] = newNode;

        while (!que.empty())
        {
            Node *currOg = que.front();
            que.pop();
            Node *currCopy = mp[currOg];
            for (auto &neighbor : currOg->neighbors)
            {
                Node *existingNeighbor = mp[neighbor];
                if (existingNeighbor)
                {
                    currCopy->neighbors.push_back(existingNeighbor);
                }
                else
                {
                    Node *newNeighbor = new Node(neighbor->val);
                    currCopy->neighbors.push_back(newNeighbor);
                    que.push(neighbor);
                    mp[neighbor] = newNeighbor;
                }
            }
        }
        return newNode;
    }
};