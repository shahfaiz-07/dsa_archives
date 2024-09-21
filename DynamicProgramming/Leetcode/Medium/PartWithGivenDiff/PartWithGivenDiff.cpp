// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int count(vector<int> &arr, int index, int target, vector<vector<int>> &dp)
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
    {
        return dp[index][target];
    }
    int x = 0;
    if (target >= arr[index])
    {
        x = count(arr, index - 1, target - arr[index], dp);
    }
    int y = count(arr, index - 1, target, dp);
    dp[index][target] = (x + y) % MOD;
    return dp[index][target];
}
int countPartitions(int n, int d, vector<int> &arr)
{
    // Code here
    int sum = 0;
    for (int &ele : arr)
    {
        sum += ele;
    }
    int target = (sum - d);
    if (target < 0 || ((target & 1) == 1))
        return 0;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return count(arr, n - 1, target / 2, dp);
}
int main(void) {
    
    return 0;
}