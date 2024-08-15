// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int l = 0, r = 1;
    while (r < nums.size())
    {
        if (nums[l] != nums[r]) // using two pointers only copy the element which is not equal to current element
        {
            nums[++l] = nums[r];
        }
        r++;
    }
    return l + 1; // l-th element will be the last element
}
int main(void)
{
    vector<int> arr = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    int n = removeDuplicates(arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}