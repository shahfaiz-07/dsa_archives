#include<bits/stdc++.h>
using namespace std;

int main(void) {
    // MULTISET STORES ELEMENT IN SORTED ORDER - NOT UNIQUE !!
    multiset<int> ms;
    ms.insert(1);
    ms.insert(5);
    ms.insert(2);
    ms.insert(2);
    ms.insert(2);

    // ERASE ALL OCCURENCE
    // ms.erase(2); // All occurence of 2 are erased

    // ERASE SINGLE OCCURENCE
    // ms.erase(ms.find(2)); - as it erases the address

    // ERASE FINITE OCCURENCE
    // ms.erase(ms.find(2), ms.find(2)+2);

    cout << "Count :" << ms.count(2) << endl;

    for(int i: ms) {
        cout << i << " ";
    }
    cout<< endl;

    // Others are same as set
    return 0;
}