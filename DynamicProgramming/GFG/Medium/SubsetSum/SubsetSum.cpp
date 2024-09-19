#include<bits/stdc++.h>
using namespace std;
// TABULATION
bool isSubsetSum(vector<int> arr, int sum)
{
    // code here
    vector<vector<bool>> dp(arr.size(), vector<bool>(sum + 1, 0));
    for (int i = 0; i < arr.size(); i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;// if the first index is equal to target sum
    for (int i = 1; i < arr.size(); i++)
    {
        for (int s = 1; s <= sum; s++)
        {
            bool pick = false;
            if (s - arr[i] >= 0)
            {
                pick = dp[i - 1][s - arr[i]];
            }
            bool notPick = dp[i - 1][s];
            dp[i][s] = (pick || notPick);
        }
    }
    return dp[arr.size() - 1][sum];
}
// MEMOIZATION
bool exists(vector<int> &arr, int sum, int index, vector<vector<int>> &dp)
{
    if (sum == 0)
    {
        return true;
    }
    if (index < 0 || sum < 0)
    {
        return false;
    }
    if (dp[index][sum] != -1)
    {
        return dp[index][sum];
    }
    // pick
    if (exists(arr, sum - arr[index], index - 1, dp))
        return dp[index][sum] = 1;
    // don't pick
    if (exists(arr, sum, index - 1, dp))
        return dp[index][sum] = 1;
    return dp[index][sum] = 0;
}

bool isSubsetSum(vector<int> arr, int sum)
{
    // code here
    vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
    return exists(arr, sum, arr.size() - 1, dp);
}
int main(void) {
    
    return 0;
}