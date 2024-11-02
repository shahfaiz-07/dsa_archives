// https://leetcode.com/problems/kth-largest-element-in-an-array/
#include<bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> pq;

    for (int &ele : nums)
    {
        pq.push(ele);
    }

    for (int i = 1; i <= k - 1; i++)
    {
        pq.pop();
    }

    return pq.top();
}
int main(void) {
    
    return 0;
}