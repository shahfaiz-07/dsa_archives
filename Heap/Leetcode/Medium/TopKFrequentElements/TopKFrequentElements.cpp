// https://leetcode.com/problems/top-k-frequent-elements/
#include<bits/stdc++.h>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    unordered_map<int, int> map;

    for (int &ele : nums)
    {
        map[ele]++;
    }

    for (auto &pairs : map)
    {
        int freq = pairs.second;
        int ele = pairs.first;

        if (minHeap.size() < k)
        {
            minHeap.push({freq, ele});
        }
        else
        {
            if (minHeap.top().first < freq)
            {
                minHeap.pop();
                minHeap.push({freq, ele});
            }
        }
    }

    vector<int> ans;
    while (!minHeap.empty())
    {
        ans.emplace_back(minHeap.top().second);
        minHeap.pop();
    }

    return ans;
}