// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
#include<bits/stdc++.h>
using namespace std;
int kthSmallest(vector<int> &arr, int k)
{
    // code here
    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < arr.size(); i++)
    {
        if (pq.top() > arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}
int main(void) {
    
    return 0;
}