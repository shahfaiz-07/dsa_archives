#include<bits/stdc++.h>
using namespace std;
int main(void) {
    auto lambda1 = [] (int &a, int &b) {
        return a > b;
    };
    vector<int> a = {1,2,3,4,5,6};
    sort(a.begin(), a.end(), lambda1);
    for(int ele: a) {
        cout << ele << " ";
    }
    cout << "\n";
    return 0;
}