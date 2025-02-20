// https://leetcode.com/problems/task-scheduler/
#include <bits/stdc++.h>
using namespace std;
int leastInterval(vector<char> &tasks, int n)
{
    priority_queue<int> heap;
    vector<int> arr(26, 0);
    for (int i = 0; i < tasks.size(); i++)
    {
        arr[tasks[i] - 'A']++;
    }
    for (int freq : arr)
    {
        if (freq > 0)
        {
            heap.push(freq);
        }
    }

    queue<pair<int, int>> q; // count and ready time
    int time = 0;
    while (!heap.empty() || !q.empty())
    {
        if (!q.empty())
        {
            int outTime = q.front().second;
            int ele = q.front().first;
            if (outTime == time)
            {
                heap.push(ele);
                q.pop();
            }
        }
        if (!heap.empty())
        {
            if (heap.top() > 1)
            {
                q.push({heap.top() - 1, time + n + 1});
            }
            heap.pop();
        }
        time++;
    }

    return time;
    }
