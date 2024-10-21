// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
#include<bits/stdc++.h>
using namespace std;
int maxMeetings(vector<int> start, vector<int> end)
{
    // Your code here
    vector<pair<int, int>> meetings; // end, start
    for (int i = 0; i < start.size(); i++)
    {
        meetings.emplace_back(make_pair(end[i], start[i]));
    }
    sort(meetings.begin(), meetings.end()); // sort according to end time
    int freeTime = -1, count = 0;
    for (auto meeting : meetings)
    {
        int end = meeting.first, start = meeting.second;
        if (start > freeTime)
        {
            freeTime = end;
            count++;
        }
    }
    return count;
}
int main(void) {
    
    return 0;
}