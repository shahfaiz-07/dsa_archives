// https://leetcode.com/problems/generate-parentheses/
#include<bits/stdc++.h>
using namespace std;
void generateP(string s, int n, vector<string> &v, int left, int right)
{
    if (s.length() == n * 2)
    {
        v.push_back(s);
        return;
    }
    if (left < n)
    {
        generateP(s + "(", n, v, left + 1, right);
    }
    if (right < left)
    {
        generateP(s + ")", n, v, left, right + 1);
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> s;
    generateP("", n, s, 0, 0);
    return s;
}
int main(void) {
    vector<string> str = generateParenthesis(3);
    for(string ele: str) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}