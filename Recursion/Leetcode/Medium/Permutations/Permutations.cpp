// https://leetcode.com/problems/permutations/
#include<bits/stdc++.h>
using namespace std;
void recurse(vector<int> &nums, int ind, vector<vector<int>> &ans)
{
    if (ind == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = ind; i < nums.size(); i++)
    {
        swap(nums[ind], nums[i]);
        recurse(nums, ind + 1, ans);
        swap(nums[ind], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    recurse(nums, 0, ans);
    return ans;
}
int main(void) {
    
    return 0;
}