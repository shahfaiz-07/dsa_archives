// https://leetcode.com/problems/combination-sum-iii/
#include<bits/stdc++.h>
using namespace std;
void findCombo(int k, int n, vector<vector<int>> &combo, vector<int> &seq, int current)
{
    if (n == 0 || current == 10)
    {
        if (seq.size() == k && n == 0)
        {
            combo.push_back(seq);
        }
        return;
    }
    if (n >= current)
    {
        seq.push_back(current);
        findCombo(k, n - current, combo, seq, current + 1);
        seq.pop_back();
        findCombo(k, n, combo, seq, current + 1);
    }
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> combo;
    vector<int> seq;
    findCombo(k, n, combo, seq, 1);
    return combo;
}
int main(void) {
    vector<vector<int>> ans = combinationSum3(3, 7);
    for(auto v: ans ){
        for(int ele: v) {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}