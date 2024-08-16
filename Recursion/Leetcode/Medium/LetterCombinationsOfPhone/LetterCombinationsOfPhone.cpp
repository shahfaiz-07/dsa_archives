// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
#include<bits/stdc++.h>
using namespace std;
void getCombos(string digits, vector<string> &combos, string seq, int index, vector<string> &charMap)
{
    if (seq.length() == digits.length())
    {
        combos.push_back(seq);
        return;
    }
    for (int i = 0; i < charMap[digits[index] - '0'].length(); i++)
    {
        getCombos(digits, combos, seq + charMap[digits[index] - '0'][i], index + 1, charMap);
    }
}
vector<string> letterCombinations(string digits)
{
    vector<string> combos;
    vector<string> charMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if (digits == "")
    {
        return combos;
    }
    getCombos(digits, combos, "", 0, charMap);
    return combos;
}
int main(void) {
    vector<string> ans = letterCombinations("234");
    for(string ele: ans) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}