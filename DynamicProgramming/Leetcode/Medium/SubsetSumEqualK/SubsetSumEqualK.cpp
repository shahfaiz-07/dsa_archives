// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
#include<bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int countSeq(int arr[], int target, int index, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || arr[0] == target)
            return 1;
        return 0;
    }
    if (dp[index][target] != -1)
        return dp[index][target];
    int x = 0;
    if (target >= arr[index])
        x = countSeq(arr, target - arr[index], index - 1, dp);
    int y = countSeq(arr, target, index - 1, dp);
    return dp[index][target] = (x + y) % mod;
}

int perfectSum(int arr[], int n, int sum)
{
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return countSeq(arr, sum, n - 1, dp);
}
int main(void) {
    
    return 0;
}