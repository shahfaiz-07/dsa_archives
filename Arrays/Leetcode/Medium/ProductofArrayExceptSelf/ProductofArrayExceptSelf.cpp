// https://leetcode.com/problems/product-of-array-except-self/

#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int l = nums.size();
    vector<int> prefixProd(l, 1);
    vector<int> suffixProd(l, 1);
    prefixProd[0] = nums[0];
    suffixProd[l - 1] = nums[l - 1];
    for (int i = 1; i < l - 1; i++)
    {
        prefixProd[i] = nums[i] * prefixProd[i - 1];
        suffixProd[l - i - 1] = nums[l - i - 1] * suffixProd[l - i];
    }
    vector<int> ans(l, 1);

    ans[0] = suffixProd[1];
    ans[l - 1] = prefixProd[l - 2];

    for (int i = 1; i < l - 1; i++)
    {
        ans[i] = prefixProd[i - 1] * suffixProd[i + 1];
    }
    return ans;
}