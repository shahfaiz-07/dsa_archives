// https://www.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1
#include<bits/stdc++.h>
using namespace std;
vector<long long int> twoOddNum(long long int Arr[], long long int N)
{
    // code here
    long long int XOR = 0;
    for (int i = 0; i < N; i++)
    {
        XOR = XOR ^ Arr[i];
    }
    long long int sep = (XOR & (XOR - 1)) ^ XOR;
    long long int b0 = 0, b1 = 0;
    for (int i = 0; i < N; i++)
    {
        if (sep & Arr[i])
        {
            b0 = b0 ^ Arr[i];
        }
        else
        {
            b1 = b1 ^ Arr[i];
        }
    }
    if (b1 > b0)
    {
        return {b1, b0};
    }
    return {b0, b1};
}
int main(void) {
    
    return 0;
}