// https://www.geeksforgeeks.org/problems/second-largest3735/
#include<bits/stdc++.h>
using namespace std;
int print2largest(vector<int> &arr)
{
    // Code Here
    int m = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > m)
        {
            m = arr[i];
        }
    }
    int sm = arr[0];
    if (m == arr[0])
    {
        sm = arr.size() > 1 ? arr[1] : arr[0];
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > sm && arr[i] < m)
        {
            sm = arr[i];
        }
    }
    return sm != m ? sm : -1;
}
int main(void) {
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout << print2largest(arr);
    return 0;
}