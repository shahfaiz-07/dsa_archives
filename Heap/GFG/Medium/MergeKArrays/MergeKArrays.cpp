// https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
#include<bits/stdc++.h>
using namespace std;
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    // code here
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>
        pq;

    for (int i = 0; i < K; i++)
    {
        pq.push({arr[i][0], {i, 0}});
    }

    vector<int> ans(K * K);
    for (int i = 0; i < K * K; i++)
    {
        auto root = pq.top();
        pq.pop();
        int num = root.first, arr_num = root.second.first, ind = root.second.second;
        ans[i] = num;
        if (ind < K - 1)
        {
            pq.push({arr[arr_num][ind + 1], {arr_num, ind + 1}});
        }
    }

    return ans;
}
int main(void) {
    
    return 0;
}