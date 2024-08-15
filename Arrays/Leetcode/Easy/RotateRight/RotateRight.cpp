// https://leetcode.com/problems/rotate-array/
#include<bits/stdc++.h>
using namespace std;
// with O(1) extra space
// Observation:
// Reverse the array
// Reverse first k elements
// Reverse next k elements
void rotate2(vector<int> &nums, int k) {
    k = k % nums.size();
    for (int i = 0; i < nums.size() / 2; i++)
    {
        int t = nums[i];
        nums[i] = nums[nums.size() - 1 - i];
        nums[nums.size() - 1 - i] = t;
    }
    for (int l = 0, r = k - 1; l < r; l++, r--)
    {
        int t = nums[l];
        nums[l] = nums[r];
        nums[r] = t;
    }
    for (int l = k, r = nums.size() - 1; l < r; l++, r--)
    {
        int t = nums[l];
        nums[l] = nums[r];
        nums[r] = t;
    }
}
// with O(1) extra space
void rotate(vector<int> &nums, int k)
{
    k = k % nums.size();
    vector<int> temp(nums.size() - k);
    for (int i = 0; i < nums.size() - k; i++)
    {
        temp[i] = nums[i];
    }
    for (int i = 0; i < k; i++)
    {
        nums[i] = nums[nums.size() - k + i];
    }
    for (int i = k, j = 0; i < nums.size(); i++, j++)
    {
        nums[i] = temp[j];
    }
}
int main(void) {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    for(int i: arr) {
        cout << i << " ";
    }
    cout << endl;
    rotate(arr, 3);
    for(int i: arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}