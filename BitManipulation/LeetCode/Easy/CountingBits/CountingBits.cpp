// https://leetcode.com/problems/counting-bits/
#include<bits/stdc++.h>
using namespace std;
// TC = O(N)
vector<int> countBits(int n)
{
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++)
    {
        ans[i] = ans[i / 2] + (i & 1);
    }
    return ans;
}
// TC = O(NlogN)
vector<int> countBits1(int n)
{
    vector<int> ans(n + 1);
    for (int i = 0; i <= n; i++)
    {
        int count = 0;
        int temp = i;
        // __builtin_popcount(i); --> inbuilt function
        while (temp)
        {
            temp = temp & (temp - 1);
            count++;
        }
        ans[i] = count;
    }
    return ans;
}
int main(void) {
    
    return 0;
}