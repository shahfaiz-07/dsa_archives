// https://leetcode.com/problems/remove-k-digits/
#include<bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0; i<num.length(); i++) {
            while(!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            if(!st.empty() ||  num[i] != '0') st.push(num[i]);
        }
        while(!st.empty() && k > 0) {
            st.pop();
            k--;
        }
        string ans ;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans.length() == 0 ? "0" : ans;
    }