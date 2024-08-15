#include<bits/stdc++.h>
using namespace std;
void reverse(vector<int> &arr, int index) {
    if(index >= arr.size()/2) {
        return;
    }
    swap(arr[index], arr[arr.size() - index - 1]);
    reverse(arr, index + 1);
}
int main(void) {
    vector<int> arr = {1,2,3,4,5};
    for(int ele: arr) {
        cout << ele << " ";
    }
    cout << endl;
    reverse(arr, 0);
    for(int ele: arr) {
        cout << ele << " ";
    }
    return 0;
}