// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1
#include<bits/stdc++.h>
using namespace std;
int largest(vector<int> &arr, int n)
{
    int m = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > m)
        {
            m = arr[i];
        }
    }
    return m;
}
int main(void) {
    vector<int> arr = {2,4,1,6,7,9,5,3};
    cout << largest(arr, arr.size());
    return 0;
}