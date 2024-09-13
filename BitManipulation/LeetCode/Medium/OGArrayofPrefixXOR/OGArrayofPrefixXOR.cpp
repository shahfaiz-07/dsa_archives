#include<bits/stdc++.h>
using namespace std;
vector<int> findArray(vector<int> &pref)
{
    vector<int> ans(pref.size());
    ans[0] = pref[0];
    for (int i = 1; i < pref.size(); i++)
    {
        ans[i] = pref[i] ^ pref[i - 1];
    }
    return ans;
}
int main(void) {
    
    return 0;
}