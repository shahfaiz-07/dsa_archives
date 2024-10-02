// https://leetcode.com/problems/word-ladder/
#include<bits/stdc++.h>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> wL(wordList.begin(), wordList.end());
    if (find(wL.begin(), wL.end(), endWord) == wL.end())
        return 0;
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    wL.erase(beginWord);
    while (!q.empty())
    {
        auto curr = q.front();
        string word = curr.first;
        int level = curr.second;
        q.pop();
        for (int i = 0; i < word.size(); i++)
        {
            string newWord = word;
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                newWord[i] = ch;
                if (newWord == endWord)
                {
                    return level + 1;
                }
                if (wL.erase(newWord))
                {
                    q.push({newWord, level + 1});
                }
            }
        }
    }
    return 0;
}