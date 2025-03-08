// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
#include<bits/stdc++.h>
using namespace std;
long subarrayXor(vector<int> &arr, int k)
{
    // code here
    unordered_map<int, int> hash;
    hash[0] = 1;
    int XOR = 0, c = 0;
    for (int ele : arr)
    {
        XOR ^= ele;
        int x_k = XOR ^ k;
        int val = hash[x_k];
        if (val)
        {
            c += val;
        }
        hash[XOR]++;
    }
    return c;
}