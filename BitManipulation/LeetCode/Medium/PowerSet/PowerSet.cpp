// https://leetcode.com/problems/subsets/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> allSubs;
    for (int i = 0; i < (1 << nums.size()); i++)
    {
        vector<int> sub;
        for (int j = 0; j < nums.size(); j++)
        {
            if ((1 << j) & i)
            {
                sub.push_back(nums[j]);
            }
        }
        allSubs.push_back(sub);
    }
    return allSubs;
}
int main(void) {
    vector<int> list = {1,2,3};
    for(vector<int> sub: subsets(list)) {
        cout << "[ ";
        for(int ele: sub) {
            cout << ele << " ";
        }
        cout << "]\n";
    }
    return 0;
}