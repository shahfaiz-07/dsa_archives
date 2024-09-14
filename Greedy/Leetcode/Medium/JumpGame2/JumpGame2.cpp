// https://leetcode.com/problems/jump-game-ii/
#include <bits/stdc++.h>
using namespace std;
int jump(vector<int> &nums)
{
    int l = 0, r = 0, jumps = 0;
    while (r < nums.size() - 1)
    {
        int maxJ = 0;
        for (int i = l; i <= r; i++)
        {
            if (i + nums[i] > maxJ)
            {
                maxJ = i + nums[i];
            }
        }
        jumps++;
        l = r + 1;
        r = maxJ;
    }
    return jumps;
}
int main(void)
{

    return 0;
}