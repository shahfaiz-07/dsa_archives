// https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1
#include<bits/stdc++.h>
using namespace std;
string postToPre(string &post_exp)
{
    // Write your code here
    stack<string> st;
    for (char &ch : post_exp)
    {
        if (isalnum(ch))
        {
            st.push(string(1, ch));
        }
        else
        {
            string right = st.top();
            st.pop();
            string left = st.top();
            st.pop();
            string exp = string(1, ch) + left + right;
            st.push(exp);
        }
    }
    return st.top();
}