// https://leetcode.com/problems/jump-game/
#include<bits/stdc++.h>
using namespace std;
bool canJump(vector<int> &nums)
{
    int maxJump = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > maxJump)
            return false;
        if (nums[i] + i > maxJump)
        {
            maxJump = nums[i] + i;
        }
        if (maxJump >= nums.size() - 1)
            return true;
    }
    return false;
}
int main(void) {
    
    return 0;
}