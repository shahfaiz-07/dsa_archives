// https://leetcode.com/problems/subsets/description/
#include<bits/stdc++.h>
using namespace std;
void subSequence(vector<int> &nums, vector<int> &sub, vector<vector<int>> &allSubs, int index)
{
    if (index >= nums.size())
    {
        allSubs.push_back(sub);
        return;
    }
    subSequence(nums, sub, allSubs, index + 1);
    sub.push_back(nums[index]);
    subSequence(nums, sub, allSubs, index + 1);
    sub.pop_back();
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> allSubs;
    vector<int> sub;
    subSequence(nums, sub, allSubs, 0);
    return allSubs;
}
int main(void) {
    vector<int> num = {1, 2, 3};
    vector<vector<int>> vec = subsets(num);
    for(auto v : vec) {
        for(int ele : v) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}