// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
#include<bits/stdc++.h>
        using namespace std;
bool check(vector<int> &nums)
{
    int breakPoint = 0;
    for (int i = 0; i < nums.size() - 1 && breakPoint <= 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            breakPoint++;
        }
    }
    if (breakPoint == 1)
    {
        return nums[0] >= nums[nums.size() - 1];
    }
    return breakPoint == 0;
}
int main(void) {
    vector<int> arr = {2,1,3,4};
    cout << check(arr);
    return 0;
}