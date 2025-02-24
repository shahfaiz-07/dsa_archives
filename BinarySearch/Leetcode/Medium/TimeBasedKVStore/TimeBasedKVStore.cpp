// https://leetcode.com/problems/time-based-key-value-store/
#include<bits/stdc++.h>
using namespace std;

//! SAME LOGIC AS JAVA BUT GIVES TLE
class TimeMap
{
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        mp[key].emplace_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp)
    {
        vector<pair<int, string>> values = mp[key];
        if (!values.size())
            return "";

        string value = "";
        int l = 0, r = values.size() - 1;
        while (l <= r)
        {
            int m = r - (r - l) / 2;
            if (values[m].first <= timestamp)
            {
                value = values[m].second;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return value;
    }
};