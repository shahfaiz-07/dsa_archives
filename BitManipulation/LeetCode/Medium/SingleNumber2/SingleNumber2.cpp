// https://leetcode.com/problems/single-number-ii/
#include<bits/stdc++.h>
using namespace std;
// USING BIT MANIPULATION
// TC = O(32*N)
int singleNumber(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i <= 31; i++)
    {
        int count = 0;
        for (int index = 0; index < nums.size(); index++)
        {
            if ((nums[index] & (1 << i)))
            {
                count++;
            }
        }
        if (count % 3 == 1)
        {
            ans = (ans | (1 << i));
        }
    }
    return ans;
}

// SORTING
// TC = O(NlogN) + O(N/3)
int singleNumber2(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i += 3)
    {
        if (nums[i - 1] != nums[i])
        {
            return nums[i - 1];
        }
    }
    return nums[nums.size() - 1];
}

// CONCEPT OF BUCKETS
int singleNumber(vector<int> &nums)
{
    int ones = 0, twos = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        // if it is not in twos, it should be in ones
        ones = (ones ^ nums[i]) & (~twos);
        // if it is not in ones, it will go to twos
        twos = (twos ^ nums[i]) & (~ones);
    }
    return ones;
}
int main(void) {
    
    return 0;
}