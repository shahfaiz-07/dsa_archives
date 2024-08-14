#include<bits/stdc++.h>
using namespace std;

int main(void) {
    map<int, int> mp;
    map<int, pair<int, int>> mp1;
    map<pair<int, int>, int> mp2;

    // Key, Value pairs - Keys(Unique), Values(Can Repeat)
    // Unique keys are stored in sorted order similar to set data structure
    // Works in most cases in log(N) time

    mp.insert({3,1});
    mp[1] = 2;

    for(auto it: mp) {
        cout << it.first << ", " << it.second << endl;
    }

    // functions like find, lower_bound, upper_bound can be applied for keys
    // erase, swap, size, empty are same

    // MULTIMAP - Same as map but you can store duplicated keys(in sorted order)
    // mp[key] CANNOT BE USED!!

    // UNORDERED_MAP _ Unique keys but not in sorted order
    // Works in O(1) time but in very rare(worst) case goes for O(n) time
    return 0;
}