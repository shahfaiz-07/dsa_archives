// https://leetcode.com/problems/erect-the-fence/
#include <bits/stdc++.h>
using namespace std;

int equation(pair<int, int> &p1, pair<int, int> &p2, pair<int, int> p3)
{
    // m23 - m21 > 0 (for convex in lower half)
    // (y3-y2)/(x3-x2) - (y2-y1)/(x2-x1)
    // (y3-y2)(x2-x1) - (y2-y1)(x3-x2)
    int x1 = p1.first, y1 = p1.second, x2 = p2.first, y2 = p2.second, x3 = p3.first, y3 = p3.second;

    return (y3 - y2) * (x2 - x1) - (y2 - y1) * (x3 - x2);
}
vector<vector<int>> outerTrees(vector<vector<int>> &trees)
{
    // looking from left bottom to right
    sort(trees.begin(), trees.end());

    deque<pair<int, int>> lower, upper;

    for (auto &point : trees)
    {
        // positive for lower negative for above for convexity
        while (lower.size() >= 2 && equation(lower[lower.size() - 2], lower[lower.size() - 1], {point[0], point[1]}) < 0)
        {
            lower.pop_back();
        }

        while (upper.size() >= 2 && equation(upper[upper.size() - 2], upper[upper.size() - 1], {point[0], point[1]}) > 0)
        {
            upper.pop_back();
        }

        lower.push_back({point[0], point[1]});
        upper.push_back({point[0], point[1]});
    }

    set<pair<int, int>> st;

    for (auto &point : lower)
    {
        st.insert(point);
    }
    for (auto &point : upper)
    {
        st.insert(point);
    }

    vector<vector<int>> ans;
    for (auto &point : st)
    {
        ans.push_back({point.first, point.second});
    }

    return ans;
}