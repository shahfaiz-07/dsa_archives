// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
#include<bits/stdc++.h>
using namespace std;
vector<int> findTwoElement(vector<int> &arr)
{
    // code here
    int allXor = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        allXor ^= arr[i];
        allXor ^= (i + 1);
    }

    // a ^ b
    int diff = allXor & ~(allXor - 1);
    int setBit = 0, unsetBit = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if ((arr[i] & diff) != 0)
            setBit ^= arr[i];
        else
            unsetBit ^= arr[i];

        if (((i + 1) & diff) != 0)
            setBit ^= (i + 1);
        else
            unsetBit ^= (i + 1);
    }

    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == setBit)
        {
            cnt++;
            if (cnt == 2)
                break;
        }
    }
    return cnt == 2 ? vector<int>{setBit, unsetBit} : vector<int>{unsetBit, setBit};
}