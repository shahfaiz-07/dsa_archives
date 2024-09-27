// https://leetcode.com/problems/palindrome-partitioning/
#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string str)
{
    int i = 0, j = str.size() - 1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void partition(string s, int index, vector<vector<string>> &seqs, vector<string> &seq)
{
    if (index == s.size())
    {
        seqs.emplace_back(seq);
        return;
    }
    string str = "";
    for (int i = index; i < s.size(); i++)
    {
        str += s[i];
        if (isPalindrome(str))
        {
            seq.emplace_back(str);
            partition(s, i + 1, seqs, seq);
            seq.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> seqs;
    vector<string> seq;
    partition(s, 0, seqs, seq);
    return seqs;
}
int main(void) {
    
    return 0;
}