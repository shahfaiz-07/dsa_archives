// https://leetcode.com/problems/candy/
#include<bits/stdc++.h>
using namespace std;
// SC = O(N)
int candy(vector<int> &ratings)
{
    vector<int> left(ratings.size());
    left[0] = 1;
    for (int i = 1; i < ratings.size(); i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            left[i] = left[i - 1] + 1;
        }
        else
        {
            left[i] = 1;
        }
    }
    int sum = left[ratings.size() - 1];
    int prev = 1;
    for (int i = ratings.size() - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            prev++;
        }
        else
        {
            prev = 1;
        }
        sum += max(left[i], prev);
    }
    return sum;
}
// Slope Approach
int main(void) {
    
    return 0;
}