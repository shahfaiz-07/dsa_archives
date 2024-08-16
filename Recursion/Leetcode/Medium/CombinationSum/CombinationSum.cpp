// https://leetcode.com/problems/combination-sum/description/
#include<bits/stdc++.h>
using namespace std;
void combinations(vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> &combo, int index)
{
    if (target <= 0 || index == candidates.size())
    {
        if (target == 0)
        {
            combo.push_back(v);
        }
        return;
    }
    v.push_back(candidates[index]);
    combinations(candidates, target - candidates[index], v, combo, index);
    v.pop_back();
    combinations(candidates, target, v, combo, index + 1);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> arr;
    vector<int> v;
    combinations(candidates, target, v, arr, 0);
    return arr;
}
int main(void) {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> ans = combinationSum(candidates, target);
    for(auto v: ans) {
        for(int ele: v) {
            cout << ele << " ";
        }
        cout << endl;
    }
}