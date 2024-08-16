// https://leetcode.com/problems/subsets-ii/
#include<bits/stdc++.h>
using namespace std;
void subsets(vector<int> &nums, vector<int> &sub, vector<vector<int>> &subs, int start)
{
    if (start <= nums.size())
    {
        subs.push_back(sub);
        if (start == nums.size())
        {
            return;
        }
    }
    for (int i = start; i < nums.size(); i++)
    {
        if (i != start && nums[i] == nums[i - 1])
        {
            continue;
        }
        sub.push_back(nums[i]);
        subsets(nums, sub, subs, i + 1);
        sub.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> sub;
    vector<vector<int>> subs;
    subsets(nums, sub, subs, 0);
    return subs;
}
int main(void) {
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(nums);
    for(auto v: ans) {
        for(int ele: v) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}