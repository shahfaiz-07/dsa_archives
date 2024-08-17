#include<bits/stdc++.h>
using namespace std;
vector<int> resultsArray(vector<int> &nums, int k)
{
    vector<int> result;
    int l = 0, r = 0, last_peak = -1;
    while (r < nums.size())
    {
        if (r > 0)
        {
            if (nums[r - 1] + 1 != nums[r])
            {
                last_peak = r;
            }
        }
        if ((r - l + 1) < k)
        {
            r++;
        }
        else if ((r - l + 1) > k)
        {
            l++;
        }
        else
        {
            if (last_peak > l && last_peak <= r)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(nums[r]);
            }
            l++;
            r++;
        }
    }
    return result;
}
int main(void) {
    vector<int> nums = {1,2,3,4,6,4,3};
    vector<int> ans = resultsArray(nums, 3);
    for(int ele: ans) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}