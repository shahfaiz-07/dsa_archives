// https://leetcode.com/problems/move-zeroes/description/
#include<bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &arr)
{
    if (arr.size() <= 1)
    {
        return;
    }
    int l = arr[0] == 0 ? 0 : 1, r = 1;
    while (r < arr.size())
    {
        if (arr[r] != 0)
        {
            while (l < r && arr[l] != 0)
            {
                l++;
            }
            if (l == r)
            {
                r++;
            }
            else
            {
                arr[l] = arr[r];
                arr[r] = 0;
            }
        }
        else
        {
            r++;
        }
    }
}
int main(void) {
    vector<int> arr = {0, 1, 0, 3, 12};
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    moveZeroes(arr);
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}