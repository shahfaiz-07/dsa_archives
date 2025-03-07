// https://leetcode.com/problems/majority-element-ii/
#include<bits/stdc++.h>
using namespace std;
// HASHING
vector<int> majorityElement(vector<int> &nums)
{
    unordered_map<int, int> hash;
    vector<int> ans;
    for (int &ele : nums)
    {
        hash[ele]++;
        if (hash[ele] == nums.size() / 3 + 1)
        {
            ans.emplace_back(ele);
            if (ans.size() == 2)
                break;
        }
    }
    return ans;
}