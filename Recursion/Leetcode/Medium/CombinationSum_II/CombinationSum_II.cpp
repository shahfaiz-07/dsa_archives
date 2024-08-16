// https://leetcode.com/problems/combination-sum-ii/
#include<bits/stdc++.h>
using namespace std;
void combinations2(vector<int> &candidates, int target, vector<int> &v, vector<vector<int>> &combo, int start)
{
    if (target == 0)
    {
        combo.emplace_back(v);
        return;
    }
    for (int i = start; i < candidates.size(); i++)
    {
        if (i != start && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;
        v.emplace_back(candidates[i]);
        combinations2(candidates, target - candidates[i], v, combo, i + 1);
        v.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> arr;
    vector<int> v;
    combinations2(candidates, target, v, arr, 0);
    return arr;
}
int main(void) {
    
    return 0;
}