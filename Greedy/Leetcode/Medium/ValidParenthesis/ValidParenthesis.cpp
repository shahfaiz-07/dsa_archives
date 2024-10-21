// https://leetcode.com/problems/valid-parenthesis-string/
#include<bits/stdc++.h>
using namespace std;
bool checkValidString(string s)
{
    int mini = 0, maxi = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            mini++;
            maxi++;
        }
        else if (ch == ')')
        {
            mini--;
            maxi--;
        }
        else
        {
            mini--;
            maxi++;
        }
        mini = mini < 0 ? 0 : mini;
        if (maxi < 0)
            return false;
    }
    return mini == 0;
}
int main(void) {
    
    return 0;
}