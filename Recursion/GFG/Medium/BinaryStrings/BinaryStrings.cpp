// https://www.geeksforgeeks.org/problems/generate-all-binary-strings/
#include<bits/stdc++.h>
using namespace std;
void generate(int num, string str, vector<string> &combos)
{
    if (str.length() == num)
    {
        combos.push_back(str);
        return;
    }
    generate(num, str + "0", combos);
    if (str.length() == 0 || str[str.length() - 1] != '1')
    {
        generate(num, str + "1", combos);
    }
}

vector<string> generateBinaryStrings(int num)
{
    vector<string> ans;
    generate(num, "", ans);
    return ans;
}
int main(void) {
    vector<string> v = generateBinaryStrings(5);
    for(string ele: v) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}