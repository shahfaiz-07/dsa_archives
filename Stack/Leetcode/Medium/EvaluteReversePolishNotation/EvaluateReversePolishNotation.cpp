// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include<bits/stdc++.h>
using namespace std;
int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++)
    {
        char ch = tokens[i][0];
        if (tokens[i].length() == 1 && (ch == '+' || ch == '-' || ch == '*' || ch == '/'))
        {
            int ch2 = st.top();
            st.pop();
            int ch1 = st.top();
            st.pop();
            int res = 0;
            switch (ch)
            {
            case '+':
                res = ch1 + ch2;
                break;
            case '-':
                res = ch1 - ch2;
                break;
            case '*':
                res = ch1 * ch2;
                break;
            case '/':
                res = ch1 / ch2;
                break;
            }
            st.push(res);
        }
        else
        {
            st.push(stoi(tokens[i]));
        }
    }
    return st.top();
}