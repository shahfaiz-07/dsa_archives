// https://www.geeksforgeeks.org/problems/ceil-the-floor2802/1
#include <bits/stdc++.h>
using namespace std;
vector<int> getFloorAndCeil(int x, vector<int> &arr)
{
    // code here
    vector<int> ans = {-1, -1};
    sort(arr.begin(), arr.end());

    int l = 0, r = arr.size() - 1;
    while (l <= r)
    {
        int m = r - (r - l) / 2;

        if (arr[m] == x)
        {
            return {x, x};
        }
        if (x > arr[m])
        {
            l = m + 1;
            ans[0] = arr[m];
        }
        else
        {
            r = m - 1;
            ans[1] = arr[m];
        }
    }
    return ans;
}
int main(void)
{

    return 0;
}