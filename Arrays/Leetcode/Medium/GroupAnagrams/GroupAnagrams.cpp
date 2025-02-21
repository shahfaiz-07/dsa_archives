// https://leetcode.com/problems/group-anagrams/
#include<bits/stdc++.h>
using namespace std;

string hashKey(string &a)
{
    vector<int> hashMap(26, 0);

    for (int i = 0; i < a.length(); i++)
    {
        hashMap[a[i] - 'a'] += 1;
    }
    string key = "";
    for (int &i : hashMap)
    {
        key += to_string(i) + ",";
    }
    return key;
}
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    for (string &str : strs)
    {
        mp[hashKey(str)].emplace_back(str);
    }

    vector<vector<string>> ans;
    for (auto &values : mp)
    {
        ans.emplace_back(values.second);
    }
    return ans;
}